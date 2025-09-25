/**
 * @file wd_battery_private_gen.h
 *
 */

#ifndef WD_BATTERY_PRIVATE_H
#define WD_BATTERY_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_battery.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    int32_t value;
    bool low_power;
    bool charging;
    lv_subject_t * bind_value;
    lv_subject_t * bind_low_power;
    lv_subject_t * bind_charging;
    lv_obj_t * battery_tip_container;
    lv_obj_t * battery_tip;
    lv_obj_t * slider_indicator;
    lv_obj_t * text_indicator_container;
    lv_obj_t * pct_text;
    lv_obj_t * charging_icon;
} wd_battery_t;

extern const lv_obj_class_t wd_battery_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_battery_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_BATTERY_PRIVATE_H*/