/**
 * @file top_bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "top_bar_gen.h"
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

lv_obj_t * top_bar_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x505050));
        lv_style_set_radius(&style_main, 0);
        lv_style_set_pad_all(&style_main, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_width(lv_obj_0, lv_pct(100));
    lv_obj_set_height(lv_obj_0, 60);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_pad_left(lv_obj_0, 90, 0);
    lv_obj_set_style_pad_right(lv_obj_0, 90, 0);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * clock_0 = clock_create(lv_obj_0);
    lv_obj_set_align(clock_0, LV_ALIGN_LEFT_MID);
    
    lv_obj_t * wd_battery_v2_0 = wd_battery_v2_create(lv_obj_0);
    wd_battery_v2_set_low_threshold(wd_battery_v2_0, 20);
    lv_obj_set_align(wd_battery_v2_0, LV_ALIGN_RIGHT_MID);
    wd_battery_v2_bind_value(wd_battery_v2_0, &battery_value);
    wd_battery_v2_bind_charging(wd_battery_v2_0, &charging);
    wd_battery_v2_bind_low_power(wd_battery_v2_0, &low_power_mode);
    wd_battery_v2_bind_show_percentage(wd_battery_v2_0, &show_percentage);
    wd_battery_v2_bind_theme(wd_battery_v2_0, &battery_theme);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "top_bar_#");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

