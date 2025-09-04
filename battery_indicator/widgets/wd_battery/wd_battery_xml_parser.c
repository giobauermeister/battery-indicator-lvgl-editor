/**
 * @file wd_battery_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "wd_battery_gen.h"
#include "lvgl/src/others/xml/parsers/lv_xml_obj_parser.h"
#include "lvgl/src/others/xml/lv_xml_widget.h"
#include "lvgl/src/others/xml/lv_xml_parser.h"
#include "wd_battery.h"

#if LV_USE_XML

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

void * wd_battery_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = wd_battery_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_battery");
        return NULL;
    }

    return item;
}

void wd_battery_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{

    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq(name, "value")) {
            wd_battery_set_value(item, lv_xml_atoi(value));
        }
        else if(lv_streq(name, "low_power")) {
            wd_battery_set_low_power(item, lv_xml_atoi(value) != 0);
        }
        else if(lv_streq(name, "charging")) {
            wd_battery_set_charging(item, lv_xml_atoi(value) != 0);
        }
        else if(lv_streq(name, "bind_value")) {
            lv_subject_t * s = lv_xml_get_subject(&state->scope, value);
            if(s) wd_battery_bind_value(item, s);
            else  LV_LOG_WARN("Subject \"%s\" not found for bind_value", value);
        }
        else if(lv_streq(name, "bind_low_power")) {
            lv_subject_t * s = lv_xml_get_subject(&state->scope, value);
            if(s) wd_battery_bind_low_power(item, s);
            else  LV_LOG_WARN("Subject \"%s\" not found for bind_low_power", value);
        }
        else if(lv_streq(name, "bind_charging")) {
            lv_subject_t * s = lv_xml_get_subject(&state->scope, value);
            if(s) wd_battery_bind_charging(item, s);
            else  LV_LOG_WARN("Subject \"%s\" not found for bind_charging", value);
        }
    }
}

void wd_battery_register(void)
{
    lv_xml_widget_register("wd_battery", wd_battery_xml_create, wd_battery_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */