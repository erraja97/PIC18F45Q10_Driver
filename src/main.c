/**
 * @file main.c
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief Blink LED Test Program for PIC18F45Q10
 *
 * This program tests the GPIO driver by toggling an LED on RA0.
 */

#include "gpio.h"
#include "config_bits.h"

// Define the LED pin
#define LED_PORT GPIO_PORTA
#define LED_PIN  0

/**
 * @brief Delays execution for a given number of milliseconds.
 *
 * This is a simple blocking delay. For accurate timing, use a timer module instead.
 *
 * @param ms The number of milliseconds to delay.
 */
void delay_ms(unsigned int ms) {
    volatile unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 500; j++) {
            __asm__ volatile ("nop");  // Do nothing (wastes one cycle)
        }
    }
}

/**
 * @brief Main entry point of the program.
 */
void main(void) {
    // Initialize the GPIO system
    GPIO_Init();

    // Set RB0 as output for LED
    GPIO_SetDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);

    while (1) {
        // Toggle LED
        GPIO_TogglePin(LED_PORT, LED_PIN);

        // Delay for 500ms
        delay_ms(500);
    }
}


