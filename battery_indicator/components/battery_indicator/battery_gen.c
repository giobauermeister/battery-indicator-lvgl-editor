/**
 * @file battery_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "battery_gen.h"
#include "battery_indicator.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * battery_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t container;
    static lv_style_t border;
    static lv_style_t indicator;
    static lv_style_t indicator_red;
    static lv_style_t indicator_yellow;
    static lv_style_t tip;
    static lv_style_t hidden;
    static lv_style_t slider_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&container);
        lv_style_set_border_width(&container, 0);
        lv_style_set_bg_opa(&container, 0);
        lv_style_set_pad_all(&container, 0);

        lv_style_init(&border);
        lv_style_set_border_color(&border, lv_color_hex(0xadadad));
        lv_style_set_border_opa(&border, 255);
        lv_style_set_border_width(&border, 3);
        lv_style_set_width(&border, 68);
        lv_style_set_height(&border, 36);
        lv_style_set_radius(&border, 9);
        lv_style_set_bg_opa(&border, 0);
        lv_style_set_pad_all(&border, 0);
        lv_style_set_margin_right(&border, 10);
        lv_style_set_pad_left(&border, 3);

        lv_style_init(&indicator);
        lv_style_set_radius(&indicator, 4);
        lv_style_set_bg_opa(&indicator, 0);

        lv_style_init(&indicator_red);
        lv_style_set_bg_color(&indicator_red, lv_color_hex(0xFD3B2F));

        lv_style_init(&indicator_yellow);
        lv_style_set_bg_color(&indicator_yellow, lv_color_hex(0xFECC0B));

        lv_style_init(&tip);
        lv_style_set_bg_color(&tip, lv_color_hex(0xadadad));
        lv_style_set_radius(&tip, 100);
        lv_style_set_border_width(&tip, 0);

        lv_style_init(&hidden);
        lv_style_set_opa(&hidden, 0);

        lv_style_init(&slider_indicator);
        lv_style_set_bg_color(&slider_indicator, lv_color_hex(0x37c557));
        lv_style_set_radius(&slider_indicator, 1);

        style_inited = true;
    }

    lv_obj_t * battery = lv_obj_create(parent);
    lv_obj_set_name(battery, "battery");
    lv_obj_set_width(battery, 79);
    lv_obj_set_height(battery, 39);
    lv_obj_set_flag(battery, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(battery, &container, 0);
    lv_obj_t * battery_tip = lv_obj_create(battery);
    lv_obj_set_name(battery_tip, "battery_tip");
    lv_obj_set_width(battery_tip, 5);
    lv_obj_set_height(battery_tip, 12);
    lv_obj_set_style_radius(battery_tip, 0, 0);
    lv_obj_set_style_border_width(battery_tip, 0, 0);
    lv_obj_set_flag(battery_tip, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_align(battery_tip, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_pad_all(battery_tip, 0, 0);
    lv_obj_set_style_bg_opa(battery_tip, 0, 0);
    lv_obj_t * lv_obj_0 = lv_obj_create(battery_tip);
    lv_obj_set_width(lv_obj_0, 12);
    lv_obj_set_height(lv_obj_0, 12);
    lv_obj_set_align(lv_obj_0, LV_ALIGN_RIGHT_MID);
    lv_obj_add_style(lv_obj_0, &tip, 0);
    
    lv_obj_t * battery_border = lv_obj_create(battery);
    lv_obj_set_name(battery_border, "battery_border");
    lv_obj_set_width(battery_border, 71);
    lv_obj_set_height(battery_border, 36);
    lv_obj_set_align(battery_border, LV_ALIGN_LEFT_MID);
    lv_obj_set_flag(battery_border, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_add_style(battery_border, &border, 0);
    lv_obj_t * lv_slider_0 = lv_slider_create(battery_border);
    lv_slider_bind_value(lv_slider_0, &battery_value);
    lv_slider_set_min_value(lv_slider_0, 0);
    lv_slider_set_max_value(lv_slider_0, 100);
    lv_obj_set_align(lv_slider_0, LV_ALIGN_LEFT_MID);
    lv_obj_set_width(lv_slider_0, 59);
    lv_obj_set_height(lv_slider_0, 24);
    lv_obj_add_style(lv_slider_0, &indicator, 0);
    lv_obj_add_style(lv_slider_0, &slider_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_0, &hidden, LV_PART_KNOB);
    lv_obj_bind_state_if_le(lv_slider_0, &battery_value, LV_STATE_USER_1, 20);
    lv_obj_add_style(lv_slider_0, &indicator_red, LV_PART_INDICATOR | LV_STATE_USER_1);
    lv_obj_bind_state_if_eq(lv_slider_0, &low_power_mode, LV_STATE_USER_2, 1);
    lv_obj_add_style(lv_slider_0, &indicator_yellow, LV_PART_INDICATOR | LV_STATE_USER_2);
    
    lv_obj_t * lv_image_0 = lv_image_create(battery);
    lv_image_set_src(lv_image_0, img_charging);
    lv_obj_set_align(lv_image_0, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_pad_left(lv_image_0, 45, 0);
    lv_obj_bind_flag_if_eq(lv_image_0, &charging, LV_OBJ_FLAG_HIDDEN, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(battery, "battery_#");

    return battery;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

