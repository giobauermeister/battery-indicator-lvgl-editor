/**
 * @file battery_indicator_2_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "battery_indicator_2_gen.h"
#include "ui.h"

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

lv_obj_t * battery_indicator_2_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t container;
    static lv_style_t text_indicator_container;
    static lv_style_t text_indicator_container_no_charging;
    static lv_style_t battery_value_text_color_dark;
    static lv_style_t battery_value_text_color_white;
    static lv_style_t indicator_red;
    static lv_style_t indicator_yellow;
    static lv_style_t tip_default;
    static lv_style_t tip_green;
    static lv_style_t tip_yellow;
    static lv_style_t hidden;
    static lv_style_t battery_indicator;
    static lv_style_t battery_background;
    static lv_style_t battery_icon_low_power_color;
    static lv_style_t battery_icon_normal_color;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&container);
        lv_style_set_border_width(&container, 0);
        lv_style_set_bg_opa(&container, 0);
        lv_style_set_pad_all(&container, 0);

        lv_style_init(&text_indicator_container);
        lv_style_set_border_width(&text_indicator_container, 0);
        lv_style_set_bg_opa(&text_indicator_container, 0);
        lv_style_set_pad_all(&text_indicator_container, 0);
        lv_style_set_layout(&text_indicator_container, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&text_indicator_container, LV_FLEX_FLOW_ROW);
        lv_style_set_pad_column(&text_indicator_container, 2);
        lv_style_set_pad_top(&text_indicator_container, 0);

        lv_style_init(&text_indicator_container_no_charging);
        lv_style_set_border_width(&text_indicator_container_no_charging, 0);
        lv_style_set_bg_opa(&text_indicator_container_no_charging, 0);
        lv_style_set_pad_all(&text_indicator_container_no_charging, 0);
        lv_style_set_layout(&text_indicator_container_no_charging, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&text_indicator_container_no_charging, LV_FLEX_FLOW_ROW);
        lv_style_set_pad_column(&text_indicator_container_no_charging, 3);

        lv_style_init(&battery_value_text_color_dark);
        lv_style_set_text_color(&battery_value_text_color_dark, lv_color_hex(0x505050));

        lv_style_init(&battery_value_text_color_white);
        lv_style_set_text_color(&battery_value_text_color_white, lv_color_hex(0xFFFFFF));

        lv_style_init(&indicator_red);
        lv_style_set_bg_color(&indicator_red, lv_color_hex(0xFD3B2F));

        lv_style_init(&indicator_yellow);
        lv_style_set_bg_color(&indicator_yellow, lv_color_hex(0xFECC0B));

        lv_style_init(&tip_default);
        lv_style_set_bg_color(&tip_default, lv_color_hex(0xadadad));
        lv_style_set_radius(&tip_default, 100);
        lv_style_set_border_width(&tip_default, 0);

        lv_style_init(&tip_green);
        lv_style_set_bg_color(&tip_green, lv_color_hex(0x37c557));
        lv_style_set_radius(&tip_green, 100);
        lv_style_set_border_width(&tip_green, 0);

        lv_style_init(&tip_yellow);
        lv_style_set_bg_color(&tip_yellow, lv_color_hex(0xFECC0B));
        lv_style_set_radius(&tip_yellow, 100);
        lv_style_set_border_width(&tip_yellow, 0);

        lv_style_init(&hidden);
        lv_style_set_opa(&hidden, 0);

        lv_style_init(&battery_indicator);
        lv_style_set_bg_color(&battery_indicator, lv_color_hex(0x37c557));
        lv_style_set_radius(&battery_indicator, 0);

        lv_style_init(&battery_background);
        lv_style_set_bg_color(&battery_background, lv_color_hex(0x999999));
        lv_style_set_bg_opa(&battery_background, 255);

        lv_style_init(&battery_icon_low_power_color);
        lv_style_set_image_recolor(&battery_icon_low_power_color, lv_color_hex(0x505050));
        lv_style_set_image_recolor_opa(&battery_icon_low_power_color, 255);

        lv_style_init(&battery_icon_normal_color);
        lv_style_set_image_recolor(&battery_icon_normal_color, lv_color_hex(0xffffff));
        lv_style_set_image_recolor_opa(&battery_icon_normal_color, 255);

        style_inited = true;
    }

    lv_obj_t * battery = lv_obj_create(parent);
    lv_obj_set_name(battery, "battery");
    lv_obj_set_width(battery, 79);
    lv_obj_set_height(battery, 36);
    lv_obj_set_flag(battery, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(battery, &container, 0);
    lv_obj_t * battery_tip_container = lv_obj_create(battery);
    lv_obj_set_name(battery_tip_container, "battery_tip_container");
    lv_obj_set_width(battery_tip_container, 5);
    lv_obj_set_height(battery_tip_container, 12);
    lv_obj_set_style_radius(battery_tip_container, 0, 0);
    lv_obj_set_style_border_width(battery_tip_container, 0, 0);
    lv_obj_set_flag(battery_tip_container, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_align(battery_tip_container, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_pad_all(battery_tip_container, 0, 0);
    lv_obj_set_style_bg_opa(battery_tip_container, 0, 0);
    lv_obj_t * battery_tip = lv_obj_create(battery_tip_container);
    lv_obj_set_name(battery_tip, "battery_tip");
    lv_obj_set_width(battery_tip, 12);
    lv_obj_set_height(battery_tip, 12);
    lv_obj_set_align(battery_tip, LV_ALIGN_RIGHT_MID);
    lv_obj_add_style(battery_tip, &tip_default, 0);
    lv_obj_bind_state_if_lt(battery_tip, &battery_value, LV_STATE_USER_1, 100);
    lv_obj_bind_state_if_eq(battery_tip, &battery_value, LV_STATE_USER_2, 100);
    lv_obj_bind_state_if_eq(battery_tip, &low_power_mode, LV_STATE_USER_3, 1);
    lv_obj_bind_state_if_eq(battery_tip, &low_power_mode, LV_STATE_USER_4, 0);
    lv_obj_add_style(battery_tip, &tip_default, LV_PART_MAIN | LV_STATE_USER_1);
    lv_obj_add_style(battery_tip, &tip_green, LV_PART_MAIN | LV_STATE_USER_2 | LV_STATE_USER_4);
    lv_obj_add_style(battery_tip, &tip_yellow, LV_PART_MAIN | LV_STATE_USER_2 | LV_STATE_USER_3);


    lv_obj_t * lv_slider_0 = lv_slider_create(battery);
    lv_slider_bind_value(lv_slider_0, &battery_value);
    lv_slider_set_min_value(lv_slider_0, 0);
    lv_slider_set_max_value(lv_slider_0, 100);
    lv_obj_set_style_radius(lv_slider_0, 9, 0);
    lv_obj_set_width(lv_slider_0, 71);
    lv_obj_set_height(lv_slider_0, 36);
    lv_obj_add_style(lv_slider_0, &hidden, LV_PART_KNOB);
    lv_obj_add_style(lv_slider_0, &battery_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_0, &battery_background, LV_PART_MAIN);
    lv_obj_bind_state_if_le(lv_slider_0, &battery_value, LV_STATE_USER_1, 20);
    lv_obj_add_style(lv_slider_0, &indicator_red, LV_PART_INDICATOR | LV_STATE_USER_1);
    lv_obj_bind_state_if_eq(lv_slider_0, &low_power_mode, LV_STATE_USER_2, 1);
    lv_obj_add_style(lv_slider_0, &indicator_yellow, LV_PART_INDICATOR | LV_STATE_USER_2);
    lv_obj_t * text_indicator = lv_obj_create(lv_slider_0);
    lv_obj_set_name(text_indicator, "text_indicator");
    lv_obj_set_width(text_indicator, LV_SIZE_CONTENT);
    lv_obj_set_height(text_indicator, LV_SIZE_CONTENT);
    lv_obj_set_flag(text_indicator, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_align(text_indicator, LV_ALIGN_CENTER);
    lv_obj_add_style(text_indicator, &text_indicator_container, 0);
    lv_obj_bind_style(text_indicator, &text_indicator_container_no_charging, 0, &charging, 0);
    lv_obj_t * lv_label_0 = lv_label_create(text_indicator);
    lv_label_bind_text(lv_label_0, &battery_value, NULL);
    lv_obj_set_style_text_font(lv_label_0, font_hour_30, 0);
    lv_obj_set_style_text_letter_space(lv_label_0, -1, 0);
    lv_obj_set_style_text_align(lv_label_0, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_bind_style(lv_label_0, &battery_value_text_color_dark, 0, &low_power_mode, 1);
    lv_obj_bind_style(lv_label_0, &battery_value_text_color_white, 0, &low_power_mode, 0);

    lv_obj_t * lv_image_0 = lv_image_create(text_indicator);
    lv_image_set_src(lv_image_0, img_charging_small);
    lv_obj_set_style_pad_top(lv_image_0, 13, 0);
    lv_obj_bind_flag_if_eq(lv_image_0, &charging, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_bind_style(lv_image_0, &battery_icon_low_power_color, 0, &low_power_mode, 1);
    lv_obj_bind_style(lv_image_0, &battery_icon_normal_color, 0, &low_power_mode, 0);





    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(battery, "battery_indicator_2_#");

    return battery;
}



/**********************
 *   STATIC FUNCTIONS
 **********************/

