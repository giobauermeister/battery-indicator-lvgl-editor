/**
 * @file wd_battery_v2.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_battery_v2_private_gen.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/
/**
 * grey color for battery light theme
 */
#define BATTERY_LIGHT_THEME_GREY lv_color_hex(0x808080)

/**
 * indicator color for battery light theme
 */
#define BATTERY_LIGHT_THEME_INDICATOR lv_color_hex(0xFFFFFF)

/**
 * grey color for battery dark theme
 */
#define BATTERY_DARK_THEME_GREY lv_color_hex(0xB2B2B2)

/**
 * indicator color for battery dark theme
 */
#define BATTERY_DARK_THEME_INDICATOR lv_color_hex(0x000000)

/**
 * green (charging) color for the battery
 */
#define BATTERY_COLOR_GREEN lv_color_hex(0x37c557)

/**
 * red (low battery) color for the battery
 */
#define BATTERY_COLOR_RED lv_color_hex(0xFD3B2F)

/**
 * yellow (low power mode) color for the battery
 */
#define BATTERY_COLOR_YELLOW lv_color_hex(0xFECC0B)

/**
 * color of the percentage text when in dark theme
 */
#define BATTERY_DARK_THEME_PCT_TEXT_COLOR lv_color_hex(0xFFFFFF)

/**
 * color of the percentage text when in light theme
 */
#define BATTERY_LIGHT_THEME_PCT_TEXT_COLOR lv_color_hex(0x000000)

/**
 * threshold value for the battery to be in a low battery state (red color)
 */
#define BATTERY_LOW_BAT_THRESHOLD 40

/**********************
 *      TYPEDEFS
 **********************/
typedef enum {
    WD_THEME_LIGHT = 0,
    WD_THEME_DARK  = 1,
} wd_theme_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void update_battery_v2_widget(wd_battery_v2_t * battery);
static void value_observer_cb(lv_observer_t * obs, lv_subject_t * subject);
static void low_power_observer_cb(lv_observer_t * obs, lv_subject_t * subject);
static void charging_observer_cb(lv_observer_t * obs, lv_subject_t * subject);
static void show_percentage_observer_cb(lv_observer_t * obs, lv_subject_t * subject);
static void theme_observer_cb(lv_observer_t * obs, lv_subject_t * subject);
static void icon_recolor_none(lv_obj_t * icon);
static void icon_recolor_dark(lv_obj_t * icon);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_battery_v2_constructor_hook(lv_obj_t * obj)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)obj;

    battery->theme = 0;

    if(!battery->low_threshold) {
        LV_LOG_USER("setting default low battery threshold");
        wd_battery_v2_set_low_threshold((lv_obj_t *)battery, BATTERY_LOW_BAT_THRESHOLD);
    }

    lv_slider_set_value(battery->battery_slider_a_mode, battery->value, LV_ANIM_OFF);
    lv_slider_set_value(battery->battery_slider_b_mode, battery->value, LV_ANIM_OFF);
}

void wd_battery_v2_destructor_hook(lv_obj_t * obj)
{

}

void wd_battery_v2_event_hook(lv_event_t * e)
{

}

void wd_battery_v2_set_value(lv_obj_t * wd_battery_v2, int32_t value)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;
    battery->value = value;
    /* Set slider with battery value */
    lv_slider_set_value(battery->battery_slider_a_mode, value, LV_ANIM_OFF);
    lv_slider_set_value(battery->battery_slider_b_mode, value, LV_ANIM_OFF);
    /* Set text with battery value */
    lv_label_set_text_fmt(battery->pct_text, "%d", (int)value);
    update_battery_v2_widget(battery);    
}

void wd_battery_v2_set_low_power(lv_obj_t * wd_battery_v2, bool low_power)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;
    battery->low_power = low_power ? 1 : 0;
    update_battery_v2_widget(battery);
}

void wd_battery_v2_set_charging(lv_obj_t * wd_battery_v2, bool charging)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;
    battery->charging = charging ? 1 : 0;
    update_battery_v2_widget(battery);
}

void wd_battery_v2_set_show_percentage(lv_obj_t * wd_battery_v2, bool show_percentage)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;
    battery->show_percentage = show_percentage ? 1 : 0;
    update_battery_v2_widget(battery);
}

void wd_battery_v2_set_low_threshold(lv_obj_t * wd_battery_v2, int32_t low_threshold)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;
    battery->low_threshold = low_threshold;
    update_battery_v2_widget(battery);
}

void wd_battery_v2_set_theme(lv_obj_t * wd_battery_v2, int32_t theme)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;
    battery->theme = theme;
    update_battery_v2_widget(battery);
}

void wd_battery_v2_bind_value(lv_obj_t * wd_battery_v2, lv_subject_t * bind_value)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;

    lv_slider_bind_value(battery->battery_slider_a_mode, bind_value);
    lv_slider_bind_value(battery->battery_slider_b_mode, bind_value);

    lv_subject_add_observer_obj(bind_value, value_observer_cb, wd_battery_v2, battery);

    int v = lv_subject_get_int(bind_value);
    wd_battery_v2_set_value(wd_battery_v2, v);
}

void wd_battery_v2_bind_low_power(lv_obj_t * wd_battery_v2, lv_subject_t * bind_low_power)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;

    lv_subject_add_observer_obj(bind_low_power, low_power_observer_cb, wd_battery_v2, battery);
    wd_battery_v2_set_low_power(wd_battery_v2, lv_subject_get_int(bind_low_power) != 0);
}

void wd_battery_v2_bind_charging(lv_obj_t * wd_battery_v2, lv_subject_t * bind_charging)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;

    lv_subject_add_observer_obj(bind_charging, charging_observer_cb, wd_battery_v2, battery);
    wd_battery_v2_set_charging(wd_battery_v2, lv_subject_get_int(bind_charging) != 0);
}

void wd_battery_v2_bind_show_percentage(lv_obj_t * wd_battery_v2, lv_subject_t * bind_show_percentage)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;

    lv_subject_add_observer_obj(bind_show_percentage, show_percentage_observer_cb, wd_battery_v2, battery);
    wd_battery_v2_set_show_percentage(wd_battery_v2, lv_subject_get_int(bind_show_percentage) != 0);
}

void wd_battery_v2_bind_theme(lv_obj_t * wd_battery_v2, lv_subject_t * bind_theme)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)wd_battery_v2;

    lv_subject_add_observer_obj(bind_theme, theme_observer_cb, wd_battery_v2, battery);
    wd_battery_v2_set_theme(wd_battery_v2, lv_subject_get_int(bind_theme));
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void update_battery_v2_widget(wd_battery_v2_t * battery)
{
    lv_color_t indicator_color =
        battery->low_power                  ? BATTERY_COLOR_YELLOW :
        (battery->value <= battery->low_threshold)? BATTERY_COLOR_RED    :
        battery->charging                   ? BATTERY_COLOR_GREEN  :
        (battery->theme == WD_THEME_DARK           ? BATTERY_DARK_THEME_INDICATOR
                                      : BATTERY_LIGHT_THEME_INDICATOR);

    /* Apply to sliders */
    lv_obj_set_style_bg_color(battery->battery_slider_a_mode, indicator_color, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(battery->battery_slider_b_mode, indicator_color, LV_PART_INDICATOR);

    /* Set the grey color based on theme */
    lv_color_t color_grey = (battery->theme == WD_THEME_DARK) ? BATTERY_DARK_THEME_GREY : BATTERY_LIGHT_THEME_GREY;

    /* Set battery border grey color */
    lv_obj_set_style_border_color(battery->battery_border, color_grey, LV_PART_MAIN);

    lv_obj_set_style_bg_color(battery->battery_slider_b_mode, color_grey, LV_PART_MAIN);

    /* Set battery tip grey color */
    lv_color_t tip_color = color_grey;
    if (battery->show_percentage) {
        tip_color = (battery->value == 100) ? indicator_color : color_grey;
    }
    lv_obj_set_style_bg_color(battery->battery_tip, tip_color, LV_PART_MAIN);


    /* Base text color depends on theme */
    lv_color_t text_color = (battery->theme == WD_THEME_DARK)
            ? BATTERY_DARK_THEME_PCT_TEXT_COLOR   /* white */
            : BATTERY_LIGHT_THEME_PCT_TEXT_COLOR; /* black */

    /* Override in special cases */
    if (battery->low_power) {
        text_color = BATTERY_LIGHT_THEME_PCT_TEXT_COLOR; /* grey in low power mode */
    }
    else if (battery->value <= battery->low_threshold || battery->charging) {
        text_color = BATTERY_DARK_THEME_PCT_TEXT_COLOR; /* white when red */
    }

    lv_obj_set_style_text_color(battery->pct_text, text_color, 0);

    if (battery->charging) {
        lv_obj_clear_flag(battery->img_thunder_charging, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(battery->img_thunder_charging, LV_OBJ_FLAG_HIDDEN);
    }
    if(battery->theme == WD_THEME_LIGHT) icon_recolor_none(battery->img_thunder_charging);
    if(battery->theme == WD_THEME_DARK) icon_recolor_dark(battery->img_thunder_charging);

    if (battery->charging) {
        lv_obj_clear_flag(battery->img_thunder_charging_small, LV_OBJ_FLAG_HIDDEN);
        if (battery->low_power) icon_recolor_dark(battery->img_thunder_charging_small);
        else                    icon_recolor_none(battery->img_thunder_charging_small);
    } else {
        lv_obj_add_flag(battery->img_thunder_charging_small, LV_OBJ_FLAG_HIDDEN);
        icon_recolor_none(battery->img_thunder_charging_small);
    }
}

/* Subject observers: keep props in sync and refresh visuals/label */
static void value_observer_cb(lv_observer_t * obs, lv_subject_t * subject)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)lv_observer_get_user_data(obs);
    int v = lv_subject_get_int(subject);
    battery->value = v;
    wd_battery_v2_set_value((lv_obj_t *)battery, battery->value);
}

static void low_power_observer_cb(lv_observer_t * obs, lv_subject_t * subject)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)lv_observer_get_user_data(obs);
    battery->low_power = lv_subject_get_int(subject) != 0;
    wd_battery_v2_set_low_power((lv_obj_t *)battery, battery->low_power);
}

static void charging_observer_cb(lv_observer_t * obs, lv_subject_t * subject)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)lv_observer_get_user_data(obs);
    battery->charging = lv_subject_get_int(subject) != 0;
    wd_battery_v2_set_charging((lv_obj_t *)battery, battery->charging);
}

static void show_percentage_observer_cb(lv_observer_t * obs, lv_subject_t * subject)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)lv_observer_get_user_data(obs);
    battery->show_percentage = lv_subject_get_int(subject) != 0;
    wd_battery_v2_set_show_percentage((lv_obj_t *)battery, battery->show_percentage);
}

static void theme_observer_cb(lv_observer_t * obs, lv_subject_t * subject)
{
    wd_battery_v2_t * battery = (wd_battery_v2_t *)lv_observer_get_user_data(obs);
    battery->theme = lv_subject_get_int(subject);
    wd_battery_v2_set_theme((lv_obj_t *)battery, battery->theme);
}

/* helpers to recolor charging icon */
static void icon_recolor_none(lv_obj_t * icon)
{
    /* show original (white) asset */
    lv_obj_set_style_image_recolor_opa(icon, LV_OPA_TRANSP, 0);
}

static void icon_recolor_dark(lv_obj_t * icon)
{
    /* dark recolor */
    lv_obj_set_style_image_recolor(icon, lv_color_hex(0x000000), 0);
    lv_obj_set_style_image_recolor_opa(icon, LV_OPA_COVER, 0);
}

