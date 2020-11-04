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


#define DEBOUNCE   30
#define ACTUATOR_DELAY 200

void Debounce(void);
void Execute(void);
void LEDs(void);
void Massage(void);

unsigned char lift_open_debounce, lift_close_debounce, back_open_debounce, back_close_debounce, heat1_debounce, heat2_debounce, intensity_debounce, mode_debounce, lock_debounce;
__bit lift_open_state, lift_close_state, back_open_state, back_close_state, intensity_btn_state;
unsigned char heat1_state, heat2_state;


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

    while (1){
        Debounce();
        Execute();
        LEDs();
    }
}

//Check buttons and update states accordingly
void Debounce(void){
    
    //don't check any buttons while init_led_timer is on
    if(led_flash_timer){
       return; 
    }
    
    //Debounce the lock button. If the lock button is pressed, do not check other buttons
    if(!LOCK_BTN_GetValue()){
        if(lock_debounce){
            lock_debounce--;
        }else{
            lock_btn_state = 1;
            return;
        }
    }else{
        lock_debounce = DEBOUNCE;
        lock_btn_state = 0;
    }
    
    //Debounce lift open
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
    
    //Debounce lift close
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
    
    //Debounce back open
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
    
    //Debounce back close
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
    
    //if actuator buttons are pressed, don't check other buttons
    if(lift_open_state || lift_close_state || back_open_state || back_close_state){
        return;
    }
    
    //Debounce heat1 button. If button is pressed, change the heat1 state
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
    //Debounce heat2 button. If button is pressed, change the heat2 state
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
    //Debounce massage mode button.
    if(!MASSAGE_BTN_GetValue()){
        if(mode_debounce){
            mode_debounce--;
            if(!mode_debounce){
                massage_timer = MASSAGE_TIMEOUT;
                mode_btn_state = 1;
                if(!massage_power){         //turn on massage if it was off
                    massage_power = 1;
                }else{                      
                    //set should_change_mode. This will be cleared in the ISR if the massage button is held to turn massage off
                    should_change_mode = 1;
                }
            }
        }
    }else{
        mode_btn_state = 0;
        mode_debounce = DEBOUNCE;
        //on button release, cycle mode if it was a regular button press
        if(should_change_mode){
            should_change_mode = 0;
            massage_mode++;
            if(massage_mode > 2){
                massage_mode = 0;
            }
        }
    }
    
    //Debounce intensity button. Cycle intensity if massage is on when pressed.
    if(!INTENSITY_BTN_GetValue()){
        if(intensity_debounce){
            intensity_debounce--;
            if(!intensity_debounce){
                massage_timer = MASSAGE_TIMEOUT;
                intensity_btn_state = 1;
                if(massage_power){
                    massage_intensity_setting++;
                    if(massage_intensity_setting > 2){
                        massage_intensity_setting = 0;
                    }
                }
            }
        }
    }else{
        intensity_btn_state = 0;
        intensity_debounce = DEBOUNCE;
    }
}

void Execute(void){
    //Turn all outputs off and reset if HC is locked or flashing led's
    if(hand_control_locked || led_flash_timer){
        LIFT_OPEN_OUT_SetLow();
        LIFT_CLOSE_OUT_SetLow();
        BACK_OPEN_OUT_SetLow();
        BACK_CLOSE_OUT_SetLow();
        heat1_state = 0;
        heat2_state = 0;
        HEAT1_OUT_SetLow();
        HEAT2_OUT_SetLow();
        ZONE1_OUT_SetLow();
        ZONE2_OUT_SetLow();
        ZONE3_OUT_SetLow();
        ZONE4_OUT_SetLow();
        massage_mode = 0;
        massage_intensity_setting = 1;
        massage_power = 0;
        return;
    }

    //handle actuators. Only run an actuator if:
    // - exactly one actuator button is pressed
    // - the lock button is not pressed
    // - the actuator is not waiting on a timer to switch directions
    if(lift_open_state && !(lift_close_state || back_open_state || back_close_state || lock_btn_state)){
        if(lift_open_delay){
            LIFT_OPEN_OUT_SetLow();
        }else{
            LIFT_OPEN_OUT_SetHigh();
            lift_close_delay = ACTUATOR_DELAY;
        }
        LIFT_CLOSE_OUT_SetLow();
        BACK_OPEN_OUT_SetLow();
        BACK_CLOSE_OUT_SetLow();
    }else if(lift_close_state && !(lift_open_state || back_open_state || back_close_state || lock_btn_state)){
        if(lift_close_delay){
            LIFT_CLOSE_OUT_SetLow();
        }else{
            LIFT_CLOSE_OUT_SetHigh();
            lift_open_delay = ACTUATOR_DELAY;
        }
        LIFT_OPEN_OUT_SetLow();
        BACK_OPEN_OUT_SetLow();
        BACK_CLOSE_OUT_SetLow();
    }else if(back_open_state && !(lift_open_state || lift_close_state ||  back_close_state || lock_btn_state)){
        if(back_open_delay){
            BACK_OPEN_OUT_SetLow();
        }else{
            BACK_OPEN_OUT_SetHigh();
            back_close_delay = ACTUATOR_DELAY;
        }
        LIFT_OPEN_OUT_SetLow();
        LIFT_CLOSE_OUT_SetLow();
        BACK_CLOSE_OUT_SetLow();
    }else if(back_close_state && !(lift_open_state || lift_close_state || back_open_state || lock_btn_state)){
        if(back_close_delay){
            BACK_CLOSE_OUT_SetLow();
        }else{
            BACK_CLOSE_OUT_SetHigh();
            back_open_delay = ACTUATOR_DELAY;
        }
        LIFT_OPEN_OUT_SetLow();
        LIFT_CLOSE_OUT_SetLow();
        BACK_OPEN_OUT_SetLow();
    }else{
        LIFT_OPEN_OUT_SetLow();
        LIFT_CLOSE_OUT_SetLow();
        BACK_OPEN_OUT_SetLow();
        BACK_CLOSE_OUT_SetLow();
    }
    
    if(pwm_count){
        pwm_count--;
    }else{
        pwm_count = PWM_MAX;
    }
    
    //Turn off heat if respective timer has timed out
    if(!heat1_timer){
        heat1_state = 0;
    }
    if(!heat2_timer){
        heat2_state = 0;
    }
    
    // perform heat operations if no actuator buttons are pressed
    if(lift_open_state || lift_close_state || back_open_state || back_close_state){
        HEAT1_OUT_SetLow();
        HEAT2_OUT_SetLow();
    }else{  //stagger the heat, so the two heat outputs are never active at the same instant, even if both are on high
        if(pwm_count <= HEAT_PHASE_1){
            HEAT2_OUT_SetLow();
            if(heat1_state){
                HEAT1_OUT_SetHigh();
            }else{
                HEAT1_OUT_SetLow();
            }
        }else if(pwm_count <= HEAT_PHASE_2){
            HEAT2_OUT_SetLow();
            if(heat1_state == 2){
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
            if(heat2_state == 2){
                HEAT2_OUT_SetHigh();
            }else{
                HEAT2_OUT_SetLow();
            }
        } 
    }
    
    //perform massage functions
    Massage(); 
}

void LEDs(void){
    //Turn on all LED's for a brief time during start-up and after HC is unlocked
    if(led_flash_timer){
        LOCK_LED_GND_SetLow();
        
        LIFT_LED_GND_SetLow();
        BACK_LED_GND_SetLow();
        
        HEAT1_RED_GND_SetLow();
        HEAT1_GRN_GND_SetLow();
        
        HEAT2_RED_GND_SetLow();
        HEAT2_GRN_GND_SetLow();
        
        STEADY_LED_GND_SetLow();
        WAVE_LED_GND_SetLow();
        PULSE_LED_GND_SetLow();
        LOW_LED_GND_SetLow();
        MED_LED_GND_SetLow();
        HIGH_LED_GND_SetLow();
        
        INTENSITY_LED_SetHigh();
        MODE_LED_SetHigh();  
        return;
    }
    
    //turn off all LEDs except the lock LED while the HC is locked
    if(hand_control_locked){
        LOCK_LED_GND_SetLow();
        
        LIFT_LED_GND_SetHigh();
        BACK_LED_GND_SetHigh();
        
        HEAT1_RED_GND_SetHigh();
        HEAT1_GRN_GND_SetHigh();
        
        HEAT2_RED_GND_SetHigh();
        HEAT2_GRN_GND_SetHigh();
        
        STEADY_LED_GND_SetHigh();
        WAVE_LED_GND_SetHigh();
        PULSE_LED_GND_SetHigh();
        LOW_LED_GND_SetHigh();
        MED_LED_GND_SetHigh();
        HIGH_LED_GND_SetHigh();
        
        INTENSITY_LED_SetLow();
        MODE_LED_SetLow();  
        return;
    }
    //HC is not locked, so turn off LOCK LED
    LOCK_LED_GND_SetHigh();

    //check if any actuator button is pressed
    if(lift_open_state || lift_close_state || back_open_state || back_close_state){
        //turn off Heat and massage LEDs when any actuator button is pressed
        HEAT1_RED_GND_SetHigh();
        HEAT1_GRN_GND_SetHigh();

        HEAT2_RED_GND_SetHigh();
        HEAT2_GRN_GND_SetHigh();

        STEADY_LED_GND_SetHigh();
        WAVE_LED_GND_SetHigh();
        PULSE_LED_GND_SetHigh();
        LOW_LED_GND_SetHigh();
        MED_LED_GND_SetHigh();
        HIGH_LED_GND_SetHigh();

        INTENSITY_LED_SetLow();
        MODE_LED_SetLow();

        //Turn on lift or back LED if they are running
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
    }else{
        //turn off back and lift LED if no actuators are running
        LIFT_LED_GND_SetHigh();
        BACK_LED_GND_SetHigh();

        //Heat LEDs
        switch(heat1_state){
            case 1:
                HEAT1_RED_GND_SetHigh();
                HEAT1_GRN_GND_SetLow();
                break;
            case 2:
                HEAT1_RED_GND_SetLow();
                HEAT1_GRN_GND_SetHigh();
                break;
            default:
                HEAT1_RED_GND_SetHigh();
                HEAT1_GRN_GND_SetHigh();
                break;
        }

        switch(heat2_state){
            case 1:
                HEAT2_RED_GND_SetHigh();
                HEAT2_GRN_GND_SetLow();
                break;
            case 2:
                HEAT2_RED_GND_SetLow();
                HEAT2_GRN_GND_SetHigh();
                break;
            default:
                HEAT2_RED_GND_SetHigh();
                HEAT2_GRN_GND_SetHigh();
                break;
        }

        //Massage_LEDs
        if(massage_power){
            //turn on mode and intensity button backlight if massage is on
            INTENSITY_LED_SetHigh(); 
            MODE_LED_SetHigh();

            switch(massage_mode){
                case 0:     //steady mode
                    STEADY_LED_GND_SetLow();
                    WAVE_LED_GND_SetHigh();
                    PULSE_LED_GND_SetHigh();
                    break;
                case 1:     //wave mode
                    STEADY_LED_GND_SetHigh();
                    WAVE_LED_GND_SetLow();
                    PULSE_LED_GND_SetHigh();
                    break;
                case 2:     //pulse mode
                    STEADY_LED_GND_SetHigh();
                    WAVE_LED_GND_SetHigh();
                    PULSE_LED_GND_SetLow();
                    break;
                default: 
                    break;
            }
            switch(massage_intensity_setting){
                case 0:     //low intensity
                    LOW_LED_GND_SetLow();
                    MED_LED_GND_SetHigh();
                    HIGH_LED_GND_SetHigh();
                    break;
                case 1:     //med intensity
                    LOW_LED_GND_SetHigh();
                    MED_LED_GND_SetLow();
                    HIGH_LED_GND_SetHigh();
                    break;
                case 2:     //high intensity
                    LOW_LED_GND_SetHigh();
                    MED_LED_GND_SetHigh();
                    HIGH_LED_GND_SetLow();
                    break;
                default:
                    break;
            }
        }else{
            //turn massage LEDs off if massage is off
            STEADY_LED_GND_SetHigh();
            WAVE_LED_GND_SetHigh();
            PULSE_LED_GND_SetHigh();
            LOW_LED_GND_SetHigh();
            MED_LED_GND_SetHigh();
            HIGH_LED_GND_SetHigh();
            INTENSITY_LED_SetLow();
            MODE_LED_SetLow();
        }
    }
}

void Massage(void){
    //turn off massage if massage timer has ended
    if(!massage_timer){
        massage_power = 0;
    }
    //run massage if massage is on and no actuator buttons are pressed
    if(massage_power && !(lift_open_state || lift_close_state || back_open_state || back_close_state)){
        //updated massage intensity
        switch(massage_intensity_setting){
            case 0:
                massage_intensity = MASSAGE_LOW_PWM;
                break;
            case 1:
                massage_intensity = MASSAGE_MED_PWM;
                break;
            case 2:
                massage_intensity = MASSAGE_HIGH_PWM;
                break;
        }
        
        switch(massage_mode){
            case 0: //steady
                //all zones run at the same continuous intensity
                if(steady_massage_intensity > pwm_count){
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
            case 1: //wave
                
                //Zone ramping up
                if(pulse_wave_in_intensity > pwm_count){
                    WaveInOn();
                }else{
                    WaveInOff();
                }
                //Zone ramping down
                if(pulse_wave_out_intensity > pwm_count){
                    WaveOutOn();
                }else{
                    WaveOutOff();
                }
                //Zones currently off
                WaveGap1Off();
                WaveGap2Off();
                break;
            case 2://pulse
                if(pulse_direction){
                    //all zones ramp up if pulse_direction is 1
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
                    //all zones ramp down if pulse direction is 0
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
                //reset to 0 if massage mode is none of these
                massage_mode = 0;
                break;
        }
    }else{
        //massage off
        ZONE1_OUT_SetLow();
        ZONE2_OUT_SetLow();
        ZONE3_OUT_SetLow();
        ZONE4_OUT_SetLow();
    }
}

/**
 End of File
*/