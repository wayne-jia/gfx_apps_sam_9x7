/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "gfx/canvas/gfx_canvas_api.h"
#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************


#define IncPosXBack 3
#define IncPosXMiddle 4
#define IncPosXFront 554

int backPosX = 0, backPosY = 0;
int middlePosX = 0, middlePosY = 0;
int frontPosX = 0, frontPosY = 0;
int16_t MidlayerThres = -677; 

leWidgetEventFilter touchEventReceiver;

bool moveLayerAnimation = false;
bool layerMoveDirection = false;

bool backgroundAnimDone = false;
bool middleAnimDone = false;
bool topAnimDone = false;

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void APP_Scene_EffectsCallback(unsigned int canvasID,
                                GFXC_FX_TYPE effect,
                                GFXC_FX_STATUS status,
                                void * parm)
{
    switch (canvasID)
    {
        case BACKGROUND_CANVAS_ID:
            backgroundAnimDone = (status == GFXC_FX_DONE) ? true : false;
            break;
        case 1:
            middleAnimDone = (status == GFXC_FX_DONE) ? true : false;
            break;
        case 2:
            topAnimDone = (status == GFXC_FX_DONE) ? true : false;
            break;
        default:
            break;
    }
}

void appSetLayerFrame(uint32_t layerID, 
                      uint32_t addr,
                      uint32_t width,
                      uint32_t height,
                      int32_t x,
                      int32_t y)
{
    gfxcSetPixelBuffer(layerID,
                       width,
                       height,
                       GFX_COLOR_MODE_RGBA_8888,
                       (void *) addr);
    
    gfxcSetWindowPosition(layerID, x, y);
    gfxcSetWindowSize(layerID, width, height);
    gfxcCanvasUpdate(layerID);
    //if(layerID == 3 || layerID == 4)
        
}

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{    
    //Do Nothing
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Tasks()
{
    //Do Nothing
}
/******************************************************************************/

void APP_ParallaxTasks ( uintptr_t context )
{

    /* Check the application's current state. */
    static uint16_t posY = 0, i=0;
    
    //Poll the layer anim for parallax scrolling
    if(!moveLayerAnimation)
        return;
    
    switch ( appData.state )
    {
        /* Application's initial state. */
        case INIT_ANIM:
        {
            appData.state = PAUSE_ANIM;
            break;
        }
            
        case BACK_ANIM:
        {
            //bool appInitialized = true;
            

            if (!layerMoveDirection)
            {
                if((backPosX - IncPosXBack) >= -282)
                {
                
                    gfxcStartEffectMove(0,
                        GFXC_FX_MOVE_FIXED,
                        backPosX,
                        backPosY,
                        backPosX - IncPosXBack,
                        posY,
                        1);                

                    backPosX -= IncPosXBack;
                    i++;
                    appData.state = MIDDLE_ANIM;
                }                
                else
                {
                    backPosX = 0;
                    i = 0;
                }
                break;
            }
            else
            {
                if((backPosX + IncPosXBack) <= 0)
                {
                
                    gfxcStartEffectMove(0,
                        GFXC_FX_MOVE_FIXED,
                        backPosX,
                        backPosY,
                        backPosX + IncPosXBack,
                        posY,
                        1);               

                    backPosX += IncPosXBack;
                    i++;
                    appData.state = MIDDLE_ANIM;
                }
                else
                {
                    backPosX = -282;
                    i = 0;
                }
                break;
              
                 break;
            }              
        }

        case MIDDLE_ANIM:
        {
            if(!layerMoveDirection)
            {
                if((middlePosX - IncPosXMiddle) >= MidlayerThres)
                {
                    gfxcStartEffectMove(1,
                        GFXC_FX_MOVE_FIXED,
                        middlePosX,
                        middlePosY,
                        middlePosX - IncPosXMiddle,
                        posY,
                        2);
                    middlePosX -= IncPosXMiddle;
                    appData.state = BACK_ANIM;
                }
                else
                {
                    middlePosX = 0;
                }
                break;
            }
            else
            {
                if((middlePosX + IncPosXMiddle) <= 0)
                {
                    gfxcStartEffectMove(1,
                        GFXC_FX_MOVE_FIXED,
                        middlePosX,
                        middlePosY,
                        middlePosX + IncPosXMiddle,
                        posY,
                        2);
                    middlePosX += IncPosXMiddle;
                    appData.state = BACK_ANIM;
                }
                else
                {
                    middlePosX = MidlayerThres;
                }
                break;
            }
        }

        case FRONT_ANIM:
        {
//            if(middleAnimDone)
            {
                if((frontPosX - IncPosXFront >= -700))
                {
                
                    gfxcStartEffectMove(2,
                            GFXC_FX_MOVE_FIXED,
                            frontPosX,
                            frontPosY,
                            frontPosX - IncPosXFront,
                            posY,
                            3);
                    frontPosX -= IncPosXFront;
                    appData.state = BACK_ANIM;
                }
                else
                {
                    frontPosX = 0;  
                }
                break;
            }
                    
        }
        case PAUSE_ANIM:
        {
            if(!moveLayerAnimation)
                break;
            appData.state = BACK_ANIM;
        }
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
