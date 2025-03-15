/**
 * @file main.c
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief Static entry point for PIC18F45Q10
 *
 * Loads different example programs from the `examples/` directory.
 */

#include "gpio.h"
#include "config_bits.h"

/** Select the active example */
// Change this value to switch between examples
#define EXAMPLE_MODE  2

#ifndef EXAMPLE_MODE
    #define EXAMPLE_MODE  2  // Default to Push Button Example if not set
#endif

#if EXAMPLE_MODE == 1
    #include "../examples/example_blink_led.c"
#elif EXAMPLE_MODE == 2
    #include "../examples/example_push_button.c"
#elif EXAMPLE_MODE == 3
    #include "../examples/example_gpio_interrupt.c"
#else
    #error "Invalid EXAMPLE_MODE selected. Choose 1, 2, or 3."
#endif


/**
 * @brief Main entry point of the program.
 */
void main(void) {
    Example_Run(); // Calls the selected example?s function
}
