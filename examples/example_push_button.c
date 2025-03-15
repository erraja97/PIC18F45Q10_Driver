/**
 * @file example_push_button.c
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief Push Button Test Program for PIC18F45Q10
 *
 * Reads a button on RB0 and toggles an LED on RA0 when pressed.
 */

#include "gpio.h"
#include "config_bits.h"

// Define LED and Button
#define LED_PORT GPIO_PORTA
#define LED_PIN  0

#define BUTTON_PORT GPIO_PORTB
#define BUTTON_PIN  0

/**
 * @brief Initializes the push button with required configurations.
 */
void init_push_button(void) {
    GPIO_SetDirection(BUTTON_PORT, BUTTON_PIN, GPIO_INPUT);  // Set RB0 as input
    GPIO_SetDigitalMode(BUTTON_PORT, BUTTON_PIN);  // Disable analog function
    GPIO_EnablePullUp(BUTTON_PORT, BUTTON_PIN);  // Enable weak pull-up
}

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

/**
 * @brief Runs the push button test.
 */
void Example_Run(void) {
    GPIO_Init();
    init_push_button(); // Configure push button settings

    // Set RA0 as output for LED
    GPIO_SetDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);

    while (1) {
        // Read button state with debounce (Active LOW)
        if (!GPIO_ReadDebounced(BUTTON_PORT, BUTTON_PIN)) {
            // Toggle LED using GPIO_Read to maintain consistency
            GPIO_Write(LED_PORT, LED_PIN, !GPIO_Read(LED_PORT, LED_PIN));

            // Small delay to prevent multiple toggles on a single press
            delay_ms(250);
        }
    }
}
