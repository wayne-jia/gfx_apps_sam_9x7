/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
typedef enum{
  Normal=1,
  Sports,
  Wool,
  Bedding,
}Prog_load;

typedef enum{
    Warm,
    Cold,
    Hot,
}Temp_load;

typedef enum{
    Medium,
    High,
    Low,
}SLevel_load;

enum buttonTracker{
    Program,
    Temperature,
    SLevel,
    Options,       
};
enum progMenuTracker{
    pbClose,
    pbOpen,
};
enum tempMenuTracker{
    tbClose,
    tbOpen,

};
enum soilMenuTracker{
    sbClose,
    sbOpen,

};

enum optionMenuTracker{
    Close,
    Open,
    Closing,
};

typedef enum {
    SCREEN0=0,
    SCREEN1,
} CURRENT_SCREEN;

typedef struct
{
    bool sound;
    bool xrinse;
    bool preWash;
    bool loadSizeHigh;
  
} LOAD_OPTIONS_STATUS;

typedef struct
{
    bool prog;
    bool temp;
    bool slevel;
    bool opts;
    uint8_t activeCount;
} MENUS_STATUS;


// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_STATE_INIT=0,
    APP_STATE_SERVICE_TASKS,
    APP_STATE_SCREEN2_POPUP,
    APP_STATE_SWITCH_SCREEN,
    /* TODO: Define states used by the application state machine. */

} APP_STATES;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_STATES state;
    CURRENT_SCREEN screen;
} APP_DATA;

/*CANVAS ID*/
/*SCREEN 1*/
#define BACKGROUND1_CANVAS_ID 0
#define TIME1_CANVAS_ID 1
#define WAVES_CANVAS_ID 2
#define MENU_CANVAS_ID 3
/*SCREEN2*/
#define BACKGROUND2_CANVAS_ID 4
#define TIME2_CANVAS_ID 5
#define ROUND_CANVAS_ID 6
#define TOP_CANVAS_ID 7



/****************************************/
/*LAYER ID*/
#define BASE_LAYER_ID 0
#define TIME_LAYER_ID 1
#define SECOND_LAYER_ID 2
#define HEO_LAYER_ID 3

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks( void );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */

/*******************************************************************************
 End of File
 */

