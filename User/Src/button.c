/**
 * @file button.c
 * @author Amu (amustriving@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "button.h"
#include "lcd_hal.h"

enum Button_IDs{
    btn1_id,
    btn2_id,
    btn3_id,
    btn4_id,
};

struct Button btn1;
struct Button btn2;
struct Button btn3;
struct Button btn4;

void BTN1_PRESS_DOWN_Handler(void* btn);
void BTN1_PRESS_UP_Handler(void* btn);
void BTN2_PRESS_REPEAT_Handler(void* btn);
void BTN2_SINGLE_Click_Handler(void* btn);
void BTN3_DOUBLE_Click_Handler(void* btn);
void BTN3_LONG_PRESS_START_Handler(void* btn);
void BTN4_LONG_PRESS_HOLD_Handler(void* btn);

/**
 * @brief 
 * 
 * @param button_id 
 * @return uint8_t 
 */
uint8_t read_button_GPIO(uint8_t button_id){
    switch (button_id)
    {
        case btn1_id:
            return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
            break;
        
        case btn2_id:
            return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
            break;
        
        case btn3_id:
            return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);
            break;
        
        case btn4_id:
            return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
            break;
        
        default:
            return 0;
            break;
    }
}

/**
 * @brief 
 * 
 */
void btn_Task(){
    button_init(&btn1, read_button_GPIO, 0, btn1_id);
    button_init(&btn2, read_button_GPIO, 0, btn2_id);
    button_init(&btn3, read_button_GPIO, 0, btn3_id);
    button_init(&btn4, read_button_GPIO, 0, btn4_id);

    button_attach(&btn1, PRESS_DOWN,       BTN1_PRESS_DOWN_Handler);
    button_attach(&btn1, PRESS_UP,         BTN1_PRESS_UP_Handler);
    // button_attach(&btn1, PRESS_REPEAT,     BTN1_PRESS_REPEAT_Handler);
    // button_attach(&btn1, SINGLE_CLICK,     BTN1_SINGLE_Click_Handler);
    // button_attach(&btn1, DOUBLE_CLICK,     BTN1_DOUBLE_Click_Handler);
    // button_attach(&btn1, LONG_PRESS_START, BTN1_LONG_PRESS_START_Handler);
    // button_attach(&btn1, LONG_PRESS_HOLD,  BTN1_LONG_PRESS_HOLD_Handler);

    // button_attach(&btn2, PRESS_DOWN,       BTN2_PRESS_DOWN_Handler);
    // button_attach(&btn2, PRESS_UP,         BTN2_PRESS_UP_Handler);
    button_attach(&btn2, PRESS_REPEAT,     BTN2_PRESS_REPEAT_Handler);
    button_attach(&btn2, SINGLE_CLICK,     BTN2_SINGLE_Click_Handler);
    // button_attach(&btn2, DOUBLE_CLICK,     BTN2_DOUBLE_Click_Handler);
    // button_attach(&btn2, LONG_PRESS_START, BTN2_LONG_PRESS_START_Handler);
    // button_attach(&btn2, LONG_PRESS_HOLD,  BTN2_LONG_PRESS_HOLD_Handler);

    // button_attach(&btn3, PRESS_DOWN,       BTN3_PRESS_DOWN_Handler);
    // button_attach(&btn3, PRESS_UP,         BTN3_PRESS_UP_Handler);
    // button_attach(&btn3, PRESS_REPEAT,     BTN3_PRESS_REPEAT_Handler);
    // button_attach(&btn3, SINGLE_CLICK,     BTN3_SINGLE_Click_Handler);
    button_attach(&btn3, DOUBLE_CLICK,     BTN3_DOUBLE_Click_Handler);
    button_attach(&btn3, LONG_PRESS_START, BTN3_LONG_PRESS_START_Handler);
    // button_attach(&btn3, LONG_PRESS_HOLD,  BTN3_LONG_PRESS_HOLD_Handler);

    // button_attach(&btn4, PRESS_DOWN,       BTN4_PRESS_DOWN_Handler);
    // button_attach(&btn4, PRESS_UP,         BTN4_PRESS_UP_Handler);
    // button_attach(&btn4, PRESS_REPEAT,     BTN4_PRESS_REPEAT_Handler);
    // button_attach(&btn4, SINGLE_CLICK,     BTN4_SINGLE_Click_Handler);
    // button_attach(&btn4, DOUBLE_CLICK,     BTN4_DOUBLE_Click_Handler);
    // button_attach(&btn4, LONG_PRESS_START, BTN4_LONG_PRESS_START_Handler);
    button_attach(&btn4, LONG_PRESS_HOLD,  BTN4_LONG_PRESS_HOLD_Handler);

    button_start(&btn1);
    button_start(&btn2);
    button_start(&btn3);
    button_start(&btn4);
}

uint8_t num[4] = {0};

void BTN1_PRESS_DOWN_Handler(void* btn){
    num[0]++;
    GuiShowNum(num);
}

void BTN1_PRESS_UP_Handler(void* btn){
    num[0]--;
    GuiShowNum(num);
}

void BTN2_PRESS_REPEAT_Handler(void* btn){
    num[1]++;
    GuiShowNum(num);
}

void BTN2_SINGLE_Click_Handler(void* btn){
    num[1]--;
    GuiShowNum(num);
}

void BTN3_DOUBLE_Click_Handler(void* btn){
    num[2]++;
    GuiShowNum(num);
}

void BTN3_LONG_PRESS_START_Handler(void* btn){
    num[2]--;
    GuiShowNum(num);
}

void BTN4_LONG_PRESS_HOLD_Handler(void* btn){
    num[3]++;
    GuiShowNum(num);
}
