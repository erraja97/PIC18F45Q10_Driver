/**
 * @file gpio.c
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief Enhanced GPIO Driver for PIC18F45Q10
 *
 * Implements GPIO functions with bitwise operations, atomic writes, 
 * debounce handling, and safe error checking.
 */

#include "gpio.h"

/**
 * @brief Initializes all GPIOs with default states (set in config.h).
 */
void GPIO_Init(void) {
    TRISA.value = GPIO_DEFAULT_TRISA;
    TRISB.value = GPIO_DEFAULT_TRISB;
    TRISC.value = GPIO_DEFAULT_TRISC;

    LATA.value = GPIO_DEFAULT_LATA;
    LATB.value = GPIO_DEFAULT_LATB;
    LATC.value = GPIO_DEFAULT_LATC;
}

/**
 * @brief Configures a GPIO pin as input or output.
 */
void GPIO_SetDirection(unsigned char port, unsigned char pin, gpio_direction_t direction) {
    if (pin > 7) return;  // Prevent out-of-bounds pin access

    switch (port) {
        case GPIO_PORTA:
            TRISA.value = (direction) ? (TRISA.value | (uint8_t)(1 << pin)) : (TRISA.value & (uint8_t)~(1 << pin));
            break;
        case GPIO_PORTB:
            TRISB.value = (direction) ? (TRISB.value | (uint8_t)(1 << pin)) : (TRISB.value & (uint8_t)~(1 << pin));
            break;
        case GPIO_PORTC:
            TRISC.value = (direction) ? (TRISC.value | (uint8_t)(1 << pin)) : (TRISC.value & (uint8_t)~(1 << pin));
            break;
    }
}

/**
 * @brief Writes a logic HIGH or LOW to a GPIO pin (atomic write).
 */
void GPIO_Write(unsigned char port, unsigned char pin, unsigned char value) {
    if (pin > 7) return;

    INTCON.GIE = 0;  // Disable global interrupts (prevents race conditions)

    switch (port) {
        case GPIO_PORTA:
            LATA.value = (value) ? (LATA.value | (uint8_t)(1 << pin)) : (LATA.value & (uint8_t)~(1 << pin));
            break;
        case GPIO_PORTB:
            LATB.value = (value) ? (LATB.value | (uint8_t)(1 << pin)) : (LATB.value & (uint8_t)~(1 << pin));
            break;
        case GPIO_PORTC:
            LATC.value = (value) ? (LATC.value | (uint8_t)(1 << pin)) : (LATC.value & (uint8_t)~(1 << pin));
            break;
    }

    INTCON.GIE = 1;  // Re-enable global interrupts
}

/**
 * @brief Reads the current logic state of a GPIO pin.
 */
unsigned char GPIO_Read(unsigned char port, unsigned char pin) {
    if (pin > 7) return 0;

    switch (port) {
        case GPIO_PORTA: return (PORTA.value >> pin) & 0x01;
        case GPIO_PORTB: return (PORTB.value >> pin) & 0x01;
        case GPIO_PORTC: return (PORTC.value >> pin) & 0x01;
        default: return 0;
    }
}

/**
 * @brief Reads the logic state of a GPIO pin with debounce.
 */
unsigned char GPIO_ReadDebounced(unsigned char port, unsigned char pin) {
    if (pin > 7) return 0;

    unsigned char stable_state = GPIO_Read(port, pin);
    for (int i = 0; i < 5; i++) {  // Read 5 times
        if (GPIO_Read(port, pin) != stable_state) {
            i = 0;  // Reset counter if state changes
        }
    }
    return stable_state;
}
