#include "display.h"

lv_obj_t* homeScreen;
lv_obj_t* autonomousScreen;
lv_obj_t* opControlScreen;

LV_IMG_DECLARE(curvedArrowIcon);
LV_IMG_DECLARE(controllerIcon);
LV_IMG_DECLARE(settingsIcon);
LV_IMG_DECLARE(statsIcon);
LV_IMG_DECLARE(storageIcon);
LV_IMG_DECLARE(homeIcon);

display::display() {
    initialize();
}

void display::initialize() {
    lv_style_init();

    homeScreen = lv_obj_create(NULL, NULL);
    autonomousScreen = lv_obj_create(NULL, NULL);
    opControlScreen = lv_obj_create(NULL, NULL);

    configureHomeScreen();
    configureAutonomousScreen();
    configureOpControlScreen();

    lv_scr_load(homeScreen);
}

void display::displayAutonSelection() {
    lv_scr_load(autonomousScreen);
}

void display::displayOpControlMenu() {
    lv_scr_load(opControlScreen);    
    lv_img_set_src(opControlScreen, &homeIcon);
    lv_obj_align(opControlScreen, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
}

void display::configureHomeScreen() {
    /* Configure Objects */
    static lv_obj_t* autonomousButton = lv_btn_create(homeScreen, NULL);
    static lv_obj_t* opControlButton = lv_btn_create(homeScreen, NULL);

    createPageButton(autonomousButton, 0, &curvedArrowIcon, "Select Autonomous");
    createPageButton(opControlButton, 1, &controllerIcon, "Operator Control");

    static lv_obj_t* settingsWidget = lv_btn_create(homeScreen, NULL);
    static lv_obj_t* statsWidget = lv_btn_create(homeScreen, NULL);
    static lv_obj_t* filesWidget = lv_btn_create(homeScreen, NULL);

    createWidgetButton(settingsWidget, 0, &settingsIcon);
    createWidgetButton(statsWidget, 1, &statsIcon);
    createWidgetButton(filesWidget, 2, &storageIcon);

    /* Configure Styling */
    static lv_style_t homeScreenStyle;

    lv_style_copy(&homeScreenStyle, getBackgroundDefaultStyle());

    lv_obj_set_style(homeScreen, &homeScreenStyle);
}

void display::configureAutonomousScreen() {
    static lv_style_t autonomousScreenStyle;

    lv_style_copy(&autonomousScreenStyle, getBackgroundDefaultStyle());

    lv_obj_set_style(autonomousScreen, &autonomousScreenStyle);
}

void display::configureOpControlScreen() {
    static lv_style_t opControlScreenStyle;

    lv_style_copy(&opControlScreenStyle, getBackgroundDefaultStyle());

    lv_obj_set_style(opControlScreen, &opControlScreenStyle);
}

void display::createPageButton(lv_obj_t* button, int slot, const lv_img_dsc_t* icon, std::string label) {
    double buttonWidth = SCREEN_WIDTH / 3;
    double buttonHeight = (SCREEN_HEIGHT / 4) * 3;
    double buttonMarginLeft = SCREEN_WIDTH / 15;
    double buttonMarginTop = SCREEN_HEIGHT / 8;
    double buttonHorizontalPosition = buttonMarginLeft + ((buttonWidth + buttonMarginLeft) * slot);

    // Set Position
    lv_obj_set_size(button, buttonWidth, buttonHeight);
    lv_obj_align(button, NULL, LV_ALIGN_IN_TOP_LEFT, buttonHorizontalPosition, buttonMarginTop);

    // Set Style
    setButtonDefaultStyle(button);
}

void display::createWidgetButton(lv_obj_t* widget, int slot, const lv_img_dsc_t* icon) {
    double widgetWidth = SCREEN_WIDTH / 10;
    double widgetHeight = SCREEN_WIDTH / 10;
    double widgetMarginLeft = (SCREEN_WIDTH / 15) * 13;
    double widgetMarginTop = (SCREEN_HEIGHT - (48 * 3)) / 4;
    double widgetVerticalPosition = widgetMarginTop + ((widgetHeight + widgetMarginTop) * slot);

    // Set Position
    lv_obj_set_size(widget, widgetWidth, widgetHeight);
    lv_obj_align(widget, NULL, LV_ALIGN_IN_TOP_LEFT, widgetMarginLeft, widgetVerticalPosition);

    // Set Style
    setWidgetDefaultStyle(widget);
}

display::~display() {

}

void display::setBackgroundColor(lv_style_t* style, lv_color_t color) {
    style->body.main_color = color;
    style->body.grad_color = color;
}

lv_style_t* display::getBackgroundDefaultStyle() {
    static lv_style_t defaultBackgroundStyle;

    lv_style_copy(&defaultBackgroundStyle, &lv_style_plain);

    setBackgroundColor(&defaultBackgroundStyle, LV_COLOR_WHITE);
    defaultBackgroundStyle.body.radius = 0;

    return &defaultBackgroundStyle;
}

lv_style_t* display::getButtonDefaultStyle() {
    static lv_style_t defaultButtonStyle;

    lv_style_copy(&defaultButtonStyle, &lv_style_plain);

    defaultButtonStyle.body.radius = 20;

    return &defaultButtonStyle;
}

lv_style_t* display::getWidgetDefaultStyle() {
    static lv_style_t defaultWidgetStyle;

    lv_style_copy(&defaultWidgetStyle, &lv_style_plain);

    defaultWidgetStyle.body.radius = 10;

    return &defaultWidgetStyle;
}

void display::setButtonDefaultStyle(lv_obj_t* button) {
    static lv_style_t openStyle;
    static lv_style_t closedStyle;
    static lv_style_t inactiveStyle;

    lv_style_copy(&openStyle, getButtonDefaultStyle());
    lv_style_copy(&closedStyle, getButtonDefaultStyle());
    lv_style_copy(&inactiveStyle, getButtonDefaultStyle());
    
    setBackgroundColor(&openStyle, BTN_MAIN_OPEN_COLOR);
    lv_btn_set_style(button, LV_BTN_STYLE_REL, &openStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_REL, &openStyle);

    setBackgroundColor(&closedStyle, BTN_MAIN_CLOSED_COLOR);
    lv_btn_set_style(button, LV_BTN_STYLE_PR, &closedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_PR, &closedStyle);

    setBackgroundColor(&inactiveStyle, LV_COLOR_GRAY);
    lv_btn_set_style(button, LV_BTN_STYLE_INA, &inactiveStyle);
}

void display::setWidgetDefaultStyle(lv_obj_t* button) {
    static lv_style_t openStyle;
    static lv_style_t closedStyle;
    static lv_style_t inactiveStyle;

    lv_style_copy(&openStyle, getWidgetDefaultStyle());
    lv_style_copy(&closedStyle, getWidgetDefaultStyle());
    lv_style_copy(&inactiveStyle, getWidgetDefaultStyle());
    
    setBackgroundColor(&openStyle, BTN_WIDGET_OPEN_COLOR);
    lv_btn_set_style(button, LV_BTN_STYLE_REL, &openStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_REL, &openStyle);

    setBackgroundColor(&closedStyle, BTN_WIDGET_CLOSED_COLOR);
    lv_btn_set_style(button, LV_BTN_STYLE_PR, &closedStyle);
    lv_btn_set_style(button, LV_BTN_STYLE_TGL_PR, &closedStyle);

    setBackgroundColor(&inactiveStyle, LV_COLOR_GRAY);
    lv_btn_set_style(button, LV_BTN_STYLE_INA, &inactiveStyle);
}