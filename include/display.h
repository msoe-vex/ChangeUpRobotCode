#pragma once

#include "api.h"

#define SCREEN_HEIGHT   240
#define SCREEN_WIDTH    480

#define BTN_MAIN_OPEN_COLOR       LV_COLOR_MAKE(0xFF, 0x00, 0x00)
#define BTN_MAIN_CLOSED_COLOR     LV_COLOR_MAKE(0xBB, 0x00, 0x00)

#define BTN_WIDGET_OPEN_COLOR     LV_COLOR_MAKE(0xFF, 0x00, 0x00)
#define BTN_WIDGET_CLOSED_COLOR   LV_COLOR_MAKE(0xBB, 0x00, 0x00)

class display {
public:
    enum DisplayScreen { Autonomous = 1, OpControl = 2 };

    display();

    void initialize();

    void displayAutonSelection();

    void displayOpControlMenu();

    ~display();

private:
    void configureHomeScreen();

    void configureAutonomousScreen();

    void configureOpControlScreen();

    lv_style_t* getDefaultStyle();

    void setBackgroundColor(lv_style_t* obj, lv_color_t color);

    void createPageButton(lv_obj_t* button, int slot, const lv_img_dsc_t* icon, std::string label);

    void createWidgetButton(lv_obj_t* widget, int slot, const lv_img_dsc_t* icon);

    lv_style_t* getBackgroundDefaultStyle();

    lv_style_t* getButtonDefaultStyle();

    lv_style_t* getWidgetDefaultStyle();

    void setButtonDefaultStyle(lv_obj_t* button);

    void setWidgetDefaultStyle(lv_obj_t* button);
};