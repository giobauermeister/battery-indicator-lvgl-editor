/**
 * @file button_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "button_gen.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/

#define LOW_POWER false

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

lv_obj_t * button_create(lv_obj_t * parent, const char * text, lv_subject_t * subject, lv_color_t enabled_color)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t main;
    static lv_style_t button_disabled;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&main);
        lv_style_set_shadow_width(&main, 0);
        lv_style_set_radius(&main, 51);

        lv_style_init(&button_disabled);
        lv_style_set_bg_color(&button_disabled, lv_color_hex(0xd3d1d1));

        style_inited = true;
    }

    lv_obj_t * lv_button_0 = lv_button_create(parent);
    lv_obj_set_width(lv_button_0, 300);
    lv_obj_set_height(lv_button_0, 90);
    lv_obj_set_style_bg_color(lv_button_0, enabled_color, 0);
    lv_obj_add_style(lv_button_0, &main, 0);

    lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
    lv_label_set_text(lv_label_0, text);
    lv_obj_set_style_text_font(lv_label_0, inter_28, 0);
    lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0x474747), 0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);

    lv_obj_bind_state_if_eq(lv_button_0, subject, LV_STATE_USER_1, 0);
    lv_obj_add_style(lv_button_0, &button_disabled, LV_PART_MAIN | LV_STATE_USER_1);


    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_button_0, "button_#");

    return lv_button_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/