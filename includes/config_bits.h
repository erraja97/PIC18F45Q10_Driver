/**
 * @file config_bits.h
 * @brief Configuration Bit Settings for PIC18F45Q10
 * @author Raja Gupta
 * @date March 15, 2025
 * 
 * This file contains configuration bits for setting up the oscillator,
 * reset behavior, watchdog timer, and other system settings.
 */

#ifndef CONFIG_BITS_H
#define CONFIG_BITS_H

// PIC18F45Q10 Configuration Bit Settings
// Configuration bits must be defined before main() is executed.

// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode (HS Crystal above 8 MHz)
#pragma config RSTOSC = EXTOSC  // Reset Oscillator to External Clock

// CONFIG1H
#pragma config CLKOUTEN = OFF   // Clock Output disabled
#pragma config CSWEN = ON       // Clock Switch Enabled

// CONFIG2L
#pragma config MCLRE = EXTMCLR  // Master Clear Enable (MCLR pin is MCLR)
#pragma config PWRTE = OFF      // Power-up Timer disabled
#pragma config LPBOREN = OFF    // Low-Power BOR disabled
#pragma config BOREN = ON       // Brown-out Reset enabled

// CONFIG2H
//#pragma config BORV = LO        // Brown-out Reset Voltage (Low)
#pragma config ZCD = OFF        // Zero-Cross Detect Disabled
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enabled

// CONFIG3L
#pragma config WDTE = OFF       // Watchdog Timer disabled

// CONFIG4L
#pragma config LVP = OFF        // Low-Voltage Programming disabled

// Define crystal frequency
#define _XTAL_FREQ 20000000  // Define crystal frequency (20 MHz)

#endif // CONFIG_BITS_H
