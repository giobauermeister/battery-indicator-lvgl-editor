/**
 * @file top_bar_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "top_bar_gen.h"
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

lv_obj_t * top_bar_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&main);
        lv_style_set_border_width(&main, 0);
        lv_style_set_bg_color(&main, lv_color_hex(0x505050));
        lv_style_set_radius(&main, 0);
        lv_style_set_pad_all(&main, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_width(lv_obj_0, lv_pct(100));
    lv_obj_set_height(lv_obj_0, 60);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_pad_left(lv_obj_0, 90, 0);
    lv_obj_set_style_pad_right(lv_obj_0, 90, 0);

    lv_obj_add_style(lv_obj_0, &main, 0);
    lv_obj_t * clock_0 = clock_create(lv_obj_0);
    lv_obj_set_align(clock_0, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_text_color(clock_0, lv_color_hex(0xEDEDED), 0);

    lv_obj_t * wd_battery_0 = wd_battery_create(lv_obj_0);
    wd_battery_bind_charging(wd_battery_0, &charging);
    wd_battery_bind_low_power(wd_battery_0, &low_power_mode);
    wd_battery_bind_value(wd_battery_0, &battery_value);
    lv_obj_set_align(wd_battery_0, LV_ALIGN_RIGHT_MID);



    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "top_bar_#");

    return lv_obj_0;
}



/**********************
 *   STATIC FUNCTIONS
 **********************/

