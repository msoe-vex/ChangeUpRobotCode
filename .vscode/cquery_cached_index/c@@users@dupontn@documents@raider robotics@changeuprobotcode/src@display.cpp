#include "display.h"

lv_obj_t* displayScreen;
lv_obj_t* opControlScreen;

lv_obj_t* homeButton;
lv_obj_t* autonomousButton;
lv_obj_t* opControlButton;

lv_style_t* opControlScreenStyle;

lv_style_t homeButtonOpenStyle;
lv_style_t homeButtonClosedStyle;
lv_style_t autonomousButtonOpenStyle;
lv_style_t autonomousButtonClosedStyle;
lv_style_t opControlButtonOpenStyle;
lv_style_t opControlButtonClosedStyle;

LV_IMG_DECLARE(home_icon);

display::display() {
    initialize();
}

void display::initialize() {
    displayScreen = lv_obj_create(NULL, NULL);
    lv_scr_load(displayScreen);
}

void display::displayAutonSelection() {

}

void display::displayOpControlMenu() {
    /*opControlScreen = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_clean(opControlScreen);
    lv_obj_set_style(opControlScreen, opControlScreenStyle);*/
    displayScreen = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(displayScreen, &home_icon);
    lv_obj_align(displayScreen, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
}

void display::configureHomeButtonStyle() {
    
}

void display::configureAutonomousButtonStyle() {

}

void display::configureOpControlButtonStyle() {

}

display::~display() {

}