/**
 * @file toggle_switch_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "toggle_switch_gen.h"
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

lv_obj_t * toggle_switch_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_knob_base;
    static lv_style_t style_off;
    static lv_style_t style_on;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_knob_base);
        lv_style_set_pad_all(&style_knob_base, -5);

        lv_style_init(&style_off);
        lv_style_set_bg_color(&style_off, lv_color_hex(0xC5C5C7));

        lv_style_init(&style_on);
        lv_style_set_bg_color(&style_on, lv_color_hex(0x35C75A));

        style_inited = true;
    }

    lv_obj_t * lv_switch_0 = lv_switch_create(parent);
    lv_obj_set_width(lv_switch_0, 115);
    lv_obj_set_height(lv_switch_0, 60);

    lv_obj_add_style(lv_switch_0, &style_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_add_style(lv_switch_0, &style_off, LV_PART_MAIN);
    lv_obj_add_style(lv_switch_0, &style_knob_base, LV_PART_KNOB);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_switch_0, "toggle_switch_#");

    return lv_switch_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

