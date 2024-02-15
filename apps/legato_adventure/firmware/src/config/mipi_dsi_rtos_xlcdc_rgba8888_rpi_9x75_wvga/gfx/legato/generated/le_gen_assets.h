/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.


  Description:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.

*******************************************************************************/


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C)  Microchip Technology Inc. and its subsidiaries.
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

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

extern const lePalette leGlobalPalette;

/*****************************************************************************
 * Legato Graphics Asset Location IDs
 *****************************************************************************/
/*********************************
 * Legato Asset Memory Location
 * Name:          DDR
 ***********************************/
#define LE_STREAM_LOCATION_ID_DDR    1

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   back
 * Size:   1082x480 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage back;

/*********************************
 * Legato Image Asset
 * Name:   middle
 * Size:   1354x480 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage middle;

/*********************************
 * Legato Image Asset
 * Name:   cherry
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage cherry;

/*********************************
 * Legato Image Asset
 * Name:   apricot
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage apricot;

/*********************************
 * Legato Image Asset
 * Name:   melon
 * Size:   32x32 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage melon;

/*********************************
 * Legato Image Asset
 * Name:   bee_0
 * Size:   37x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bee_0;

/*********************************
 * Legato Image Asset
 * Name:   bee_1
 * Size:   37x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bee_1;

/*********************************
 * Legato Image Asset
 * Name:   bee_2
 * Size:   37x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bee_2;

/*********************************
 * Legato Image Asset
 * Name:   bee_3
 * Size:   37x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bee_3;

/*********************************
 * Legato Image Asset
 * Name:   bee_4
 * Size:   37x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bee_4;

/*********************************
 * Legato Image Asset
 * Name:   bee_5
 * Size:   37x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bee_5;

/*********************************
 * Legato Image Asset
 * Name:   bee_6
 * Size:   37x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bee_6;

/*********************************
 * Legato Image Asset
 * Name:   bee_7
 * Size:   37x39 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bee_7;

/*********************************
 * Legato Image Asset
 * Name:   transparent_fg
 * Size:   188x266 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage transparent_fg;

/*********************************
 * Legato Image Asset
 * Name:   legatoLib
 * Size:   250x50 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage legatoLib;

/*********************************
 * Legato Image Asset
 * Name:   logo1
 * Size:   100x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage logo1;

/*********************************
 * Legato Image Asset
 * Name:   logo2
 * Size:   100x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage logo2;

/*********************************
 * Legato Image Asset
 * Name:   logo3
 * Size:   100x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage logo3;

/*********************************
 * Legato Image Asset
 * Name:   logo4
 * Size:   100x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage logo4;

/*********************************
 * Legato Image Asset
 * Name:   logo5
 * Size:   100x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage logo5;

/*********************************
 * Legato Image Asset
 * Name:   logo6
 * Size:   100x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage logo6;

/*********************************
 * Legato Image Asset
 * Name:   hud1
 * Size:   108x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage hud1;

/*********************************
 * Legato Image Asset
 * Name:   hud2
 * Size:   108x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage hud2;

/*********************************
 * Legato Image Asset
 * Name:   hud3
 * Size:   108x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage hud3;

/*********************************
 * Legato Image Asset
 * Name:   hud4
 * Size:   108x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage hud4;

/*********************************
 * Legato Image Asset
 * Name:   pause
 * Size:   30x30 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage pause;

/*********************************
 * Legato Image Asset
 * Name:   play
 * Size:   30x30 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage play;

/*********************************
 * Legato Image Asset
 * Name:   headerImage
 * Size:   400x100 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage headerImage;

/*********************************
 * Legato Image Asset
 * Name:   bottom
 * Size:   1487x120 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage bottom;

/*********************************
 * Legato Image Asset
 * Name:   dead1
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage dead1;

/*********************************
 * Legato Image Asset
 * Name:   dead2
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage dead2;

/*********************************
 * Legato Image Asset
 * Name:   dead3
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage dead3;

/*********************************
 * Legato Image Asset
 * Name:   dead4
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage dead4;

/*********************************
 * Legato Image Asset
 * Name:   dizzy0
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage dizzy0;

/*********************************
 * Legato Image Asset
 * Name:   dizzy1
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage dizzy1;

/*********************************
 * Legato Image Asset
 * Name:   dizzy2
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage dizzy2;

/*********************************
 * Legato Image Asset
 * Name:   empty
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage empty;

/*********************************
 * Legato Image Asset
 * Name:   idle0
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage idle0;

/*********************************
 * Legato Image Asset
 * Name:   idle1
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage idle1;

/*********************************
 * Legato Image Asset
 * Name:   idle2
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage idle2;

/*********************************
 * Legato Image Asset
 * Name:   idle3
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage idle3;

/*********************************
 * Legato Image Asset
 * Name:   jump0
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump0;

/*********************************
 * Legato Image Asset
 * Name:   jump1
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump1;

/*********************************
 * Legato Image Asset
 * Name:   jump2
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump2;

/*********************************
 * Legato Image Asset
 * Name:   jump3
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump3;

/*********************************
 * Legato Image Asset
 * Name:   jump4
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump4;

/*********************************
 * Legato Image Asset
 * Name:   jump5
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump5;

/*********************************
 * Legato Image Asset
 * Name:   jump6
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump6;

/*********************************
 * Legato Image Asset
 * Name:   jump7
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump7;

/*********************************
 * Legato Image Asset
 * Name:   run0
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage run0;

/*********************************
 * Legato Image Asset
 * Name:   run1
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage run1;

/*********************************
 * Legato Image Asset
 * Name:   run2
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage run2;

/*********************************
 * Legato Image Asset
 * Name:   idle_left0
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage idle_left0;

/*********************************
 * Legato Image Asset
 * Name:   idle_left1
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage idle_left1;

/*********************************
 * Legato Image Asset
 * Name:   idle_left2
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage idle_left2;

/*********************************
 * Legato Image Asset
 * Name:   idle_left3
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage idle_left3;

/*********************************
 * Legato Image Asset
 * Name:   jump_left0
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump_left0;

/*********************************
 * Legato Image Asset
 * Name:   jump_left1
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump_left1;

/*********************************
 * Legato Image Asset
 * Name:   jump_left2
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump_left2;

/*********************************
 * Legato Image Asset
 * Name:   jump_left3
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump_left3;

/*********************************
 * Legato Image Asset
 * Name:   jump_left4
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump_left4;

/*********************************
 * Legato Image Asset
 * Name:   jump_left5
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump_left5;

/*********************************
 * Legato Image Asset
 * Name:   jump_left6
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump_left6;

/*********************************
 * Legato Image Asset
 * Name:   jump_left7
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage jump_left7;

/*********************************
 * Legato Image Asset
 * Name:   run_left0
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage run_left0;

/*********************************
 * Legato Image Asset
 * Name:   run_left1
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage run_left1;

/*********************************
 * Legato Image Asset
 * Name:   run_left2
 * Size:   192x267 pixels
 * Type:   RGB Data
 * Format: RGBA_8888
 ***********************************/
extern leImage run_left2;

/*********************************
 * Legato Image Asset
 * Name:   cpu
 * Size:   90x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage cpu;

/*********************************
 * Legato Image Asset
 * Name:   num0
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num0;

/*********************************
 * Legato Image Asset
 * Name:   num1
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num1;

/*********************************
 * Legato Image Asset
 * Name:   num2
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num2;

/*********************************
 * Legato Image Asset
 * Name:   num3
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num3;

/*********************************
 * Legato Image Asset
 * Name:   num4
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num4;

/*********************************
 * Legato Image Asset
 * Name:   num5
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num5;

/*********************************
 * Legato Image Asset
 * Name:   num6
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num6;

/*********************************
 * Legato Image Asset
 * Name:   num7
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num7;

/*********************************
 * Legato Image Asset
 * Name:   num8
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num8;

/*********************************
 * Legato Image Asset
 * Name:   num9
 * Size:   20x20 pixels
 * Type:   RGB Data
 * Format: RGB_888
 ***********************************/
extern leImage num9;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular
 * Height:       21
 * Baseline:     27
 * Style:        Antialias
 * Glyph Count:  95
 * Range Count:  8
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont NotoSans_Regular;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   3
 *****************************************************************************/

// language IDs
#define language_Default    0

// string IDs
#define stringID_Smart    0
#define stringID_Fast    1
#define stringID_Easy    2

extern const leStringTable stringTable;


// string list
extern leTableString string_Smart;
extern leTableString string_Fast;
extern leTableString string_Easy;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
