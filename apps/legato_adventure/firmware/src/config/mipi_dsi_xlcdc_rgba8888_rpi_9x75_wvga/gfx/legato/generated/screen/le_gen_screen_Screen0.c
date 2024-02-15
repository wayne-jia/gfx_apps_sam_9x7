#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;
static leWidget* root1;
static leWidget* root2;
static leWidget* root3;

leImageWidget* Screen0_ImageWidget_1;
leImageWidget* Screen0_ImageWidget_0;
leImageWidget* Screen0_ImageWidget_2;
leImageWidget* Screen0_ImageWidget_3;

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
    root0->fn->setSize(root0, 1600, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_ImageWidget_1 = leImageWidget_New();
    Screen0_ImageWidget_1->fn->setPosition(Screen0_ImageWidget_1, 0, 0);
    Screen0_ImageWidget_1->fn->setSize(Screen0_ImageWidget_1, 1082, 480);
    Screen0_ImageWidget_1->fn->setBackgroundType(Screen0_ImageWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_1->fn->setBorderType(Screen0_ImageWidget_1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_1->fn->setImage(Screen0_ImageWidget_1, (leImage*)&back);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget_1);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 1600, 480);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_ImageWidget_0 = leImageWidget_New();
    Screen0_ImageWidget_0->fn->setPosition(Screen0_ImageWidget_0, 0, 0);
    Screen0_ImageWidget_0->fn->setSize(Screen0_ImageWidget_0, 1354, 480);
    Screen0_ImageWidget_0->fn->setBackgroundType(Screen0_ImageWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_0->fn->setBorderType(Screen0_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0->fn->setImage(Screen0_ImageWidget_0, (leImage*)&middle);
    root1->fn->addChild(root1, (leWidget*)Screen0_ImageWidget_0);

    Screen0_ImageWidget_2 = leImageWidget_New();
    Screen0_ImageWidget_2->fn->setPosition(Screen0_ImageWidget_2, 0, 370);
    Screen0_ImageWidget_2->fn->setSize(Screen0_ImageWidget_2, 1487, 110);
    Screen0_ImageWidget_2->fn->setBackgroundType(Screen0_ImageWidget_2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_2->fn->setBorderType(Screen0_ImageWidget_2, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_2->fn->setImage(Screen0_ImageWidget_2, (leImage*)&bottom);
    root1->fn->addChild(root1, (leWidget*)Screen0_ImageWidget_2);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_RGBA_8888);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 1600, 480);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_ImageWidget_3 = leImageWidget_New();
    Screen0_ImageWidget_3->fn->setPosition(Screen0_ImageWidget_3, 0, 0);
    Screen0_ImageWidget_3->fn->setSize(Screen0_ImageWidget_3, 800, 480);
    Screen0_ImageWidget_3->fn->setBackgroundType(Screen0_ImageWidget_3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_3->fn->setBorderType(Screen0_ImageWidget_3, LE_WIDGET_BORDER_NONE);
    root2->fn->addChild(root2, (leWidget*)Screen0_ImageWidget_3);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_RGBA_8888);

    // layer 3
    root3 = leWidget_New();
    root3->fn->setSize(root3, 1600, 480);
    root3->fn->setBackgroundType(root3, LE_WIDGET_BACKGROUND_NONE);
    root3->fn->setMargins(root3, 0, 0, 0, 0);
    root3->flags |= LE_WIDGET_IGNOREEVENTS;
    root3->flags |= LE_WIDGET_IGNOREPICK;

    leAddRootWidget(root3, 3);
    leSetLayerColorMode(3, LE_COLOR_MODE_RGBA_8888);

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

    Screen0_OnUpdate(); // raise event
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_ImageWidget_1 = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    Screen0_ImageWidget_0 = NULL;
    Screen0_ImageWidget_2 = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    Screen0_ImageWidget_3 = NULL;

    leRemoveRootWidget(root3, 3);
    leWidget_Delete(root3);
    root3 = NULL;


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
        default:
        {
            return NULL;
        }
    }
}

