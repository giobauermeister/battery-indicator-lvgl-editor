/**
 * @file wd_battery_v2_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_battery_v2_private_gen.h"
#include "lvgl/src/core/lv_obj_class_private.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/
/**
 * width of the battery
 */
#define BATTERY_WIDTH 72

/**
 * height of the battery
 */
#define BATTERY_HEIGHT 38

/**
 * width of the battery
 */
#define BATTERY_INDICATOR_WIDTH 60

/**
 * width of the battery
 */
#define BATTERY_INDICATOR_HEIGHT 26

/**
 * grey color for battery light theme
 */
#define BATTERY_LIGHT_THEME_GREY lv_color_hex(0x808080)

/**
 * indicator color for battery light theme
 */
#define BATTERY_LIGHT_THEME_INDICATOR lv_color_hex(0xFFFFFF)

/**
 * grey color for battery dark theme
 */
#define BATTERY_DARK_THEME_GREY lv_color_hex(0xB2B2B2)

/**
 * indicator color for battery dark theme
 */
#define BATTERY_DARK_THEME_INDICATOR lv_color_hex(0x000000)

/**
 * green (charging) color for the battery
 */
#define BATTERY_COLOR_GREEN lv_color_hex(0x37c557)

/**
 * red (low battery) color for the battery
 */
#define BATTERY_COLOR_RED lv_color_hex(0xFD3B2F)

/**
 * yellow (low power mode) color for the battery
 */
#define BATTERY_COLOR_YELLOW lv_color_hex(0xFECC0B)

/**
 * color of the percentage text when in dark theme
 */
#define BATTERY_DARK_THEME_PCT_TEXT_COLOR lv_color_hex(0xFFFFFF)

/**
 * color of the percentage text when in light theme
 */
#define BATTERY_LIGHT_THEME_PCT_TEXT_COLOR lv_color_hex(0x000000)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void wd_battery_v2_constructor_hook(lv_obj_t * obj);
void wd_battery_v2_destructor_hook(lv_obj_t * obj);
void wd_battery_v2_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_battery_v2_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_battery_v2_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_battery_v2_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_battery_v2_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_battery_v2_constructor,
    .destructor_cb = wd_battery_v2_destructor,
    .event_cb = wd_battery_v2_event,
    .instance_size = sizeof(wd_battery_v2_t),
    .editable = 1,
    .name = "wd_battery_v2"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_battery_v2_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_battery_v2_class, parent);
    lv_obj_class_init_obj(obj);
    
    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_battery_v2_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_battery_v2_t * widget = (wd_battery_v2_t *)obj;
    static lv_style_t style_battery_container;
    static lv_style_t tip_default;
    static lv_style_t hidden;
    static lv_style_t style_a_border;
    static lv_style_t style_a_indicator;
    static lv_style_t style_a_slider_indicator;
    static lv_style_t style_a_battery_outline;
    static lv_style_t style_a_mask_base;
    static lv_style_t style_a_with_mask;
    static lv_style_t style_a_no_mask;
    static lv_style_t style_b_battery_indicator;
    static lv_style_t style_b_battery_background;
    static lv_style_t style_b_text_indicator;
    static lv_style_t style_b_battery_value_text_color_dark;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_battery_container);
        lv_style_set_border_width(&style_battery_container, 0);
        lv_style_set_bg_opa(&style_battery_container, 0);
        lv_style_set_pad_all(&style_battery_container, 0);

        lv_style_init(&tip_default);
        lv_style_set_bg_color(&tip_default, BATTERY_LIGHT_THEME_GREY);
        lv_style_set_border_width(&tip_default, 0);

        lv_style_init(&hidden);
        lv_style_set_opa(&hidden, 0);

        lv_style_init(&style_a_border);
        lv_style_set_radius(&style_a_border, 14);
        lv_style_set_border_width(&style_a_border, 3);
        lv_style_set_border_color(&style_a_border, BATTERY_LIGHT_THEME_GREY);
        lv_style_set_bg_opa(&style_a_border, 0);
        lv_style_set_pad_all(&style_a_border, 0);

        lv_style_init(&style_a_indicator);
        lv_style_set_radius(&style_a_indicator, 8);
        lv_style_set_bg_opa(&style_a_indicator, 0);

        lv_style_init(&style_a_slider_indicator);
        lv_style_set_bg_color(&style_a_slider_indicator, BATTERY_COLOR_GREEN);
        lv_style_set_radius(&style_a_slider_indicator, 8);

        lv_style_init(&style_a_battery_outline);
        lv_style_set_border_width(&style_a_battery_outline, 0);
        lv_style_set_bg_opa(&style_a_battery_outline, 0);
        lv_style_set_pad_all(&style_a_battery_outline, 0);

        lv_style_init(&style_a_mask_base);
        lv_style_set_border_width(&style_a_mask_base, 0);
        lv_style_set_bg_opa(&style_a_mask_base, 0);
        lv_style_set_pad_all(&style_a_mask_base, 0);

        lv_style_init(&style_a_with_mask);
        lv_style_set_bitmap_mask_src(&style_a_with_mask, img_battery_mask_v2);

        lv_style_init(&style_a_no_mask);
        lv_style_set_bitmap_mask_src(&style_a_no_mask, NULL);

        lv_style_init(&style_b_battery_indicator);
        lv_style_set_bg_color(&style_b_battery_indicator, lv_color_hex(0xFFFFFF));
        lv_style_set_radius(&style_b_battery_indicator, 0);

        lv_style_init(&style_b_battery_background);
        lv_style_set_bg_color(&style_b_battery_background, lv_color_hex(0x999999));
        lv_style_set_bg_opa(&style_b_battery_background, 255);

        lv_style_init(&style_b_text_indicator);
        lv_style_set_border_width(&style_b_text_indicator, 0);
        lv_style_set_bg_opa(&style_b_text_indicator, 0);
        lv_style_set_pad_all(&style_b_text_indicator, 0);
        lv_style_set_layout(&style_b_text_indicator, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_b_text_indicator, LV_FLEX_FLOW_ROW);
        lv_style_set_pad_column(&style_b_text_indicator, 2);
        lv_style_set_pad_top(&style_b_text_indicator, 0);

        lv_style_init(&style_b_battery_value_text_color_dark);
        lv_style_set_text_color(&style_b_battery_value_text_color_dark, lv_color_hex(0x505050));

        style_inited = true;
    }
    lv_obj_set_name(obj, "battery");
    lv_obj_set_width(obj, 79);
    lv_obj_set_height(obj, 38);
    lv_obj_set_flag(obj, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(obj, &style_battery_container, 0);
    lv_obj_t * battery_tip_container = lv_obj_create(obj);
    lv_obj_set_name(battery_tip_container, "battery_tip_container");
    lv_obj_set_width(battery_tip_container, 4);
    lv_obj_set_height(battery_tip_container, 12);
    lv_obj_set_style_radius(battery_tip_container, 0, 0);
    lv_obj_set_style_border_width(battery_tip_container, 0, 0);
    lv_obj_set_flag(battery_tip_container, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_align(battery_tip_container, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_pad_all(battery_tip_container, 0, 0);
    lv_obj_set_style_bg_opa(battery_tip_container, 0, 0);
    widget->battery_tip_container = battery_tip_container;
    lv_obj_t * battery_tip = lv_obj_create(battery_tip_container);
    lv_obj_set_name(battery_tip, "battery_tip");
    lv_obj_set_width(battery_tip, 12);
    lv_obj_set_height(battery_tip, 12);
    lv_obj_set_align(battery_tip, LV_ALIGN_RIGHT_MID);
    widget->battery_tip = battery_tip;
    lv_obj_add_style(battery_tip, &tip_default, 0);
    
    lv_obj_t * battery_mode_outline = lv_obj_create(obj);
    lv_obj_set_name(battery_mode_outline, "battery_mode_outline");
    lv_obj_set_width(battery_mode_outline, BATTERY_WIDTH);
    lv_obj_set_height(battery_mode_outline, BATTERY_HEIGHT);
    lv_obj_set_align(battery_mode_outline, LV_ALIGN_LEFT_MID);
    lv_obj_set_flag(battery_mode_outline, LV_OBJ_FLAG_SCROLLABLE, false);
    widget->battery_mode_outline = battery_mode_outline;
    lv_obj_add_style(battery_mode_outline, &style_a_battery_outline, 0);
    lv_obj_bind_flag_if_eq(battery_mode_outline, &show_percentage, LV_OBJ_FLAG_HIDDEN, 1);
    lv_obj_t * mask_container = lv_obj_create(battery_mode_outline);
    lv_obj_set_name(mask_container, "mask_container");
    lv_obj_set_width(mask_container, BATTERY_WIDTH);
    lv_obj_set_height(mask_container, BATTERY_HEIGHT);
    lv_obj_set_align(mask_container, LV_ALIGN_LEFT_MID);
    lv_obj_set_flag(mask_container, LV_OBJ_FLAG_SCROLLABLE, false);
    widget->mask_container = mask_container;
    lv_obj_add_style(mask_container, &style_a_mask_base, 0);
    lv_obj_bind_style(mask_container, &style_a_no_mask, LV_PART_MAIN, &charging, 0);
    lv_obj_bind_style(mask_container, &style_a_with_mask, LV_PART_MAIN, &charging, 1);
    lv_obj_t * battery_border = lv_obj_create(mask_container);
    lv_obj_set_name(battery_border, "battery_border");
    lv_obj_set_width(battery_border, BATTERY_WIDTH);
    lv_obj_set_height(battery_border, BATTERY_HEIGHT);
    lv_obj_set_align(battery_border, LV_ALIGN_LEFT_MID);
    lv_obj_set_flag(battery_border, LV_OBJ_FLAG_SCROLLABLE, false);
    widget->battery_border = battery_border;
    lv_obj_add_style(battery_border, &style_a_border, 0);
    lv_obj_t * battery_slider_a_mode = lv_slider_create(battery_border);
    lv_obj_set_name(battery_slider_a_mode, "battery_slider_a_mode");
    lv_obj_set_width(battery_slider_a_mode, BATTERY_INDICATOR_WIDTH);
    lv_obj_set_height(battery_slider_a_mode, BATTERY_INDICATOR_HEIGHT);
    lv_slider_set_min_value(battery_slider_a_mode, 0);
    lv_slider_set_max_value(battery_slider_a_mode, 100);
    lv_obj_set_align(battery_slider_a_mode, LV_ALIGN_LEFT_MID);
    lv_obj_set_x(battery_slider_a_mode, 3);
    lv_obj_set_flag(battery_slider_a_mode, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_slider_bind_value(battery_slider_a_mode, &battery_value);
    widget->battery_slider_a_mode = battery_slider_a_mode;
    lv_obj_add_style(battery_slider_a_mode, &style_a_indicator, 0);
    lv_obj_add_style(battery_slider_a_mode, &style_a_slider_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(battery_slider_a_mode, &hidden, LV_PART_KNOB);
    
    lv_obj_t * img_thunder_charging = lv_image_create(battery_mode_outline);
    lv_obj_set_name(img_thunder_charging, "img_thunder_charging");
    lv_image_set_src(img_thunder_charging, img_thunder_v2);
    lv_obj_set_align(img_thunder_charging, LV_ALIGN_CENTER);
    widget->img_thunder_charging = img_thunder_charging;
    lv_obj_bind_flag_if_eq(img_thunder_charging, &charging, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_t * battery_slider_b_mode = lv_slider_create(obj);
    lv_obj_set_name(battery_slider_b_mode, "battery_slider_b_mode");
    lv_obj_set_width(battery_slider_b_mode, BATTERY_WIDTH);
    lv_obj_set_height(battery_slider_b_mode, BATTERY_HEIGHT);
    lv_obj_set_style_radius(battery_slider_b_mode, 14, 0);
    lv_slider_set_min_value(battery_slider_b_mode, 0);
    lv_slider_set_max_value(battery_slider_b_mode, 100);
    lv_obj_set_align(battery_slider_b_mode, LV_ALIGN_LEFT_MID);
    lv_obj_set_flag(battery_slider_b_mode, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_slider_bind_value(battery_slider_b_mode, &battery_value);
    widget->battery_slider_b_mode = battery_slider_b_mode;
    lv_obj_bind_flag_if_eq(battery_slider_b_mode, &show_percentage, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_add_style(battery_slider_b_mode, &hidden, LV_PART_KNOB);
    lv_obj_add_style(battery_slider_b_mode, &style_b_battery_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(battery_slider_b_mode, &style_b_battery_background, LV_PART_MAIN);
    lv_obj_t * text_indicator_container = lv_obj_create(battery_slider_b_mode);
    lv_obj_set_name(text_indicator_container, "text_indicator_container");
    lv_obj_set_width(text_indicator_container, LV_SIZE_CONTENT);
    lv_obj_set_height(text_indicator_container, LV_SIZE_CONTENT);
    lv_obj_set_align(text_indicator_container, LV_ALIGN_CENTER);
    widget->text_indicator_container = text_indicator_container;
    lv_obj_add_style(text_indicator_container, &style_b_text_indicator, 0);
    lv_obj_t * pct_text = lv_label_create(text_indicator_container);
    lv_obj_set_name(pct_text, "pct_text");
    lv_label_set_text(pct_text, "100");
    lv_obj_set_style_text_font(pct_text, font_inter_semibold_30, 0);
    lv_obj_set_style_text_letter_space(pct_text, -1, 0);
    lv_obj_set_style_text_align(pct_text, LV_TEXT_ALIGN_LEFT, 0);
    widget->pct_text = pct_text;
    lv_obj_add_style(pct_text, &style_b_battery_value_text_color_dark, 0);
    
    lv_obj_t * img_thunder_charging_small = lv_image_create(text_indicator_container);
    lv_obj_set_name(img_thunder_charging_small, "img_thunder_charging_small");
    lv_image_set_src(img_thunder_charging_small, img_thunder_small_v2);
    lv_obj_set_style_pad_top(img_thunder_charging_small, 13, 0);
    widget->img_thunder_charging_small = img_thunder_charging_small;
    lv_obj_bind_flag_if_eq(img_thunder_charging_small, &charging, LV_OBJ_FLAG_HIDDEN, 0);


    wd_battery_v2_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_battery_v2_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_battery_v2_destructor_hook(obj);
}

static void wd_battery_v2_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_battery_v2_class, e);
    if(res != LV_RESULT_OK) return;

    wd_battery_v2_event_hook(e);
}

