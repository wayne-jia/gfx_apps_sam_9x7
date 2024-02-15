/*******************************************************************************
  MPLAB Harmony Application Splash Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_Splash.c

  Summary:
    This file contains the source code for the demo splash screen.

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

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "gfx/legato/generated/le_gen_init.h"
#include "definitions.h"

#define DELAY_IN_TICKS       1
#define SPLASH_ALPHA_DELTA  75

#define SPLASH_CANVAS 2
#define SPLASH_LAYER 2

static uint32_t splashAlpha;
static uint32_t barPosX;
static uint32_t triggerTick;
static uint32_t currentTick;
static uint32_t delayCount;

static SYS_TIME_HANDLE DelayMS;

imgSeq Logo[6];

static enum
{
    SCREEN_SETUP = 0,
    SCREEN_UPDATE_LOGO,
    SCREEN_SWAP_LOGO_ALPHA,
    SCREEN_SHOW_STRING,
    SCREEN_END_DELAY,
    SCREEN_DONE
} screenState;

static void LogoSprite()
{
    Logo[0].img = &logo1;
    Logo[1].img = &logo2;
    Logo[2].img = &logo3;
    Logo[3].img = &logo4;
    Logo[4].img = &logo5;
    Logo[5].img = &logo6;
}

static void SplashSetup()
{
    LogoSprite();
    gfxcSetLayer(SPLASH_CANVAS, SPLASH_LAYER);
    gfxcSetWindowSize(SPLASH_CANVAS, 800, 480);    
    gfxcShowCanvas(SPLASH_CANVAS);  
    gfxcCanvasUpdate(SPLASH_CANVAS);
    
    screenState = SCREEN_UPDATE_LOGO;
}

static bool UpdateLogoCanvas()
{
    static uint8_t logoCount = 0;
    
    if(logoCount < 25)
    {
        // if(logoCount < 5)
        // {
        // Screen1_LegatoLogo->fn->setImage(Screen1_LegatoLogo, Logo[logoCount].img);
        // gfxcCanvasUpdate(SPLASH_CANVAS);
        // ++logoCount;
        // return true;
        // }                
        // else
        {
        Screen1_LegatoLogo->fn->setImage(Screen1_LegatoLogo, Logo[logoCount % 5].img);
        gfxcCanvasUpdate(SPLASH_CANVAS);
        ++logoCount;
        return true;
        }
    }
    Screen1_LegatoLogo->fn->setImage(Screen1_LegatoLogo, Logo[5].img);
    return false;
        
}


void Screen1_OnShow()
{
    splashAlpha = 255;        
    barPosX = 480;
    
    screenState = SCREEN_SETUP;
}

void Screen1_OnHide()
{
}

void Screen1_OnUpdate()
{
    switch (screenState)
    {
        case SCREEN_SETUP:
        {
            if(leRenderer_IsIdle() &&
               leEvent_GetCount() == 0)
            {
                SplashSetup();
            }
            SYS_TIME_DelayMS(1, &DelayMS);
            break;
        }
        case SCREEN_UPDATE_LOGO:
        {
            if(SYS_TIME_DelayIsComplete(DelayMS))
            {
                SYS_TIME_DelayMS(100, &DelayMS);
                if(!UpdateLogoCanvas())
                {
                    screenState = SCREEN_SHOW_STRING;
                    SYS_TIME_DelayMS(500, &DelayMS);
                }
            }
            
            break;
        }
        case SCREEN_SWAP_LOGO_ALPHA:
        {
            //Do Nothing
            
            break;                    
        }

        case SCREEN_SHOW_STRING:
        {
            if(SYS_TIME_DelayIsComplete(DelayMS))                    
            {
                Screen1_legatoLib->fn->setVisible(Screen1_legatoLib, true);
                screenState = SCREEN_END_DELAY;
                SYS_TIME_DelayMS(2000, &DelayMS);
            }

            break;
        }
        case SCREEN_END_DELAY:            
        {
            if(SYS_TIME_DelayIsComplete(DelayMS))
            {
                legato_showScreen(screenID_Screen0);
                //gfxcDestroy(SPLASH_CANVAS);
                screenState = SCREEN_DONE;
            }

            break;
        }
        case SCREEN_DONE:
        default:
            break;
    }
}

/*******************************************************************************
 End of File
 */
