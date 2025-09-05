/**
 * @file wd_battery_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "wd_battery_private_gen.h"
#include "lvgl/src/core/lv_obj_class_private.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/



/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void wd_battery_constructor_hook(lv_obj_t * obj);
void wd_battery_destructor_hook(lv_obj_t * obj);
void wd_battery_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_battery_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_battery_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_battery_event(const lv_obj_class_t * class_p, lv_event_t * e);



/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_battery_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_battery_constructor,
    .destructor_cb = wd_battery_destructor,
    .event_cb = wd_battery_event,
    .instance_size = sizeof(wd_battery_t),
    .editable = 1,
    .name = "wd_battery"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/


lv_obj_t * wd_battery_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_battery_class, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


static void wd_battery_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_battery_t * widget = (wd_battery_t *)obj;
    static lv_style_t container;
static lv_style_t tip_default;
static lv_style_t hidden;
static lv_style_t battery_indicator;
static lv_style_t battery_background;
static lv_style_t text_indicator;
static lv_style_t battery_value_text_color_dark;
static lv_style_t battery_value_text_color_white;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&container);
        lv_style_set_border_width(&container, 0);
        lv_style_set_bg_opa(&container, 0);
        lv_style_set_pad_all(&container, 0);

        lv_style_init(&tip_default);
        lv_style_set_bg_color(&tip_default, lv_color_hex(0x999999));
        lv_style_set_border_width(&tip_default, 0);

        lv_style_init(&hidden);
        lv_style_set_opa(&hidden, 0);

        lv_style_init(&battery_indicator);
        lv_style_set_bg_color(&battery_indicator, lv_color_hex(0xFFFFFF));
        lv_style_set_radius(&battery_indicator, 0);

        lv_style_init(&battery_background);
        lv_style_set_bg_color(&battery_background, lv_color_hex(0x999999));
        lv_style_set_bg_opa(&battery_background, 255);

        lv_style_init(&text_indicator);
        lv_style_set_border_width(&text_indicator, 0);
        lv_style_set_bg_opa(&text_indicator, 0);
        lv_style_set_pad_all(&text_indicator, 0);
        lv_style_set_layout(&text_indicator, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&text_indicator, LV_FLEX_FLOW_ROW);
        lv_style_set_pad_column(&text_indicator, 2);
        lv_style_set_pad_top(&text_indicator, 0);

        lv_style_init(&battery_value_text_color_dark);
        lv_style_set_text_color(&battery_value_text_color_dark, lv_color_hex(0x505050));

        lv_style_init(&battery_value_text_color_white);
        lv_style_set_text_color(&battery_value_text_color_white, lv_color_hex(0xFFFFFF));

        style_inited = true;
    }

    lv_obj_set_name(obj, "battery");
    lv_obj_set_width(obj, 79);
    lv_obj_set_height(obj, 36);
    lv_obj_set_flag(obj, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(obj, &container, 0);
    lv_obj_t * battery_tip_container = lv_obj_create(obj);
    lv_obj_set_name(battery_tip_container, "battery_tip_container");
    lv_obj_set_width(battery_tip_container, 5);
    lv_obj_set_height(battery_tip_container, 12);
    lv_obj_set_style_radius(battery_tip_container, 0, 0);
    lv_obj_set_style_border_width(battery_tip_container, 0, 0);
    lv_obj_set_flag(battery_tip_container, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_align(battery_tip_container, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_pad_all(battery_tip_container, 0, 0);
    lv_obj_set_style_bg_opa(battery_tip_container, 0, 0);
    widget->battery_tip_container = battery_tip_container;
    lv_obj_t * battery_tip = lv_obj_create(battery_tip_container);
    lv_obj_set_name(battery_tip, "battery_tip");
    lv_obj_set_width(battery_tip, 12);
    lv_obj_set_height(battery_tip, 12);
    lv_obj_set_align(battery_tip, LV_ALIGN_RIGHT_MID);
    widget->battery_tip = battery_tip;
    lv_obj_add_style(battery_tip, &tip_default, 0);


    lv_obj_t * slider_indicator = lv_slider_create(obj);
    lv_obj_set_name(slider_indicator, "slider_indicator");
    lv_obj_set_width(slider_indicator, 71);
    lv_obj_set_height(slider_indicator, 36);
    lv_obj_set_style_radius(slider_indicator, 9, 0);
    lv_slider_set_min_value(slider_indicator, 0);
    lv_slider_set_max_value(slider_indicator, 100);
    lv_slider_set_value(slider_indicator, 50, false);
    lv_obj_set_flag(slider_indicator, LV_OBJ_FLAG_CLICKABLE, false);
    widget->slider_indicator = slider_indicator;
    lv_obj_add_style(slider_indicator, &hidden, LV_PART_KNOB);
    lv_obj_add_style(slider_indicator, &battery_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(slider_indicator, &battery_background, LV_PART_MAIN);
    lv_obj_t * text_indicator_container = lv_obj_create(slider_indicator);
    lv_obj_set_name(text_indicator_container, "text_indicator_container");
    lv_obj_set_width(text_indicator_container, LV_SIZE_CONTENT);
    lv_obj_set_height(text_indicator_container, LV_SIZE_CONTENT);
    lv_obj_set_align(text_indicator_container, LV_ALIGN_CENTER);
    widget->text_indicator_container = text_indicator_container;
    lv_obj_add_style(text_indicator_container, &text_indicator, 0);
    lv_obj_t * pct_text = lv_label_create(text_indicator_container);
    lv_obj_set_name(pct_text, "pct_text");
    lv_label_set_text(pct_text, "100");
    lv_obj_set_style_text_font(pct_text, font_hour_30, 0);
    lv_obj_set_style_text_letter_space(pct_text, -1, 0);
    lv_obj_set_style_text_align(pct_text, LV_TEXT_ALIGN_LEFT, 0);
    widget->pct_text = pct_text;
    lv_obj_add_style(pct_text, &battery_value_text_color_dark, 0);

    lv_obj_t * charging_icon = lv_image_create(text_indicator_container);
    lv_obj_set_name(charging_icon, "charging_icon");
    lv_image_set_src(charging_icon, img_charging_small);
    lv_obj_set_style_pad_top(charging_icon, 13, 0);
    widget->charging_icon = charging_icon;





    wd_battery_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_battery_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_battery_destructor_hook(obj);
}

static void wd_battery_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_battery_class, e);
    if(res != LV_RESULT_OK) return;

    wd_battery_event_hook(e);
}

