/**
 * @file clock_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "clock_gen.h"
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

lv_obj_t * clock_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_light;
    static lv_style_t style_dark;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, font_hour_32);

        lv_style_init(&style_light);
        lv_style_set_text_color(&style_light, lv_color_hex(0xFFFFFF));

        lv_style_init(&style_dark);
        lv_style_set_text_color(&style_dark, lv_color_hex(0x000000));

        style_inited = true;
    }

    lv_obj_t * lv_label_0 = lv_label_create(parent);
    lv_label_set_text(lv_label_0, "10:55");

    lv_obj_add_style(lv_label_0, &style_main, 0);
    lv_obj_bind_style(lv_label_0, &style_light, 0, &battery_theme, 0);
    lv_obj_bind_style(lv_label_0, &style_dark, 0, &battery_theme, 1);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_label_0, "clock_#");

    return lv_label_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

