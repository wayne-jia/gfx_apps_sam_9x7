
![](../../../../images/mhgs.png)

legato_adventure_9x75_eb_rpi_7inch.X

Defining the Architecture
-------------------------

![](../../../../images/legato_sam9x75_single_buffer_arch_mipi.png)

This application demonstrates multi-layer WVGA graphics using DDR3 memory.
The demo utilizes pre-processed sprite images stored in DDR3 memory overlaid on top of two-layer scrolling background images intended to achieve parallax scrolling effect. The application code uses the Graphic Canvas library to configure sprite animations and overlaid using XLCDC layers

User touch input on the display panel is received through the capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library through the Input System Service. The navigation of character sprite is based on the location of touch events on the screen.

### Demonstration Features

-   Legato Graphics Library and Graphics Canvas
-   Signature application for the SAM9X75-DDR3-EB Early Access Evaluation Board
-   24-bit color, multi-layer, WVGA (800x480) screen design
-   Time system service, RTT peripheral library with driver
-   Graphics Acceleration using integrated display controller (XLCDC)
-   GFX2D GPU Driver Support
-   Raspberry Pi Touch Display driver

Creating the Project Graph
--------------------------

![](../../../../images/sam_9x75_eb_adv_mipi.png)

The Project Graph diagram shows the Harmony 3 components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides.

Adding the **SAM 9X75 Evaluation Board BSP** and **Legato Graphics w/ RPi Touch Display** Graphics Template component into the project graph will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display and touch controller.


The Graphics Canvas component is added between the XLCDC and the legato graphics library to enable the use of the XLCDC layers to overlay multiple layers, frames and to perform the sprite animations. Inside the canvas component, 4 canvas objects were configured to manage the overlay of scrolling backgrounds, Character sprite and other game assets respectively.

**Graphics Canvas**

![](../../../../images/CanvasConfig.png)

Building the Application
------------------------

The parent directory for this application is gfx/apps/legato\_adventure. To build this application, use MPLAB X IDE to open the gfx/apps/legato\_adventure/firmware/legato\_adventure\_9x75\_eb\_rpi_7inch.X project folder and press F11.
A successful build will generate a harmony.bin file in dist/mipi_dsi_xlcdc_rgba8888_rpi_9x75_wvga/production in the project folder.

The following table lists configuration properties:

|Project Name|BSP Used|Graphics Template Used|Description|
|:-----------|:-------|:---------------------|:----------|
|legato\_adventure\_9x75\_eb\_rpi_7inch.X|[SAM 9X75 Evaluation Board BSP](https://www.microchip.com/en-us/development-tool/EA14J50A) |Legato Graphics w/ RPi Touch Display|[SAM9X75-DDR3-EB Early Access Evaluation Board](https://www.microchip.com/en-us/development-tool/EA14J50A) and [Raspberry Pi Touch Display](https://www.raspberrypi.com/products/raspberry-pi-touch-display/) MIPI DSI Display|

> **NOTE:** This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Code Configurator to regenerate the application code, do not remove or replace the custom code.


Configuring the Hardware
------------------------

Configure the hardware as follows:
-   Connect the power pins of the Raspberry Pi Touch Display (5V and GND) to the SAM9X75 Evaluation Board's mikroBus header using jumpers as shown in the image below.

![](../../../../images/sam_9x75_eb_mipi.png)

-   Connect the display to the evaluation board using a [22-pin to 15-pin DSI FFC cable](https://www.waveshare.com/dsi-cable-15cm.htm). Connect the 15-pin side to the display with the contacts facing up and the 22-pin side with the contacts facing away from flip-lock as shown in the image.

-	Take an SD Card formatted with the FAT32 file system and copy the boot.bin binary file from this [location](./binaries/boot.bin). Also copy the harmony.bin file you generated from the "Building the Application" section.

-   Insert the SD card into the SDMMC0 slot on the SAM9X75-DDR3-EB Early Access Evaluation Board and power up the board by connecting a USB cable (5V/1A recommended) to the USB port or an adapter to the barrel jack (5V/1A recommended, Center Positive).

Running the Demonstration
-------------------------
On start, the LCD should display rotating 'LEGATO' logo screen on successful power-on.
After rendering the Splash screen, the application automaticaly transitions to the game window.

**About the Game**
- The objective of this game is to make the character sprite(Sheep) follow through the natural game direction(RIGHT), gather the fruit assets and evade the Bees. A total of 3 lives (6 bee strikes) is allowed and the game is designed to automatically re-spawn after that.    

![](../../../../images/SplashScreen.png)
![](../../../../images/legato_adventure.png)

UI Guide
-------------------------

**Interactions**

![](../../../../images/UI_interactionFinal.png)

**Canvas**

-   The application uses the Graphics Canvas to demonstrate advanced graphics effects through the display controller layer functions. These effects include layer fade in/out, layer slide in/out and sprite animation.
-   Canvas objects are used to reference frames in DDR. The Graphics Canvas is used to assign a canvas frame to each XLCDC layer and generate the composited frame. Effects such as fade and motion can be applied to each canvas object.

**Sprite Animation**
- A series of animated character sprites are pre-processed and stored in DDR memory.
- To run the sprite animation, the overlay start address is set to location of sprite images in DDR. The horizontal and vertical positions of the character sprite is adjusted using Canvas windowing technique.
- The states of the character sprite is stored in an array which holds the image along with its corresponding position(x,y coordinates).
- This array is used by the application to reference the image buffer, size and position and sets these values to the overlay.

> **NOTE:** This display has [non-square pixels](https://forums.raspberrypi.com/viewtopic.php?t=120710). Therefore, images may appear slightly stretched across the width of the display. You can fix this by scaling **only the width** of the image assets down from **100% to 92.47%** in your favourite image editor.

* * * * *
