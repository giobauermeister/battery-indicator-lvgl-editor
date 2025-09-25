/**
 * @file wd_battery_v2_private_gen.h
 *
 */

#ifndef WD_BATTERY_V2_PRIVATE_H
#define WD_BATTERY_V2_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_battery_v2.h"

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
    bool show_percentage;
    int32_t theme;
    int32_t low_threshold;
    lv_subject_t * bind_value;
    lv_subject_t * bind_low_power;
    lv_subject_t * bind_charging;
    lv_subject_t * bind_show_percentage;
    lv_subject_t * bind_theme;
    lv_obj_t * battery_tip_container;
    lv_obj_t * battery_tip;
    lv_obj_t * battery_mode_outline;
    lv_obj_t * mask_container;
    lv_obj_t * battery_border;
    lv_obj_t * battery_slider_a_mode;
    lv_obj_t * img_thunder_charging;
    lv_obj_t * battery_slider_b_mode;
    lv_obj_t * text_indicator_container;
    lv_obj_t * pct_text;
    lv_obj_t * img_thunder_charging_small;
} wd_battery_v2_t;

extern const lv_obj_class_t wd_battery_v2_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_battery_v2_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_BATTERY_V2_PRIVATE_H*/