/*
 * @file gpio.h
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief GPIO Driver for PIC18F45Q10
 * 
 * 
 * Provides functions for configuring and controlling GPIO pins,
 * including bitwise manipulation, atomic writes and debounce handling.
 */

#ifndef GPIO_H
#define	GPIO_H

#include "pic18f45q10_regs.h"
#include "config.h"

/** Port definitions for better readability */
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

/** Pin direction enumeration */
typedef enum {
    GPIO_INPUT = 1, ///< Configure pin as input
    GPIO_OUTPUT = 0 ///< COnfigure pin as output
} gpio_direction_t;

/** GPIO API Function Prototypes */

/**
 * @brief Initializes all GPIOs with default states (set in config.h)
 */
void GPIO_Init(void);

/**
 * @brief Configure a GPIO pin as input or output
 */
void GPIO_SetDirection(unsigned char port, unsigned char pin, gpio_direction_t direction);

/**
 * @brief Writes a value (HIGH/LOW) to a GPIO pin (atomic write).
 */
void GPIO_Write(unsigned char port, unsigned char pin, unsigned char value);

/**
 * @brief Reads the logic state of a GPIO pin.
 */
unsigned char GPIO_Read(unsigned char port, unsigned char pin);

/**
 * @brief Reads the logic state of a GPIO pin with debounce.
 */
unsigned char GPIO_ReadDebounced(unsigned char port, unsigned char pin);

/**
 * @brief Macro for setting a pin HIGH(bitwise)
 */
static inline void GPIO_SetPin(unsigned char port, unsigned char pin){
    switch(port){
        case GPIO_PORTA: LATA.value |= (1 << pin); break;
        case GPIO_PORTB: LATB.value |= (1 << pin); break;
        case GPIO_PORTC: LATC.value |= (1 << pin); break;
    }
}

/**
 * @brief Macro for setting a pin LOW(bitwise)
 */
static inline void GPIO_ClearPin(unsigned char port, unsigned char pin){
    switch(port){
        case GPIO_PORTA: LATA.value &= ~(1 << pin); break;
        case GPIO_PORTB: LATB.value &= ~(1 << pin); break;
        case GPIO_PORTC: LATC.value &= ~(1 << pin); break;
    }
}

/** 
 * @brief Macro for toggling a pin (bitwise).
 */
static inline void GPIO_TogglePin(unsigned char port, unsigned char pin) {
    switch (port) {
        case GPIO_PORTA: LATA.value ^= (1 << pin); break;
        case GPIO_PORTB: LATB.value ^= (1 << pin); break;
        case GPIO_PORTC: LATC.value ^= (1 << pin); break;
    }
}

#endif	/* GPIO_H */

