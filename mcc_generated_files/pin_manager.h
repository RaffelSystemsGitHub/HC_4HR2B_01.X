/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F1937
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set HEAT2_RED_GND aliases
#define HEAT2_RED_GND_TRIS                 TRISAbits.TRISA0
#define HEAT2_RED_GND_LAT                  LATAbits.LATA0
#define HEAT2_RED_GND_PORT                 PORTAbits.RA0
#define HEAT2_RED_GND_ANS                  ANSELAbits.ANSA0
#define HEAT2_RED_GND_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define HEAT2_RED_GND_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define HEAT2_RED_GND_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define HEAT2_RED_GND_GetValue()           PORTAbits.RA0
#define HEAT2_RED_GND_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define HEAT2_RED_GND_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define HEAT2_RED_GND_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define HEAT2_RED_GND_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set HEAT2_GRN_GND aliases
#define HEAT2_GRN_GND_TRIS                 TRISAbits.TRISA1
#define HEAT2_GRN_GND_LAT                  LATAbits.LATA1
#define HEAT2_GRN_GND_PORT                 PORTAbits.RA1
#define HEAT2_GRN_GND_ANS                  ANSELAbits.ANSA1
#define HEAT2_GRN_GND_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define HEAT2_GRN_GND_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define HEAT2_GRN_GND_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define HEAT2_GRN_GND_GetValue()           PORTAbits.RA1
#define HEAT2_GRN_GND_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define HEAT2_GRN_GND_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define HEAT2_GRN_GND_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define HEAT2_GRN_GND_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LIFT_OPEN_BTN aliases
#define LIFT_OPEN_BTN_TRIS                 TRISAbits.TRISA2
#define LIFT_OPEN_BTN_LAT                  LATAbits.LATA2
#define LIFT_OPEN_BTN_PORT                 PORTAbits.RA2
#define LIFT_OPEN_BTN_ANS                  ANSELAbits.ANSA2
#define LIFT_OPEN_BTN_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LIFT_OPEN_BTN_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LIFT_OPEN_BTN_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LIFT_OPEN_BTN_GetValue()           PORTAbits.RA2
#define LIFT_OPEN_BTN_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LIFT_OPEN_BTN_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LIFT_OPEN_BTN_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LIFT_OPEN_BTN_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LOCK_BTN aliases
#define LOCK_BTN_TRIS                 TRISAbits.TRISA3
#define LOCK_BTN_LAT                  LATAbits.LATA3
#define LOCK_BTN_PORT                 PORTAbits.RA3
#define LOCK_BTN_ANS                  ANSELAbits.ANSA3
#define LOCK_BTN_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LOCK_BTN_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LOCK_BTN_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LOCK_BTN_GetValue()           PORTAbits.RA3
#define LOCK_BTN_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LOCK_BTN_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LOCK_BTN_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LOCK_BTN_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set LIFT_LED_GND aliases
#define LIFT_LED_GND_TRIS                 TRISAbits.TRISA4
#define LIFT_LED_GND_LAT                  LATAbits.LATA4
#define LIFT_LED_GND_PORT                 PORTAbits.RA4
#define LIFT_LED_GND_ANS                  ANSELAbits.ANSA4
#define LIFT_LED_GND_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LIFT_LED_GND_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LIFT_LED_GND_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LIFT_LED_GND_GetValue()           PORTAbits.RA4
#define LIFT_LED_GND_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LIFT_LED_GND_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LIFT_LED_GND_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define LIFT_LED_GND_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set HIGH_LED_GND aliases
#define HIGH_LED_GND_TRIS                 TRISAbits.TRISA5
#define HIGH_LED_GND_LAT                  LATAbits.LATA5
#define HIGH_LED_GND_PORT                 PORTAbits.RA5
#define HIGH_LED_GND_ANS                  ANSELAbits.ANSA5
#define HIGH_LED_GND_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define HIGH_LED_GND_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define HIGH_LED_GND_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define HIGH_LED_GND_GetValue()           PORTAbits.RA5
#define HIGH_LED_GND_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define HIGH_LED_GND_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define HIGH_LED_GND_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define HIGH_LED_GND_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set BACK_OPEN_OUT aliases
#define BACK_OPEN_OUT_TRIS                 TRISAbits.TRISA6
#define BACK_OPEN_OUT_LAT                  LATAbits.LATA6
#define BACK_OPEN_OUT_PORT                 PORTAbits.RA6
#define BACK_OPEN_OUT_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define BACK_OPEN_OUT_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define BACK_OPEN_OUT_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define BACK_OPEN_OUT_GetValue()           PORTAbits.RA6
#define BACK_OPEN_OUT_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define BACK_OPEN_OUT_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set BACK_CLOSE_OUT aliases
#define BACK_CLOSE_OUT_TRIS                 TRISAbits.TRISA7
#define BACK_CLOSE_OUT_LAT                  LATAbits.LATA7
#define BACK_CLOSE_OUT_PORT                 PORTAbits.RA7
#define BACK_CLOSE_OUT_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define BACK_CLOSE_OUT_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define BACK_CLOSE_OUT_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define BACK_CLOSE_OUT_GetValue()           PORTAbits.RA7
#define BACK_CLOSE_OUT_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define BACK_CLOSE_OUT_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set INTENSITY_LED aliases
#define INTENSITY_LED_TRIS                 TRISBbits.TRISB0
#define INTENSITY_LED_LAT                  LATBbits.LATB0
#define INTENSITY_LED_PORT                 PORTBbits.RB0
#define INTENSITY_LED_WPU                  WPUBbits.WPUB0
#define INTENSITY_LED_ANS                  ANSELBbits.ANSB0
#define INTENSITY_LED_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define INTENSITY_LED_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define INTENSITY_LED_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define INTENSITY_LED_GetValue()           PORTBbits.RB0
#define INTENSITY_LED_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define INTENSITY_LED_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define INTENSITY_LED_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define INTENSITY_LED_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define INTENSITY_LED_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define INTENSITY_LED_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set BACK_LED_GND aliases
#define BACK_LED_GND_TRIS                 TRISBbits.TRISB1
#define BACK_LED_GND_LAT                  LATBbits.LATB1
#define BACK_LED_GND_PORT                 PORTBbits.RB1
#define BACK_LED_GND_WPU                  WPUBbits.WPUB1
#define BACK_LED_GND_ANS                  ANSELBbits.ANSB1
#define BACK_LED_GND_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BACK_LED_GND_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BACK_LED_GND_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BACK_LED_GND_GetValue()           PORTBbits.RB1
#define BACK_LED_GND_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BACK_LED_GND_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BACK_LED_GND_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BACK_LED_GND_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BACK_LED_GND_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define BACK_LED_GND_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BACK_OPEN_BTN aliases
#define BACK_OPEN_BTN_TRIS                 TRISBbits.TRISB2
#define BACK_OPEN_BTN_LAT                  LATBbits.LATB2
#define BACK_OPEN_BTN_PORT                 PORTBbits.RB2
#define BACK_OPEN_BTN_WPU                  WPUBbits.WPUB2
#define BACK_OPEN_BTN_ANS                  ANSELBbits.ANSB2
#define BACK_OPEN_BTN_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BACK_OPEN_BTN_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BACK_OPEN_BTN_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BACK_OPEN_BTN_GetValue()           PORTBbits.RB2
#define BACK_OPEN_BTN_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BACK_OPEN_BTN_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BACK_OPEN_BTN_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BACK_OPEN_BTN_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BACK_OPEN_BTN_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BACK_OPEN_BTN_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set HEAT1_GRN_GND aliases
#define HEAT1_GRN_GND_TRIS                 TRISBbits.TRISB3
#define HEAT1_GRN_GND_LAT                  LATBbits.LATB3
#define HEAT1_GRN_GND_PORT                 PORTBbits.RB3
#define HEAT1_GRN_GND_WPU                  WPUBbits.WPUB3
#define HEAT1_GRN_GND_ANS                  ANSELBbits.ANSB3
#define HEAT1_GRN_GND_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define HEAT1_GRN_GND_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define HEAT1_GRN_GND_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define HEAT1_GRN_GND_GetValue()           PORTBbits.RB3
#define HEAT1_GRN_GND_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define HEAT1_GRN_GND_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define HEAT1_GRN_GND_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define HEAT1_GRN_GND_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define HEAT1_GRN_GND_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define HEAT1_GRN_GND_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set HEAT1_RED_GND aliases
#define HEAT1_RED_GND_TRIS                 TRISBbits.TRISB4
#define HEAT1_RED_GND_LAT                  LATBbits.LATB4
#define HEAT1_RED_GND_PORT                 PORTBbits.RB4
#define HEAT1_RED_GND_WPU                  WPUBbits.WPUB4
#define HEAT1_RED_GND_ANS                  ANSELBbits.ANSB4
#define HEAT1_RED_GND_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define HEAT1_RED_GND_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define HEAT1_RED_GND_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define HEAT1_RED_GND_GetValue()           PORTBbits.RB4
#define HEAT1_RED_GND_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define HEAT1_RED_GND_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define HEAT1_RED_GND_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define HEAT1_RED_GND_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define HEAT1_RED_GND_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define HEAT1_RED_GND_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set HEAT1_BTN aliases
#define HEAT1_BTN_TRIS                 TRISBbits.TRISB5
#define HEAT1_BTN_LAT                  LATBbits.LATB5
#define HEAT1_BTN_PORT                 PORTBbits.RB5
#define HEAT1_BTN_WPU                  WPUBbits.WPUB5
#define HEAT1_BTN_ANS                  ANSELBbits.ANSB5
#define HEAT1_BTN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define HEAT1_BTN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define HEAT1_BTN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define HEAT1_BTN_GetValue()           PORTBbits.RB5
#define HEAT1_BTN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define HEAT1_BTN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define HEAT1_BTN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define HEAT1_BTN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define HEAT1_BTN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define HEAT1_BTN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set PGC aliases
#define PGC_TRIS                 TRISBbits.TRISB6
#define PGC_LAT                  LATBbits.LATB6
#define PGC_PORT                 PORTBbits.RB6
#define PGC_WPU                  WPUBbits.WPUB6
#define PGC_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define PGC_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define PGC_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define PGC_GetValue()           PORTBbits.RB6
#define PGC_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define PGC_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define PGC_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define PGC_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set PGD aliases
#define PGD_TRIS                 TRISBbits.TRISB7
#define PGD_LAT                  LATBbits.LATB7
#define PGD_PORT                 PORTBbits.RB7
#define PGD_WPU                  WPUBbits.WPUB7
#define PGD_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define PGD_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define PGD_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define PGD_GetValue()           PORTBbits.RB7
#define PGD_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define PGD_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define PGD_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define PGD_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set LIFT_CLOSE_OUT aliases
#define LIFT_CLOSE_OUT_TRIS                 TRISCbits.TRISC0
#define LIFT_CLOSE_OUT_LAT                  LATCbits.LATC0
#define LIFT_CLOSE_OUT_PORT                 PORTCbits.RC0
#define LIFT_CLOSE_OUT_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LIFT_CLOSE_OUT_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LIFT_CLOSE_OUT_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LIFT_CLOSE_OUT_GetValue()           PORTCbits.RC0
#define LIFT_CLOSE_OUT_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LIFT_CLOSE_OUT_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set LIFT_OPEN_OUT aliases
#define LIFT_OPEN_OUT_TRIS                 TRISCbits.TRISC1
#define LIFT_OPEN_OUT_LAT                  LATCbits.LATC1
#define LIFT_OPEN_OUT_PORT                 PORTCbits.RC1
#define LIFT_OPEN_OUT_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LIFT_OPEN_OUT_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LIFT_OPEN_OUT_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LIFT_OPEN_OUT_GetValue()           PORTCbits.RC1
#define LIFT_OPEN_OUT_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LIFT_OPEN_OUT_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set ZONE4_OUT aliases
#define ZONE4_OUT_TRIS                 TRISCbits.TRISC2
#define ZONE4_OUT_LAT                  LATCbits.LATC2
#define ZONE4_OUT_PORT                 PORTCbits.RC2
#define ZONE4_OUT_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define ZONE4_OUT_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define ZONE4_OUT_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define ZONE4_OUT_GetValue()           PORTCbits.RC2
#define ZONE4_OUT_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define ZONE4_OUT_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set ZONE3_OUT aliases
#define ZONE3_OUT_TRIS                 TRISCbits.TRISC3
#define ZONE3_OUT_LAT                  LATCbits.LATC3
#define ZONE3_OUT_PORT                 PORTCbits.RC3
#define ZONE3_OUT_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define ZONE3_OUT_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define ZONE3_OUT_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define ZONE3_OUT_GetValue()           PORTCbits.RC3
#define ZONE3_OUT_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define ZONE3_OUT_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set ZONE1_OUT aliases
#define ZONE1_OUT_TRIS                 TRISCbits.TRISC4
#define ZONE1_OUT_LAT                  LATCbits.LATC4
#define ZONE1_OUT_PORT                 PORTCbits.RC4
#define ZONE1_OUT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define ZONE1_OUT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define ZONE1_OUT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define ZONE1_OUT_GetValue()           PORTCbits.RC4
#define ZONE1_OUT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define ZONE1_OUT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set HEAT2_OUT aliases
#define HEAT2_OUT_TRIS                 TRISCbits.TRISC5
#define HEAT2_OUT_LAT                  LATCbits.LATC5
#define HEAT2_OUT_PORT                 PORTCbits.RC5
#define HEAT2_OUT_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define HEAT2_OUT_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define HEAT2_OUT_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define HEAT2_OUT_GetValue()           PORTCbits.RC5
#define HEAT2_OUT_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define HEAT2_OUT_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set HEAT1_OUT aliases
#define HEAT1_OUT_TRIS                 TRISCbits.TRISC6
#define HEAT1_OUT_LAT                  LATCbits.LATC6
#define HEAT1_OUT_PORT                 PORTCbits.RC6
#define HEAT1_OUT_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define HEAT1_OUT_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define HEAT1_OUT_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define HEAT1_OUT_GetValue()           PORTCbits.RC6
#define HEAT1_OUT_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define HEAT1_OUT_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set INTENSITY_BTN aliases
#define INTENSITY_BTN_TRIS                 TRISCbits.TRISC7
#define INTENSITY_BTN_LAT                  LATCbits.LATC7
#define INTENSITY_BTN_PORT                 PORTCbits.RC7
#define INTENSITY_BTN_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define INTENSITY_BTN_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define INTENSITY_BTN_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define INTENSITY_BTN_GetValue()           PORTCbits.RC7
#define INTENSITY_BTN_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define INTENSITY_BTN_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set MED_LED_GND aliases
#define MED_LED_GND_TRIS                 TRISDbits.TRISD0
#define MED_LED_GND_LAT                  LATDbits.LATD0
#define MED_LED_GND_PORT                 PORTDbits.RD0
#define MED_LED_GND_ANS                  ANSELDbits.ANSD0
#define MED_LED_GND_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define MED_LED_GND_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define MED_LED_GND_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define MED_LED_GND_GetValue()           PORTDbits.RD0
#define MED_LED_GND_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define MED_LED_GND_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define MED_LED_GND_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define MED_LED_GND_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set WAVE_LED_GND aliases
#define WAVE_LED_GND_TRIS                 TRISDbits.TRISD1
#define WAVE_LED_GND_LAT                  LATDbits.LATD1
#define WAVE_LED_GND_PORT                 PORTDbits.RD1
#define WAVE_LED_GND_ANS                  ANSELDbits.ANSD1
#define WAVE_LED_GND_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define WAVE_LED_GND_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define WAVE_LED_GND_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define WAVE_LED_GND_GetValue()           PORTDbits.RD1
#define WAVE_LED_GND_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define WAVE_LED_GND_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define WAVE_LED_GND_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define WAVE_LED_GND_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set MASSAGE_BTN aliases
#define MASSAGE_BTN_TRIS                 TRISDbits.TRISD2
#define MASSAGE_BTN_LAT                  LATDbits.LATD2
#define MASSAGE_BTN_PORT                 PORTDbits.RD2
#define MASSAGE_BTN_ANS                  ANSELDbits.ANSD2
#define MASSAGE_BTN_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define MASSAGE_BTN_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define MASSAGE_BTN_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define MASSAGE_BTN_GetValue()           PORTDbits.RD2
#define MASSAGE_BTN_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define MASSAGE_BTN_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define MASSAGE_BTN_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define MASSAGE_BTN_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set ZONE2_OUT aliases
#define ZONE2_OUT_TRIS                 TRISDbits.TRISD3
#define ZONE2_OUT_LAT                  LATDbits.LATD3
#define ZONE2_OUT_PORT                 PORTDbits.RD3
#define ZONE2_OUT_ANS                  ANSELDbits.ANSD3
#define ZONE2_OUT_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define ZONE2_OUT_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define ZONE2_OUT_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define ZONE2_OUT_GetValue()           PORTDbits.RD3
#define ZONE2_OUT_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define ZONE2_OUT_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define ZONE2_OUT_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define ZONE2_OUT_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set MODE_LED aliases
#define MODE_LED_TRIS                 TRISDbits.TRISD4
#define MODE_LED_LAT                  LATDbits.LATD4
#define MODE_LED_PORT                 PORTDbits.RD4
#define MODE_LED_ANS                  ANSELDbits.ANSD4
#define MODE_LED_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define MODE_LED_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define MODE_LED_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define MODE_LED_GetValue()           PORTDbits.RD4
#define MODE_LED_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define MODE_LED_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define MODE_LED_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define MODE_LED_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set LOW_LED_GND aliases
#define LOW_LED_GND_TRIS                 TRISDbits.TRISD5
#define LOW_LED_GND_LAT                  LATDbits.LATD5
#define LOW_LED_GND_PORT                 PORTDbits.RD5
#define LOW_LED_GND_ANS                  ANSELDbits.ANSD5
#define LOW_LED_GND_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LOW_LED_GND_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LOW_LED_GND_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LOW_LED_GND_GetValue()           PORTDbits.RD5
#define LOW_LED_GND_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LOW_LED_GND_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define LOW_LED_GND_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define LOW_LED_GND_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set STEADY_LED_GND aliases
#define STEADY_LED_GND_TRIS                 TRISDbits.TRISD6
#define STEADY_LED_GND_LAT                  LATDbits.LATD6
#define STEADY_LED_GND_PORT                 PORTDbits.RD6
#define STEADY_LED_GND_ANS                  ANSELDbits.ANSD6
#define STEADY_LED_GND_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define STEADY_LED_GND_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define STEADY_LED_GND_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define STEADY_LED_GND_GetValue()           PORTDbits.RD6
#define STEADY_LED_GND_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define STEADY_LED_GND_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define STEADY_LED_GND_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define STEADY_LED_GND_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set BACK_CLOSE_BTN aliases
#define BACK_CLOSE_BTN_TRIS                 TRISDbits.TRISD7
#define BACK_CLOSE_BTN_LAT                  LATDbits.LATD7
#define BACK_CLOSE_BTN_PORT                 PORTDbits.RD7
#define BACK_CLOSE_BTN_ANS                  ANSELDbits.ANSD7
#define BACK_CLOSE_BTN_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define BACK_CLOSE_BTN_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define BACK_CLOSE_BTN_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define BACK_CLOSE_BTN_GetValue()           PORTDbits.RD7
#define BACK_CLOSE_BTN_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define BACK_CLOSE_BTN_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define BACK_CLOSE_BTN_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define BACK_CLOSE_BTN_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set PULSE_LED_GND aliases
#define PULSE_LED_GND_TRIS                 TRISEbits.TRISE0
#define PULSE_LED_GND_LAT                  LATEbits.LATE0
#define PULSE_LED_GND_PORT                 PORTEbits.RE0
#define PULSE_LED_GND_ANS                  ANSELEbits.ANSE0
#define PULSE_LED_GND_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define PULSE_LED_GND_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define PULSE_LED_GND_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define PULSE_LED_GND_GetValue()           PORTEbits.RE0
#define PULSE_LED_GND_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define PULSE_LED_GND_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define PULSE_LED_GND_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define PULSE_LED_GND_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set LOCK_LED_GND aliases
#define LOCK_LED_GND_TRIS                 TRISEbits.TRISE1
#define LOCK_LED_GND_LAT                  LATEbits.LATE1
#define LOCK_LED_GND_PORT                 PORTEbits.RE1
#define LOCK_LED_GND_ANS                  ANSELEbits.ANSE1
#define LOCK_LED_GND_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LOCK_LED_GND_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LOCK_LED_GND_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LOCK_LED_GND_GetValue()           PORTEbits.RE1
#define LOCK_LED_GND_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LOCK_LED_GND_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LOCK_LED_GND_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define LOCK_LED_GND_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set LIFT_CLOSE_BTN aliases
#define LIFT_CLOSE_BTN_TRIS                 TRISEbits.TRISE2
#define LIFT_CLOSE_BTN_LAT                  LATEbits.LATE2
#define LIFT_CLOSE_BTN_PORT                 PORTEbits.RE2
#define LIFT_CLOSE_BTN_ANS                  ANSELEbits.ANSE2
#define LIFT_CLOSE_BTN_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define LIFT_CLOSE_BTN_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define LIFT_CLOSE_BTN_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define LIFT_CLOSE_BTN_GetValue()           PORTEbits.RE2
#define LIFT_CLOSE_BTN_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define LIFT_CLOSE_BTN_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define LIFT_CLOSE_BTN_SetAnalogMode()      do { ANSELEbits.ANSE2 = 1; } while(0)
#define LIFT_CLOSE_BTN_SetDigitalMode()     do { ANSELEbits.ANSE2 = 0; } while(0)

// get/set HEAT2_BTN aliases
#define HEAT2_BTN_TRIS                 TRISEbits.TRISE3
#define HEAT2_BTN_LAT                  LATEbits.LATE3
#define HEAT2_BTN_PORT                 PORTEbits.RE3
#define HEAT2_BTN_WPU                  WPUEbits.WPUE3
#define HEAT2_BTN_SetHigh()            do { LATEbits.LATE3 = 1; } while(0)
#define HEAT2_BTN_SetLow()             do { LATEbits.LATE3 = 0; } while(0)
#define HEAT2_BTN_Toggle()             do { LATEbits.LATE3 = ~LATEbits.LATE3; } while(0)
#define HEAT2_BTN_GetValue()           PORTEbits.RE3
#define HEAT2_BTN_SetDigitalInput()    do { TRISEbits.TRISE3 = 1; } while(0)
#define HEAT2_BTN_SetDigitalOutput()   do { TRISEbits.TRISE3 = 0; } while(0)
#define HEAT2_BTN_SetPullup()          do { WPUEbits.WPUE3 = 1; } while(0)
#define HEAT2_BTN_ResetPullup()        do { WPUEbits.WPUE3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/