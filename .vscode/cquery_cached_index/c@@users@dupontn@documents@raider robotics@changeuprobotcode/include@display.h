#pragma once

#include "api.h"

#define DISPLAY_COLOR_WHITE     lv_color_hex(0xFFFFFF)
#define DISPLAY_COLOR_GRAY      lv_color_hex(0x8A8A8A)
#define DISPLAY_COLOR_RED       lv_color_hex(0xD51732)

class display {
public:
    enum DisplayScreen { Autonomous = 1, OpControl = 2 };

    display();

    void initialize();

    void displayAutonSelection();

    void displayOpControlMenu();

    void configureHomeButtonStyle();

    void configureAutonomousButtonStyle();

    void configureOpControlButtonStyle();

    ~display();
};