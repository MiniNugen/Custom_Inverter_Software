
//
// FILE:   empty_driverlib_main.c
//
// TITLE:  Empty Project

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "gpio.h"
#include "stdio.h"


void main(void)

{
    Device_init();
    Device_initGPIO();

    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED1, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED1, GPIO_DIR_MODE_OUT);

    // Initialize PIE and clear PIE registers. Disables CPU interrupts. 
    Interrupt_initModule();
    // Initialize the PIE vector table 
    Interrupt_initVectorTable();
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    EINT;
    ERTM;

    // Loop Forever
    for(;;)
    {
        // Turn on LED
        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 0);
        // Delay for a bit.
        DEVICE_DELAY_US(500000);
        // Turn off LED
        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 1);
        // Delay for a bit.
        DEVICE_DELAY_US(2000000);

        // Turn on LED
        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 0);
        // Delay for a bit.
        DEVICE_DELAY_US(100000);
        // Turn off LED
        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 1);
        // Delay for a bit.
        DEVICE_DELAY_US(500000);


    }
}

//
// End of File
//
