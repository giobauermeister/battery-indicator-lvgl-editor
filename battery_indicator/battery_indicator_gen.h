/**
 * @file battery_indicator_gen.h
 */

#ifndef BATTERY_INDICATOR_GEN_H
#define BATTERY_INDICATOR_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/



/**********************
 *      TYPEDEFS
 **********************/



/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/


/*----------------
 * Fonts
 *----------------*/
extern lv_font_t * font_hour_32;
extern lv_font_t * inter_28;
extern lv_font_t * font_hour_25;

/*----------------
 * Images
 *----------------*/
extern const void * img_charging;
extern const void * img_charging_no_stroke;

/*----------------
 * Subjects
 *----------------*/
extern lv_subject_t battery_value;
extern lv_subject_t low_power_mode;
extern lv_subject_t charging;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/
void btn_low_power_toggle_cb(lv_event_t * e);
void btn_charging_toggle_cb(lv_event_t * e);

/**
 * Initialize the component library
 */

void battery_indicator_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "components/battery_indicator/battery_gen.h"
#include "components/button/button_gen.h"
#include "components/charge_slider/charge_slider_gen.h"
#include "components/clock/clock_gen.h"
#include "components/top_bar/top_bar_gen.h"
#include "screens/smartwatch_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*BATTERY_INDICATOR_GEN_H*/