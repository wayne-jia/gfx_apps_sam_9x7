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
#include "fonts/fonts.h"
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
uint32_t color_map[] =
    {
        0x00000000,
        0x333333FF,
        0xFF0000FF,
        0xFF8000FF,
        0x00FF00FF,
        0x80FF00FF,
        0x0000FFFF,
        0x0180FFFF,
        0xFF01FD84,
        0xFFFF00FF,
        0x01FEFDFF,
        0x8200FDFF,
        0xFD01FCFF,
        0xFE017FFF,
        0x030003FF,
        0x060307FF,
        0x080808FF,
        0x090909FF,
        0x0E0C0FFF,
        0x100D10FF,
        0x111111FF,
        0x151515FF,
        0x161616FF,
        0x1A1A1AFF,
        0x1B1B1BFF,
        0x1F1F21FF,
        0x060307FF,
        0x0E0C0FFF,
        0x1A1A1AFF,
        0x343436FF,
        0x4D4A4EFF,
        0x686568FF,
        0x7F7D80FF,
        0x9A979BFF,
        0xB4B1B4FF,
        0xCDCBCEFF,
        0xE7E4E7FF,
        0xFFFFFFFF,
};
const size_t color_max = sizeof(color_map) / sizeof(color_map[0]) - 1;
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

void draw_pixel(uint32_t x, uint32_t y, uint32_t color)
{
    if (x < appData.width && y < appData.height)
    {
        appData.buffer[y * appData.width + x] = color;
    }
}

void draw_line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color)
{
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx - dy, e2;

    while (1)
    {
        draw_pixel(x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_circle(uint32_t x, uint32_t y, uint32_t r, uint32_t color, bool fill)
{
    int32_t d = 3 - (r << 1);
    uint32_t cx = 0, cy = r;

    while (cx <= cy)
    {
        if (fill)
        {
            draw_line(x - cx, y - cy, x + cx, y - cy, color);
            draw_line(x - cx, y + cy, x + cx, y + cy, color);
            draw_line(x - cy, y - cx, x + cy, y - cx, color);
            draw_line(x - cy, y + cx, x + cy, y + cx, color);
        }
        else
        {
            draw_pixel(x + cx, y + cy, color);
            draw_pixel(x + cx, y - cy, color);
            draw_pixel(x - cx, y + cy, color);
            draw_pixel(x - cx, y - cy, color);
            draw_pixel(x + cy, y + cx, color);
            draw_pixel(x + cy, y - cx, color);
            draw_pixel(x - cy, y + cx, color);
            draw_pixel(x - cy, y - cx, color);
        }
        if (d < 0)
        {
            d += (cx << 2) + 6;
        }
        else
        {
            d += ((cx - cy) << 2) + 10;
            cy--;
        }
        cx++;
    }
}

void draw_rect_fill(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color)
{
    for (uint32_t y = y1; y <= y2; y++)
    {
        for (uint32_t x = x1; x <= x2; x++)
        {
            draw_pixel(x, y, color);
        }
    }
}

uint32_t draw_char(uint32_t x, uint32_t y, char ascii_char, font_size_alias_t font_size, uint32_t color)
{
    font_t font;
    get_font(ascii_char, font_size, &font);
    uint32_t bytes_per_row = font.data_len / font.height;

    for (int i = 0; i < font.height; i++)
    {
        for (int j = 0; j < bytes_per_row; j++)
        {
            uint32_t line = font.data[i * bytes_per_row + j];
            for (int k = 0; k < 8; k++)
            {
                if (line & (0x80 >> k))
                {
                    draw_pixel(x + j * 8 + k, y + i, color);
                }
            }
        }
    }
    return font.width;
}

uint32_t draw_string(uint32_t x, uint32_t y, const char *str, font_size_alias_t font_size, uint32_t color)
{
    uint32_t nx = x;
    while (*str)
    {
        nx += draw_char(nx, y, *str++, font_size, color) + 1;
    }
    return nx - x;
}

uint32_t get_gradient(uint32_t start_color, uint32_t end_color, uint32_t current_step, uint32_t total_steps)
{
    uint32_t result = 0;
    for (int i = 0; i < 4; i++)
    {
        uint8_t start = (start_color >> (8 * i)) & 0xFF;
        uint8_t end = (end_color >> (8 * i)) & 0xFF;
        uint8_t grad = start + (end - start) * current_step / total_steps;
        result |= (uint32_t)grad << (8 * i);
    }
    return result;
}

void draw_test_pattern(uint32_t width, uint32_t height)
{
    int x_div = (width < 800) ? 10 : 16;
    int y_div = 9;
    int str_width = draw_string(0, 0, "Blank Quickstart", FONT_BASE, 0);

    // Draw grid lines
    for (int i = 0; i <= x_div; i++)
    {
        int x = (width - 1) * i / x_div;
        draw_line(x, 0, x, height - 1, color_map[1]);
    }
    for (int i = 0; i <= y_div; i++)
    {
        int y = (height - 1) * i / y_div;
        draw_line(0, y, width - 1, y, color_map[1]);
    }

    // Draw center circle
    draw_circle(width / 2 - 1, height / 2 - 1, height / 2, color_map[1], false);

    // Draw corner circles
    int r = (width - 1) / x_div;
    for (int x = 1; x < x_div; x += x_div - 2)
    {
        for (int y = 1; y < y_div; y += y_div - 2)
        {
            int cx = (width - 1) * x / x_div;
            int cy = (height - 1) * y / y_div;
            draw_circle(cx, cy, r, color_map[1], false);
            draw_circle(cx, cy, r / 3, color_map[color_max], true);
        }
    }

    // Draw central rectangle and text
    int x1 = (width - 1) / x_div;
    int y1 = (height - 1) / y_div;
    int x2 = (width - 1) * (x_div - 1) / x_div;
    int y2 = (height - 1) * (y_div - 1) / y_div;
    draw_rect_fill(x1 * 2 + 2, y1 * 2 + 1, x2 - x1 - 2, y2 - y1 - 1, 0);
    x1 = ((x1 * 2 + 2) + x2 - x1 - 2) / 2;
    draw_string(x1 - str_width / 2, y2 - y1 + y1 / 2.75f, "Blank Quickstart", FONT_BASE, color_map[color_max]);

    // Draw color bars
    char tmp[16];
    for (int i = 2; i < x_div - 2; i++)
    {
        int cx = (width - 1) * i / x_div;
        int y_offset = (height - 1) / y_div;

        draw_rect_fill(cx + 2, y_offset * 2 + 2, cx + r - 1, y_offset * 3 - 2, color_map[i]);
        draw_rect_fill(cx + 2, y_offset * 3 + 2, cx + r - 1, y_offset * 4 - 2, color_map[i + 12]);
        draw_rect_fill(cx + 2, y_offset * 4 + 2, cx + r - 1, y_offset * 5 - 2, color_map[i + 24]);

        snprintf(tmp, sizeof(tmp), "%d%%", i - 1);
        draw_string(cx + 4, y_offset * 3 + 4, tmp, FONT_SM, color_map[color_max]);

        if (i == 2)
            snprintf(tmp, sizeof(tmp), "2%%");
        else if (i == 3)
            snprintf(tmp, sizeof(tmp), "5%%");
        else
            snprintf(tmp, sizeof(tmp), "%d%%", (i - 3) * 10);
        draw_string(cx + 4, y_offset * 4 + 4, tmp, FONT_SM, (i < 7) ? 0xFFFFFFFF : 0);
    }

    // Draw gradient bars
    x1 = (width - 1) * 2 / x_div + 2;
    x2 = (width - 1) * (x_div - 2) / x_div - 2;
    int mid = (x1 + x2) / 2;

    for (int j = 0; j < 3; j++)
    {
        y1 = (height - 1) * (5 + j * 0.667) / y_div + 2;
        y2 = (height - 1) * (5.667 + j * 0.667) / y_div - 2;

        for (int i = x1; i <= mid; i++)
        {
            draw_line(i, y1, i, y2, get_gradient(color_map[0], color_map[2 + 2 * j], i - x1, (x2 - x1) / 2));
        }
        for (int i = mid + 1; i <= x2; i++)
        {
            draw_line(i, y1, i, y2, get_gradient(color_map[2 + 2 * j], color_map[color_max], i - mid, (x2 - x1) / 2));
        }
    }
}

void init_touch_map(uint32_t width, uint32_t height)
{
    int x_div = (width < 800) ? 10 : 16;
    int y_div = 9;

    appData.touch_map[0].x1 = 0;
    appData.touch_map[0].y1 = 0;
    appData.touch_map[0].x2 = (width - 1) * 2 / x_div;
    appData.touch_map[0].y2 = (height - 1) * 2 / y_div;

    appData.touch_map[1].x1 = 0;
    appData.touch_map[1].y1 = (height - 1) * 7 / y_div;
    appData.touch_map[1].x2 = (width - 1) * 2 / x_div;
    appData.touch_map[1].y2 = height - 1;

    appData.touch_map[2].x1 = (width - 1) * (x_div - 2) / x_div;
    appData.touch_map[2].y1 = 0;
    appData.touch_map[2].x2 = width - 1;
    appData.touch_map[2].y2 = (height - 1) * 2 / y_div;

    appData.touch_map[3].x1 = (width - 1) * (x_div - 2) / x_div;
    appData.touch_map[3].y1 = (height - 1) * 7 / y_div;
    appData.touch_map[3].x2 = width - 1;
    appData.touch_map[3].y2 = height - 1;
}

void touchDownHandler(const SYS_INP_TouchStateEvent *const evt)
{
    for (int i = 0; i < 4; i++)
    {
        if (evt->x > appData.touch_map[i].x1 &&
            evt->x < appData.touch_map[i].x2 &&
            evt->y > appData.touch_map[i].y1 &&
            evt->y < appData.touch_map[i].y2)
        {
            draw_circle((appData.touch_map[i].x1 + appData.touch_map[i].x2) / 2,
                        (appData.touch_map[i].y1 + appData.touch_map[i].y2) / 2,
                        (appData.touch_map[0].x1 + appData.touch_map[0].x2) / 6,
                        color_map[4], true);
        }
    }
    LED_GREEN_On();
}

void touchUpHandler(const SYS_INP_TouchStateEvent *const evt)
{
    LED_GREEN_Off();
    LED_BLUE_Off();
}

void touchMoveHandler(const SYS_INP_TouchMoveEvent *const evt)
{
    LED_BLUE_On();
}

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize(void)
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    memset(&appData, 0, sizeof(appData));
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void)
{
    /* Check the application's current state. */
    switch (appData.state)
    {
    /* Application's initial state. */
    case APP_STATE_INIT:
    {
        SYS_INP_InputListener appInputListener;
        gfxIOCTLArg_DisplaySize argDispSize;
        gfxIOCTLArg_Value argVal;
        bool appInitialized = true;

        if (appInitialized)
        {
            // Register the input event handlers
            appInputListener.handleTouchDown = &touchDownHandler;
            appInputListener.handleTouchUp = &touchUpHandler;
            appInputListener.handleTouchMove = &touchMoveHandler;
            SYS_INP_AddListener(&appInputListener);

            // Fetch display parameters
            if ((DRV_XLCDC_IOCTL(GFX_IOCTL_GET_DISPLAY_SIZE, &argDispSize) == GFX_IOCTL_OK) &&
                (DRV_XLCDC_IOCTL(GFX_IOCTL_GET_FRAMEBUFFER, &argVal) == GFX_IOCTL_OK))
            {
                appData.width = argDispSize.width;
                appData.height = argDispSize.height;
                appData.buffer = argVal.value.v_pbuffer->pixels;
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            else
            {
                appData.state = APP_STATE_ERROR;
            }
        }
        break;
    }

    case APP_STATE_SERVICE_TASKS:
    {
        draw_test_pattern(appData.width, appData.height);
        init_touch_map(appData.width, appData.height);

        appData.state = APP_STATE_IDLE;
        break;
    }

    case APP_STATE_IDLE:
    {
        break;
    }

    case APP_STATE_ERROR:
    {
        break;
    }

    default:
    {
        break;
    }
    }
}

/*******************************************************************************
 End of File
 */
