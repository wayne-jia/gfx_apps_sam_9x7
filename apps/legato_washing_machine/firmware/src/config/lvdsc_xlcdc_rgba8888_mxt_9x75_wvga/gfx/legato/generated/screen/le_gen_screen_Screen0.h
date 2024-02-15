#ifndef LE_GEN_SCREEN_SCREEN0_H
#define LE_GEN_SCREEN_SCREEN0_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen0_BackgroundPanel;
extern leImageWidget* Screen0_ImageWidget_background;
extern leImageWidget* Screen0_mhgsLogo;
extern leRectangleWidget* Screen0_RectangleWidget_0;
extern leRectangleWidget* Screen0_RectangleWidget_1;
extern leRectangleWidget* Screen0_RectangleWidget_2;
extern leRectangleWidget* Screen0_RectangleWidget_3;
extern leLabelWidget* Screen0_LabelWidget_0;
extern leLabelWidget* Screen0_LabelWidget_1;
extern leLabelWidget* Screen0_LabelWidget_2;
extern leLabelWidget* Screen0_LabelWidget_3;
extern leLabelWidget* Screen0_LabelTime;
extern leLabelWidget* Screen0_Label_colon;
extern leRectangleWidget* Screen0_RectangleWidget_background_prog;
extern leRectangleWidget* Screen0_RectangleWidget_backgroundTemp;
extern leRectangleWidget* Screen0_RectangleWidget_backgroundSLevel;
extern leRectangleWidget* Screen0_RectangleWidget_backgroundOption;
extern leButtonWidget* Screen0_ButtonWidget_t1;
extern leButtonWidget* Screen0_ButtonWidget_t2;
extern leButtonWidget* Screen0_ButtonWidget_t3;
extern leButtonWidget* Screen0_ButtonWidget_p1;
extern leButtonWidget* Screen0_ButtonWidget_p2;
extern leButtonWidget* Screen0_ButtonWidget_p3;
extern leButtonWidget* Screen0_ButtonWidget_p4;
extern leButtonWidget* Screen0_ButtonWidget_sl1;
extern leButtonWidget* Screen0_ButtonWidget_sl2;
extern leButtonWidget* Screen0_ButtonWidget_sl3;
extern leButtonWidget* Screen0_ButtonWidget_Opt_preWash;
extern leButtonWidget* Screen0_ButtonWidget_Opt_LoadSize;
extern leButtonWidget* Screen0_ButtonWidget_Opt_rinse;
extern leButtonWidget* Screen0_ButtonWidget_Options;
extern leButtonWidget* Screen0_ButtonWidget_Start;
extern leLabelWidget* Screen0_Labelbuttont1;
extern leImageWidget* Screen0_Imagebuttont1;
extern leLabelWidget* Screen0_Labelbuttont2;
extern leImageWidget* Screen0_Imagebuttont2;
extern leLabelWidget* Screen0_Labelbuttont3;
extern leImageWidget* Screen0_Imagebuttont3;
extern leLabelWidget* Screen0_Labelbuttonp1;
extern leImageWidget* Screen0_Imagebuttonp1;
extern leLabelWidget* Screen0_Labelbuttonp2;
extern leImageWidget* Screen0_Imagebuttonp2;
extern leLabelWidget* Screen0_Labelbuttonp3;
extern leImageWidget* Screen0_Imagebuttonp3;
extern leLabelWidget* Screen0_Labelbuttonp4;
extern leImageWidget* Screen0_Imagebuttonp4;
extern leLabelWidget* Screen0_Labelbutonsl1;
extern leImageWidget* Screen0_Imagebuttonsl1;
extern leLabelWidget* Screen0_Labelbuttonsl2;
extern leImageWidget* Screen0_Imagebuttonsl2;
extern leLabelWidget* Screen0_Labelbuttonsl3;
extern leImageWidget* Screen0_Imagebuttonsl3;
extern leImageWidget* Screen0_ImageOptPrewash;
extern leLabelWidget* Screen0_LabelOptPrewash;
extern leImageWidget* Screen0_ImageOptLoadSize;
extern leLabelWidget* Screen0_LabelOptLoadSize;
extern leImageWidget* Screen0_ImageOptRinse;
extern leLabelWidget* Screen0_LabelOptRinse;
extern leImageWidget* Screen0_ImageOption1;
extern leImageWidget* Screen0_ImageOption2;
extern leImageWidget* Screen0_ImageOption3;
extern leImageWidget* Screen0_ImageOption4;
extern leLabelWidget* Screen0_LabelOptSound;
extern leImageWidget* Screen0_ImageOptSound;
extern leWidget* Screen0_PanelWidget_screen2;
extern leImageWidget* Screen0_ImageWidget_background2;
extern leLabelWidget* Screen0_LabelTime_2;
extern leLabelWidget* Screen0_LabelColon2;
extern leImageWidget* Screen0_ImageWidget_0;
extern leButtonWidget* Screen0_ButtonWidget_pp;
extern leButtonWidget* Screen0_ButtonWidget_exit;
extern leImageWidget* Screen0_ImageWidget_progress;
extern leImageWidget* Screen0_ImagePopUp;
extern leLabelWidget* Screen0_LabelCycleComplete;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen0_ButtonWidget_t1_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_t2_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_t3_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_p1_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_p2_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_p3_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_p4_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_sl1_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_sl2_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_sl3_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_Opt_preWash_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_Opt_LoadSize_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_Opt_rinse_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_Options_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_Start_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_pp_OnReleased(leButtonWidget* btn);
void event_Screen0_ButtonWidget_exit_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen0(void); // called when Legato is initialized
leResult screenShow_Screen0(void); // called when screen is shown
void screenHide_Screen0(void); // called when screen is hidden
void screenDestroy_Screen0(void); // called when Legato is destroyed
void screenUpdate_Screen0(void); // called when Legato is updating

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen0_OnShow(void); // called when this screen is shown

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN0_H
