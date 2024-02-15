#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;
static leWidget* root3;
static leWidget* root4;
static leWidget* root5;
static leWidget* root6;
static leWidget* root7;

leWidget* Screen0_BackgroundPanel;
leImageWidget* Screen0_ImageWidget_background;
leImageWidget* Screen0_mhgsLogo;
leRectangleWidget* Screen0_RectangleWidget_0;
leRectangleWidget* Screen0_RectangleWidget_1;
leRectangleWidget* Screen0_RectangleWidget_2;
leRectangleWidget* Screen0_RectangleWidget_3;
leLabelWidget* Screen0_LabelWidget_0;
leLabelWidget* Screen0_LabelWidget_1;
leLabelWidget* Screen0_LabelWidget_2;
leLabelWidget* Screen0_LabelWidget_3;
leLabelWidget* Screen0_LabelTime;
leLabelWidget* Screen0_Label_colon;
leRectangleWidget* Screen0_RectangleWidget_background_prog;
leRectangleWidget* Screen0_RectangleWidget_backgroundTemp;
leRectangleWidget* Screen0_RectangleWidget_backgroundSLevel;
leRectangleWidget* Screen0_RectangleWidget_backgroundOption;
leButtonWidget* Screen0_ButtonWidget_t1;
leButtonWidget* Screen0_ButtonWidget_t2;
leButtonWidget* Screen0_ButtonWidget_t3;
leButtonWidget* Screen0_ButtonWidget_p1;
leButtonWidget* Screen0_ButtonWidget_p2;
leButtonWidget* Screen0_ButtonWidget_p3;
leButtonWidget* Screen0_ButtonWidget_p4;
leButtonWidget* Screen0_ButtonWidget_sl1;
leButtonWidget* Screen0_ButtonWidget_sl2;
leButtonWidget* Screen0_ButtonWidget_sl3;
leButtonWidget* Screen0_ButtonWidget_Opt_preWash;
leButtonWidget* Screen0_ButtonWidget_Opt_LoadSize;
leButtonWidget* Screen0_ButtonWidget_Opt_rinse;
leButtonWidget* Screen0_ButtonWidget_Options;
leButtonWidget* Screen0_ButtonWidget_Start;
leLabelWidget* Screen0_Labelbuttont1;
leImageWidget* Screen0_Imagebuttont1;
leLabelWidget* Screen0_Labelbuttont2;
leImageWidget* Screen0_Imagebuttont2;
leLabelWidget* Screen0_Labelbuttont3;
leImageWidget* Screen0_Imagebuttont3;
leLabelWidget* Screen0_Labelbuttonp1;
leImageWidget* Screen0_Imagebuttonp1;
leLabelWidget* Screen0_Labelbuttonp2;
leImageWidget* Screen0_Imagebuttonp2;
leLabelWidget* Screen0_Labelbuttonp3;
leImageWidget* Screen0_Imagebuttonp3;
leLabelWidget* Screen0_Labelbuttonp4;
leImageWidget* Screen0_Imagebuttonp4;
leLabelWidget* Screen0_Labelbutonsl1;
leImageWidget* Screen0_Imagebuttonsl1;
leLabelWidget* Screen0_Labelbuttonsl2;
leImageWidget* Screen0_Imagebuttonsl2;
leLabelWidget* Screen0_Labelbuttonsl3;
leImageWidget* Screen0_Imagebuttonsl3;
leImageWidget* Screen0_ImageOptPrewash;
leLabelWidget* Screen0_LabelOptPrewash;
leImageWidget* Screen0_ImageOptLoadSize;
leLabelWidget* Screen0_LabelOptLoadSize;
leImageWidget* Screen0_ImageOptRinse;
leLabelWidget* Screen0_LabelOptRinse;
leImageWidget* Screen0_ImageOption1;
leImageWidget* Screen0_ImageOption2;
leImageWidget* Screen0_ImageOption3;
leImageWidget* Screen0_ImageOption4;
leLabelWidget* Screen0_LabelOptSound;
leImageWidget* Screen0_ImageOptSound;
leWidget* Screen0_PanelWidget_screen2;
leImageWidget* Screen0_ImageWidget_background2;
leLabelWidget* Screen0_LabelTime_2;
leLabelWidget* Screen0_LabelColon2;
leImageWidget* Screen0_ImageWidget_0;
leButtonWidget* Screen0_ButtonWidget_pp;
leButtonWidget* Screen0_ButtonWidget_exit;
leImageWidget* Screen0_ImageWidget_progress;
leImageWidget* Screen0_ImagePopUp;
leLabelWidget* Screen0_LabelCycleComplete;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_BackgroundPanel = leWidget_New();
    Screen0_BackgroundPanel->fn->setPosition(Screen0_BackgroundPanel, 0, 0);
    Screen0_BackgroundPanel->fn->setSize(Screen0_BackgroundPanel, 800, 480);
    Screen0_BackgroundPanel->fn->setScheme(Screen0_BackgroundPanel, &GreyScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_BackgroundPanel);

    Screen0_ImageWidget_background = leImageWidget_New();
    Screen0_ImageWidget_background->fn->setPosition(Screen0_ImageWidget_background, 1, 0);
    Screen0_ImageWidget_background->fn->setSize(Screen0_ImageWidget_background, 800, 480);
    Screen0_ImageWidget_background->fn->setScheme(Screen0_ImageWidget_background, &WhiteScheme);
    Screen0_ImageWidget_background->fn->setBackgroundType(Screen0_ImageWidget_background, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_background->fn->setBorderType(Screen0_ImageWidget_background, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_background->fn->setImage(Screen0_ImageWidget_background, (leImage*)&template);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_background);

    Screen0_mhgsLogo = leImageWidget_New();
    Screen0_mhgsLogo->fn->setPosition(Screen0_mhgsLogo, 700, 0);
    Screen0_mhgsLogo->fn->setBackgroundType(Screen0_mhgsLogo, LE_WIDGET_BACKGROUND_NONE);
    Screen0_mhgsLogo->fn->setBorderType(Screen0_mhgsLogo, LE_WIDGET_BORDER_NONE);
    Screen0_mhgsLogo->fn->setImage(Screen0_mhgsLogo, (leImage*)&logoH);
    root0->fn->addChild(root0, (leWidget*)Screen0_mhgsLogo);

    Screen0_RectangleWidget_0 = leRectangleWidget_New();
    Screen0_RectangleWidget_0->fn->setPosition(Screen0_RectangleWidget_0, 30, 60);
    Screen0_RectangleWidget_0->fn->setSize(Screen0_RectangleWidget_0, 140, 90);
    Screen0_RectangleWidget_0->fn->setScheme(Screen0_RectangleWidget_0, &GreenScheme);
    Screen0_RectangleWidget_0->fn->setBorderType(Screen0_RectangleWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_RectangleWidget_0->fn->setThickness(Screen0_RectangleWidget_0, 2);
    root0->fn->addChild(root0, (leWidget*)Screen0_RectangleWidget_0);

    Screen0_LabelWidget_0 = leLabelWidget_New();
    Screen0_LabelWidget_0->fn->setPosition(Screen0_LabelWidget_0, 0, 5);
    Screen0_LabelWidget_0->fn->setSize(Screen0_LabelWidget_0, 128, 25);
    Screen0_LabelWidget_0->fn->setScheme(Screen0_LabelWidget_0, &WhiteScheme);
    Screen0_LabelWidget_0->fn->setBackgroundType(Screen0_LabelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_0->fn->setString(Screen0_LabelWidget_0, (leString*)&string_program);
    Screen0_RectangleWidget_0->fn->addChild(Screen0_RectangleWidget_0, (leWidget*)Screen0_LabelWidget_0);

    Screen0_RectangleWidget_1 = leRectangleWidget_New();
    Screen0_RectangleWidget_1->fn->setPosition(Screen0_RectangleWidget_1, 180, 60);
    Screen0_RectangleWidget_1->fn->setSize(Screen0_RectangleWidget_1, 140, 90);
    Screen0_RectangleWidget_1->fn->setScheme(Screen0_RectangleWidget_1, &BlueScheme);
    Screen0_RectangleWidget_1->fn->setBorderType(Screen0_RectangleWidget_1, LE_WIDGET_BORDER_NONE);
    Screen0_RectangleWidget_1->fn->setThickness(Screen0_RectangleWidget_1, 2);
    root0->fn->addChild(root0, (leWidget*)Screen0_RectangleWidget_1);

    Screen0_LabelWidget_1 = leLabelWidget_New();
    Screen0_LabelWidget_1->fn->setPosition(Screen0_LabelWidget_1, 0, 5);
    Screen0_LabelWidget_1->fn->setSize(Screen0_LabelWidget_1, 128, 25);
    Screen0_LabelWidget_1->fn->setScheme(Screen0_LabelWidget_1, &WhiteScheme);
    Screen0_LabelWidget_1->fn->setBackgroundType(Screen0_LabelWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_1->fn->setString(Screen0_LabelWidget_1, (leString*)&string_temperature);
    Screen0_RectangleWidget_1->fn->addChild(Screen0_RectangleWidget_1, (leWidget*)Screen0_LabelWidget_1);

    Screen0_RectangleWidget_2 = leRectangleWidget_New();
    Screen0_RectangleWidget_2->fn->setPosition(Screen0_RectangleWidget_2, 330, 60);
    Screen0_RectangleWidget_2->fn->setSize(Screen0_RectangleWidget_2, 140, 90);
    Screen0_RectangleWidget_2->fn->setScheme(Screen0_RectangleWidget_2, &GreenScheme);
    Screen0_RectangleWidget_2->fn->setBorderType(Screen0_RectangleWidget_2, LE_WIDGET_BORDER_NONE);
    Screen0_RectangleWidget_2->fn->setThickness(Screen0_RectangleWidget_2, 2);
    root0->fn->addChild(root0, (leWidget*)Screen0_RectangleWidget_2);

    Screen0_LabelWidget_2 = leLabelWidget_New();
    Screen0_LabelWidget_2->fn->setPosition(Screen0_LabelWidget_2, 0, 5);
    Screen0_LabelWidget_2->fn->setSize(Screen0_LabelWidget_2, 128, 25);
    Screen0_LabelWidget_2->fn->setScheme(Screen0_LabelWidget_2, &WhiteScheme);
    Screen0_LabelWidget_2->fn->setBackgroundType(Screen0_LabelWidget_2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_2->fn->setString(Screen0_LabelWidget_2, (leString*)&string_soil);
    Screen0_RectangleWidget_2->fn->addChild(Screen0_RectangleWidget_2, (leWidget*)Screen0_LabelWidget_2);

    Screen0_RectangleWidget_3 = leRectangleWidget_New();
    Screen0_RectangleWidget_3->fn->setPosition(Screen0_RectangleWidget_3, 480, 60);
    Screen0_RectangleWidget_3->fn->setSize(Screen0_RectangleWidget_3, 140, 90);
    Screen0_RectangleWidget_3->fn->setScheme(Screen0_RectangleWidget_3, &BlueScheme);
    Screen0_RectangleWidget_3->fn->setBorderType(Screen0_RectangleWidget_3, LE_WIDGET_BORDER_NONE);
    Screen0_RectangleWidget_3->fn->setThickness(Screen0_RectangleWidget_3, 2);
    root0->fn->addChild(root0, (leWidget*)Screen0_RectangleWidget_3);

    Screen0_LabelWidget_3 = leLabelWidget_New();
    Screen0_LabelWidget_3->fn->setPosition(Screen0_LabelWidget_3, 0, 5);
    Screen0_LabelWidget_3->fn->setSize(Screen0_LabelWidget_3, 128, 25);
    Screen0_LabelWidget_3->fn->setScheme(Screen0_LabelWidget_3, &WhiteScheme);
    Screen0_LabelWidget_3->fn->setBackgroundType(Screen0_LabelWidget_3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_3->fn->setString(Screen0_LabelWidget_3, (leString*)&string_options);
    Screen0_RectangleWidget_3->fn->addChild(Screen0_RectangleWidget_3, (leWidget*)Screen0_LabelWidget_3);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 190, 45);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_LabelTime = leLabelWidget_New();
    Screen0_LabelTime->fn->setPosition(Screen0_LabelTime, 0, 0);
    Screen0_LabelTime->fn->setSize(Screen0_LabelTime, 140, 30);
    Screen0_LabelTime->fn->setVisible(Screen0_LabelTime, LE_FALSE);
    Screen0_LabelTime->fn->setScheme(Screen0_LabelTime, &BlueScheme);
    Screen0_LabelTime->fn->setBackgroundType(Screen0_LabelTime, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->addChild(root1, (leWidget*)Screen0_LabelTime);

    Screen0_Label_colon = leLabelWidget_New();
    Screen0_Label_colon->fn->setPosition(Screen0_Label_colon, 32, 2);
    Screen0_Label_colon->fn->setSize(Screen0_Label_colon, 17, 25);
    Screen0_Label_colon->fn->setVisible(Screen0_Label_colon, LE_FALSE);
    Screen0_Label_colon->fn->setScheme(Screen0_Label_colon, &BlueScheme);
    Screen0_Label_colon->fn->setBackgroundType(Screen0_Label_colon, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelTime->fn->addChild(Screen0_LabelTime, (leWidget*)Screen0_Label_colon);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 800, 180);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGBA_8888);

    // layer 3
    root3 = leWidget_New();
    root3->fn->setSize(root3, 800, 480);
    root3->fn->setBackgroundType(root3, LE_WIDGET_BACKGROUND_NONE);
    root3->fn->setMargins(root3, 0, 0, 0, 0);
    root3->flags |= LE_WIDGET_IGNOREEVENTS;
    root3->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_RectangleWidget_background_prog = leRectangleWidget_New();
    Screen0_RectangleWidget_background_prog->fn->setPosition(Screen0_RectangleWidget_background_prog, 30, 150);
    Screen0_RectangleWidget_background_prog->fn->setSize(Screen0_RectangleWidget_background_prog, 140, 0);
    Screen0_RectangleWidget_background_prog->fn->setVisible(Screen0_RectangleWidget_background_prog, LE_FALSE);
    Screen0_RectangleWidget_background_prog->fn->setScheme(Screen0_RectangleWidget_background_prog, &GreenSchemeTransparent);
    Screen0_RectangleWidget_background_prog->fn->setBorderType(Screen0_RectangleWidget_background_prog, LE_WIDGET_BORDER_NONE);
    Screen0_RectangleWidget_background_prog->fn->setThickness(Screen0_RectangleWidget_background_prog, 2);
    root3->fn->addChild(root3, (leWidget*)Screen0_RectangleWidget_background_prog);

    Screen0_RectangleWidget_backgroundTemp = leRectangleWidget_New();
    Screen0_RectangleWidget_backgroundTemp->fn->setPosition(Screen0_RectangleWidget_backgroundTemp, 180, 150);
    Screen0_RectangleWidget_backgroundTemp->fn->setSize(Screen0_RectangleWidget_backgroundTemp, 140, 0);
    Screen0_RectangleWidget_backgroundTemp->fn->setVisible(Screen0_RectangleWidget_backgroundTemp, LE_FALSE);
    Screen0_RectangleWidget_backgroundTemp->fn->setScheme(Screen0_RectangleWidget_backgroundTemp, &BlueSchemeTransparent);
    Screen0_RectangleWidget_backgroundTemp->fn->setBorderType(Screen0_RectangleWidget_backgroundTemp, LE_WIDGET_BORDER_NONE);
    Screen0_RectangleWidget_backgroundTemp->fn->setThickness(Screen0_RectangleWidget_backgroundTemp, 2);
    root3->fn->addChild(root3, (leWidget*)Screen0_RectangleWidget_backgroundTemp);

    Screen0_RectangleWidget_backgroundSLevel = leRectangleWidget_New();
    Screen0_RectangleWidget_backgroundSLevel->fn->setPosition(Screen0_RectangleWidget_backgroundSLevel, 330, 150);
    Screen0_RectangleWidget_backgroundSLevel->fn->setSize(Screen0_RectangleWidget_backgroundSLevel, 140, 0);
    Screen0_RectangleWidget_backgroundSLevel->fn->setVisible(Screen0_RectangleWidget_backgroundSLevel, LE_FALSE);
    Screen0_RectangleWidget_backgroundSLevel->fn->setScheme(Screen0_RectangleWidget_backgroundSLevel, &GreenSchemeTransparent);
    Screen0_RectangleWidget_backgroundSLevel->fn->setBorderType(Screen0_RectangleWidget_backgroundSLevel, LE_WIDGET_BORDER_NONE);
    Screen0_RectangleWidget_backgroundSLevel->fn->setThickness(Screen0_RectangleWidget_backgroundSLevel, 2);
    root3->fn->addChild(root3, (leWidget*)Screen0_RectangleWidget_backgroundSLevel);

    Screen0_RectangleWidget_backgroundOption = leRectangleWidget_New();
    Screen0_RectangleWidget_backgroundOption->fn->setPosition(Screen0_RectangleWidget_backgroundOption, 480, 150);
    Screen0_RectangleWidget_backgroundOption->fn->setSize(Screen0_RectangleWidget_backgroundOption, 140, 0);
    Screen0_RectangleWidget_backgroundOption->fn->setVisible(Screen0_RectangleWidget_backgroundOption, LE_FALSE);
    Screen0_RectangleWidget_backgroundOption->fn->setScheme(Screen0_RectangleWidget_backgroundOption, &BlueSchemeTransparent);
    Screen0_RectangleWidget_backgroundOption->fn->setBorderType(Screen0_RectangleWidget_backgroundOption, LE_WIDGET_BORDER_NONE);
    Screen0_RectangleWidget_backgroundOption->fn->setThickness(Screen0_RectangleWidget_backgroundOption, 2);
    root3->fn->addChild(root3, (leWidget*)Screen0_RectangleWidget_backgroundOption);

    Screen0_ButtonWidget_t1 = leButtonWidget_New();
    Screen0_ButtonWidget_t1->fn->setPosition(Screen0_ButtonWidget_t1, 188, 94);
    Screen0_ButtonWidget_t1->fn->setSize(Screen0_ButtonWidget_t1, 120, 50);
    Screen0_ButtonWidget_t1->fn->setScheme(Screen0_ButtonWidget_t1, &WhiteScheme);
    Screen0_ButtonWidget_t1->fn->setBackgroundType(Screen0_ButtonWidget_t1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_t1->fn->setBorderType(Screen0_ButtonWidget_t1, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_t1->fn->setPressedImage(Screen0_ButtonWidget_t1, (leImage*)&green_but_down);
    Screen0_ButtonWidget_t1->fn->setReleasedImage(Screen0_ButtonWidget_t1, (leImage*)&green_but_up);
    Screen0_ButtonWidget_t1->fn->setImagePosition(Screen0_ButtonWidget_t1, LE_RELATIVE_POSITION_BEHIND);
    Screen0_ButtonWidget_t1->fn->setReleasedEventCallback(Screen0_ButtonWidget_t1, event_Screen0_ButtonWidget_t1_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_t1);

    Screen0_Labelbuttont1 = leLabelWidget_New();
    Screen0_Labelbuttont1->fn->setPosition(Screen0_Labelbuttont1, 2, 12);
    Screen0_Labelbuttont1->fn->setScheme(Screen0_Labelbuttont1, &WhiteScheme);
    Screen0_Labelbuttont1->fn->setBackgroundType(Screen0_Labelbuttont1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttont1->fn->setString(Screen0_Labelbuttont1, (leString*)&string_WarmTemp);
    Screen0_ButtonWidget_t1->fn->addChild(Screen0_ButtonWidget_t1, (leWidget*)Screen0_Labelbuttont1);

    Screen0_Imagebuttont1 = leImageWidget_New();
    Screen0_Imagebuttont1->fn->setPosition(Screen0_Imagebuttont1, 90, 10);
    Screen0_Imagebuttont1->fn->setSize(Screen0_Imagebuttont1, 30, 30);
    Screen0_Imagebuttont1->fn->setBackgroundType(Screen0_Imagebuttont1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttont1->fn->setBorderType(Screen0_Imagebuttont1, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttont1->fn->setImage(Screen0_Imagebuttont1, (leImage*)&warmTemp);
    Screen0_ButtonWidget_t1->fn->addChild(Screen0_ButtonWidget_t1, (leWidget*)Screen0_Imagebuttont1);

    Screen0_ButtonWidget_t2 = leButtonWidget_New();
    Screen0_ButtonWidget_t2->fn->setPosition(Screen0_ButtonWidget_t2, 188, 157);
    Screen0_ButtonWidget_t2->fn->setSize(Screen0_ButtonWidget_t2, 120, 50);
    Screen0_ButtonWidget_t2->fn->setVisible(Screen0_ButtonWidget_t2, LE_FALSE);
    Screen0_ButtonWidget_t2->fn->setBackgroundType(Screen0_ButtonWidget_t2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_t2->fn->setBorderType(Screen0_ButtonWidget_t2, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_t2->fn->setPressedImage(Screen0_ButtonWidget_t2, (leImage*)&green_but_down);
    Screen0_ButtonWidget_t2->fn->setReleasedImage(Screen0_ButtonWidget_t2, (leImage*)&green_but_up);
    Screen0_ButtonWidget_t2->fn->setReleasedEventCallback(Screen0_ButtonWidget_t2, event_Screen0_ButtonWidget_t2_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_t2);

    Screen0_Labelbuttont2 = leLabelWidget_New();
    Screen0_Labelbuttont2->fn->setPosition(Screen0_Labelbuttont2, 2, 12);
    Screen0_Labelbuttont2->fn->setScheme(Screen0_Labelbuttont2, &WhiteScheme);
    Screen0_Labelbuttont2->fn->setBackgroundType(Screen0_Labelbuttont2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttont2->fn->setString(Screen0_Labelbuttont2, (leString*)&string_ColdTemp);
    Screen0_ButtonWidget_t2->fn->addChild(Screen0_ButtonWidget_t2, (leWidget*)Screen0_Labelbuttont2);

    Screen0_Imagebuttont2 = leImageWidget_New();
    Screen0_Imagebuttont2->fn->setPosition(Screen0_Imagebuttont2, 90, 10);
    Screen0_Imagebuttont2->fn->setSize(Screen0_Imagebuttont2, 30, 30);
    Screen0_Imagebuttont2->fn->setBackgroundType(Screen0_Imagebuttont2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttont2->fn->setBorderType(Screen0_Imagebuttont2, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttont2->fn->setImage(Screen0_Imagebuttont2, (leImage*)&coldTemp);
    Screen0_ButtonWidget_t2->fn->addChild(Screen0_ButtonWidget_t2, (leWidget*)Screen0_Imagebuttont2);

    Screen0_ButtonWidget_t3 = leButtonWidget_New();
    Screen0_ButtonWidget_t3->fn->setPosition(Screen0_ButtonWidget_t3, 189, 220);
    Screen0_ButtonWidget_t3->fn->setSize(Screen0_ButtonWidget_t3, 120, 50);
    Screen0_ButtonWidget_t3->fn->setVisible(Screen0_ButtonWidget_t3, LE_FALSE);
    Screen0_ButtonWidget_t3->fn->setBackgroundType(Screen0_ButtonWidget_t3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_t3->fn->setBorderType(Screen0_ButtonWidget_t3, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_t3->fn->setPressedImage(Screen0_ButtonWidget_t3, (leImage*)&green_but_down);
    Screen0_ButtonWidget_t3->fn->setReleasedImage(Screen0_ButtonWidget_t3, (leImage*)&green_but_up);
    Screen0_ButtonWidget_t3->fn->setReleasedEventCallback(Screen0_ButtonWidget_t3, event_Screen0_ButtonWidget_t3_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_t3);

    Screen0_Labelbuttont3 = leLabelWidget_New();
    Screen0_Labelbuttont3->fn->setPosition(Screen0_Labelbuttont3, 2, 12);
    Screen0_Labelbuttont3->fn->setScheme(Screen0_Labelbuttont3, &WhiteScheme);
    Screen0_Labelbuttont3->fn->setBackgroundType(Screen0_Labelbuttont3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttont3->fn->setString(Screen0_Labelbuttont3, (leString*)&string_HotTemp);
    Screen0_ButtonWidget_t3->fn->addChild(Screen0_ButtonWidget_t3, (leWidget*)Screen0_Labelbuttont3);

    Screen0_Imagebuttont3 = leImageWidget_New();
    Screen0_Imagebuttont3->fn->setPosition(Screen0_Imagebuttont3, 90, 10);
    Screen0_Imagebuttont3->fn->setSize(Screen0_Imagebuttont3, 30, 30);
    Screen0_Imagebuttont3->fn->setBackgroundType(Screen0_Imagebuttont3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttont3->fn->setBorderType(Screen0_Imagebuttont3, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttont3->fn->setImage(Screen0_Imagebuttont3, (leImage*)&hotTemp);
    Screen0_ButtonWidget_t3->fn->addChild(Screen0_ButtonWidget_t3, (leWidget*)Screen0_Imagebuttont3);

    Screen0_ButtonWidget_p1 = leButtonWidget_New();
    Screen0_ButtonWidget_p1->fn->setPosition(Screen0_ButtonWidget_p1, 38, 94);
    Screen0_ButtonWidget_p1->fn->setSize(Screen0_ButtonWidget_p1, 120, 50);
    Screen0_ButtonWidget_p1->fn->setScheme(Screen0_ButtonWidget_p1, &WhiteScheme);
    Screen0_ButtonWidget_p1->fn->setBackgroundType(Screen0_ButtonWidget_p1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_p1->fn->setBorderType(Screen0_ButtonWidget_p1, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_p1->fn->setPressedImage(Screen0_ButtonWidget_p1, (leImage*)&blue_but_down);
    Screen0_ButtonWidget_p1->fn->setReleasedImage(Screen0_ButtonWidget_p1, (leImage*)&blue_but_up);
    Screen0_ButtonWidget_p1->fn->setImagePosition(Screen0_ButtonWidget_p1, LE_RELATIVE_POSITION_BEHIND);
    Screen0_ButtonWidget_p1->fn->setReleasedEventCallback(Screen0_ButtonWidget_p1, event_Screen0_ButtonWidget_p1_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_p1);

    Screen0_Labelbuttonp1 = leLabelWidget_New();
    Screen0_Labelbuttonp1->fn->setPosition(Screen0_Labelbuttonp1, 2, 12);
    Screen0_Labelbuttonp1->fn->setScheme(Screen0_Labelbuttonp1, &WhiteScheme);
    Screen0_Labelbuttonp1->fn->setBackgroundType(Screen0_Labelbuttonp1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttonp1->fn->setString(Screen0_Labelbuttonp1, (leString*)&string_NormalProg);
    Screen0_ButtonWidget_p1->fn->addChild(Screen0_ButtonWidget_p1, (leWidget*)Screen0_Labelbuttonp1);

    Screen0_Imagebuttonp1 = leImageWidget_New();
    Screen0_Imagebuttonp1->fn->setPosition(Screen0_Imagebuttonp1, 87, 10);
    Screen0_Imagebuttonp1->fn->setSize(Screen0_Imagebuttonp1, 30, 30);
    Screen0_Imagebuttonp1->fn->setBackgroundType(Screen0_Imagebuttonp1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttonp1->fn->setBorderType(Screen0_Imagebuttonp1, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttonp1->fn->setImage(Screen0_Imagebuttonp1, (leImage*)&normalprog);
    Screen0_ButtonWidget_p1->fn->addChild(Screen0_ButtonWidget_p1, (leWidget*)Screen0_Imagebuttonp1);

    Screen0_ButtonWidget_p2 = leButtonWidget_New();
    Screen0_ButtonWidget_p2->fn->setPosition(Screen0_ButtonWidget_p2, 38, 157);
    Screen0_ButtonWidget_p2->fn->setSize(Screen0_ButtonWidget_p2, 120, 50);
    Screen0_ButtonWidget_p2->fn->setVisible(Screen0_ButtonWidget_p2, LE_FALSE);
    Screen0_ButtonWidget_p2->fn->setBackgroundType(Screen0_ButtonWidget_p2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_p2->fn->setBorderType(Screen0_ButtonWidget_p2, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_p2->fn->setPressedImage(Screen0_ButtonWidget_p2, (leImage*)&blue_but_down);
    Screen0_ButtonWidget_p2->fn->setReleasedImage(Screen0_ButtonWidget_p2, (leImage*)&blue_but_up);
    Screen0_ButtonWidget_p2->fn->setReleasedEventCallback(Screen0_ButtonWidget_p2, event_Screen0_ButtonWidget_p2_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_p2);

    Screen0_Labelbuttonp2 = leLabelWidget_New();
    Screen0_Labelbuttonp2->fn->setPosition(Screen0_Labelbuttonp2, 2, 12);
    Screen0_Labelbuttonp2->fn->setScheme(Screen0_Labelbuttonp2, &WhiteScheme);
    Screen0_Labelbuttonp2->fn->setBackgroundType(Screen0_Labelbuttonp2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttonp2->fn->setString(Screen0_Labelbuttonp2, (leString*)&string_SportsProg);
    Screen0_ButtonWidget_p2->fn->addChild(Screen0_ButtonWidget_p2, (leWidget*)Screen0_Labelbuttonp2);

    Screen0_Imagebuttonp2 = leImageWidget_New();
    Screen0_Imagebuttonp2->fn->setPosition(Screen0_Imagebuttonp2, 88, 10);
    Screen0_Imagebuttonp2->fn->setSize(Screen0_Imagebuttonp2, 30, 30);
    Screen0_Imagebuttonp2->fn->setBackgroundType(Screen0_Imagebuttonp2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttonp2->fn->setBorderType(Screen0_Imagebuttonp2, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttonp2->fn->setImage(Screen0_Imagebuttonp2, (leImage*)&sportsprog);
    Screen0_ButtonWidget_p2->fn->addChild(Screen0_ButtonWidget_p2, (leWidget*)Screen0_Imagebuttonp2);

    Screen0_ButtonWidget_p3 = leButtonWidget_New();
    Screen0_ButtonWidget_p3->fn->setPosition(Screen0_ButtonWidget_p3, 36, 220);
    Screen0_ButtonWidget_p3->fn->setSize(Screen0_ButtonWidget_p3, 120, 50);
    Screen0_ButtonWidget_p3->fn->setVisible(Screen0_ButtonWidget_p3, LE_FALSE);
    Screen0_ButtonWidget_p3->fn->setBackgroundType(Screen0_ButtonWidget_p3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_p3->fn->setBorderType(Screen0_ButtonWidget_p3, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_p3->fn->setPressedImage(Screen0_ButtonWidget_p3, (leImage*)&blue_but_down);
    Screen0_ButtonWidget_p3->fn->setReleasedImage(Screen0_ButtonWidget_p3, (leImage*)&blue_but_up);
    Screen0_ButtonWidget_p3->fn->setReleasedEventCallback(Screen0_ButtonWidget_p3, event_Screen0_ButtonWidget_p3_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_p3);

    Screen0_Labelbuttonp3 = leLabelWidget_New();
    Screen0_Labelbuttonp3->fn->setPosition(Screen0_Labelbuttonp3, 2, 12);
    Screen0_Labelbuttonp3->fn->setScheme(Screen0_Labelbuttonp3, &WhiteScheme);
    Screen0_Labelbuttonp3->fn->setBackgroundType(Screen0_Labelbuttonp3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttonp3->fn->setString(Screen0_Labelbuttonp3, (leString*)&string_WoolProg);
    Screen0_ButtonWidget_p3->fn->addChild(Screen0_ButtonWidget_p3, (leWidget*)Screen0_Labelbuttonp3);

    Screen0_Imagebuttonp3 = leImageWidget_New();
    Screen0_Imagebuttonp3->fn->setPosition(Screen0_Imagebuttonp3, 90, 10);
    Screen0_Imagebuttonp3->fn->setSize(Screen0_Imagebuttonp3, 30, 30);
    Screen0_Imagebuttonp3->fn->setBackgroundType(Screen0_Imagebuttonp3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttonp3->fn->setBorderType(Screen0_Imagebuttonp3, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttonp3->fn->setImage(Screen0_Imagebuttonp3, (leImage*)&woolprog);
    Screen0_ButtonWidget_p3->fn->addChild(Screen0_ButtonWidget_p3, (leWidget*)Screen0_Imagebuttonp3);

    Screen0_ButtonWidget_p4 = leButtonWidget_New();
    Screen0_ButtonWidget_p4->fn->setPosition(Screen0_ButtonWidget_p4, 38, 283);
    Screen0_ButtonWidget_p4->fn->setSize(Screen0_ButtonWidget_p4, 120, 50);
    Screen0_ButtonWidget_p4->fn->setVisible(Screen0_ButtonWidget_p4, LE_FALSE);
    Screen0_ButtonWidget_p4->fn->setBackgroundType(Screen0_ButtonWidget_p4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_p4->fn->setBorderType(Screen0_ButtonWidget_p4, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_p4->fn->setPressedImage(Screen0_ButtonWidget_p4, (leImage*)&blue_but_down);
    Screen0_ButtonWidget_p4->fn->setReleasedImage(Screen0_ButtonWidget_p4, (leImage*)&blue_but_up);
    Screen0_ButtonWidget_p4->fn->setReleasedEventCallback(Screen0_ButtonWidget_p4, event_Screen0_ButtonWidget_p4_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_p4);

    Screen0_Labelbuttonp4 = leLabelWidget_New();
    Screen0_Labelbuttonp4->fn->setPosition(Screen0_Labelbuttonp4, 2, 12);
    Screen0_Labelbuttonp4->fn->setScheme(Screen0_Labelbuttonp4, &WhiteScheme);
    Screen0_Labelbuttonp4->fn->setBackgroundType(Screen0_Labelbuttonp4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttonp4->fn->setString(Screen0_Labelbuttonp4, (leString*)&string_BedProg);
    Screen0_ButtonWidget_p4->fn->addChild(Screen0_ButtonWidget_p4, (leWidget*)Screen0_Labelbuttonp4);

    Screen0_Imagebuttonp4 = leImageWidget_New();
    Screen0_Imagebuttonp4->fn->setPosition(Screen0_Imagebuttonp4, 88, 10);
    Screen0_Imagebuttonp4->fn->setSize(Screen0_Imagebuttonp4, 30, 30);
    Screen0_Imagebuttonp4->fn->setBackgroundType(Screen0_Imagebuttonp4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttonp4->fn->setBorderType(Screen0_Imagebuttonp4, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttonp4->fn->setImage(Screen0_Imagebuttonp4, (leImage*)&bedprog);
    Screen0_ButtonWidget_p4->fn->addChild(Screen0_ButtonWidget_p4, (leWidget*)Screen0_Imagebuttonp4);

    Screen0_ButtonWidget_sl1 = leButtonWidget_New();
    Screen0_ButtonWidget_sl1->fn->setPosition(Screen0_ButtonWidget_sl1, 338, 94);
    Screen0_ButtonWidget_sl1->fn->setSize(Screen0_ButtonWidget_sl1, 120, 50);
    Screen0_ButtonWidget_sl1->fn->setBackgroundType(Screen0_ButtonWidget_sl1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_sl1->fn->setBorderType(Screen0_ButtonWidget_sl1, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_sl1->fn->setPressedImage(Screen0_ButtonWidget_sl1, (leImage*)&blue_but_down);
    Screen0_ButtonWidget_sl1->fn->setReleasedImage(Screen0_ButtonWidget_sl1, (leImage*)&blue_but_up);
    Screen0_ButtonWidget_sl1->fn->setReleasedEventCallback(Screen0_ButtonWidget_sl1, event_Screen0_ButtonWidget_sl1_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_sl1);

    Screen0_Labelbutonsl1 = leLabelWidget_New();
    Screen0_Labelbutonsl1->fn->setPosition(Screen0_Labelbutonsl1, 2, 12);
    Screen0_Labelbutonsl1->fn->setScheme(Screen0_Labelbutonsl1, &WhiteScheme);
    Screen0_Labelbutonsl1->fn->setBackgroundType(Screen0_Labelbutonsl1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbutonsl1->fn->setString(Screen0_Labelbutonsl1, (leString*)&string_MediumSoilLevel);
    Screen0_ButtonWidget_sl1->fn->addChild(Screen0_ButtonWidget_sl1, (leWidget*)Screen0_Labelbutonsl1);

    Screen0_Imagebuttonsl1 = leImageWidget_New();
    Screen0_Imagebuttonsl1->fn->setPosition(Screen0_Imagebuttonsl1, 87, 10);
    Screen0_Imagebuttonsl1->fn->setSize(Screen0_Imagebuttonsl1, 30, 30);
    Screen0_Imagebuttonsl1->fn->setBackgroundType(Screen0_Imagebuttonsl1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttonsl1->fn->setBorderType(Screen0_Imagebuttonsl1, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttonsl1->fn->setImage(Screen0_Imagebuttonsl1, (leImage*)&mediumSL);
    Screen0_ButtonWidget_sl1->fn->addChild(Screen0_ButtonWidget_sl1, (leWidget*)Screen0_Imagebuttonsl1);

    Screen0_ButtonWidget_sl2 = leButtonWidget_New();
    Screen0_ButtonWidget_sl2->fn->setPosition(Screen0_ButtonWidget_sl2, 338, 157);
    Screen0_ButtonWidget_sl2->fn->setSize(Screen0_ButtonWidget_sl2, 120, 50);
    Screen0_ButtonWidget_sl2->fn->setVisible(Screen0_ButtonWidget_sl2, LE_FALSE);
    Screen0_ButtonWidget_sl2->fn->setBackgroundType(Screen0_ButtonWidget_sl2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_sl2->fn->setBorderType(Screen0_ButtonWidget_sl2, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_sl2->fn->setPressedImage(Screen0_ButtonWidget_sl2, (leImage*)&blue_but_down);
    Screen0_ButtonWidget_sl2->fn->setReleasedImage(Screen0_ButtonWidget_sl2, (leImage*)&blue_but_up);
    Screen0_ButtonWidget_sl2->fn->setReleasedEventCallback(Screen0_ButtonWidget_sl2, event_Screen0_ButtonWidget_sl2_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_sl2);

    Screen0_Labelbuttonsl2 = leLabelWidget_New();
    Screen0_Labelbuttonsl2->fn->setPosition(Screen0_Labelbuttonsl2, 2, 12);
    Screen0_Labelbuttonsl2->fn->setScheme(Screen0_Labelbuttonsl2, &WhiteScheme);
    Screen0_Labelbuttonsl2->fn->setBackgroundType(Screen0_Labelbuttonsl2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttonsl2->fn->setString(Screen0_Labelbuttonsl2, (leString*)&string_HighSoilLevel);
    Screen0_ButtonWidget_sl2->fn->addChild(Screen0_ButtonWidget_sl2, (leWidget*)Screen0_Labelbuttonsl2);

    Screen0_Imagebuttonsl2 = leImageWidget_New();
    Screen0_Imagebuttonsl2->fn->setPosition(Screen0_Imagebuttonsl2, 87, 10);
    Screen0_Imagebuttonsl2->fn->setSize(Screen0_Imagebuttonsl2, 30, 30);
    Screen0_Imagebuttonsl2->fn->setBackgroundType(Screen0_Imagebuttonsl2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttonsl2->fn->setBorderType(Screen0_Imagebuttonsl2, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttonsl2->fn->setImage(Screen0_Imagebuttonsl2, (leImage*)&highSL);
    Screen0_ButtonWidget_sl2->fn->addChild(Screen0_ButtonWidget_sl2, (leWidget*)Screen0_Imagebuttonsl2);

    Screen0_ButtonWidget_sl3 = leButtonWidget_New();
    Screen0_ButtonWidget_sl3->fn->setPosition(Screen0_ButtonWidget_sl3, 338, 220);
    Screen0_ButtonWidget_sl3->fn->setSize(Screen0_ButtonWidget_sl3, 120, 50);
    Screen0_ButtonWidget_sl3->fn->setVisible(Screen0_ButtonWidget_sl3, LE_FALSE);
    Screen0_ButtonWidget_sl3->fn->setBackgroundType(Screen0_ButtonWidget_sl3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_sl3->fn->setBorderType(Screen0_ButtonWidget_sl3, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_sl3->fn->setPressedImage(Screen0_ButtonWidget_sl3, (leImage*)&blue_but_down);
    Screen0_ButtonWidget_sl3->fn->setReleasedImage(Screen0_ButtonWidget_sl3, (leImage*)&blue_but_up);
    Screen0_ButtonWidget_sl3->fn->setReleasedEventCallback(Screen0_ButtonWidget_sl3, event_Screen0_ButtonWidget_sl3_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_sl3);

    Screen0_Labelbuttonsl3 = leLabelWidget_New();
    Screen0_Labelbuttonsl3->fn->setPosition(Screen0_Labelbuttonsl3, 2, 12);
    Screen0_Labelbuttonsl3->fn->setScheme(Screen0_Labelbuttonsl3, &WhiteScheme);
    Screen0_Labelbuttonsl3->fn->setBackgroundType(Screen0_Labelbuttonsl3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Labelbuttonsl3->fn->setString(Screen0_Labelbuttonsl3, (leString*)&string_LowSoilLevel);
    Screen0_ButtonWidget_sl3->fn->addChild(Screen0_ButtonWidget_sl3, (leWidget*)Screen0_Labelbuttonsl3);

    Screen0_Imagebuttonsl3 = leImageWidget_New();
    Screen0_Imagebuttonsl3->fn->setPosition(Screen0_Imagebuttonsl3, 87, 10);
    Screen0_Imagebuttonsl3->fn->setSize(Screen0_Imagebuttonsl3, 30, 30);
    Screen0_Imagebuttonsl3->fn->setBackgroundType(Screen0_Imagebuttonsl3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_Imagebuttonsl3->fn->setBorderType(Screen0_Imagebuttonsl3, LE_WIDGET_BORDER_NONE);
    Screen0_Imagebuttonsl3->fn->setImage(Screen0_Imagebuttonsl3, (leImage*)&lowSL);
    Screen0_ButtonWidget_sl3->fn->addChild(Screen0_ButtonWidget_sl3, (leWidget*)Screen0_Imagebuttonsl3);

    Screen0_ButtonWidget_Opt_preWash = leButtonWidget_New();
    Screen0_ButtonWidget_Opt_preWash->fn->setPosition(Screen0_ButtonWidget_Opt_preWash, 488, 220);
    Screen0_ButtonWidget_Opt_preWash->fn->setSize(Screen0_ButtonWidget_Opt_preWash, 120, 50);
    Screen0_ButtonWidget_Opt_preWash->fn->setVisible(Screen0_ButtonWidget_Opt_preWash, LE_FALSE);
    Screen0_ButtonWidget_Opt_preWash->fn->setBackgroundType(Screen0_ButtonWidget_Opt_preWash, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Opt_preWash->fn->setBorderType(Screen0_ButtonWidget_Opt_preWash, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_Opt_preWash->fn->setPressedImage(Screen0_ButtonWidget_Opt_preWash, (leImage*)&green_but_down);
    Screen0_ButtonWidget_Opt_preWash->fn->setReleasedImage(Screen0_ButtonWidget_Opt_preWash, (leImage*)&green_but_up);
    Screen0_ButtonWidget_Opt_preWash->fn->setReleasedEventCallback(Screen0_ButtonWidget_Opt_preWash, event_Screen0_ButtonWidget_Opt_preWash_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_Opt_preWash);

    Screen0_ImageOptPrewash = leImageWidget_New();
    Screen0_ImageOptPrewash->fn->setPosition(Screen0_ImageOptPrewash, 88, 10);
    Screen0_ImageOptPrewash->fn->setSize(Screen0_ImageOptPrewash, 30, 30);
    Screen0_ImageOptPrewash->fn->setBackgroundType(Screen0_ImageOptPrewash, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageOptPrewash->fn->setBorderType(Screen0_ImageOptPrewash, LE_WIDGET_BORDER_NONE);
    Screen0_ImageOptPrewash->fn->setImage(Screen0_ImageOptPrewash, (leImage*)&preWash);
    Screen0_ButtonWidget_Opt_preWash->fn->addChild(Screen0_ButtonWidget_Opt_preWash, (leWidget*)Screen0_ImageOptPrewash);

    Screen0_LabelOptPrewash = leLabelWidget_New();
    Screen0_LabelOptPrewash->fn->setPosition(Screen0_LabelOptPrewash, 1, 6);
    Screen0_LabelOptPrewash->fn->setSize(Screen0_LabelOptPrewash, 100, 42);
    Screen0_LabelOptPrewash->fn->setScheme(Screen0_LabelOptPrewash, &WhiteScheme);
    Screen0_LabelOptPrewash->fn->setBackgroundType(Screen0_LabelOptPrewash, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelOptPrewash->fn->setString(Screen0_LabelOptPrewash, (leString*)&string_preWashOn);
    Screen0_ButtonWidget_Opt_preWash->fn->addChild(Screen0_ButtonWidget_Opt_preWash, (leWidget*)Screen0_LabelOptPrewash);

    Screen0_ButtonWidget_Opt_LoadSize = leButtonWidget_New();
    Screen0_ButtonWidget_Opt_LoadSize->fn->setPosition(Screen0_ButtonWidget_Opt_LoadSize, 488, 283);
    Screen0_ButtonWidget_Opt_LoadSize->fn->setSize(Screen0_ButtonWidget_Opt_LoadSize, 120, 50);
    Screen0_ButtonWidget_Opt_LoadSize->fn->setVisible(Screen0_ButtonWidget_Opt_LoadSize, LE_FALSE);
    Screen0_ButtonWidget_Opt_LoadSize->fn->setBackgroundType(Screen0_ButtonWidget_Opt_LoadSize, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Opt_LoadSize->fn->setBorderType(Screen0_ButtonWidget_Opt_LoadSize, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_Opt_LoadSize->fn->setPressedImage(Screen0_ButtonWidget_Opt_LoadSize, (leImage*)&green_but_down);
    Screen0_ButtonWidget_Opt_LoadSize->fn->setReleasedImage(Screen0_ButtonWidget_Opt_LoadSize, (leImage*)&green_but_up);
    Screen0_ButtonWidget_Opt_LoadSize->fn->setReleasedEventCallback(Screen0_ButtonWidget_Opt_LoadSize, event_Screen0_ButtonWidget_Opt_LoadSize_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_Opt_LoadSize);

    Screen0_ImageOptLoadSize = leImageWidget_New();
    Screen0_ImageOptLoadSize->fn->setPosition(Screen0_ImageOptLoadSize, 88, 10);
    Screen0_ImageOptLoadSize->fn->setSize(Screen0_ImageOptLoadSize, 30, 30);
    Screen0_ImageOptLoadSize->fn->setBackgroundType(Screen0_ImageOptLoadSize, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageOptLoadSize->fn->setBorderType(Screen0_ImageOptLoadSize, LE_WIDGET_BORDER_NONE);
    Screen0_ImageOptLoadSize->fn->setImage(Screen0_ImageOptLoadSize, (leImage*)&loadSize);
    Screen0_ButtonWidget_Opt_LoadSize->fn->addChild(Screen0_ButtonWidget_Opt_LoadSize, (leWidget*)Screen0_ImageOptLoadSize);

    Screen0_LabelOptLoadSize = leLabelWidget_New();
    Screen0_LabelOptLoadSize->fn->setPosition(Screen0_LabelOptLoadSize, 1, 6);
    Screen0_LabelOptLoadSize->fn->setSize(Screen0_LabelOptLoadSize, 100, 45);
    Screen0_LabelOptLoadSize->fn->setScheme(Screen0_LabelOptLoadSize, &WhiteScheme);
    Screen0_LabelOptLoadSize->fn->setBackgroundType(Screen0_LabelOptLoadSize, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelOptLoadSize->fn->setString(Screen0_LabelOptLoadSize, (leString*)&string_LoadHigh);
    Screen0_ButtonWidget_Opt_LoadSize->fn->addChild(Screen0_ButtonWidget_Opt_LoadSize, (leWidget*)Screen0_LabelOptLoadSize);

    Screen0_ButtonWidget_Opt_rinse = leButtonWidget_New();
    Screen0_ButtonWidget_Opt_rinse->fn->setPosition(Screen0_ButtonWidget_Opt_rinse, 488, 157);
    Screen0_ButtonWidget_Opt_rinse->fn->setSize(Screen0_ButtonWidget_Opt_rinse, 120, 50);
    Screen0_ButtonWidget_Opt_rinse->fn->setVisible(Screen0_ButtonWidget_Opt_rinse, LE_FALSE);
    Screen0_ButtonWidget_Opt_rinse->fn->setBackgroundType(Screen0_ButtonWidget_Opt_rinse, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Opt_rinse->fn->setBorderType(Screen0_ButtonWidget_Opt_rinse, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_Opt_rinse->fn->setPressedImage(Screen0_ButtonWidget_Opt_rinse, (leImage*)&green_but_down);
    Screen0_ButtonWidget_Opt_rinse->fn->setReleasedImage(Screen0_ButtonWidget_Opt_rinse, (leImage*)&green_but_up);
    Screen0_ButtonWidget_Opt_rinse->fn->setReleasedEventCallback(Screen0_ButtonWidget_Opt_rinse, event_Screen0_ButtonWidget_Opt_rinse_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_Opt_rinse);

    Screen0_ImageOptRinse = leImageWidget_New();
    Screen0_ImageOptRinse->fn->setPosition(Screen0_ImageOptRinse, 88, 10);
    Screen0_ImageOptRinse->fn->setSize(Screen0_ImageOptRinse, 30, 30);
    Screen0_ImageOptRinse->fn->setBackgroundType(Screen0_ImageOptRinse, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageOptRinse->fn->setBorderType(Screen0_ImageOptRinse, LE_WIDGET_BORDER_NONE);
    Screen0_ImageOptRinse->fn->setImage(Screen0_ImageOptRinse, (leImage*)&rinse);
    Screen0_ButtonWidget_Opt_rinse->fn->addChild(Screen0_ButtonWidget_Opt_rinse, (leWidget*)Screen0_ImageOptRinse);

    Screen0_LabelOptRinse = leLabelWidget_New();
    Screen0_LabelOptRinse->fn->setPosition(Screen0_LabelOptRinse, 1, 6);
    Screen0_LabelOptRinse->fn->setSize(Screen0_LabelOptRinse, 100, 42);
    Screen0_LabelOptRinse->fn->setScheme(Screen0_LabelOptRinse, &WhiteScheme);
    Screen0_LabelOptRinse->fn->setBackgroundType(Screen0_LabelOptRinse, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelOptRinse->fn->setString(Screen0_LabelOptRinse, (leString*)&string_XtraRinseOn);
    Screen0_ButtonWidget_Opt_rinse->fn->addChild(Screen0_ButtonWidget_Opt_rinse, (leWidget*)Screen0_LabelOptRinse);

    Screen0_ButtonWidget_Options = leButtonWidget_New();
    Screen0_ButtonWidget_Options->fn->setPosition(Screen0_ButtonWidget_Options, 488, 94);
    Screen0_ButtonWidget_Options->fn->setSize(Screen0_ButtonWidget_Options, 120, 50);
    Screen0_ButtonWidget_Options->fn->setBackgroundType(Screen0_ButtonWidget_Options, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Options->fn->setBorderType(Screen0_ButtonWidget_Options, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_Options->fn->setPressedImage(Screen0_ButtonWidget_Options, (leImage*)&green_but_down);
    Screen0_ButtonWidget_Options->fn->setReleasedImage(Screen0_ButtonWidget_Options, (leImage*)&green_but_up);
    Screen0_ButtonWidget_Options->fn->setReleasedEventCallback(Screen0_ButtonWidget_Options, event_Screen0_ButtonWidget_Options_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_Options);

    Screen0_ImageOption1 = leImageWidget_New();
    Screen0_ImageOption1->fn->setPosition(Screen0_ImageOption1, 0, 10);
    Screen0_ImageOption1->fn->setSize(Screen0_ImageOption1, 30, 30);
    Screen0_ImageOption1->fn->setBackgroundType(Screen0_ImageOption1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageOption1->fn->setBorderType(Screen0_ImageOption1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageOption1->fn->setImage(Screen0_ImageOption1, (leImage*)&Sound);
    Screen0_ButtonWidget_Options->fn->addChild(Screen0_ButtonWidget_Options, (leWidget*)Screen0_ImageOption1);

    Screen0_ImageOption2 = leImageWidget_New();
    Screen0_ImageOption2->fn->setPosition(Screen0_ImageOption2, 28, 10);
    Screen0_ImageOption2->fn->setSize(Screen0_ImageOption2, 30, 30);
    Screen0_ImageOption2->fn->setBackgroundType(Screen0_ImageOption2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageOption2->fn->setBorderType(Screen0_ImageOption2, LE_WIDGET_BORDER_NONE);
    Screen0_ImageOption2->fn->setImage(Screen0_ImageOption2, (leImage*)&rinse);
    Screen0_ButtonWidget_Options->fn->addChild(Screen0_ButtonWidget_Options, (leWidget*)Screen0_ImageOption2);

    Screen0_ImageOption3 = leImageWidget_New();
    Screen0_ImageOption3->fn->setPosition(Screen0_ImageOption3, 60, 10);
    Screen0_ImageOption3->fn->setSize(Screen0_ImageOption3, 30, 30);
    Screen0_ImageOption3->fn->setBackgroundType(Screen0_ImageOption3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageOption3->fn->setBorderType(Screen0_ImageOption3, LE_WIDGET_BORDER_NONE);
    Screen0_ImageOption3->fn->setImage(Screen0_ImageOption3, (leImage*)&preWash);
    Screen0_ButtonWidget_Options->fn->addChild(Screen0_ButtonWidget_Options, (leWidget*)Screen0_ImageOption3);

    Screen0_ImageOption4 = leImageWidget_New();
    Screen0_ImageOption4->fn->setPosition(Screen0_ImageOption4, 89, 10);
    Screen0_ImageOption4->fn->setSize(Screen0_ImageOption4, 30, 30);
    Screen0_ImageOption4->fn->setBackgroundType(Screen0_ImageOption4, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageOption4->fn->setBorderType(Screen0_ImageOption4, LE_WIDGET_BORDER_NONE);
    Screen0_ImageOption4->fn->setImage(Screen0_ImageOption4, (leImage*)&loadSize);
    Screen0_ButtonWidget_Options->fn->addChild(Screen0_ButtonWidget_Options, (leWidget*)Screen0_ImageOption4);

    Screen0_LabelOptSound = leLabelWidget_New();
    Screen0_LabelOptSound->fn->setPosition(Screen0_LabelOptSound, 1, 6);
    Screen0_LabelOptSound->fn->setSize(Screen0_LabelOptSound, 100, 42);
    Screen0_LabelOptSound->fn->setVisible(Screen0_LabelOptSound, LE_FALSE);
    Screen0_LabelOptSound->fn->setScheme(Screen0_LabelOptSound, &WhiteScheme);
    Screen0_LabelOptSound->fn->setBackgroundType(Screen0_LabelOptSound, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelOptSound->fn->setString(Screen0_LabelOptSound, (leString*)&string_SoundOn);
    Screen0_ButtonWidget_Options->fn->addChild(Screen0_ButtonWidget_Options, (leWidget*)Screen0_LabelOptSound);

    Screen0_ImageOptSound = leImageWidget_New();
    Screen0_ImageOptSound->fn->setPosition(Screen0_ImageOptSound, 86, 10);
    Screen0_ImageOptSound->fn->setSize(Screen0_ImageOptSound, 30, 30);
    Screen0_ImageOptSound->fn->setVisible(Screen0_ImageOptSound, LE_FALSE);
    Screen0_ImageOptSound->fn->setBackgroundType(Screen0_ImageOptSound, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageOptSound->fn->setBorderType(Screen0_ImageOptSound, LE_WIDGET_BORDER_NONE);
    Screen0_ImageOptSound->fn->setImage(Screen0_ImageOptSound, (leImage*)&SoundOn);
    Screen0_ButtonWidget_Options->fn->addChild(Screen0_ButtonWidget_Options, (leWidget*)Screen0_ImageOptSound);

    Screen0_ButtonWidget_Start = leButtonWidget_New();
    Screen0_ButtonWidget_Start->fn->setPosition(Screen0_ButtonWidget_Start, 662, 207);
    Screen0_ButtonWidget_Start->fn->setSize(Screen0_ButtonWidget_Start, 120, 50);
    Screen0_ButtonWidget_Start->fn->setScheme(Screen0_ButtonWidget_Start, &WhiteScheme);
    Screen0_ButtonWidget_Start->fn->setBackgroundType(Screen0_ButtonWidget_Start, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_Start->fn->setBorderType(Screen0_ButtonWidget_Start, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_Start->fn->setString(Screen0_ButtonWidget_Start, (leString*)&string_Start);
    Screen0_ButtonWidget_Start->fn->setPressedImage(Screen0_ButtonWidget_Start, (leImage*)&blue_but_down);
    Screen0_ButtonWidget_Start->fn->setReleasedImage(Screen0_ButtonWidget_Start, (leImage*)&blue_but_up);
    Screen0_ButtonWidget_Start->fn->setImagePosition(Screen0_ButtonWidget_Start, LE_RELATIVE_POSITION_BEHIND);
    Screen0_ButtonWidget_Start->fn->setReleasedEventCallback(Screen0_ButtonWidget_Start, event_Screen0_ButtonWidget_Start_OnReleased);
    root3->fn->addChild(root3, (leWidget*)Screen0_ButtonWidget_Start);

    leAddRootWidget(root3, 3);
    leSetLayerColorMode(3, LE_COLOR_MODE_RGBA_8888);

    // layer 4
    root4 = leWidget_New();
    root4->fn->setSize(root4, 800, 480);
    root4->fn->setBackgroundType(root4, LE_WIDGET_BACKGROUND_NONE);
    root4->fn->setMargins(root4, 0, 0, 0, 0);
    root4->flags |= LE_WIDGET_IGNOREEVENTS;
    root4->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget_screen2 = leWidget_New();
    Screen0_PanelWidget_screen2->fn->setPosition(Screen0_PanelWidget_screen2, 0, 0);
    Screen0_PanelWidget_screen2->fn->setSize(Screen0_PanelWidget_screen2, 800, 480);
    Screen0_PanelWidget_screen2->fn->setEnabled(Screen0_PanelWidget_screen2, LE_FALSE);
    Screen0_PanelWidget_screen2->fn->setScheme(Screen0_PanelWidget_screen2, &GreyScheme);
    root4->fn->addChild(root4, (leWidget*)Screen0_PanelWidget_screen2);

    Screen0_ImageWidget_background2 = leImageWidget_New();
    Screen0_ImageWidget_background2->fn->setPosition(Screen0_ImageWidget_background2, 0, 0);
    Screen0_ImageWidget_background2->fn->setSize(Screen0_ImageWidget_background2, 300, 480);
    Screen0_ImageWidget_background2->fn->setEnabled(Screen0_ImageWidget_background2, LE_FALSE);
    Screen0_ImageWidget_background2->fn->setBackgroundType(Screen0_ImageWidget_background2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_background2->fn->setBorderType(Screen0_ImageWidget_background2, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_background2->fn->setImage(Screen0_ImageWidget_background2, (leImage*)&Normal_cycle);
    root4->fn->addChild(root4, (leWidget*)Screen0_ImageWidget_background2);

    leAddRootWidget(root4, 4);
    leSetLayerColorMode(4, LE_COLOR_MODE_RGBA_8888);

    // layer 5
    root5 = leWidget_New();
    root5->fn->setSize(root5, 190, 45);
    root5->fn->setBackgroundType(root5, LE_WIDGET_BACKGROUND_NONE);
    root5->fn->setMargins(root5, 0, 0, 0, 0);
    root5->flags |= LE_WIDGET_IGNOREEVENTS;
    root5->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_LabelTime_2 = leLabelWidget_New();
    Screen0_LabelTime_2->fn->setPosition(Screen0_LabelTime_2, 0, 0);
    Screen0_LabelTime_2->fn->setSize(Screen0_LabelTime_2, 140, 30);
    Screen0_LabelTime_2->fn->setEnabled(Screen0_LabelTime_2, LE_FALSE);
    Screen0_LabelTime_2->fn->setVisible(Screen0_LabelTime_2, LE_FALSE);
    Screen0_LabelTime_2->fn->setScheme(Screen0_LabelTime_2, &BlueScheme);
    Screen0_LabelTime_2->fn->setBackgroundType(Screen0_LabelTime_2, LE_WIDGET_BACKGROUND_NONE);
    root5->fn->addChild(root5, (leWidget*)Screen0_LabelTime_2);

    Screen0_LabelColon2 = leLabelWidget_New();
    Screen0_LabelColon2->fn->setPosition(Screen0_LabelColon2, 32, 2);
    Screen0_LabelColon2->fn->setSize(Screen0_LabelColon2, 17, 25);
    Screen0_LabelColon2->fn->setEnabled(Screen0_LabelColon2, LE_FALSE);
    Screen0_LabelColon2->fn->setVisible(Screen0_LabelColon2, LE_FALSE);
    Screen0_LabelColon2->fn->setScheme(Screen0_LabelColon2, &BlueScheme);
    Screen0_LabelColon2->fn->setBackgroundType(Screen0_LabelColon2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelTime_2->fn->addChild(Screen0_LabelTime_2, (leWidget*)Screen0_LabelColon2);

    leAddRootWidget(root5, 5);
    leSetLayerColorMode(5, LE_COLOR_MODE_RGBA_8888);

    // layer 6
    root6 = leWidget_New();
    root6->fn->setSize(root6, 265, 245);
    root6->fn->setBackgroundType(root6, LE_WIDGET_BACKGROUND_NONE);
    root6->fn->setMargins(root6, 0, 0, 0, 0);
    root6->flags |= LE_WIDGET_IGNOREEVENTS;
    root6->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_ImageWidget_0 = leImageWidget_New();
    Screen0_ImageWidget_0->fn->setPosition(Screen0_ImageWidget_0, 0, 0);
    Screen0_ImageWidget_0->fn->setSize(Screen0_ImageWidget_0, 265, 245);
    Screen0_ImageWidget_0->fn->setEnabled(Screen0_ImageWidget_0, LE_FALSE);
    Screen0_ImageWidget_0->fn->setBackgroundType(Screen0_ImageWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_0->fn->setBorderType(Screen0_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0->fn->setImage(Screen0_ImageWidget_0, (leImage*)&r1);
    root6->fn->addChild(root6, (leWidget*)Screen0_ImageWidget_0);

    leAddRootWidget(root6, 6);
    leSetLayerColorMode(6, LE_COLOR_MODE_RGBA_8888);

    // layer 7
    root7 = leWidget_New();
    root7->fn->setSize(root7, 800, 480);
    root7->fn->setBackgroundType(root7, LE_WIDGET_BACKGROUND_NONE);
    root7->fn->setMargins(root7, 0, 0, 0, 0);
    root7->flags |= LE_WIDGET_IGNOREEVENTS;
    root7->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_ButtonWidget_pp = leButtonWidget_New();
    Screen0_ButtonWidget_pp->fn->setPosition(Screen0_ButtonWidget_pp, 743, 424);
    Screen0_ButtonWidget_pp->fn->setSize(Screen0_ButtonWidget_pp, 50, 50);
    Screen0_ButtonWidget_pp->fn->setEnabled(Screen0_ButtonWidget_pp, LE_FALSE);
    Screen0_ButtonWidget_pp->fn->setBackgroundType(Screen0_ButtonWidget_pp, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_pp->fn->setBorderType(Screen0_ButtonWidget_pp, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_pp->fn->setPressedImage(Screen0_ButtonWidget_pp, (leImage*)&r_pause);
    Screen0_ButtonWidget_pp->fn->setReleasedImage(Screen0_ButtonWidget_pp, (leImage*)&r_pause);
    Screen0_ButtonWidget_pp->fn->setReleasedEventCallback(Screen0_ButtonWidget_pp, event_Screen0_ButtonWidget_pp_OnReleased);
    root7->fn->addChild(root7, (leWidget*)Screen0_ButtonWidget_pp);

    Screen0_ButtonWidget_exit = leButtonWidget_New();
    Screen0_ButtonWidget_exit->fn->setPosition(Screen0_ButtonWidget_exit, 743, 6);
    Screen0_ButtonWidget_exit->fn->setSize(Screen0_ButtonWidget_exit, 50, 50);
    Screen0_ButtonWidget_exit->fn->setEnabled(Screen0_ButtonWidget_exit, LE_FALSE);
    Screen0_ButtonWidget_exit->fn->setBackgroundType(Screen0_ButtonWidget_exit, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ButtonWidget_exit->fn->setBorderType(Screen0_ButtonWidget_exit, LE_WIDGET_BORDER_NONE);
    Screen0_ButtonWidget_exit->fn->setPressedImage(Screen0_ButtonWidget_exit, (leImage*)&round_exit);
    Screen0_ButtonWidget_exit->fn->setReleasedImage(Screen0_ButtonWidget_exit, (leImage*)&round_exit);
    Screen0_ButtonWidget_exit->fn->setReleasedEventCallback(Screen0_ButtonWidget_exit, event_Screen0_ButtonWidget_exit_OnReleased);
    root7->fn->addChild(root7, (leWidget*)Screen0_ButtonWidget_exit);

    Screen0_ImageWidget_progress = leImageWidget_New();
    Screen0_ImageWidget_progress->fn->setPosition(Screen0_ImageWidget_progress, 368, 53);
    Screen0_ImageWidget_progress->fn->setSize(Screen0_ImageWidget_progress, 406, 372);
    Screen0_ImageWidget_progress->fn->setEnabled(Screen0_ImageWidget_progress, LE_FALSE);
    Screen0_ImageWidget_progress->fn->setBackgroundType(Screen0_ImageWidget_progress, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_progress->fn->setBorderType(Screen0_ImageWidget_progress, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_progress->fn->setImage(Screen0_ImageWidget_progress, (leImage*)&PreWash0);
    root7->fn->addChild(root7, (leWidget*)Screen0_ImageWidget_progress);

    Screen0_ImagePopUp = leImageWidget_New();
    Screen0_ImagePopUp->fn->setPosition(Screen0_ImagePopUp, 250, 190);
    Screen0_ImagePopUp->fn->setSize(Screen0_ImagePopUp, 300, 100);
    Screen0_ImagePopUp->fn->setVisible(Screen0_ImagePopUp, LE_FALSE);
    Screen0_ImagePopUp->fn->setBackgroundType(Screen0_ImagePopUp, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImagePopUp->fn->setBorderType(Screen0_ImagePopUp, LE_WIDGET_BORDER_NONE);
    Screen0_ImagePopUp->fn->setImage(Screen0_ImagePopUp, (leImage*)&pop_up);
    root7->fn->addChild(root7, (leWidget*)Screen0_ImagePopUp);

    Screen0_LabelCycleComplete = leLabelWidget_New();
    Screen0_LabelCycleComplete->fn->setPosition(Screen0_LabelCycleComplete, 0, 25);
    Screen0_LabelCycleComplete->fn->setSize(Screen0_LabelCycleComplete, 300, 50);
    Screen0_LabelCycleComplete->fn->setScheme(Screen0_LabelCycleComplete, &WhiteScheme);
    Screen0_LabelCycleComplete->fn->setBackgroundType(Screen0_LabelCycleComplete, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelCycleComplete->fn->setHAlignment(Screen0_LabelCycleComplete, LE_HALIGN_CENTER);
    Screen0_LabelCycleComplete->fn->setString(Screen0_LabelCycleComplete, (leString*)&string_cycle_complete);
    Screen0_ImagePopUp->fn->addChild(Screen0_ImagePopUp, (leWidget*)Screen0_LabelCycleComplete);

    leAddRootWidget(root7, 7);
    leSetLayerColorMode(7, LE_COLOR_MODE_RGBA_8888);

    Screen0_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);
    root3->fn->setSize(root3, root3->rect.width, root3->rect.height);
    root4->fn->setSize(root4, root4->rect.width, root4->rect.height);
    root5->fn->setSize(root5, root5->rect.width, root5->rect.height);
    root6->fn->setSize(root6, root6->rect.width, root6->rect.height);
    root7->fn->setSize(root7, root7->rect.width, root7->rect.height);
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_BackgroundPanel = NULL;
    Screen0_ImageWidget_background = NULL;
    Screen0_mhgsLogo = NULL;
    Screen0_RectangleWidget_0 = NULL;
    Screen0_RectangleWidget_1 = NULL;
    Screen0_RectangleWidget_2 = NULL;
    Screen0_RectangleWidget_3 = NULL;
    Screen0_LabelWidget_0 = NULL;
    Screen0_LabelWidget_1 = NULL;
    Screen0_LabelWidget_2 = NULL;
    Screen0_LabelWidget_3 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_LabelTime = NULL;
    Screen0_Label_colon = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    leRemoveRootWidget(root3, 3);
    leWidget_Delete(root3);
    root3 = NULL;

    Screen0_RectangleWidget_background_prog = NULL;
    Screen0_RectangleWidget_backgroundTemp = NULL;
    Screen0_RectangleWidget_backgroundSLevel = NULL;
    Screen0_RectangleWidget_backgroundOption = NULL;
    Screen0_ButtonWidget_t1 = NULL;
    Screen0_ButtonWidget_t2 = NULL;
    Screen0_ButtonWidget_t3 = NULL;
    Screen0_ButtonWidget_p1 = NULL;
    Screen0_ButtonWidget_p2 = NULL;
    Screen0_ButtonWidget_p3 = NULL;
    Screen0_ButtonWidget_p4 = NULL;
    Screen0_ButtonWidget_sl1 = NULL;
    Screen0_ButtonWidget_sl2 = NULL;
    Screen0_ButtonWidget_sl3 = NULL;
    Screen0_ButtonWidget_Opt_preWash = NULL;
    Screen0_ButtonWidget_Opt_LoadSize = NULL;
    Screen0_ButtonWidget_Opt_rinse = NULL;
    Screen0_ButtonWidget_Options = NULL;
    Screen0_ButtonWidget_Start = NULL;
    Screen0_Labelbuttont1 = NULL;
    Screen0_Imagebuttont1 = NULL;
    Screen0_Labelbuttont2 = NULL;
    Screen0_Imagebuttont2 = NULL;
    Screen0_Labelbuttont3 = NULL;
    Screen0_Imagebuttont3 = NULL;
    Screen0_Labelbuttonp1 = NULL;
    Screen0_Imagebuttonp1 = NULL;
    Screen0_Labelbuttonp2 = NULL;
    Screen0_Imagebuttonp2 = NULL;
    Screen0_Labelbuttonp3 = NULL;
    Screen0_Imagebuttonp3 = NULL;
    Screen0_Labelbuttonp4 = NULL;
    Screen0_Imagebuttonp4 = NULL;
    Screen0_Labelbutonsl1 = NULL;
    Screen0_Imagebuttonsl1 = NULL;
    Screen0_Labelbuttonsl2 = NULL;
    Screen0_Imagebuttonsl2 = NULL;
    Screen0_Labelbuttonsl3 = NULL;
    Screen0_Imagebuttonsl3 = NULL;
    Screen0_ImageOptPrewash = NULL;
    Screen0_LabelOptPrewash = NULL;
    Screen0_ImageOptLoadSize = NULL;
    Screen0_LabelOptLoadSize = NULL;
    Screen0_ImageOptRinse = NULL;
    Screen0_LabelOptRinse = NULL;
    Screen0_ImageOption1 = NULL;
    Screen0_ImageOption2 = NULL;
    Screen0_ImageOption3 = NULL;
    Screen0_ImageOption4 = NULL;
    Screen0_LabelOptSound = NULL;
    Screen0_ImageOptSound = NULL;

    leRemoveRootWidget(root4, 4);
    leWidget_Delete(root4);
    root4 = NULL;

    Screen0_PanelWidget_screen2 = NULL;
    Screen0_ImageWidget_background2 = NULL;

    leRemoveRootWidget(root5, 5);
    leWidget_Delete(root5);
    root5 = NULL;

    Screen0_LabelTime_2 = NULL;
    Screen0_LabelColon2 = NULL;

    leRemoveRootWidget(root6, 6);
    leWidget_Delete(root6);
    root6 = NULL;

    Screen0_ImageWidget_0 = NULL;

    leRemoveRootWidget(root7, 7);
    leWidget_Delete(root7);
    root7 = NULL;

    Screen0_ButtonWidget_pp = NULL;
    Screen0_ButtonWidget_exit = NULL;
    Screen0_ImageWidget_progress = NULL;
    Screen0_ImagePopUp = NULL;
    Screen0_LabelCycleComplete = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen0(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        case 1:
        {
            return root1;
        }
        case 2:
        {
            return root2;
        }
        case 3:
        {
            return root3;
        }
        case 4:
        {
            return root4;
        }
        case 5:
        {
            return root5;
        }
        case 6:
        {
            return root6;
        }
        case 7:
        {
            return root7;
        }
        default:
        {
            return NULL;
        }
    }
}

