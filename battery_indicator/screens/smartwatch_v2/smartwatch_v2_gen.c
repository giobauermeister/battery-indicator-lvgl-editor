/**
 * @file smartwatch_v2_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "smartwatch_v2_gen.h"
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

lv_obj_t * smartwatch_v2_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t slider_knob;
    static lv_style_t slider_indicator;
    static lv_style_t slider_bg;
    static lv_style_t style_bg_light;
    static lv_style_t style_bg_dark;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&slider_knob);
        lv_style_set_bg_color(&slider_knob, lv_color_hex(0x37c557));
        lv_style_set_pad_all(&slider_knob, 10);

        lv_style_init(&slider_indicator);
        lv_style_set_bg_color(&slider_indicator, lv_color_hex(0x505050));

        lv_style_init(&slider_bg);
        lv_style_set_bg_color(&slider_bg, lv_color_hex(0x929292));

        lv_style_init(&style_bg_light);
        lv_style_set_bg_image_src(&style_bg_light, img_background_light);

        lv_style_init(&style_bg_dark);
        lv_style_set_bg_image_src(&style_bg_dark, img_background);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_bind_style(lv_obj_0, &style_bg_light, 0, &battery_theme, 1);
    lv_obj_bind_style(lv_obj_0, &style_bg_dark, 0, &battery_theme, 0);
    lv_obj_t * top_bar_0 = top_bar_create(lv_obj_0);
    lv_obj_set_style_bg_opa(top_bar_0, 0, 0);
    
    lv_obj_t * charge_slider_0 = charge_slider_create(lv_obj_0);
    lv_slider_bind_value(charge_slider_0, &battery_value);
    lv_obj_set_height(charge_slider_0, 55);
    lv_obj_set_x(charge_slider_0, 55);
    lv_obj_set_y(charge_slider_0, 65);
    
    lv_obj_t * settings_panel_0 = settings_panel_create(lv_obj_0);
    lv_obj_set_align(settings_panel_0, LV_ALIGN_CENTER);
    lv_obj_set_y(settings_panel_0, 50);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "smartwatch_v2");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

