/**
 * @file battery_indicator.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "battery_indicator.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void battery_indicator_init(const char * asset_path)
{
    battery_indicator_init_gen(asset_path);

    lv_screen_load(smartwatch_create());
}

void btn_low_power_toggle_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);

    if(lv_event_get_code(e) == LV_EVENT_CLICKED) {
        int32_t v = lv_subject_get_int(&low_power_mode);
        lv_subject_set_int(&low_power_mode, !v);
    }
}

void btn_charging_toggle_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);

    if(lv_event_get_code(e) == LV_EVENT_CLICKED) {
        int32_t v = lv_subject_get_int(&charging);
        lv_subject_set_int(&charging, !v);
    }
}

void check_low_power_click_cb(lv_event_t * e)
{
    lv_obj_t * check_box = lv_event_get_target(e);

    if(lv_event_get_code(e) == LV_EVENT_CLICKED) {

    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/