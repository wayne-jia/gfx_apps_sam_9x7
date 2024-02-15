/* ************************************************************************** */
/** Descriptive File Name

  Company:
    Microchip Technology Inc.

  File Name:
    screen_MainEF.c

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
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include <stdio.h>
#include "definitions.h"
#include "gfx/canvas/gfx_canvas.h"
#include "gfx/canvas/gfx_canvas_api.h"
#include "gfx/driver/controller/xlcdc/plib/plib_xlcdc.h"
#include "gfx/driver/controller/xlcdc/drv_gfx_xlcdc.h"
#include "gfx/legato/generated/le_gen_init.h"
#include <stdio.h>
#include <string.h>
#include "system/time/sys_time.h"


#define APP_SPRITE_STEP_X  2
#define APP_SPRITE_OFFSET 8
#define APP_IDLE_SPRITE_DELAY 20
#define APP_JUMP_SPRITE_DELAY 12
#define APP_HURT_SPRITE_DELAY 40
#define APP_RUN_SPRITE_DELAY 15
#define APP_DEAD_SPRITE_DELAY 75
#define SPRITE_WIDTH 168
#define SPRITE_HEIGHT 135
#define HIT_OFFSET -2
#define JUMP_OFFSET  20
#define RUN_OFFSET  4
#define HURT_OFFSET  -2
#define INIT_POSX  50
#define INIT_POSY  122
#define INIT_YOFFSET 130
#define SCENE_RIGHT_END 800
#define SCENE_RIGHT_START 0
#define SCENE_HIT_SPRITE 5
#define SCENE_OFFSET 10
#define SCENE_Y_MAX 140
#define SCENE_Y_MIN 260
#define SCENE_HEIGHT(a,b) (PROP_HEIGHT(((assetPosition[a]) >> (b)) & (1)))
#define PROP_HEIGHT(x) ((x == (1)) ? SCENE_Y_MAX : SCENE_Y_MIN)
//static int8_t inc = -1;
//#define LIMIT_ITER() ( inc = (((++inc) < 6) && ((inc) != -1)) ? inc : 0)

#define HEADER_CANVAS_ID 2
#define HEADER_LAYER_ID 2
#define HEADER_WIDTH 700
#define HEADER_HEIGHT 150
#define HEADER_XPOS 100
#define HEADER_YPOS 40

//int32_t spriteIndex = 0;
int32_t spritePosX;
int32_t spritePosY;
int32_t triggerCount = 0;
int32_t tickDelay = APP_IDLE_SPRITE_DELAY;

static uint8_t hurtCount = 0;

imgSeq idleSprite[4];
imgSeq runSprite[3];
imgSeq jumpSprite[8];
imgSeq hurtSprite[3];
imgSeq deadSprite[4];

imgSeq * currentSprite;
imgSeq * previousSprite;

static imgSeq OnesDigitNum[10];
static imgSeq TensDigitNum[10];

union Scene
{
    imgSeq SceneProps[11];
    struct 
    {
        imgSeq Cherry;
        imgSeq Apricot;
        imgSeq Melon;
        imgSeq Bee[8];
    }param;
}sceneProperties, previousProperties;

int32_t APP_SPRITE_ANCHOR_MIN = 50;
int32_t APP_SPRITE_ANCHOR_MAX = 320;

int32_t APP_SPRITE_ANCHOR_MIN_LEFT = 310;
int32_t APP_SPRITE_ANCHOR_MAX_LEFT = 580;

int32_t APP_SPRITE_ANCHOR_MAX_JUMP = 440;

static enum JUMPOFFSETS
{
    JUMPOFFSET0 = 164,
    JUMPOFFSET1 = 128,
    JUMPOFFSET2 = 80,
    JUMPOFFSET3 = 42,
    JUMPOFFSET4 = 36,
    JUMPOFFSET5 = 68,
    JUMPOFFSET6 = 142,
    JUMPOFFSET7 = 174
};
static enum JUMPOFFSETS jumpOffSet[8] = {JUMPOFFSET0, JUMPOFFSET1, JUMPOFFSET2, JUMPOFFSET3, JUMPOFFSET4, JUMPOFFSET5, JUMPOFFSET6, JUMPOFFSET7};

static SYS_INP_InputListener app_inputListener;
static int inputListenerID = 0;
 uint8_t spriteCount = 0;
 
static bool directionChange = false;
static bool sceneMake = false;
static bool spriteHurt = false;
static bool spriteDead = false;

static SYS_TIME_HANDLE handleAnimation = SYS_TIME_HANDLE_INVALID;
static SYS_TIME_HANDLE handleLocomotion = SYS_TIME_HANDLE_INVALID;
static SYS_TIME_HANDLE CustomDelay = SYS_TIME_HANDLE_INVALID;
static SYS_TIME_HANDLE handleParallax = SYS_TIME_HANDLE_INVALID;

APP_DATA appData;
static uint8_t OnesDigit = 0, TensDigit = 0;

uint8_t assetPosition[6] = {0b1000,0b1110,0b0111,0b1010,0b1001,0b1011};

///custom functions
static gfxRect srcRect, destRect;
//GFXC_CANVAS canvas[3];
static GFXC_RESULT FillCanvasTransparent(unsigned int canvID)
{
    gfxRect canvRect;
    canvRect.x = 0;
    canvRect.y = 0;
    canvRect.width = 800;
    canvRect.height = 480;
    
    DRV_GFX2D_Fill(&canvas[canvID].pixelBuffer, &canvRect, 0x00000000);
    
    return GFX_SUCCESS;
}
static GFXC_RESULT _CustomClearImagefromCanvas(unsigned int destID,
                         const leImage * source,
                         const gfxRect * srcRect,
                         const gfxRect * destRect)
{
    void* srcPtr;
    void* destPtr;
    uint32_t row, rowSize; 
    
    if (canvas[destID].pixelBuffer.mode != (gfxColorMode)source->buffer.mode ||
            srcRect->height != destRect->height ||
            srcRect->width != destRect->width)
        return GFX_FAILURE;
    
    rowSize = source->buffer.size.width * 
              gfxColorInfoTable[source->buffer.mode].size;
    //memset(&canvas[destID].pixelBuffer.pixels, (int)0x00, (canvas[destID].pixelBuffer.size.width * canvas[destID].pixelBuffer.size.height * gfxColorInfoTable[canvas[destID].pixelBuffer.mode].size));
    for(row = 0; row < source->buffer.size.height; row++)
    {
        srcPtr = lePixelBufferOffsetGet(&transparent_fg.buffer, 
                                          srcRect->x, srcRect->y + row);
        destPtr = gfxPixelBufferOffsetGet(&canvas[destID].pixelBuffer,
                                          destRect->x, destRect->y + row);

        memcpy(destPtr, srcPtr, rowSize);
        //DRV_GFX2D_Fill(&canvas[destID].pixelBuffer, destRect, 0);
        //memset(destPtr, (int)0x00, rowSize);
        
    }
    
    return GFX_SUCCESS;
        
    
}

static GFXC_RESULT ClearImageFromCanvas(unsigned int canvID,
                    const leImage * srcImg,
                    int32_t x,
                    int32_t y)
{
    gfxPixelBuffer_SetLocked(&canvas[canvID].pixelBuffer, GFX_TRUE);
    canvas[canvID].active = GFX_FALSE;
    
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.height = srcImg->buffer.size.height;
    srcRect.width = srcImg->buffer.size.width;

    destRect.x = x;
    destRect.y = y;
    destRect.height = srcImg->buffer.size.height;
    destRect.width = srcImg->buffer.size.width;
    
    //memset(&canvas[canvID].pixelBuffer.pixels, 0x00, sizeof(canvas[canvID].pixelBuffer.pixels) );

    _CustomClearImagefromCanvas(canvID, srcImg, &srcRect, &destRect);    
    gfxPixelBuffer_SetLocked(&canvas[canvID].pixelBuffer, GFX_FALSE);
    canvas[canvID].active = GFX_TRUE;    
    
    return GFX_SUCCESS;    
} 

//custom function for copying image to foreground buffer which inturn to be utilized in canvas

static GFXC_RESULT _CustomCopyImagetoCanvas(unsigned int destID,
                         const leImage * source,
                         const gfxRect * srcRect,
                         const gfxRect * destRect)
{
    void* srcPtr;
    void* destPtr;
    uint32_t row, rowSize; 
    
    if (canvas[destID].pixelBuffer.mode != (gfxColorMode)source->buffer.mode ||
            srcRect->height != destRect->height ||
            srcRect->width != destRect->width)
        return GFX_FAILURE;
    
    rowSize = source->buffer.size.width * 
              gfxColorInfoTable[source->buffer.mode].size;

    for(row = 0; row < source->buffer.size.height; row++)
    {
        srcPtr = lePixelBufferOffsetGet(&source->buffer, 
                                          srcRect->x, srcRect->y + row);
        destPtr = gfxPixelBufferOffsetGet(&canvas[destID].pixelBuffer,
                                          destRect->x, destRect->y + row);

        memcpy(destPtr, srcPtr, rowSize);
    }
    
    return GFX_SUCCESS;
        
}

static GFXC_RESULT CopyImagetoCanvas(unsigned int canvID,
                    const leImage * srcImg,
                    int32_t x,
                    int32_t y)
{
    gfxPixelBuffer_SetLocked(&canvas[canvID].pixelBuffer, GFX_TRUE);
    canvas[canvID].active = GFX_FALSE;
    
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.height = srcImg->buffer.size.height;
    srcRect.width = srcImg->buffer.size.width;

    destRect.x = x;
    destRect.y = y;
    destRect.height = srcImg->buffer.size.height;
    destRect.width = srcImg->buffer.size.width;
    
    //memset(&canvas[canvID].pixelBuffer.pixels, 0x00, sizeof(canvas[canvID].pixelBuffer.pixels) );

    _CustomCopyImagetoCanvas(canvID, srcImg, &srcRect, &destRect);
    gfxPixelBuffer_SetLocked(&canvas[canvID].pixelBuffer, GFX_FALSE);
    canvas[canvID].active = GFX_TRUE;
    
    return GFX_SUCCESS;
}
///end of custom functions

static int32_t ScenePosition(int32_t  x )
{
    return (x-2);
}
static uint8_t limitInc()
{
    static int itr = 0, inc = 0;
    
    if(itr == 4)
    {
        itr = 1;
        if((inc + 1) < 6)
        {
             ++inc;
        }
        else
        {
            inc = 0;
        }
    }
    else
        ++itr;
    
    return inc;
    
}


static enum
{
    SCREEN_INIT = 0,
    SCREEN_INIT_SPRITE,
    SCREEN_HEADER,
    SCREEN_HEADER_WAIT,
    SCREEN_RUNNING,
    SCREEN_RESTART,
    SCREEN_RESTART_WAIT,
} screenState;

static enum
{
    FACE_RIGHT = 0,
    FACE_LEFT,
} spriteFacing;

static enum
{
    IDLE = 0,
    RUN,
    HURT,
    DEAD,
    JUMP
} spriteState;

static enum
{
    RAMP_LOW = 2,
    RAMP_HIGH = 1
    
}
spriteRamp;

static enum
{
    CherryApricotMelonBee = 0,
    BeeMelonApricotCherry,
    ApricotBeeMelonCherry
}sceneOrder;

static void populateBee(int32_t xx, int32_t yy, uint8_t hit)
{
    int i = 0;
    for(i;i<8;i++)
    {
        sceneProperties.param.Bee[i].x = xx;
        sceneProperties.param.Bee[i].y = yy;
        sceneProperties.param.Bee[i].hit = hit;
    }
}

static void populateAssets(int32_t xx, int32_t yy, uint8_t hit)
{
    int i = 0;
    for(i;i<3;i++)
    {
        sceneProperties.SceneProps[i].x = xx;
        sceneProperties.SceneProps[i].y = yy;
        sceneProperties.SceneProps[i].hit = hit;
    }
}

static void UpdateSceneAnimation()
{
    sceneProperties.param.Cherry.img = &cherry;
    sceneProperties.param.Apricot.img = &apricot;
    sceneProperties.param.Melon.img = &melon;
    
    sceneProperties.param.Bee[0].img = &bee_0;
    sceneProperties.param.Bee[1].img = &bee_1;
    sceneProperties.param.Bee[2].img = &bee_2;
    sceneProperties.param.Bee[3].img = &bee_3;
    sceneProperties.param.Bee[4].img = &bee_4;
    sceneProperties.param.Bee[5].img = &bee_5;
    sceneProperties.param.Bee[6].img = &bee_6;
    sceneProperties.param.Bee[7].img = &bee_7;
    
}

static void UpdateSpriteAnimation()
{
    if(spriteFacing == FACE_RIGHT)
    {
        idleSprite[0].img = &idle0;
        idleSprite[1].img = &idle1;
        idleSprite[2].img = &idle2;
        idleSprite[3].img = &idle3;
    
        runSprite[0].img = &run0;
        runSprite[1].img = &run1;
        runSprite[2].img = &run2;


        jumpSprite[0].img = &jump0;
        jumpSprite[1].img = &jump1;
        jumpSprite[2].img = &jump2;
        jumpSprite[3].img = &jump3;
        jumpSprite[4].img = &jump4;
        jumpSprite[5].img = &jump5;
        jumpSprite[6].img = &jump6;
        jumpSprite[7].img = &jump7;

        hurtSprite[0].img = &dizzy0;
        hurtSprite[1].img = &dizzy1;
        hurtSprite[2].img = &dizzy2;
        
        deadSprite[0].img = &dead1;
        deadSprite[1].img = &dead2;
        deadSprite[2].img = &dead3;
        deadSprite[3].img = &dead4;

        
        layerMoveDirection = false;
        
    }
    else
    {
        //idleSprite[0].img = &idle_left0;
        //idleSprite[1].img = &idle_left1;
        //idleSprite[2].img = &idle_left2;
        //idleSprite[3].img = &idle_left3;
    
        runSprite[0].img = &run_left0;
        runSprite[1].img = &run_left1;
        runSprite[2].img = &run_left2;


        jumpSprite[0].img = &jump_left0;
        jumpSprite[1].img = &jump_left1;
        jumpSprite[2].img = &jump_left2;
        jumpSprite[3].img = &jump_left3;
        jumpSprite[4].img = &jump_left4;
        jumpSprite[5].img = &jump_left5;
        jumpSprite[6].img = &jump_left6;
        jumpSprite[7].img = &jump_left7;

        /*hurtSprite[0].img = &hurt_left0;
        hurtSprite[1].img = &hurt_left1;
        hurtSprite[2].img = &hurt_left2;
        hurtSprite[3].img = &hurt_left3;*/
        
        layerMoveDirection = true;
        
    }
    
    #ifdef RTOS_CONFIGURED
    
        OnesDigitNum[0].img = &num0;
        OnesDigitNum[1].img = &num1;
        OnesDigitNum[2].img = &num2;
        OnesDigitNum[3].img = &num3;
        OnesDigitNum[4].img = &num4;
        OnesDigitNum[5].img = &num5;
        OnesDigitNum[6].img = &num6;
        OnesDigitNum[7].img = &num7;
        OnesDigitNum[8].img = &num8;
        OnesDigitNum[9].img = &num9;
    
        TensDigitNum[0].img = &num0;
        TensDigitNum[1].img = &num1;
        TensDigitNum[2].img = &num2;
        TensDigitNum[3].img = &num3;
        TensDigitNum[4].img = &num4;
        TensDigitNum[5].img = &num5;
        TensDigitNum[6].img = &num6;
        TensDigitNum[7].img = &num7;
        TensDigitNum[8].img = &num8;
        TensDigitNum[9].img = &num9;
    
    #endif

}
static void HandleHurtSprite()
{
    if(spriteHurt)
    {
        spriteState = HURT;
        tickDelay = APP_HURT_SPRITE_DELAY;
        spriteCount = 0;
        triggerCount = 0;
        moveLayerAnimation = false;
        sceneMake = false;
    }
}
static void UpdateSpriteCanvas(imgSeq * CurrentImage, imgSeq * PreviousImage)//uintptr_t context)//imgSeq * CurrentImage, imgSeq * PreviousImage)//imgSeq * ImageSeq, uint16_t offset)
{
    gfxcSetWindowSize(3U, 192, 267);
    CopyImagetoCanvas(3U, CurrentImage->img, 0, 0);
    gfxcSetWindowPosition(3U, CurrentImage->x, CurrentImage->y);
    
    
    #ifdef RTOS_CONFIGURED
    
        
    
        OnesDigit = (100 - cpu_free)%10;
        TensDigit = ((100 - cpu_free) / 10);
        CopyImagetoCanvas(2U, &cpu, 20, 10);
        CopyImagetoCanvas(2U, (OnesDigit < 10)?OnesDigitNum[OnesDigit].img : &num0, 125, 10);
        CopyImagetoCanvas(2U, (TensDigit < 10)?TensDigitNum[TensDigit].img : &num0, 110, 10);
        gfxcCanvasUpdate(2U);
        
    #endif
        
        gfxcCanvasUpdate(3U);
        
}

static void hitBox()
{
    uint8_t v_val = 0;
    switch(spriteState)
    {
        case RUN:
        {
            for(v_val; v_val < 11; v_val++)
            {
                if((!sceneProperties.SceneProps[v_val].hit) && (sceneProperties.SceneProps[v_val].y == SCENE_Y_MIN) && (currentSprite->y == INIT_POSY))
                {
                    if((sceneProperties.SceneProps[v_val].x >= (currentSprite->x + (SPRITE_WIDTH - (SPRITE_WIDTH/2)))) && (sceneProperties.SceneProps[v_val].x <= (currentSprite->x + SPRITE_WIDTH )))//- 5U
                    {
                        sceneProperties.SceneProps[v_val].hit = true;
                        if(v_val > 2)
                        {
                            ++hurtCount;
                            spriteHurt = true;
                            break;                          
                        }
                    }
                }
                                
            }
            break;
        }
        
        case JUMP:
        {
            for(v_val; v_val < 11; v_val++)
            {
                if((!sceneProperties.SceneProps[v_val].hit) && (sceneProperties.SceneProps[v_val].y == SCENE_Y_MAX) && ((INIT_POSY + jumpOffSet[spriteCount]) <= (SCENE_Y_MAX + 40U)))
                {
                    if((sceneProperties.SceneProps[v_val].x >= (currentSprite->x + (SPRITE_WIDTH - (SPRITE_WIDTH/2)))) && (sceneProperties.SceneProps[v_val].x <= (currentSprite->x + SPRITE_WIDTH )))//- 5U
                    {
                        sceneProperties.SceneProps[v_val].hit = true;
                        if(v_val > 2)
                        {
                            ++hurtCount;
                            spriteHurt = true;
                            break;                          
                        }
                    }
                }
                else if((!sceneProperties.SceneProps[v_val].hit) && (sceneProperties.SceneProps[v_val].y == SCENE_Y_MIN) && ((INIT_POSY + jumpOffSet[spriteCount]) > (SCENE_Y_MIN + 120U)))
                {
                    if((sceneProperties.SceneProps[v_val].x >= (currentSprite->x + (SPRITE_WIDTH - (SPRITE_WIDTH/2)))) && (sceneProperties.SceneProps[v_val].x <= (currentSprite->x + SPRITE_WIDTH )))//- 5U
                    {
                        sceneProperties.SceneProps[v_val].hit = true;
                        if(v_val > 2)
                        {
                            ++hurtCount;
                            spriteHurt = true;
                            break;                          
                        }
                    }
                }
                else
                {}
                                
            }
            break;
            
        }
    }
        
}

static void UpdateSceneCanvas()
{
    
    uint8_t i = 0;
    for(i;i<3;i++)
    {    
        if((sceneProperties.SceneProps[i].x != SCENE_RIGHT_END) && (sceneProperties.SceneProps[i].x != SCENE_RIGHT_START) && (sceneProperties.SceneProps[i].hit != true))
        {
            CopyImagetoCanvas(2U, sceneProperties.SceneProps[i].img, sceneProperties.SceneProps[i].x, sceneProperties.SceneProps[i].y);                
        }
        else
            ClearImageFromCanvas(2U, previousProperties.SceneProps[i].img, previousProperties.SceneProps[i].x, previousProperties.SceneProps[i].y);
                
                
    }
    static uint8_t beeCount = 0;
    beeCount = (beeCount < 8)? ++beeCount : 0;
    if(beeCount < 8)
    {
        if((sceneProperties.param.Bee[beeCount].x == SCENE_RIGHT_END) || (sceneProperties.param.Bee[beeCount].x == SCENE_RIGHT_START) || (sceneProperties.param.Bee[beeCount].hit == true))

        {
            {
                ClearImageFromCanvas(2U, previousProperties.param.Bee[beeCount].img, previousProperties.param.Bee[beeCount].x, previousProperties.param.Bee[beeCount].y);
                //CopyImagetoCanvas(2U, sceneProperties.param.Bee[beeCount].img, sceneProperties.param.Bee[beeCount].x, sceneProperties.param.Bee[beeCount].y);
                ClearImageFromCanvas(2U, sceneProperties.param.Bee[beeCount].img, sceneProperties.param.Bee[beeCount].x, sceneProperties.param.Bee[beeCount].y);
            }            
        }
        else 
        {
            //ClearImageFromCanvas(2U, previousProperties.param.Bee[beeCount].img, previousProperties.param.Bee[beeCount].x, previousProperties.param.Bee[beeCount].y);
            CopyImagetoCanvas(2U, sceneProperties.param.Bee[beeCount].img, sceneProperties.param.Bee[beeCount].x, sceneProperties.param.Bee[beeCount].y);
        }                
    }

    if(hurtCount == 0U)
        CopyImagetoCanvas(2U, &hud4, 682, 10);
    else if(hurtCount == 2U)
        CopyImagetoCanvas(2U, &hud3, 682, 10);
    else if(hurtCount == 4U)
        CopyImagetoCanvas(2U, &hud2, 682, 10);
    else if(hurtCount == 6U)
    {
        spriteDead = true;        
        CopyImagetoCanvas(2U, &hud1, 682, 10);
    }
    else
    {
        //do nothing
    }
    gfxcCanvasUpdate(2U);
    previousProperties = sceneProperties;
   
}

static void prepareScene()
{
    static int32_t assetStart = SCENE_RIGHT_END, refStart = SCENE_RIGHT_END;
    if(sceneMake)
    {

    if(directionChange)
    {
        if(spriteFacing == FACE_RIGHT)
        {
            refStart = SCENE_RIGHT_END;
            assetStart = refStart;                        
        }
        else
        {
            FillCanvasTransparent(2U);
            refStart = SCENE_RIGHT_START;
            assetStart = refStart;
        }
                    
            sceneProperties.param.Cherry.x = SCENE_RIGHT_END;
            sceneProperties.param.Cherry.y = SCENE_Y_MAX;
            
            sceneProperties.param.Apricot.x = SCENE_RIGHT_END;
            sceneProperties.param.Apricot.y = SCENE_Y_MAX;
            
            sceneProperties.param.Melon.x = SCENE_RIGHT_END;
            sceneProperties.param.Melon.y = SCENE_Y_MAX;
            
            populateBee(SCENE_RIGHT_END,SCENE_Y_MAX, false);
        directionChange = false;        
    }
    else
    {       
        assetStart = ScenePosition(assetStart);
        static uint16_t pause = 0, beeY = SCENE_Y_MAX;
        switch(sceneOrder)
        {                      
            case CherryApricotMelonBee:
            {
                if(!pause)
                {
                    sceneProperties.param.Cherry.y = SCENE_HEIGHT(limitInc(),0);
                    sceneProperties.param.Apricot.y = SCENE_HEIGHT(limitInc(),1);
                    sceneProperties.param.Melon.y = SCENE_HEIGHT(limitInc(),2);
                    beeY = SCENE_HEIGHT(limitInc(),3);
                    pause = 1U;
                }
                
                if(spriteFacing == FACE_RIGHT)
                {
                hitBox();
                sceneProperties.param.Cherry.x = (assetStart > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Cherry.hit != true) ? assetStart : sceneProperties.param.Cherry.x ): 0;                                
                sceneProperties.param.Apricot.x = (refStart - (assetStart + 35) > 170) && ((assetStart + 170) > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Apricot.hit != true) ? assetStart + 170 : sceneProperties.param.Apricot.x) : 0;                                
                sceneProperties.param.Melon.x = (refStart - (assetStart + 35) > 340) && ((assetStart + 340) > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Melon.hit != true) ? assetStart + 340 : sceneProperties.param.Melon.x) : 0;                                
                populateBee(((refStart - (assetStart + 35) > 510) && ((assetStart + 510)> (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Bee[0].hit != true) ? assetStart + 510 : sceneProperties.param.Bee[0].x) : 0) , beeY, sceneProperties.param.Bee[0].hit);
                
                if(assetStart + 510 < (SCENE_RIGHT_START + SCENE_OFFSET))
                {
                    sceneOrder = BeeMelonApricotCherry;
                    pause = 0U;
                    assetStart = refStart;
                    populateAssets(refStart, SCENE_Y_MAX, false);
                    populateBee(refStart, SCENE_Y_MAX, false);
                }
                }
                else{}
                
                break;
            }
            case BeeMelonApricotCherry:
            {
                if(!pause)
                {
                    sceneProperties.param.Cherry.y = SCENE_HEIGHT(limitInc(),3);
                    sceneProperties.param.Apricot.y = SCENE_HEIGHT(limitInc(),2);
                    sceneProperties.param.Melon.y = SCENE_HEIGHT(limitInc(),1);
                    beeY = SCENE_HEIGHT(limitInc(),0);
                    pause = 1U;
                }
                
                if(spriteFacing == FACE_RIGHT)
                {
                    hitBox();
                sceneProperties.param.Cherry.x = ((refStart - (assetStart + 35) > 510) && ((assetStart + 510)> (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Cherry.hit != true) ? assetStart + 510 : sceneProperties.param.Cherry.x) : 0);                                
                sceneProperties.param.Apricot.x = (refStart - (assetStart + 35) > 340) && ((assetStart + 340) > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Apricot.hit != true) ? assetStart + 340 : sceneProperties.param.Apricot.x) : 0;                                
                sceneProperties.param.Melon.x = (refStart - (assetStart + 35) > 170) && ((assetStart + 170) > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Melon.hit != true) ? assetStart + 170 : sceneProperties.param.Melon.x) : 0;                                
                populateBee(((assetStart > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Bee[0].hit != true) ? assetStart : sceneProperties.param.Bee[0].x) : 0) , beeY, sceneProperties.param.Bee[0].hit);
                
                if(assetStart + 510 < (SCENE_RIGHT_START + SCENE_OFFSET))
                {
                    sceneOrder = ApricotBeeMelonCherry;
                    pause = 0U;
                    assetStart = refStart;
                    populateAssets(refStart, SCENE_Y_MAX, false);
                    populateBee(refStart, SCENE_Y_MAX, false);
                }
                }
                else{}
                
                break;
            }
            case ApricotBeeMelonCherry:
            {
                if(!pause)
                {
                    sceneProperties.param.Cherry.y = SCENE_HEIGHT(limitInc(),3);
                    sceneProperties.param.Apricot.y = SCENE_HEIGHT(limitInc(),0);;
                    sceneProperties.param.Melon.y = SCENE_HEIGHT(limitInc(),2);
                    beeY = SCENE_HEIGHT(limitInc(),1);
                    pause = 1U;
                }
                
                if(spriteFacing == FACE_RIGHT)
                {
                    hitBox();
                sceneProperties.param.Cherry.x = ((refStart - (assetStart + 35) > 510) && ((assetStart + 510)> (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Cherry.hit != true) ? assetStart + 510 : sceneProperties.param.Cherry.x) : 0);                                
                sceneProperties.param.Apricot.x = (assetStart > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Apricot.hit != true) ? assetStart : sceneProperties.param.Apricot.x) : 0 ;                                
                sceneProperties.param.Melon.x = (refStart - (assetStart + 35) > 340) && ((assetStart + 340) > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Melon.hit != true) ? assetStart + 340 : sceneProperties.param.Melon.x) : 0;                                
                populateBee((refStart - (assetStart + 35) > 170) && ((assetStart + 170) > (SCENE_RIGHT_START + SCENE_OFFSET)) ? ((sceneProperties.param.Bee[0].hit != true) ? assetStart + 170 : sceneProperties.param.Bee[0].x) : 0 , beeY, sceneProperties.param.Bee[0].hit);
                //hitBox();
                if(assetStart + 510 < (SCENE_RIGHT_START + SCENE_OFFSET))
                {
                    sceneOrder = CherryApricotMelonBee;
                    pause = 0U;
                    assetStart = refStart;
                    populateAssets(refStart, SCENE_Y_MAX, false);
                    populateBee(refStart, SCENE_Y_MAX, false);
                }
                }
                else{}
                
                break;
            }
           default:
               break;
        }
        
        UpdateSceneCanvas();
    }
    }
}

static void MainScreen_HandleLocomotion(uintptr_t context)
{
    if(spriteState != RUN && spriteState != JUMP)
    {
        return;
    }

    if(spriteState == RUN)
    {
        if (spriteFacing == FACE_RIGHT)
        {
            if(spritePosX > APP_SPRITE_ANCHOR_MAX)
                --spritePosX;
            else
            {
            
            if(spriteRamp == RAMP_HIGH)
                spritePosX += (APP_SPRITE_STEP_X/RAMP_HIGH);
            else
                spritePosX -= (APP_SPRITE_STEP_X/RAMP_LOW);
            
            
            spritePosX = leClampi(APP_SPRITE_ANCHOR_MIN, APP_SPRITE_ANCHOR_MAX, spritePosX);
            static uint8_t forceDelay = 0;

            if (spritePosX >= APP_SPRITE_ANCHOR_MAX )
            {            
                if(++forceDelay > 20)//160
                {
                    spritePosX -= (APP_SPRITE_STEP_X);
                    forceDelay = 0;
                    spriteRamp = RAMP_LOW;                
                }
                else
                    spritePosX = APP_SPRITE_ANCHOR_MAX;
            /*spriteState = HURT;
            tickDelay = APP_HURT_SPRITE_DELAY;
            triggerCount = 0;
            moveLayerAnimation = false;*/
            }
            if(spritePosX <= APP_SPRITE_ANCHOR_MIN)
            {
                if(++forceDelay > 20)
                {
                    spritePosX += (APP_SPRITE_STEP_X);
                    forceDelay = 0;
                    spriteRamp = RAMP_HIGH;
                }
                else
                    spritePosX = APP_SPRITE_ANCHOR_MIN;
            
            }
            }
        }
        else if (spriteFacing == FACE_LEFT)
        {
            if(spritePosX < APP_SPRITE_ANCHOR_MIN_LEFT)
                ++spritePosX;
            else
            {
            
            if(spriteRamp == RAMP_HIGH)
                spritePosX -= (APP_SPRITE_STEP_X/RAMP_HIGH);
            else
                spritePosX += (APP_SPRITE_STEP_X/RAMP_LOW);
            
            
            spritePosX = leClampi(APP_SPRITE_ANCHOR_MIN_LEFT, APP_SPRITE_ANCHOR_MAX_LEFT, spritePosX);
            static uint8_t forceDelay = 0;

            if (spritePosX >= APP_SPRITE_ANCHOR_MAX_LEFT )
            {            
                if(++forceDelay > 100)
                {
                    spritePosX -= (APP_SPRITE_STEP_X);
                    forceDelay = 0;
                    spriteRamp = RAMP_HIGH;                
                }
                else
                    spritePosX = APP_SPRITE_ANCHOR_MAX_LEFT;
            /*spriteState = HURT;
            tickDelay = APP_HURT_SPRITE_DELAY;
            triggerCount = 0;
            moveLayerAnimation = false;*/
            }
            if(spritePosX <= APP_SPRITE_ANCHOR_MIN_LEFT)
            {
                if(++forceDelay > 100)
                {
                    spritePosX += (APP_SPRITE_STEP_X);
                    forceDelay = 0;
                    spriteRamp = RAMP_LOW;
                }
                else
                    spritePosX = APP_SPRITE_ANCHOR_MIN_LEFT;
            
            }
            }
        }

        
    }
    else if(spriteState == JUMP)
    {
        if (spriteFacing == FACE_RIGHT)
        {
            spritePosX += (APP_SPRITE_STEP_X);// - 1U
            spritePosX = leClampi(APP_SPRITE_ANCHOR_MIN, APP_SPRITE_ANCHOR_MAX_JUMP, spritePosX);
        }
        else if (spriteFacing == FACE_LEFT)
        {
            spritePosX -= (APP_SPRITE_STEP_X);//- 1U
            spritePosX = leClampi(APP_SPRITE_ANCHOR_MIN_LEFT, APP_SPRITE_ANCHOR_MAX_LEFT, spritePosX);
        }

        //spritePosX = leClampi(APP_SPRITE_ANCHOR_MIN, APP_SPRITE_ANCHOR_MAX, spritePosX);

    }
}

static void MainScreen_HandleAnimation(uintptr_t context)
{
    {
        prepareScene();
        
        if (triggerCount-- > 0)
        {
            return;
        }
        else
        {
            //Renew tick count
            triggerCount = tickDelay;
        }
        
        switch(spriteState)
        {
            case IDLE:
            {
                spriteCount = (spriteCount < 4)? ++spriteCount : 0;
                if(spriteCount < 4)
                {
                    idleSprite[spriteCount].x = spritePosX;
                    idleSprite[spriteCount].y = spritePosY;
                    currentSprite = &idleSprite[spriteCount];                    
                }                
                break;
            }
            case RUN:
            {
                spriteCount = (spriteCount < 3)? ++spriteCount : 0;
                if(spriteCount < 3)
                {
                    runSprite[spriteCount].x = spritePosX;
                    runSprite[spriteCount].y = spritePosY;
                    currentSprite = &runSprite[spriteCount];                    
                }
                HandleHurtSprite();
                break;
            }
            case JUMP:
            {
                spriteCount = (spriteCount < 8)? ++spriteCount : 0;
                if(spriteCount < 8)
                {
                    jumpSprite[spriteCount].x = spritePosX;
                    jumpSprite[spriteCount].y = spritePosY;// - SPRITE_HEIGHT;
                    currentSprite = &jumpSprite[spriteCount];                    
                }
                else
                {
                    spriteState = RUN;
                    triggerCount = 0;
                    tickDelay = APP_RUN_SPRITE_DELAY;
                }
                HandleHurtSprite();
                break;
            }
            case HURT:
            {
                {
                    spriteCount = (spriteCount <= 6)? ++spriteCount : 0;
                    if(spriteCount <= 6)
                    {
                        hurtSprite[spriteCount%3].x = spritePosX;
                        hurtSprite[spriteCount%3].y = spritePosY + 1U;
                        currentSprite = &hurtSprite[spriteCount%3];                    
                    }                                                            
                    else
                    {
                        if(!spriteDead)
                        {
                            spriteState = IDLE;
                            spriteCount = 0;
                            triggerCount = 0;
                            tickDelay = APP_IDLE_SPRITE_DELAY;
                            spriteHurt = false;
                        }
                        else
                        {
                            spriteState = DEAD;
                            spriteCount = 0;
                            triggerCount = 0;
                            tickDelay = APP_DEAD_SPRITE_DELAY;
                        }

                    }
                }
                
                break;
                
            }
            case DEAD:
            {

                spriteCount = (spriteCount < 4)? ++spriteCount : 0;
                if(spriteCount < 4)
                {
                    deadSprite[spriteCount].x = spritePosX;
                    deadSprite[spriteCount].y = spritePosY + 10U;
                    currentSprite = &deadSprite[spriteCount];                    
                }
                else
                {
                    moveLayerAnimation = false;
                    sceneMake = false;
                    screenState = SCREEN_RESTART;
                    spriteHurt = false;
                    spriteDead = false;
                    hurtCount = 0;
                }

            }
                
            default:
                break;
        }
        
        //UpdateSceneCanvas();
        UpdateSpriteCanvas(currentSprite, previousSprite);
        previousSprite = currentSprite;
    }
}



static void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    
    if((spriteState == HURT) || (spriteState == DEAD))
        return; 
    
    if(evt->y < (spritePosY + INIT_YOFFSET))
    {
        spriteState = JUMP;
        moveLayerAnimation = true;
        sceneMake = true;
        triggerCount = 0;
        tickDelay = APP_JUMP_SPRITE_DELAY;
        //spriteCount = 0;
        if(evt->x < (spritePosX))
        {
            if(spriteFacing == FACE_RIGHT)
                directionChange = true;
            spriteFacing = FACE_LEFT;
            
        }
        else
        {
            if(spriteFacing == FACE_LEFT)
                directionChange = true;
            spriteFacing = FACE_RIGHT;                
        }
    }
    else if(evt->x > (spritePosX + SPRITE_WIDTH))
    {
        spriteState = RUN;
        if(spriteFacing == FACE_LEFT)
            directionChange = true;
            
        spriteFacing = FACE_RIGHT;
        triggerCount = 0;
        tickDelay = APP_RUN_SPRITE_DELAY;
        moveLayerAnimation = true;
        sceneMake = true;
    }
    else if(evt->x < spritePosX)
    {
        spriteState = RUN;
        if(spriteFacing == FACE_RIGHT)
            directionChange = true;
        spriteFacing = FACE_LEFT;
        triggerCount = 0;
        tickDelay = APP_RUN_SPRITE_DELAY;
        moveLayerAnimation = true;        
    }
    else
    {
    }
    UpdateSpriteAnimation();
}

static void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
}

void Screen0_OnShow()
{
    screenState = SCREEN_INIT;
    spriteState = IDLE;
    spriteFacing = FACE_RIGHT;
}

void Screen0_OnHide()
{
    SYS_TIME_TimerDestroy(handleAnimation);
    SYS_TIME_TimerDestroy(handleLocomotion);
}

void Screen0_OnUpdate()
{
    switch (screenState)
    {
        case SCREEN_INIT:
        {
            if(leRenderer_IsIdle() &&
               leEvent_GetCount() == 0)
            {
                app_inputListener.handleTouchDown = &app_touchDownHandler;
                app_inputListener.handleTouchUp = &app_touchUpHandler;
                inputListenerID = SYS_INP_AddListener(&app_inputListener); 
                
                /* Place the Parallax state machine in its initial state. */
                appData.state = INIT_ANIM;
                handleParallax = SYS_TIME_CallbackRegisterMS(APP_ParallaxTasks, 0, 8, SYS_TIME_PERIODIC);
    
                gfxcSetEffectsCallback(0, APP_Scene_EffectsCallback, NULL);
                gfxcSetEffectsCallback(1, APP_Scene_EffectsCallback, NULL);
                gfxcSetEffectsCallback(2, APP_Scene_EffectsCallback, NULL);

                gfxcSetLayer(BACKGROUND_CANVAS_ID, BACKGROUND_LAYER_ID);   
                gfxcSetWindowSize(BACKGROUND_CANVAS_ID, BACKGROUND_CANVAS_WIDTH, BACKGROUND_CANVAS_HEIGHT);  
                gfxcShowCanvas(BACKGROUND_CANVAS_ID);   
                gfxcCanvasUpdate(BACKGROUND_CANVAS_ID);
                gfxcSetLayer(1, 1);
    
                gfxcSetWindowSize(1, 1600, 480);    
                gfxcShowCanvas(1);  
                gfxcCanvasUpdate(1);
                
                screenState = SCREEN_INIT_SPRITE;

            }
            
            break;
        }
        case SCREEN_INIT_SPRITE:
        {
            UpdateSpriteAnimation();
            UpdateSceneAnimation();
            //Populate Scene Variables
            uint8_t r = 0;
            for(r;r<11;r++)
            {
                sceneProperties.SceneProps[r].x = SCENE_RIGHT_END;
                sceneProperties.SceneProps[r].y = SCENE_Y_MAX;
                sceneProperties.SceneProps[r].hit = false;
            }
            sceneOrder = CherryApricotMelonBee;
                
            previousProperties = sceneProperties;
            
            //Populate sprite variables
            spriteState = IDLE;
            spriteFacing = FACE_RIGHT;
            spriteRamp = RAMP_HIGH;
            tickDelay = APP_IDLE_SPRITE_DELAY;
            triggerCount = 0;
            spriteCount = 0;
            
            spritePosX= INIT_POSX;
            spritePosY= INIT_POSY;
                
            idleSprite[0].x = INIT_POSX;
            idleSprite[0].y = INIT_POSY;
            currentSprite = &idleSprite[0];
            previousSprite = &idleSprite[0];
            
            directionChange = false;
            sceneMake = false;
            spriteHurt = false;
            spriteDead = false;            
            
            //Update Front layer canvas
            gfxcSetLayer(2, 2);    
            //gfxcSetWindowPosition(2, 0, 0);
            gfxcSetWindowSize(2, 800, 480);    
            gfxcShowCanvas(2);   
            CopyImagetoCanvas(2U, &headerImage, 200, 20);
            gfxcCanvasUpdate(2U);
            
            gfxcSetLayer(3,3);
            gfxcSetWindowSize(3, 192, 267);    
            gfxcShowCanvas(3);   
            gfxcCanvasUpdate(3U);
            
                
            screenState = SCREEN_HEADER;
            break;
        }
        case SCREEN_HEADER:
        {
            #ifndef RTOS_CONFIGURED
            SYS_TIME_DelayMS(200U, &CustomDelay);
            #endif
            screenState = SCREEN_HEADER_WAIT;
            break;
        }
        case SCREEN_HEADER_WAIT:
        {
            
            #ifndef RTOS_CONFIGURED
            if(SYS_TIME_DelayIsComplete(CustomDelay))
            #endif
            {
                ClearImageFromCanvas(2U, &headerImage, 200, 20);
                
                #ifdef RTOS_CONFIGURED

                    CopyImagetoCanvas(2U, &cpu, 20, 10);
                    CopyImagetoCanvas(2U, &num0, 110, 10);
                    CopyImagetoCanvas(2U, &num0, 125, 10);
                
                #endif
                gfxcCanvasUpdate(2U);
                handleAnimation = SYS_TIME_CallbackRegisterMS(MainScreen_HandleAnimation, 0, 7, SYS_TIME_PERIODIC);
                handleLocomotion = SYS_TIME_CallbackRegisterMS(MainScreen_HandleLocomotion, 0, 40, SYS_TIME_PERIODIC);
                screenState = SCREEN_RUNNING;
        
            }
            break;
            
        }
        case SCREEN_RUNNING:
            break;
        case SCREEN_RESTART:
        {
            //if(SYS_TIME_DelayIsComplete(CustomDelay))
            {
                SYS_TIME_TimerDestroy(handleAnimation);
                SYS_TIME_TimerDestroy(handleLocomotion);                
                SYS_TIME_DelayMS(200U, &CustomDelay);
                screenState = SCREEN_RESTART_WAIT;
            }
            
            break;
        }
        case SCREEN_RESTART_WAIT:
        {
            if(SYS_TIME_DelayIsComplete(CustomDelay))
            {                
                screenState = SCREEN_INIT_SPRITE;
                FillCanvasTransparent(2U);
            }
            
            break;
        }
        default:
            break;
    }
}


/* *****************************************************************************
 End of File
 */
