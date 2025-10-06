/**
 * @file settings_menu_line_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_menu_line_gen.h"
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

lv_obj_t * settings_menu_line_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_border_width(&style_main, 1);
        lv_style_set_border_color(&style_main, lv_color_hex(0xCDCDCD));
        lv_style_set_border_side(&style_main, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_radius(&style_main, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_width(lv_obj_0, 275);
    lv_obj_set_height(lv_obj_0, 1);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "settings_menu_line_#");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

