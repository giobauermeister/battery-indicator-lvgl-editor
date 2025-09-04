/**
 * @file charge_slider_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "charge_slider_gen.h"
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

lv_obj_t * charge_slider_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t slider_knob;
    static lv_style_t slider_indicator;
    static lv_style_t indicator;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&slider_knob);
        lv_style_set_bg_color(&slider_knob, lv_color_hex(0xFFFFFF));
        lv_style_set_pad_left(&slider_knob, -23);
        lv_style_set_pad_right(&slider_knob, -41);
        lv_style_set_pad_ver(&slider_knob, -19);
        lv_style_set_opa(&slider_knob, 0);

        lv_style_init(&slider_indicator);
        lv_style_set_bg_color(&slider_indicator, lv_color_hex(0x37c557));
        lv_style_set_radius(&slider_indicator, 22);

        lv_style_init(&indicator);
        lv_style_set_bg_color(&indicator, lv_color_hex(0xD3D1D1));
        lv_style_set_radius(&indicator, 22);
        lv_style_set_bg_opa(&indicator, (255 * 100 / 100));

        style_inited = true;
    }

    lv_obj_t * lv_slider_0 = lv_slider_create(parent);
    lv_obj_set_width(lv_slider_0, 300);
    lv_obj_set_height(lv_slider_0, 70);
    lv_slider_set_min_value(lv_slider_0, 0);
    lv_slider_set_max_value(lv_slider_0, 100);
    lv_slider_set_value(lv_slider_0, 50, false);    lv_obj_add_style(lv_slider_0, &indicator, 0);
    lv_obj_add_style(lv_slider_0, &slider_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_0, &slider_knob, LV_PART_KNOB);

    lv_obj_t * lv_label_0 = lv_label_create(lv_slider_0);
    lv_obj_set_style_text_font(lv_label_0, font_hour_32, 0);
    lv_label_bind_text(lv_label_0, &battery_value, NULL);lv_obj_set_align(lv_label_0, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_pad_right(lv_label_0, 15, 0);
    lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0x474747), 0);


    lv_obj_t * lv_image_0 = lv_image_create(lv_slider_0);
    lv_image_set_src(lv_image_0, img_charging_no_stroke);
    lv_obj_set_align(lv_image_0, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_pad_left(lv_image_0, 35, 0);



    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_slider_0, "charge_slider_#");

    return lv_slider_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/