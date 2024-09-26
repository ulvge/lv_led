/**
 * @file lv_calendar_obj_dropdown.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_calendar_header_dropdown.h"
#if LV_USE_CALENDAR_HEADER_DROPDOWN

#include <stdio.h>
#include <stdlib.h>
#include "lv_calendar.h"
#include "../../../widgets/lv_dropdown.h"
#include "../../layouts/flex/lv_flex.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void my_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void year_event_cb(lv_event_t * e);
static void month_event_cb(lv_event_t * e);
static void value_changed_event_cb(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_calendar_header_dropdown_class = {
    .base_class = &lv_obj_class,
    .width_def = LV_PCT(100),
    .height_def = LV_SIZE_CONTENT,
    .constructor_cb = my_constructor
};

static const char * month_list = "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12";
static const char * year_list = {
    "2050\n2049\n2048\n2047\n2046\n2045\n2044\n2043\n2042\n2041\n2040\n2039\n2038\n2037\n2036\n2035\n2034\n2033\n2032\n2031\n"
    "2030\n2029\n2028\n2027\n2026\n2025\n2024\n2023\n2022\n2021"
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * lv_calendar_header_dropdown_create(lv_obj_t * parent)
{
    lv_obj_t * obj = lv_obj_class_create_obj(&lv_calendar_header_dropdown_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *  STATIC FUNCTIONS
 **********************/

static void my_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_TRACE_OBJ_CREATE("begin");

    LV_UNUSED(class_p);

    lv_obj_t * calendar = lv_obj_get_parent(obj);
    lv_obj_move_to_index(obj, 0);
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);

    lv_obj_t * year_dd = lv_dropdown_create(obj);
    lv_dropdown_set_options(year_dd, year_list);
    lv_obj_add_event_cb(year_dd, year_event_cb, LV_EVENT_VALUE_CHANGED, calendar);
    lv_obj_set_flex_grow(year_dd, 1);

    lv_obj_t * month_dd = lv_dropdown_create(obj);
    lv_dropdown_set_options(month_dd, month_list);
    lv_obj_add_event_cb(month_dd, month_event_cb, LV_EVENT_VALUE_CHANGED, calendar);
    lv_obj_set_flex_grow(month_dd, 1);

    lv_obj_add_event_cb(obj, value_changed_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    /*Refresh the drop downs*/
    lv_event_send(obj, LV_EVENT_VALUE_CHANGED, NULL);
}

static void month_event_cb(lv_event_t * e)
{
    lv_obj_t * dropdown = lv_event_get_target(e);
    lv_obj_t * calendar = lv_event_get_user_data(e);

    uint16_t sel = lv_dropdown_get_selected(dropdown);

    const lv_calendar_date_t * d;
    d = lv_calendar_get_showed_date(calendar);
    lv_calendar_date_t newd = *d;
    newd.month = sel + 1;

    lv_calendar_set_showed_date(calendar, &newd);
}

static void year_event_cb(lv_event_t * e)
{
    uint16_t configFirstYear = atoi(year_list);
    lv_obj_t * dropdown = lv_event_get_target(e);
    lv_obj_t * calendar = lv_event_get_user_data(e);

    uint16_t sel = lv_dropdown_get_selected(dropdown);

    const lv_calendar_date_t * d;
    d = lv_calendar_get_showed_date(calendar);
    lv_calendar_date_t newd = *d;
    newd.year = configFirstYear - sel;

    lv_calendar_set_showed_date(calendar, &newd);
}

static void value_changed_event_cb(lv_event_t * e)
{
    uint16_t configFirstYear = atoi(year_list);
    lv_obj_t * header = lv_event_get_target(e);
    lv_obj_t * calendar = lv_obj_get_parent(header);
    const lv_calendar_date_t * cur_date = lv_calendar_get_showed_date(calendar);

    lv_obj_t * year_dd = lv_obj_get_child(header, 0);
    lv_dropdown_set_selected(year_dd, configFirstYear - cur_date->year);

    lv_obj_t * month_dd = lv_obj_get_child(header, 1);
    lv_dropdown_set_selected(month_dd, cur_date->month - 1);
}

#endif /*LV_USE_CALENDAR_HEADER_ARROW*/

