/**
 * @file wd_battery.h
 *
 */

#ifndef WD_BATTERY_H
#define WD_BATTERY_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "wd_battery_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void wd_battery_set_value(lv_obj_t * o, int32_t v);
void wd_battery_bind_value(lv_obj_t * o, lv_subject_t * subject);
void wd_battery_set_low_power(lv_obj_t * o, bool en);
void wd_battery_bind_low_power(lv_obj_t * o, lv_subject_t * subject);
void wd_battery_set_charging(lv_obj_t * o, bool en);
void wd_battery_bind_charging(lv_obj_t * o, lv_subject_t * subject);


/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_BATTERY_H*/