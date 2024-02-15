
![](../../../../images/mhgs.png)

lvgl_sc_9x75_eb_ac69t88a.X

Defining the Architecture
-------------------------

![](../../../../images/legato_sam9x60_single_buffer_arch.png)

This application demonstrates single-layer WVGA graphics using DDR3 memory.

User touch input on the display panel is received through the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library through the Input System Service.

### Demonstration Features

-   LVGL Graphics Library
-   Reference application for the SAM9X75-DDR3-EB Early Access Evaluation Board
-   24-bit RGB565 color, single-layer, WVGA (800x480) screen design
-   Time system service, RTT peripheral library and driver
-   Graphics support with integrated display controller (XLCDC)
-   I2C and maXTouch® controller driver

Creating the Project Graph
--------------------------

![](../../../../images/sam_9x75_eb_wm_lvds_no_legato.png)

The Project Graph diagram shows the Harmony 3 components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides.

Building the Application
------------------------

The parent directory for this application is gfx/apps/lvgl\_showcase. To build this application, use MPLAB X IDE to open the gfx/apps/lvgl\_showcase/firmware/lvgl\_sc\_9x75\_eb\_ac69t88a.X project folder and press F11.
A successful build will generate a harmony.bin file in dist/lvdsc_xlcdc_rgba8888_mxt_9x75_wvga/production in the project folder.

The following table lists configuration properties:

|Project Name|BSP Used|Graphics Template Used|Description|
|:-----------|:-------|:---------------------|:----------|
|lvgl\_sc\_9x75\_eb\_ac69t88a.X|[SAM 9X75 Evaluation Board BSP](https://www.microchip.com/en-us/development-tool/EA14J50A) |LVGL Graphics w/ Microchip AC69T88A Display|[SAM9X75-DDR3-EB Early Access Evaluation Board](https://www.microchip.com/en-us/development-tool/EA14J50A) with LVDS Interface and [MPU32 LVDS Display WVGA](https://www.microchip.com/)|

> **NOTE:** This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Code Configurator to regenerate the application code, do not remove or replace the custom code.


Configuring the Hardware
------------------------

Configure the hardware as follows:
-   Connect the MPU32-EB-LVDS-ADAPTER - REV2 add-on board to the SAM 9X75 Evaluation Board. Make sure to remove any jumpers on the marked areas and start by inserting the mikroBUS header first for easy alignment. <br/>**Note:** Please contact your local [Microchip Sales Office](https://www.microchip.com/en-us/about/global-sales-and-distribution) for access to the LVDS adapter and LVDS display.

![](../../../../images/sam_9x75_eb.png)


-   Connect the AC69T88A display to the MPU32-EB-LVDS-ADAPTER-REV2 add-on board using a 30-pin 0.5mm pitch FFC ribbon. <br/> **Important**: You may need a Type A FFC (upto REV2), or on newer LVDS-Adapter boards, a Type D FFC (contacts on opposite sides). Ultimately, you need to align pin 1 of the adapter to pin 1 of the display.

-	Take an SD Card formatted with the FAT32 file system and copy the boot.bin binary file from this [location](./binaries/boot.bin). Also copy the harmony.bin file you generated from the "Building the Application" section.

-   Insert the SD card into the SDMMC0 slot on the SAM9X75-DDR3-EB Early Access Evaluation Board and power up the board by connecting a USB cable (5V/1A recommended) to the USB port or an adapter to the barrel jack (5V/1A recommended, Center Positive).

Running the Demonstration
-------------------------

**About the Demonstration**

The LCD should display a simple menu with images, text, and a button on successful power-on. See reference image.
   
![](../../../../images/lvgl_showcase.png)


* * * * *
