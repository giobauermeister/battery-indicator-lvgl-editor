/**
 * @file battery_indicator_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "battery_indicator_gen.h"

#if LV_USE_XML
#include "widgets/wd_battery/wd_battery_private_gen.h"
#include "widgets/wd_battery_v2/wd_battery_v2_private_gen.h"
#endif /* LV_USE_XML */

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

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_hour_32;
extern lv_font_t font_hour_32_data;
lv_font_t * inter_28;
extern lv_font_t inter_28_data;
lv_font_t * font_hour_25;
extern lv_font_t font_hour_25_data;
lv_font_t * font_inter_semibold_30;
extern lv_font_t font_inter_semibold_30_data;
lv_font_t * font_inter_semibold_25;
extern lv_font_t font_inter_semibold_25_data;

/*----------------
 * Images
 *----------------*/

const void * img_charging;
extern const void * img_charging_data;
const void * img_charging_no_stroke;
extern const void * img_charging_no_stroke_data;
const void * img_charging_small;
extern const void * img_charging_small_data;
const void * img_thunder_transparent;
extern const void * img_thunder_transparent_data;
const void * img_thunder_v2;
extern const void * img_thunder_v2_data;
const void * img_thunder_small_v2;
extern const void * img_thunder_small_v2_data;
const void * img_battery_mask_v2;
extern const void * img_battery_mask_v2_data;
const void * img_background;
extern const void * img_background_data;
const void * img_background_light;
extern const void * img_background_light_data;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t battery_value;
lv_subject_t low_power_mode;
lv_subject_t show_percentage;
lv_subject_t charging;
lv_subject_t battery_theme;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void battery_indicator_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/

    /* get font 'font_hour_32' from a C array */
    font_hour_32 = &font_hour_32_data;
    /* get font 'inter_28' from a C array */
    inter_28 = &inter_28_data;
    /* get font 'font_hour_25' from a C array */
    font_hour_25 = &font_hour_25_data;
    /* get font 'font_inter_semibold_30' from a C array */
    font_inter_semibold_30 = &font_inter_semibold_30_data;
    /* get font 'font_inter_semibold_25' from a C array */
    font_inter_semibold_25 = &font_inter_semibold_25_data;


    /*----------------
     * Images
     *----------------*/
    img_charging = &img_charging_data;
    img_charging_no_stroke = &img_charging_no_stroke_data;
    img_charging_small = &img_charging_small_data;
    img_thunder_transparent = &img_thunder_transparent_data;
    img_thunder_v2 = &img_thunder_v2_data;
    img_thunder_small_v2 = &img_thunder_small_v2_data;
    img_battery_mask_v2 = &img_battery_mask_v2_data;
    img_background = &img_background_data;
    img_background_light = &img_background_light_data;

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&battery_value, 50);
    lv_subject_init_int(&low_power_mode, 0);
    lv_subject_init_int(&show_percentage, 0);
    lv_subject_init_int(&charging, 0);
    lv_subject_init_int(&battery_theme, 0);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */
    wd_battery_register();
    wd_battery_v2_register();

    /* Register fonts */
    lv_xml_register_font(NULL, "font_hour_32", font_hour_32);
    lv_xml_register_font(NULL, "inter_28", inter_28);
    lv_xml_register_font(NULL, "font_hour_25", font_hour_25);
    lv_xml_register_font(NULL, "font_inter_semibold_30", font_inter_semibold_30);
    lv_xml_register_font(NULL, "font_inter_semibold_25", font_inter_semibold_25);

    /* Register subjects */
    lv_xml_register_subject(NULL, "battery_value", &battery_value);
    lv_xml_register_subject(NULL, "low_power_mode", &low_power_mode);
    lv_xml_register_subject(NULL, "show_percentage", &show_percentage);
    lv_xml_register_subject(NULL, "charging", &charging);
    lv_xml_register_subject(NULL, "battery_theme", &battery_theme);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "btn_low_power_toggle_cb", btn_low_power_toggle_cb);
    lv_xml_register_event_cb(NULL, "btn_charging_toggle_cb", btn_charging_toggle_cb);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "img_charging", img_charging);
    lv_xml_register_image(NULL, "img_charging_no_stroke", img_charging_no_stroke);
    lv_xml_register_image(NULL, "img_charging_small", img_charging_small);
    lv_xml_register_image(NULL, "img_thunder_transparent", img_thunder_transparent);
    lv_xml_register_image(NULL, "img_thunder_v2", img_thunder_v2);
    lv_xml_register_image(NULL, "img_thunder_small_v2", img_thunder_small_v2);
    lv_xml_register_image(NULL, "img_battery_mask_v2", img_battery_mask_v2);
    lv_xml_register_image(NULL, "img_background", img_background);
    lv_xml_register_image(NULL, "img_background_light", img_background_light);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     *manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) btn_low_power_toggle_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("btn_low_power_toggle_cb was called\n");
}
void __attribute__((weak)) btn_charging_toggle_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("btn_charging_toggle_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/