#include "gfx/legato/generated/screen/le_gen_screen_Screen1.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;

leWidget* Screen1_Panel_0;
leImageWidget* Screen1_LegatoLogo;
leImageWidget* Screen1_legatoLib;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen1(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen1(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 1600, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 1600, 480);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 800, 480);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    Screen1_Panel_0 = leWidget_New();
    Screen1_Panel_0->fn->setPosition(Screen1_Panel_0, 0, 0);
    Screen1_Panel_0->fn->setSize(Screen1_Panel_0, 800, 480);
    Screen1_Panel_0->fn->setScheme(Screen1_Panel_0, &RedScheme);
    root2->fn->addChild(root2, (leWidget*)Screen1_Panel_0);

    Screen1_LegatoLogo = leImageWidget_New();
    Screen1_LegatoLogo->fn->setPosition(Screen1_LegatoLogo, 350, 140);
    Screen1_LegatoLogo->fn->setBackgroundType(Screen1_LegatoLogo, LE_WIDGET_BACKGROUND_NONE);
    Screen1_LegatoLogo->fn->setBorderType(Screen1_LegatoLogo, LE_WIDGET_BORDER_NONE);
    Screen1_Panel_0->fn->addChild(Screen1_Panel_0, (leWidget*)Screen1_LegatoLogo);

    Screen1_legatoLib = leImageWidget_New();
    Screen1_legatoLib->fn->setPosition(Screen1_legatoLib, 275, 275);
    Screen1_legatoLib->fn->setSize(Screen1_legatoLib, 250, 60);
    Screen1_legatoLib->fn->setVisible(Screen1_legatoLib, LE_FALSE);
    Screen1_legatoLib->fn->setBackgroundType(Screen1_legatoLib, LE_WIDGET_BACKGROUND_NONE);
    Screen1_legatoLib->fn->setBorderType(Screen1_legatoLib, LE_WIDGET_BORDER_NONE);
    Screen1_legatoLib->fn->setImage(Screen1_legatoLib, (leImage*)&legatoLib);
    Screen1_Panel_0->fn->addChild(Screen1_Panel_0, (leWidget*)Screen1_legatoLib);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGBA_8888);

    Screen1_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen1(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
    root1->fn->setSize(root1, root1->rect.width, root1->rect.height);
    root2->fn->setSize(root2, root2->rect.width, root2->rect.height);

    Screen1_OnUpdate(); // raise event
}

void screenHide_Screen1(void)
{
    Screen1_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    Screen1_Panel_0 = NULL;
    Screen1_LegatoLogo = NULL;
    Screen1_legatoLib = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen1(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen1(uint32_t lyrIdx)
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
        default:
        {
            return NULL;
        }
    }
}

