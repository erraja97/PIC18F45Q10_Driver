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

void GPIO_Init(void) {
    TRISA.value = GPIO_DEFAULT_TRISA;
    TRISB.value = GPIO_DEFAULT_TRISB;
    TRISC.value = GPIO_DEFAULT_TRISC;

    LATA.value = GPIO_DEFAULT_LATA;
    LATB.value = GPIO_DEFAULT_LATB;
    LATC.value = GPIO_DEFAULT_LATC;
}

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

unsigned char GPIO_Read(unsigned char port, unsigned char pin) {
    if (pin > 7) return 0;

    switch (port) {
        case GPIO_PORTA:
            return (TRISA.value & (1 << pin)) ? ((PORTA.value >> pin) & 0x01) : ((LATA.value >> pin) & 0x01);
        case GPIO_PORTB:
            return (TRISB.value & (1 << pin)) ? ((PORTB.value >> pin) & 0x01) : ((LATB.value >> pin) & 0x01);
        case GPIO_PORTC:
            return (TRISC.value & (1 << pin)) ? ((PORTC.value >> pin) & 0x01) : ((LATC.value >> pin) & 0x01);
        default:
            return 0;
    }
}

unsigned char GPIO_ReadDebounced(unsigned char port, unsigned char pin) {
    uint8_t stable_value, temp_value;
    uint8_t debounce_counter = 5;  // Number of stable reads before confirming

    stable_value = GPIO_Read(port, pin); // Read initial value

    for (uint8_t i = 0; i < debounce_counter; i++) {
        temp_value = GPIO_Read(port, pin);  // Read again
        if (temp_value != stable_value) {
            i = 0;  // Reset counter if value changes
            stable_value = temp_value;
        }
    }
    
    return stable_value;
}

void GPIO_WritePort(unsigned char port, uint8_t value) {
    INTCON.GIE = 0;  // Disable global interrupts to prevent race conditions

    switch (port) {
        case GPIO_PORTA:
            LATA.value = value;  // Write full 8-bit value to PORTA
            break;
        case GPIO_PORTB:
            LATB.value = value;  // Write full 8-bit value to PORTB
            break;
        case GPIO_PORTC:
            LATC.value = value;  // Write full 8-bit value to PORTC
            break;
    }

    INTCON.GIE = 1;  // Re-enable global interrupts
}

uint8_t GPIO_ReadPort(unsigned char port) {
    switch (port) {
        case GPIO_PORTA:
            return (TRISA.value == 0xFF) ? PORTA.value : LATA.value;  
        case GPIO_PORTB:
            return (TRISB.value == 0xFF) ? PORTB.value : LATB.value;
        case GPIO_PORTC:
            return (TRISC.value == 0xFF) ? PORTC.value : LATC.value;
        default:
            return 0;
    }
}

uint8_t GPIO_ReadPortDebounced(unsigned char port) {
    uint8_t stable_value, temp_value;
    uint8_t debounce_counter = 5;

    stable_value = GPIO_ReadPort(port);

    for (uint8_t i = 0; i < debounce_counter; i++) {
        temp_value = GPIO_ReadPort(port);
        if (temp_value != stable_value) {
            i = 0;
            stable_value = temp_value;
        }
    }
    
    return stable_value;
}




