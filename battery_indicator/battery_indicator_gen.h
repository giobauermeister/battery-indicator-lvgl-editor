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

extern lv_font_t * font_inter_semibold_30;

extern lv_font_t * font_inter_semibold_25;

/*----------------
 * Images
 *----------------*/

extern const void * img_charging;
extern const void * img_charging_no_stroke;
extern const void * img_charging_small;
extern const void * img_thunder_transparent;
extern const void * img_thunder_v2;
extern const void * img_thunder_small_v2;
extern const void * img_battery_mask_v2;
extern const void * img_background;
extern const void * img_background_light;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t battery_value;
extern lv_subject_t low_power_mode;
extern lv_subject_t show_percentage;
extern lv_subject_t charging;
extern lv_subject_t battery_theme;

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
#include "widgets/wd_battery/wd_battery_gen.h"
#include "widgets/wd_battery_v2/wd_battery_v2_gen.h"
#include "components/battery_indicator/battery_gen.h"
#include "components/battery_indicator_2/battery_indicator_2_gen.h"
#include "components/battery_indicator_v2/battery_indicator_v2_gen.h"
#include "components/button/button_gen.h"
#include "components/charge_slider/charge_slider_gen.h"
#include "components/clock/clock_gen.h"
#include "components/settings_item/settings_item_gen.h"
#include "components/settings_menu_line/settings_menu_line_gen.h"
#include "components/settings_panel/settings_panel_gen.h"
#include "components/toggle_switch/toggle_switch_gen.h"
#include "components/top_bar/top_bar_gen.h"
#include "screens/smartwatch/smartwatch_gen.h"
#include "screens/smartwatch_v2/smartwatch_v2_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*BATTERY_INDICATOR_GEN_H*/