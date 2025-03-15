/* 
 * @file   config.h
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief Default values for PIC18F45Q10
 * 
 */

#ifndef CONFIG_H
#define CONFIG_H

// Define default GPIO directions (1 = input, 0 = output)
#define GPIO_DEFAULT_TRISA 0b00000000  // All outputs
#define GPIO_DEFAULT_TRISB 0b11111111  // All inputs
#define GPIO_DEFAULT_TRISC 0b00000000  // All outputs

// Define default output values
#define GPIO_DEFAULT_LATA  0b00000000  // All LOW
#define GPIO_DEFAULT_LATB  0b00000000  // ALL LOW
#define GPIO_DEFAULT_LATC  0b00000000  // ALL LOW

#endif  // CONFIG_H

