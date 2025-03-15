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

/** Pin state enumeration */
typedef enum {
    GPIO_HIGH = 1, ///< Configure pin as input
    GPIO_LOW = 0 ///< COnfigure pin as output
} gpio_state_t;

/** GPIO API Function Prototypes */

/**
 * @brief Initializes all GPIOs with default states (set in config.h)
 */
void GPIO_Init(void);

/**
 * @brief Configure a GPIO pin as input or output
 * @param port          The target port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC)
 * @param pin           The target pin (0-7)
 * @param direction     The direction of pin (GPIO_INPUT, GPIO_OUTPUT)
 */
void GPIO_SetDirection(unsigned char port, unsigned char pin, gpio_direction_t direction);

/**
 * @brief Writes a value (HIGH/LOW) to a GPIO pin (atomic write).
 * @param port          The target port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC)
 * @param pin           The target pin (0-7)
 * @param state         The state of pin (GPIO_HIGH, GPIO_LOW)
 */
void GPIO_Write(unsigned char port, unsigned char pin, unsigned char value);


/**
 * @brief Reads the current logic state of a GPIO pin.
 *
 * If the pin is configured as an input, it reads from PORTx.
 * If the pin is configured as an output, it reads from LATx.
 *
 * @param port          The target port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
 * @param pin           The pin number (0-7).
 * @return 1 if HIGH, 0 if LOW.
 */
unsigned char GPIO_Read(unsigned char port, unsigned char pin);



/**
 * @brief Reads the logic state of a GPIO pin with debounce.
 *
 * If the pin is configured as an input, it reads from PORTx.
 * If the pin is configured as an output, it reads from LATx.
 * This function filters out bouncing noise from mechanical switches.
 *
 * @param port          The target port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
 * @param pin           The pin number (0-7).
 * @return 1 if HIGH, 0 if LOW.
 */
unsigned char GPIO_ReadDebounced(unsigned char port, unsigned char pin);



/**
 * @brief Writes an 8-bit value to an entire GPIO port.
 *
 * @param port The target port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC)
 * @param value The 8-bit value to write (0x00 - 0xFF)
 */
void GPIO_WritePort(unsigned char port, uint8_t value);


/**
 * @brief Reads the entire 8-bit value from a GPIO port.
 * 
 * If the pin is configured as an input, it reads from PORTx.
 * If the pin is configured as an output, it reads from LATx.
 *
 * @param port          The target port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
 * @return The 8-bit value read from the port.
 */
uint8_t GPIO_ReadPort(unsigned char port);


/**
 * @brief Reads the entire 8-bit value from a GPIO port with debounce.
 *
 * If the pin is configured as an input, it reads from PORTx.
 * If the pin is configured as an output, it reads from LATx.
 *
 * @param port          The target port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
 * @return The 8-bit debounced value read from the port.
 */
uint8_t GPIO_ReadPortDebounced(unsigned char port);


#endif	/* GPIO_H */

