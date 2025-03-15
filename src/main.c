/**
 * @file main.c
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief Static entry point for PIC18F45Q10
 *
 * Loads different example programs from the `examples/` directory.
 */

/** Select the active example */
#define EXAMPLE_MODE  1  // Change this value to switch between examples

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
