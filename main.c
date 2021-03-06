
/*******************************************************************************
* Title                 :   Oriented Programming practices
* Filename              :   main.c
* Author                :   TRAN MINH THUAN
* Origin Date           :   11/14/2021
* Version               :   1.0.0
* Compiler              :   CCS version 11.
* Target                :   TM4C123
*******************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "Lib/BSP.h"

#include "Lib/oop/shape.h"
#include "Lib/oop/rect.h"
#include "Lib/logger.h"
#include "Lib/log_uart.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
#define BGCOLOR     LCD_BLACK
#define AXISCOLOR   LCD_ORANGE
#define MAGCOLOR    LCD_YELLOW
#define EWMACOLOR   LCD_CYAN
#define SOUNDCOLOR  LCD_CYAN
#define LIGHTCOLOR  LCD_RED
#define TEMPCOLOR   LCD_LIGHTGREEN
#define TOPTXTCOLOR LCD_WHITE
#define TOPNUMCOLOR LCD_ORANGE

#define ACCELERATION_MAX 1400
#define ACCELERATION_MIN 600
#define SOUND_MAX 900
#define SOUND_MIN 300
#define LIGHT_MAX 2000
#define LIGHT_MIN 0
#define TEMP_MAX 1023
#define TEMP_MIN 0
/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
#if 0

#include "Lib/uart.h"
uart_t uart0;
uart_config_t uart0_config =
{
		.baudrate	= 9600,
		.datalen	= DATA_LEN_8B,
		.parity		= PARITY_NONE,
		.stop_bit	= STOP_BIT_1B
};
const uint8_t send_me[]="Hello \n\n";
uart_ctor(&uart0, UART0_INSTANCE, &uart0_config);
uart_init(&uart0);
while(1)
uart_send(&uart0, send_me, strlen(send_me));
#endif  /* End of 0 */

LogUART_t LogUART0;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void Blink_LED(void);
void LED_Init(void);




Rectangle rec1, rec2;
Shape s1;
/******************************************************************************
* Function Definitions
*******************************************************************************/
int main(void)
{
	LogUART_Ctor(&LogUART0);

//	Log_Msg(&LogUART0, LOGSYSTEM_APP, "Hi \n\n", strlen("Hi \n\n"));

//	LogUART_Send(&LogUART0, "Hi \n\n", strlen("Hi \n\n"));

//    Shape_ctor(&s1, 9, 9);
//    Shape_draw(&s1);

    LED_Init();
    BSP_LCD_Init();
    BSP_LCD_FillScreen(BSP_LCD_Color565(0, 0, 0));
    IntMasterEnable();
    while(1)
    {
        Blink_LED();
    }
}

void LED_Init(void)
{
    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    //
    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
}

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
void Blink_LED(void)
{
    volatile uint32_t ui32Loop;
    //
    // Turn on the LED.
    //
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);

    //
    // Delay for a bit.
    //
    for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
    {
    }

    //
    // Turn off the LED.
    //
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

    //
    // Delay for a bit.
    //
    for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
    {
    }
}

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
void __error__(char *pcFilename, uint32_t ui32Line)
{
    while(1);
}
