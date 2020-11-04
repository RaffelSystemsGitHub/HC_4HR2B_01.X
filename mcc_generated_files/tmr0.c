/**
  TMR0 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr0.c

  @Summary
    This is the generated driver implementation file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR0.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F1937
        Driver Version    :  2.01
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr0.h"
#include "pin_manager.h"

#define LOCK_HOLD_TIME 4500     //Time to hold lock button to lock the hand control
#define UNLOCK_HOLD_TIME 8000   //Time to hold lock button to unlock the hand control

/**
  Section: Global Variables Definitions
*/

volatile uint8_t timer0ReloadVal;
void (*TMR0_InterruptHandler)(void);
/**
  Section: TMR0 APIs
*/

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface
	
    // PSA assigned; PS 1:4; TMRSE Increment_hi_lo; mask the nWPUEN and INTEDG bits
    OPTION_REG = (uint8_t)((OPTION_REG & 0xC0) | (0xD1 & 0x3F)); 
	//OPTION_REG = 0b10001000;
    // TMR0 6; 
    TMR0 = 0x0A;
	
    // Load the TMR value to reload variable
    timer0ReloadVal= 10;

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt
    INTCONbits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);
}

uint8_t TMR0_ReadTimer(void)
{
    uint8_t readVal;

    readVal = TMR0;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer0 register
    TMR0 = timerVal;
}

void TMR0_Reload(void)
{
    // Write to the Timer0 register
    TMR0 = timer0ReloadVal;
}

void TMR0_ISR(void)
{

    // Clear the TMR0 interrupt flag
    //Generated code to handle timer ISR
    INTCONbits.TMR0IF = 0;

    TMR0 = timer0ReloadVal;

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }
    //End generated code
    
    //Decrement timers
    if(lift_open_delay){
        lift_open_delay--;
    }
    if(lift_close_delay){
        lift_close_delay--;
    }
    if(back_open_delay){
        back_open_delay--;
    }
    if(back_close_delay){
        back_close_delay--;
    }
    if(led_flash_timer){
        led_flash_timer--;
    }
    
    //Massage and heat shutdown timers
    if(second_timer){
        second_timer--;
    }else{
        second_timer = SECOND_COUNTS;
        if(heat1_timer){
            heat1_timer--;
        }
        if(heat2_timer){
            heat2_timer--;
        }

        if(massage_timer){
            massage_timer--;
        }
    }
    
    if(lock_btn_state){
        if(!lock_flag){     //only execute one change to lock state per press
            if(lock_timer){
                lock_timer--;
            }else{
                lock_flag = 1;
                hand_control_locked = !hand_control_locked;
                //if the actuator is being unlocked, set the init led timer
                if(!hand_control_locked){
                    led_flash_timer = INIT_LED_TIME;
                }
            }
        }
    }else{
        lock_flag = 0;
        //Set required timer hold time
        if(hand_control_locked){
            lock_timer = UNLOCK_HOLD_TIME;
        }else{
            lock_timer = LOCK_HOLD_TIME;
        }
    }
   
    //handle massage hold timer
    if(mode_btn_state){
        if(massage_hold_timer){
            massage_hold_timer--;
        }else{
            massage_power = 0;
            should_change_mode = 0;
        }
    }else{
        massage_hold_timer = MASSAGE_HOLD_TIME;
    }
    
    //handle changes to massage phase, used in wave and pulse functions
    if(phase_change_timer){
        phase_change_timer--;
    }else{
        if(massage_phase >= MASSAGE_PHASE_MAX){
            massage_phase = 0;
            //rotate zone function pointes for the wave function
            WavePlaceHolderOn = WaveInOn;       //store zone that just ramped up
            WavePlaceHolderOff = WaveInOff;
            WaveInOn = WaveGap2On;              //previous Gap2 starts ramping up
            WaveInOff = WaveGap2Off;
            WaveGap2On = WaveGap1On;            //previous Gap1 is now Gap2
            WaveGap2Off = WaveGap1Off;
            WaveGap1On = WaveOutOn;             //zone that finished ramping down is not Gap1
            WaveGap1Off = WaveOutOff;
            WaveOutOn = WavePlaceHolderOn;      //zone that just ramped up starts ramping down
            WaveOutOff = WavePlaceHolderOff;
            //change whether pulse is ramping up or down
            pulse_direction = !pulse_direction;
        }
        massage_phase++;
        phase_change_timer = PHASE_CHANGE_TIME;
        //calculate massage intensity values
        pulse_wave_in_intensity = massage_intensity*massage_phase/MASSAGE_PHASE_MAX;
        pulse_wave_out_intensity = massage_intensity - pulse_wave_in_intensity;
        pulse_wave_in_intensity += MIN_MASSAGE_PWM;
        pulse_wave_out_intensity += MIN_MASSAGE_PWM;
        steady_massage_intensity = massage_intensity + MIN_MASSAGE_PWM;
    }
}


void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void){
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
}


//Functions pointed to by wave function pointers
void Z1SetHigh(void){
    ZONE1_OUT_SetHigh();
}

void Z1SetLow(){
    ZONE1_OUT_SetLow();
}

void Z2SetHigh(void){
    ZONE2_OUT_SetHigh();
}

void Z2SetLow(){
    ZONE2_OUT_SetLow();
}

void Z3SetHigh(void){
    ZONE3_OUT_SetHigh();
}

void Z3SetLow(){
    ZONE3_OUT_SetLow();
}

void Z4SetHigh(void){
    ZONE4_OUT_SetHigh();
}

void Z4SetLow(){
    ZONE4_OUT_SetLow();
}

/**
  End of File
*/
