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
#include "peripheral/pio/plib_pio.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/
uint32_t __attribute__ ((section(".region_nocache"), aligned (32))) fbgpudemo[800 *480] = { 0 };

void gpu_demo(void)
{
    //GPU fill color bar example
    gfxPixelBuffer buf;
    buf.pixel_count = 800 * 480;
    buf.size.width = 800;
    buf.size.height = 480;
    buf.mode = GFX_COLOR_MODE_RGBA_8888;
    buf.buffer_length = 800 * 480 * 4;
    buf.flags = 0;
    buf.pixels = (gfxBuffer)fbgpudemo;
    buf.orientation = GFX_ORIENT_0;
    memset(fbgpudemo, 0x00, sizeof(fbgpudemo));  //Set background to black color

    XLCDC_SetLayerEnable(BASE_LAYER, false, true);
    XLCDC_SetLayerAddress(BASE_LAYER, (uint32_t)fbgpudemo, false);
    XLCDC_SetLayerOpts(BASE_LAYER, 255, true, false);
    XLCDC_SetLayerWindowXYPos(BASE_LAYER, 0, 0, false);
    XLCDC_SetLayerWindowXYSize(BASE_LAYER, 800, 480, false);
    XLCDC_SetLayerEnable(BASE_LAYER, true, true);

    gfxRect drawRect;
    drawRect.x = 0;
    drawRect.y = 0;
    drawRect.width = 100;
    drawRect.height = 480;
    DRV_GFX2D_Fill(&buf, &drawRect, 0xFF000000); //RED
    
    drawRect.x = 100;
    DRV_GFX2D_Fill(&buf, &drawRect, 0x00FF0000); //GREEN

    drawRect.x = 200;
    DRV_GFX2D_Fill(&buf, &drawRect, 0x0000FF00); //BLUE

    drawRect.x = 300;
    DRV_GFX2D_Fill(&buf, &drawRect, 0xFFFFFF00); //WHITE
    
    drawRect.x = 400;
    DRV_GFX2D_Fill(&buf, &drawRect, 0xFFFF0000); //YELLOW

    drawRect.x = 500;
    DRV_GFX2D_Fill(&buf, &drawRect, 0xFF00FF00); //PINK


    //GPU blit example
    gfxPixelBuffer srcBuf;
    srcBuf.pixel_count = 174 * 40;
    srcBuf.size.width = 174;
    srcBuf.size.height = 40;
    srcBuf.mode = GFX_COLOR_MODE_RGBA_8888;
    srcBuf.buffer_length = 174 * 40 * 4;
    srcBuf.flags = 0;
    srcBuf.pixels = (void*)Image0.buffer.pixels;
    srcBuf.orientation = GFX_ORIENT_0;

    gfxRect srcRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.width = 174;
    srcRect.height = 40;

    gfxRect destRect;
    destRect.x = 620;
    destRect.y = 80;
    destRect.width = 174;
    destRect.height = 40;

    DRV_GFX2D_Blit(&srcBuf, &srcRect, &buf, &destRect);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */



void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}



/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            // START OF CUSTOM CODE
            static bool once = true;
            
            if(once)
            {
                /* Enable AC69T88A Display Backlight */
                AC69T88A_BACKLIGHT_EN_Set();
                gpu_demo();
                once = false;
            }
            // END OF CUSTOM CODE
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
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
