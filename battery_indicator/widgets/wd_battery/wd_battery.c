/**
 * @file wd_battery.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "wd_battery_private_gen.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/
#define BATTERY_LOW_THRESHOLD 20

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void icon_recolor_none(lv_obj_t * icon);
static void icon_recolor_dark(lv_obj_t * icon);
static void update_battery_widget(wd_battery_t * w);
static void slider_value_changed_cb(lv_event_t * e);
static void value_observer_cb(lv_observer_t * obs, lv_subject_t * subject);
static void low_power_observer_cb(lv_observer_t * obs, lv_subject_t * subject);
static void charging_observer_cb(lv_observer_t *obs, lv_subject_t *subject);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_battery_constructor_hook(lv_obj_t * obj)
{
    wd_battery_t * battery = (wd_battery_t *)obj;

    /* Initial UI state derived from props (defaults come from <api>) */
    if(battery->charging_icon) lv_obj_add_flag(battery->charging_icon, LV_OBJ_FLAG_HIDDEN);

    if(battery->slider_indicator) {
        lv_slider_set_value(battery->slider_indicator, battery->value, LV_ANIM_OFF);
        lv_obj_add_event_cb(battery->slider_indicator, slider_value_changed_cb,
                            LV_EVENT_VALUE_CHANGED, battery);
        lv_obj_remove_flag(battery->slider_indicator, LV_OBJ_FLAG_CLICKABLE);
    }

    if(battery->pct_text) lv_label_set_text_fmt(battery->pct_text, "%d", (int)battery->value);

    update_battery_widget(battery);
}

void wd_battery_destructor_hook(lv_obj_t * obj)
{

}

void wd_battery_event_hook(lv_event_t * e)
{

}

void wd_battery_set_value(lv_obj_t * o, int32_t v)
{
    wd_battery_t * battery = (wd_battery_t *)o;
    battery->value = v;
    /* Set slider with battery value */
    if(battery->slider_indicator) lv_slider_set_value(battery->slider_indicator, v, LV_ANIM_OFF);
    /* Set text with battery value */
    if(battery->pct_text) lv_label_set_text_fmt(battery->pct_text, "%d", (int)v);
}

void wd_battery_bind_value(lv_obj_t * o, lv_subject_t * subject)
{
    wd_battery_t * battery = (wd_battery_t *)o;
    if(!battery || !subject || !battery->slider_indicator) return;

    /* two-way binding: slider <-> subject */
    lv_slider_bind_value(battery->slider_indicator, subject);

    /* observe to keep label synced */
    lv_subject_add_observer_obj(subject, value_observer_cb, o, battery);

    /* prime from current subject value */
    wd_battery_set_value(o, lv_subject_get_int(subject));
}

void wd_battery_set_low_power(lv_obj_t * o, bool en)
{
    wd_battery_t * battery = (wd_battery_t *)o;
    battery->low_power = en ? 1 : 0;
    update_battery_widget(battery);
}

void wd_battery_bind_low_power(lv_obj_t * o, lv_subject_t * subject)
{
    wd_battery_t * battery = (wd_battery_t *)o;
    if(!battery || !subject) return;

    lv_subject_add_observer_obj(subject, low_power_observer_cb, o, battery);
    wd_battery_set_low_power(o, lv_subject_get_int(subject) != 0);
}

void wd_battery_set_charging(lv_obj_t * o, bool en)
{
    wd_battery_t * battery = (wd_battery_t *)o;
    battery->charging = en ? 1 : 0;
    update_battery_widget(battery);
}

void wd_battery_bind_charging(lv_obj_t * o, lv_subject_t * subject)
{
    wd_battery_t * battery = (wd_battery_t *)o;
    if(!battery || !subject) return;

    lv_subject_add_observer_obj(subject, charging_observer_cb, o, battery);
    wd_battery_set_charging(o, lv_subject_get_int(subject) != 0);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* helpers to recolor charging icon */
static void icon_recolor_none(lv_obj_t * icon)
{
    /* show original (white) asset */
    lv_obj_set_style_image_recolor_opa(icon, LV_OPA_TRANSP, 0);
}

static void icon_recolor_dark(lv_obj_t * icon)
{
    /* dark recolor */
    lv_obj_set_style_image_recolor(icon, lv_color_hex(0x505050), 0);
    lv_obj_set_style_image_recolor_opa(icon, LV_OPA_COVER, 0);
}

static void update_battery_widget(wd_battery_t * battery)
{
    /* Indicator color: green normal, yellow when low-power */
    lv_color_t indicator_color = lv_color_hex(0xFFFFFF); /* white (normal) */
    if (battery->low_power) {
        indicator_color = lv_color_hex(0xFECC0B);  /* yellow */
    } else if(battery->value <= BATTERY_LOW_THRESHOLD) {
        indicator_color = lv_color_hex(0xFD3B2F); /* red */
    } else if(battery->charging) {
        indicator_color = lv_color_hex(0x37C557); /* green */
    }


    if(battery->slider_indicator) {
        lv_obj_set_style_bg_color(battery->slider_indicator, indicator_color, LV_PART_INDICATOR);
    }

    /* Update color of the battery tip */
    if(battery->battery_tip) {
        if(battery->value == 100) lv_obj_set_style_bg_color(battery->battery_tip, indicator_color, LV_PART_MAIN);
        else lv_obj_set_style_bg_color(battery->battery_tip, lv_color_hex(0x999999), LV_PART_MAIN);
    }
    
    /* Text color:
       - low_power -> dark
       - else if (charging OR value ≤ threshold) -> white
       - else -> dark
    */
    lv_color_t text_color = battery->low_power ? lv_color_hex(0x505050)
                           : ((battery->charging || battery->value <= BATTERY_LOW_THRESHOLD)
                                 ? lv_color_hex(0xFFFFFF)
                                 : lv_color_hex(0x505050));

    /* Update battery text indicator color*/
    if(battery->pct_text) {
        lv_obj_set_style_text_color(battery->pct_text, text_color, 0);
    }

    /* Charging icon visible only when charging=1 */
    if(battery->charging_icon) {
        if(battery->charging) {
            lv_obj_remove_flag(battery->charging_icon, LV_OBJ_FLAG_HIDDEN);

            if(battery->low_power) {
                icon_recolor_dark(battery->charging_icon);
            } else {
                icon_recolor_none(battery->charging_icon);
            }
        } else {
            lv_obj_add_flag(battery->charging_icon, LV_OBJ_FLAG_HIDDEN);
            icon_recolor_none(battery->charging_icon);
        }
    }
}

/* Keep label text in sync with slider value (user drag or programmatic) */
static void slider_value_changed_cb(lv_event_t * e)
{
    wd_battery_t * battery = (wd_battery_t *)lv_event_get_user_data(e);
    if(!battery || !battery->slider_indicator) return;

    int32_t v = lv_slider_get_value(battery->slider_indicator);
    battery->value = v;

    if(battery->pct_text) lv_label_set_text_fmt(battery->pct_text, "%d", (int)v);
}

/* Subject observers: keep props in sync and refresh visuals/label */
static void value_observer_cb(lv_observer_t * obs, lv_subject_t * subject)
{
    wd_battery_t * battery = (wd_battery_t *)lv_observer_get_user_data(obs);
    if(!battery) return;
    int v = lv_subject_get_int(subject);
    battery->value = v;
    if(battery->slider_indicator) lv_slider_set_value(battery->slider_indicator, v, LV_ANIM_OFF);
    if(battery->pct_text) lv_label_set_text_fmt(battery->pct_text, "%d", v);
    update_battery_widget(battery);
}

static void low_power_observer_cb(lv_observer_t * obs, lv_subject_t * subject)
{
    wd_battery_t * battery = (wd_battery_t *)lv_observer_get_user_data(obs);
    if(!battery) return;
    battery->low_power = lv_subject_get_int(subject) != 0;
    update_battery_widget(battery);
}

static void charging_observer_cb(lv_observer_t *obs, lv_subject_t *subject)
{
    wd_battery_t * battery = (wd_battery_t *)lv_observer_get_user_data(obs);
    if(!battery) return;
    battery->charging = lv_subject_get_int(subject) != 0;
    update_battery_widget(battery);
}