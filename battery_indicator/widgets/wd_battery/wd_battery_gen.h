/**
 * @file wd_battery_gen.h
 *
 */

#ifndef WD_BATTERY_GEN_H
#define WD_BATTERY_GEN_H

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
 * Create a wd_battery object
 * @param parent pointer to an object, it will be the parent of the new wd_battery
 * @return pointer to the created wd_battery
 */
lv_obj_t * wd_battery_create(lv_obj_t * parent);


/**
 * The value of the battery
 * @param obj   pointer to a wd_battery
 * @param value  The value of the battery
 */
void wd_battery_set_value(lv_obj_t * wd_battery, int32_t value);

/**
 * The low power state of the battery
 * @param obj   pointer to a wd_battery
 * @param low_power  The low power state of the battery
 */
void wd_battery_set_low_power(lv_obj_t * wd_battery, bool low_power);

/**
 * The charging state of the battery
 * @param obj   pointer to a wd_battery
 * @param charging  The charging state of the battery
 */
void wd_battery_set_charging(lv_obj_t * wd_battery, bool charging);

/**
 * wd_battery bind_value
 * @param obj   pointer to a wd_battery
 * @param bind_value  bind_value
 */
void wd_battery_bind_value(lv_obj_t * wd_battery, lv_subject_t * bind_value);

/**
 * wd_battery bind_low_power
 * @param obj   pointer to a wd_battery
 * @param bind_low_power  bind_low_power
 */
void wd_battery_bind_low_power(lv_obj_t * wd_battery, lv_subject_t * bind_low_power);

/**
 * wd_battery bind_charging
 * @param obj   pointer to a wd_battery
 * @param bind_charging  bind_charging
 */
void wd_battery_bind_charging(lv_obj_t * wd_battery, lv_subject_t * bind_charging);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_BATTERY_GEN_H*/