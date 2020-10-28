/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F1937
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "main.h"

#define DEBOUNCE   30
#define ACTUATOR_DELAY 200

void Debounce(void);
void Execute(void);
void LEDs(void);
void Massage(void);

unsigned char lift_open_debounce, lift_close_debounce, back_open_debounce, back_close_debounce, heat1_debounce, heat2_debounce, intensity_debounce, mode_debounce, lock_debounce;
__bit lift_open_state, lift_close_state, back_open_state, back_close_state, mode_btn_state, intensity_btn_state;
unsigned char heat1_state, heat2_state, massage_mode;







/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        Debounce();
        Execute();
        LEDs();
        // Add your application code
    }
}


void Debounce(void){
    if(!LIFT_OPEN_BTN_GetValue()){
        if(lift_open_debounce){
            lift_open_debounce--;
        }else{
            lift_open_state = 1;
        }
    }else{
        lift_open_debounce = DEBOUNCE;
        lift_open_state = 0;
    }
    
    if(!LIFT_CLOSE_BTN_GetValue()){
        if(lift_close_debounce){
            lift_close_debounce--;
        }else{
            lift_close_state = 1;
        }
    }else{
        lift_close_debounce = DEBOUNCE;
        lift_close_state = 0;
    }
    
    if(!BACK_OPEN_BTN_GetValue()){
        if(back_open_debounce){
            back_open_debounce--;
        }else{
            back_open_state = 1;
        }
    }else{
        back_open_debounce = DEBOUNCE;
        back_open_state = 0;
    }
    
    if(!BACK_CLOSE_BTN_GetValue()){
        if(back_close_debounce){
            back_close_debounce--;
        }else{
            back_close_state = 1;
        }
    }else{
        back_close_debounce = DEBOUNCE;
        back_close_state = 0;
    }
    
    if(!HEAT1_BTN_GetValue()){
        if(heat1_debounce){
            heat1_debounce--;
            if(!heat1_debounce){
                heat1_timer = HEAT_TIMEOUT; 
                heat1_state++;
                if(heat1_state > 2){
                    heat1_state = 0;
                }
            }
        }
    }else{
        heat1_debounce = DEBOUNCE;
    }
    if(!HEAT2_BTN_GetValue()){
        if(heat2_debounce){
            heat2_debounce--;
            if(!heat2_debounce){
                heat2_timer = HEAT_TIMEOUT;
                heat2_state++;
                if(heat2_state > 2){
                    heat2_state = 0;
                }
            }
        }
    }else{
        heat2_debounce = DEBOUNCE;
    }
    
    if(!LOCK_BTN_GetValue()){
        if(lock_debounce){
            lock_debounce--;
        }else{
            lock_btn_state = 1;
        }
    }else{
        lock_debounce = DEBOUNCE;
        lock_btn_state = 0;
    }
    
    if(!MASSAGE_BTN_GetValue()){
        if(mode_debounce){
            mode_debounce--;
            if(!mode_debounce){
                massage_timer = MASSAGE_TIMEOUT;
                mode_btn_state = 1;
                if(!massage_intensity_setting){
                    massage_intensity_setting = 1;
                }else{
                    massage_mode++;
                    if(massage_mode > 2){
                        massage_mode = 0;
                    }
                }
            }
        }
    }else{
        mode_btn_state = 0;
        mode_debounce = DEBOUNCE;
    }
    
    if(!INTENSITY_BTN_GetValue()){
        if(intensity_debounce){
            intensity_debounce--;
            if(!intensity_debounce){
                massage_timer = MASSAGE_TIMEOUT;
                intensity_btn_state = 1;
                massage_intensity_setting++;
                if(massage_intensity_setting > 3){
                    massage_intensity_setting = 0;
                }
            }
        }
    }else{
        intensity_btn_state = 0;
        intensity_debounce = DEBOUNCE;
    }
}

void Execute(void){
    
    if(lock_btn_state || lock_actuators || (lift_open_state==lift_close_state)){
        LIFT_OPEN_OUT_SetLow();
        LIFT_CLOSE_OUT_SetLow();
    }else{
        if(lift_open_state){
            LIFT_CLOSE_OUT_SetLow(); 
            if(lift_open_delay){
                LIFT_OPEN_OUT_SetLow();
            }else{
                LIFT_OPEN_OUT_SetHigh();
                lift_close_delay = ACTUATOR_DELAY;
            }
        }else if(lift_close_state){
            LIFT_OPEN_OUT_SetLow();
            if(lift_close_delay){
                LIFT_CLOSE_OUT_SetLow();
            }else{
                LIFT_CLOSE_OUT_SetHigh(); 
                lift_open_delay = ACTUATOR_DELAY;
            }
        }
    }
    
    if(lock_btn_state || lock_actuators || (back_open_state==back_close_state)){
        BACK_OPEN_OUT_SetLow();
        BACK_CLOSE_OUT_SetLow();
    }else{
        if(back_open_state){
            BACK_CLOSE_OUT_SetLow(); 
            if(back_open_delay){
                BACK_OPEN_OUT_SetLow();
            }else{
                BACK_OPEN_OUT_SetHigh();
                back_close_delay = ACTUATOR_DELAY;
            }
        }else if(back_close_state){
            BACK_OPEN_OUT_SetLow();
            if(back_close_delay){
                BACK_CLOSE_OUT_SetLow();
            }else{
                BACK_CLOSE_OUT_SetHigh(); 
                back_open_delay = ACTUATOR_DELAY;
            }
        }
    }
    
    if(!heat1_timer){
        heat1_state = 0;
    }
    if(!heat2_timer){
        heat2_state = 0;
    }
    if(LIFT_OPEN_OUT_GetValue() || LIFT_CLOSE_OUT_GetValue() || BACK_OPEN_OUT_GetValue() || BACK_CLOSE_OUT_GetValue()){
        HEAT1_OUT_SetLow();
        HEAT2_OUT_SetLow();
    }else{
        if(pwm_count <= HEAT_PHASE_1){
            HEAT2_OUT_SetLow();
            if(heat1_state){
                HEAT1_OUT_SetHigh();
            }else{
                HEAT1_OUT_SetLow();
            }
        }else if(pwm_count <= HEAT_PHASE_2){
            HEAT2_OUT_SetLow();
            if(heat1_state == 1){
                HEAT1_OUT_SetHigh();
            }else{
                HEAT1_OUT_SetLow();
            }
        }else if(pwm_count <= HEAT_PHASE_3){
            HEAT1_OUT_SetLow();
            if(heat2_state){
                HEAT2_OUT_SetHigh();
            }else{
                HEAT2_OUT_SetLow();
            }
        }else{
            HEAT1_OUT_SetLow();
            if(heat2_state == 1){
                HEAT2_OUT_SetHigh();
            }else{
                HEAT2_OUT_SetLow();
            }
        } 
    }
    switch(massage_intensity_setting){
        case 0:
            massage_intensity = 0;
            break;
        case 1:
            massage_intensity = MASSAGE_LOW_PWM;
            break;
        case 2:
            massage_intensity = MASSAGE_MED_PWM;
            break;
        case 3:
            massage_intensity = MASSAGE_HIGH_PWM;
            break;
    }
    Massage();
}

void LEDs(void){
    if(lock_actuators){
        LOCK_LED_GND_SetLow();
    }else{
        LOCK_LED_GND_SetHigh();
    }
    if(LIFT_OPEN_OUT_GetValue() || LIFT_CLOSE_OUT_GetValue()){
        LIFT_LED_GND_SetLow();
    }else{
        LIFT_LED_GND_SetHigh();
    }
    
    if(BACK_OPEN_OUT_GetValue() || BACK_CLOSE_OUT_GetValue()){
        BACK_LED_GND_SetLow();
    }else{
        BACK_LED_GND_SetHigh();
    }
    
    switch(heat1_state){
        case 1:
            HEAT1_RED_GND_SetLow();
            HEAT1_GRN_GND_SetHigh();
            break;
        case 2:
            HEAT1_RED_GND_SetLow();
            HEAT1_GRN_GND_SetLow();
            break;
        default:
            HEAT1_RED_GND_SetHigh();
            HEAT1_GRN_GND_SetHigh();
            break;
    }
    
    switch(heat2_state){
        case 1:
            HEAT2_RED_GND_SetLow();
            HEAT2_GRN_GND_SetHigh();
            break;
        case 2:
            HEAT2_RED_GND_SetLow();
            HEAT2_GRN_GND_SetLow();
            break;
        default:
            HEAT2_RED_GND_SetHigh();
            HEAT2_GRN_GND_SetHigh();
            break;
    }
    
    if(massage_intensity_setting){

        switch(massage_mode){
            case 0:
                STEADY_LED_GND_SetLow();
                WAVE_LED_GND_SetHigh();
                PULSE_LED_GND_SetHigh();
                break;
            case 1:
                STEADY_LED_GND_SetHigh();
                WAVE_LED_GND_SetLow();
                PULSE_LED_GND_SetHigh();
                break;
            case 2:
                STEADY_LED_GND_SetHigh();
                WAVE_LED_GND_SetHigh();
                PULSE_LED_GND_SetLow();
                break;
            default: 
                break;
        }
        switch(massage_intensity_setting){
            case 1: 
                LOW_LED_GND_SetLow();
                MED_LED_GND_SetHigh();
                HIGH_LED_GND_SetHigh();
                break;
            case 2:
                LOW_LED_GND_SetHigh();
                MED_LED_GND_SetLow();
                HIGH_LED_GND_SetHigh();
                break;
            case 3:
                LOW_LED_GND_SetHigh();
                MED_LED_GND_SetHigh();
                HIGH_LED_GND_SetLow();
                break;
            default:
                break;
        }
    }else{
        STEADY_LED_GND_SetHigh();
        WAVE_LED_GND_SetHigh();
        PULSE_LED_GND_SetHigh();
        LOW_LED_GND_SetHigh();
        MED_LED_GND_SetHigh();
        HIGH_LED_GND_SetHigh();
    }  
}

void Massage(void){    
    if(!massage_timer){
        massage_intensity_setting = 0;
    }
    if(massage_intensity_setting && LIFT_LED_GND_GetValue()){
        switch(massage_mode){
            case 0://continuous
                if(massage_intensity > pwm_count){
                    ZONE1_OUT_SetHigh();
                    ZONE2_OUT_SetHigh();
                    ZONE3_OUT_SetHigh();
                    ZONE4_OUT_SetHigh();
                }else{
                    ZONE1_OUT_SetLow();
                    ZONE2_OUT_SetLow();
                    ZONE3_OUT_SetLow();
                    ZONE4_OUT_SetLow();
                }
                break;
            case 1://wave
                if(pulse_wave_in_intensity > pwm_count){
                    WaveInOn();
                    WaveOutOff();
                }else{
                    WaveInOff();
                    WaveOutOn();
                }
                WaveGap1Off();
                WaveGap2Off();
                break;
            case 2://pulse
                if(pulse_direction){
                    if(pulse_wave_in_intensity > pwm_count){
                        ZONE1_OUT_SetHigh();
                        ZONE2_OUT_SetHigh();
                        ZONE3_OUT_SetHigh();
                        ZONE4_OUT_SetHigh();
                    }else{
                        ZONE1_OUT_SetLow();
                        ZONE2_OUT_SetLow();
                        ZONE3_OUT_SetLow();
                        ZONE4_OUT_SetLow();
                    }
                }else{
                    if(pulse_wave_out_intensity > pwm_count){
                        ZONE1_OUT_SetHigh();
                        ZONE2_OUT_SetHigh();
                        ZONE3_OUT_SetHigh();
                        ZONE4_OUT_SetHigh();
                    }else{
                        ZONE1_OUT_SetLow();
                        ZONE2_OUT_SetLow();
                        ZONE3_OUT_SetLow();
                        ZONE4_OUT_SetLow();
                    }
                }

                break;
            default: 
                ZONE1_OUT_SetLow();
                ZONE2_OUT_SetLow();
                ZONE3_OUT_SetLow();
                ZONE4_OUT_SetLow();
                break;
        }
    }else{
        ZONE1_OUT_SetLow();
        ZONE2_OUT_SetLow();
        ZONE3_OUT_SetLow();
        ZONE4_OUT_SetLow();
    }
}

/**
 End of File
*/