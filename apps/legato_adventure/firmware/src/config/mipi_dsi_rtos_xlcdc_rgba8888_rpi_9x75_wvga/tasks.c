/*******************************************************************************
 System Tasks File

  File Name:
    tasks.c

  Summary:
    This file contains source code necessary to maintain system's polled tasks.

  Description:
    This file contains source code necessary to maintain system's polled tasks.
    It implements the "SYS_Tasks" function that calls the individual "Tasks"
    functions for all polled MPLAB Harmony modules in the system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    polled in the system.  These handles are passed into the individual module
    "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "definitions.h"
#include "sys_tasks.h"

//CUSTOM CODE - DO NOT REMOVE OR MODIFY ANYTHING IN THIS FILE!!!
#include <stdio.h>
#include "task.h"
//#define SHOW_RTOS_IDLE_TASK 1
//#ifdef RTOS_ENABLED
#define CLOCK_TICK_TIMER_PERIOD_MS 10
//#else
//#define CLOCK_TICK_TIMER_PERIOD_MS 30
//#endif
#define NUM_COUNT_SEC_TICK (1000/CLOCK_TICK_TIMER_PERIOD_MS)
enum
{
    APP_TASK_ID,
    LEGATO_TASK_ID,    
    MXT_TOUCH_TASK_ID,
    XLCDC_TASK_ID,
    SYS_INPUT_TASK_ID,
    CANVAS_TASK_ID,
#ifdef SHOW_RTOS_IDLE_TASK
    IDLE_TASK_ID,
#endif
    MAX_TASK_ID
};
volatile unsigned int tick_count = 0;
unsigned int tick_count_last = 0;
volatile unsigned int sec_count = 0;
int last_sec_count = 0;
unsigned int cpu_free = 0;
bool stats_enabled = 0;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
SemaphoreHandle_t xSemaPhoreCPU = NULL;
typedef struct
{
    TaskHandle_t handle;
    char * name;
    uint32_t lastCount;
    uint32_t count;
} APP_TASK_STRUCT_t;
static enum
{
    TASK_INIT=0,
    TASK_RUN,
}TaskState;
APP_TASK_STRUCT_t tasks[MAX_TASK_ID] = 
{
    [MXT_TOUCH_TASK_ID] = 
    {
        .name = "Touch Task",
    },
    [XLCDC_TASK_ID] = 
    {
        .name = "Display Task",
    },
    [LEGATO_TASK_ID] = 
    {
        .name = "GFX Task",
    },
    [SYS_INPUT_TASK_ID] = 
    {
        .name = "Input Task",
    },
    [APP_TASK_ID] = {
        .name = "User IDLE Task",
    },
    [CANVAS_TASK_ID] = {
        .name = "GFX Canvas Task",
    },
#ifdef SHOW_RTOS_IDLE_TASK    
    [IDLE_TASK_ID] = {
        .name = "RTOS IDLE Task",
    },
#endif
};
extern uint32_t leGetScratchBufferSizeKB(void);
void RTOS_AppConfigureTimerForRuntimeStats()
{
    //do nothing
    tick_count = 0;
}
uint32_t RTOS_AppGetRuntimeCounterValue(void)
{
    return tick_count;
}
static void Timer_Callback ( uintptr_t context)
{
    tick_count++;
    
    if (tick_count % NUM_COUNT_SEC_TICK == 0)
    {
        sec_count++;
    }
}
unsigned int Task_Usage(void)
{
    static uint32_t ulLastTotalTime = 0;
    unsigned int i = 0;
    uint32_t ulTotalTime;
    uint32_t pctRunTime;
    TaskStatus_t xTaskDetails;
    uint32_t app_usage = 0;
#ifdef SHOW_RTOS_IDLE_TASK        
    tasks[IDLE_TASK_ID].handle = xTaskGetIdleTaskHandle();
#endif    
    
    //gather the new total time
    for (i = 0; i < MAX_TASK_ID; i++)
    {
        // Use the handle to obtain further information about the task.
        vTaskGetInfo( tasks[i].handle,
                      &xTaskDetails,
                      pdTRUE, // Include the high water mark in xTaskDetails.
                      eInvalid ); // Include the task state in xTaskDetails.
        tasks[i].count = xTaskDetails.ulRunTimeCounter;
    }
//    printf("\n\r........................................... \n\r");
//    printf("Task Usage \t%%   @ %u fps, %ukB sBuff\n\r", 
//                fps, 
//                (unsigned int) leGetScratchBufferSizeKB());
//    printf("........................................... \n\r");
    
    ulTotalTime = portGET_RUN_TIME_COUNTER_VALUE(); /* get total time passed in system */
    
    for (i = 0; i < MAX_TASK_ID; i++)
    {
        pctRunTime = (((tasks[i].count - tasks[i].lastCount) * 100)/(ulTotalTime - ulLastTotalTime));
        pctRunTime = (pctRunTime > 100) ? 100 : pctRunTime;
        
        if (pctRunTime > 0)
        {
//            printf("%.20s \t%u",
//                    tasks[i].name,
//                    (unsigned int) pctRunTime);
        }
        else
        {
//            printf("%.20s \t<1",
//                    tasks[i].name);
        }
        tasks[i].lastCount = tasks[i].count;
        
        if (i == APP_TASK_ID)
        {
            app_usage = pctRunTime;
//            printf(" (free) \n\r");
        }
        else
        {
//            printf("\n\r");
        }
    }
    
    ulLastTotalTime = ulTotalTime;
    
    return app_usage;
            
}
//END OF CUSTOM CODE

// *****************************************************************************
// *****************************************************************************
// Section: RTOS "Tasks" Routine
// *****************************************************************************
// *****************************************************************************
void _LEGATO_Tasks(  void *pvParameters  )
{
    while(1)
    {
        Legato_Tasks();
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

void _GFX_CANVAS_Task(  void *pvParameters  )
{
    while(1)
    {
        GFX_CANVAS_Task();
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

void _SYS_INPUT_Tasks(  void *pvParameters  )
{
    while(1)
    {
        SYS_INP_Tasks();
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

void _XLCDC_Tasks(  void *pvParameters  )
{
    while(1)
    {
        DRV_XLCDC_Update();
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

void _DISP_RPi_Tasks(  void *pvParameters  )
{
    while(1)
    {
        DISP_RPi_Update();
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}

/* Handle for the APP_Tasks. */
TaskHandle_t xAPP_Tasks;

static void lAPP_Tasks(  void *pvParameters  )
{   
    while(true)
    {
        switch(TaskState)
        {
            case TASK_INIT:
            {
                timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, CLOCK_TICK_TIMER_PERIOD_MS, SYS_TIME_PERIODIC);
                stats_enabled = true;
                //xSemaPhoreCPU = xSemaphoreCreateBinary();
                TaskState = TASK_RUN;
                break;
            }
            case TASK_RUN:
            {
                static unsigned int sec_count_last;              

                if (stats_enabled == true && 
                    sec_count != sec_count_last)
                {

                            cpu_free = Task_Usage();
                            sec_count_last = sec_count;

                }
                if(sec_count != last_sec_count)
                {
                    //printf("\n\r %u percent",100 - cpu_free);
                    last_sec_count = sec_count;
                }
                break;
            }
        }
    }
}




// *****************************************************************************
// *****************************************************************************
// Section: System "Tasks" Routine
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SYS_Tasks ( void )

  Remarks:
    See prototype in system/common/sys_module.h.
*/
void SYS_Tasks ( void )
{
    /* Maintain system services */
    

    /* Maintain Device Drivers */
        xTaskCreate( _GFX_CANVAS_Task,
        "GFX_CANVAS_Tasks",
        1024,
        (void*)NULL,
        3,
        (TaskHandle_t*)&tasks[CANVAS_TASK_ID]
    );


    xTaskCreate( _XLCDC_Tasks,
        "XLCDC_Tasks",
        1024,
        (void*)NULL,
        2,
        (TaskHandle_t*)&tasks[XLCDC_TASK_ID]
    );



    /* Maintain Middleware & Other Libraries */
    
    xTaskCreate( _LEGATO_Tasks,
        "LEGATO_Tasks",
        1024,
        (void*)NULL,
        2,
        (TaskHandle_t*)&tasks[LEGATO_TASK_ID]
    );


    xTaskCreate( _SYS_INPUT_Tasks,
        "SYS_INPUT_Tasks",
        1024,
        (void*)NULL,
        2,
        (TaskHandle_t*)&tasks[SYS_INPUT_TASK_ID]
    );


    xTaskCreate( _DISP_RPi_Tasks,
        "DISP_RPi_Tasks",
        1024,
        (void*)NULL,
        3,
        (TaskHandle_t*)&tasks[MXT_TOUCH_TASK_ID]
    );



    /* Maintain the application's state machine. */
        /* Create OS Thread for APP_Tasks. */
    (void) xTaskCreate((TaskFunction_t) lAPP_Tasks,
                "APP_Tasks",
                1024,
                NULL,
                1,
                (TaskHandle_t*)&tasks[APP_TASK_ID]);




    /* Start RTOS Scheduler. */
    
     /**********************************************************************
     * Create all Threads for APP Tasks before starting FreeRTOS Scheduler *
     ***********************************************************************/
    vTaskStartScheduler(); /* This function never returns. */

}

/*******************************************************************************
 End of File
 */

