/**
 * @file example_blink_led.c
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief Blinks an LED on RA0
 */

#include "gpio.h"
#include "config_bits.h"

// Define the LED pin
#define LED_PORT GPIO_PORTA
#define LED_PIN  0

/**
 * @brief Delays execution for a given number of milliseconds.
 */
void delay_ms(unsigned int ms) {
    while (ms--) {
        for (volatile unsigned int j = 0; j < 500; j++) {
            __asm__ volatile ("nop");
        }
    }
}

void Example_Run(void) {
    // Initialize the GPIO system
    GPIO_Init();

    // Set RA0 as output for LED
    GPIO_SetDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);

    while (1) {
        // Toggle LED by reading current state and inverting it
        GPIO_Write(LED_PORT, LED_PIN, !GPIO_Read(LED_PORT, LED_PIN));

        // Delay for 500ms
        delay_ms(500);
    }
}

