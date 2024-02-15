/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    screen_splash.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "SCREEN_SPLASH_Initialize" and "SCREEN_SPLASH_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "SCREEN_SPLASH_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _SCREEN_SPLASH_H
#define _SCREEN_SPLASH_H

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
#define SCREEN_SPLASH_Initialize()
#define SCREEN_SPLASH_Tasks()
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
    SCREEN_SPLASH_STATE_INIT=0,
    SCREEN_SPLASH_STATE_SERVICE_TASKS,
    /* TODO: Define states used by the application state machine. */

} SCREEN_SPLASH_STATES;


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
    SCREEN_SPLASH_STATES state;

    /* TODO: Define any additional data used by the application. */

} SCREEN_SPLASH_DATA;

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
    void SCREEN_SPLASH_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    SCREEN_SPLASH_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    SCREEN_SPLASH_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

//void SCREEN_SPLASH_Initialize ( void );


/*******************************************************************************
  Function:
    void SCREEN_SPLASH_Tasks ( void )

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
    SCREEN_SPLASH_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

//void SCREEN_SPLASH_Tasks( void );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _SCREEN_SPLASH_H */

/*******************************************************************************
 End of File
 */

