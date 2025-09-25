/**
 * @file wd_battery_v2_gen.h
 *
 */

#ifndef WD_BATTERY_V2_GEN_H
#define WD_BATTERY_V2_GEN_H

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

#include "battery_indicator_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a wd_battery_v2 object
 * @param parent pointer to an object, it will be the parent of the new wd_battery_v2
 * @return pointer to the created wd_battery_v2
 */
lv_obj_t * wd_battery_v2_create(lv_obj_t * parent);
/**
 * The value of the battery
 * @param obj   pointer to a wd_battery_v2
 * @param value  The value of the battery
 */
void wd_battery_v2_set_value(lv_obj_t * wd_battery_v2, int32_t value);

/**
 * The low power state of the battery
 * @param obj   pointer to a wd_battery_v2
 * @param low_power  The low power state of the battery
 */
void wd_battery_v2_set_low_power(lv_obj_t * wd_battery_v2, bool low_power);

/**
 * The charging state of the battery
 * @param obj   pointer to a wd_battery_v2
 * @param charging  The charging state of the battery
 */
void wd_battery_v2_set_charging(lv_obj_t * wd_battery_v2, bool charging);

/**
 * 1: pill with number, 0: outline only
 * @param obj   pointer to a wd_battery_v2
 * @param show_percentage  1: pill with number, 0: outline only
 */
void wd_battery_v2_set_show_percentage(lv_obj_t * wd_battery_v2, bool show_percentage);

/**
 * 0: light theme, 1: dark theme
 * @param obj   pointer to a wd_battery_v2
 * @param theme  0: light theme, 1: dark theme
 */
void wd_battery_v2_set_theme(lv_obj_t * wd_battery_v2, int32_t theme);

/**
 * threshold red style (when not charging)
 * @param obj   pointer to a wd_battery_v2
 * @param low_threshold  threshold red style (when not charging)
 */
void wd_battery_v2_set_low_threshold(lv_obj_t * wd_battery_v2, int32_t low_threshold);

/**
 * wd_battery_v2 bind_value
 * @param obj   pointer to a wd_battery_v2
 * @param bind_value  bind_value
 */
void wd_battery_v2_bind_value(lv_obj_t * wd_battery_v2, lv_subject_t * bind_value);

/**
 * wd_battery_v2 bind_low_power
 * @param obj   pointer to a wd_battery_v2
 * @param bind_low_power  bind_low_power
 */
void wd_battery_v2_bind_low_power(lv_obj_t * wd_battery_v2, lv_subject_t * bind_low_power);

/**
 * wd_battery_v2 bind_charging
 * @param obj   pointer to a wd_battery_v2
 * @param bind_charging  bind_charging
 */
void wd_battery_v2_bind_charging(lv_obj_t * wd_battery_v2, lv_subject_t * bind_charging);

/**
 * wd_battery_v2 bind_show_percentage
 * @param obj   pointer to a wd_battery_v2
 * @param bind_show_percentage  bind_show_percentage
 */
void wd_battery_v2_bind_show_percentage(lv_obj_t * wd_battery_v2, lv_subject_t * bind_show_percentage);

/**
 * wd_battery_v2 bind_theme
 * @param obj   pointer to a wd_battery_v2
 * @param bind_theme  bind_theme
 */
void wd_battery_v2_bind_theme(lv_obj_t * wd_battery_v2, lv_subject_t * bind_theme);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_BATTERY_V2_GEN_H*/