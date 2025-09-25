/**
 * @file smartwatch_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "smartwatch_gen.h"
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

lv_obj_t * smartwatch_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t slider_knob;
    static lv_style_t slider_indicator;
    static lv_style_t slider_bg;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&slider_knob);
        lv_style_set_bg_color(&slider_knob, lv_color_hex(0x37c557));
        lv_style_set_pad_all(&slider_knob, 10);

        lv_style_init(&slider_indicator);
        lv_style_set_bg_color(&slider_indicator, lv_color_hex(0x505050));

        lv_style_init(&slider_bg);
        lv_style_set_bg_color(&slider_bg, lv_color_hex(0x929292));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xF9F9F9), 0);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_t * top_bar_0 = top_bar_create(lv_obj_0);
    
    lv_obj_t * charge_slider_0 = charge_slider_create(lv_obj_0);
    lv_slider_bind_value(charge_slider_0, &battery_value);
    lv_obj_set_align(charge_slider_0, LV_ALIGN_CENTER);
    lv_obj_set_x(charge_slider_0, 0);
    lv_obj_set_y(charge_slider_0, -95);
    
    lv_obj_t * btn_low_power_toggle = button_create(lv_obj_0, "LOW POWER MODE", &low_power_mode, lv_color_hex(0xfecc0b));
    lv_obj_set_name(btn_low_power_toggle, "btn_low_power_toggle");
    lv_obj_set_align(btn_low_power_toggle, LV_ALIGN_CENTER);
    lv_obj_set_x(btn_low_power_toggle, 0);
    lv_obj_set_y(btn_low_power_toggle, 21);
    lv_obj_add_event_cb(btn_low_power_toggle, btn_low_power_toggle_cb, LV_EVENT_CLICKED, NULL);
    
    lv_obj_t * btn_charging_toggle = button_create(lv_obj_0, "CHARGING", &charging, lv_color_hex(0x37c557));
    lv_obj_set_name(btn_charging_toggle, "btn_charging_toggle");
    lv_obj_set_align(btn_charging_toggle, LV_ALIGN_CENTER);
    lv_obj_set_x(btn_charging_toggle, 0);
    lv_obj_set_y(btn_charging_toggle, 144);
    lv_obj_add_event_cb(btn_charging_toggle, btn_charging_toggle_cb, LV_EVENT_CLICKED, NULL);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "smartwatch");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

