/*
 * @file pic18f45q10_regs.h
 * @author Raja Gupta
 * @Created March 15, 2025
 * @brief Register definitions for PIC18F45Q10
 * 
 * 
 * Provides direct memory access and bitfield structures
 * for easier GPIO manipulation
 */

#ifndef PIC18F45Q10_REGS_H
#define	PIC18F45Q10_REGS_H

#include<stdint.h> //Standard integer types

/** Struct for bitwise access to PORT registers*/
typedef union{
    struct{
        uint8_t RA0 : 1; //Bit 0
        uint8_t RA1 : 1; //Bit 1
        uint8_t RA2 : 1; //Bit 2
        uint8_t RA3 : 1; //Bit 3
        uint8_t RA4 : 1; //Bit 4
        uint8_t RA5 : 1; //Bit 5
        uint8_t RA6 : 1; //Bit 6
        uint8_t RA7 : 1; //Bit 7
        
    };
    uint8_t value; //Full register access
}PORTA_t;

typedef union{
    struct{
        uint8_t RA0 : 1; //Bit 0
        uint8_t RA1 : 1; //Bit 1
        uint8_t RA2 : 1; //Bit 2
        uint8_t RA3 : 1; //Bit 3
        uint8_t RA4 : 1; //Bit 4
        uint8_t RA5 : 1; //Bit 5
        uint8_t RA6 : 1; //Bit 6
        uint8_t RA7 : 1; //Bit 7
        
    };
    uint8_t value; //Full register access
}PORTB_t;

typedef union{
    struct{
        uint8_t RA0 : 1; //Bit 0
        uint8_t RA1 : 1; //Bit 1
        uint8_t RA2 : 1; //Bit 2
        uint8_t RA3 : 1; //Bit 3
        uint8_t RA4 : 1; //Bit 4
        uint8_t RA5 : 1; //Bit 5
        uint8_t RA6 : 1; //Bit 6
        uint8_t RA7 : 1; //Bit 7
        
    };
    uint8_t value; //Full register access
}PORTC_t;

/**
 * @brief Interrupt Control Register (INTCON) Definition (Final Corrected Version)
 */
typedef union {
    struct {
        uint8_t : 1;         ///< Unused Bit (Bit 0, Reserved)
        uint8_t INT0EDG : 1; ///< INT0 External Interrupt Edge Select
        uint8_t INT1EDG : 1; ///< INT1 External Interrupt Edge Select
        uint8_t INT2EDG : 1; ///< INT2 External Interrupt Edge Select
        uint8_t : 2;         ///< Unused Bits (Bit 4 & Bit 3, Reserved)
        uint8_t IPEN : 1;    ///< Interrupt Priority Enable
        uint8_t GIE : 1;     ///< Global Interrupt Enable
    };
    uint8_t value;
} INTCON_t;

/**
 * @brief Weak pull up control on GPIO
 */
typedef union {
    struct {
        uint8_t WPU0 : 1;
        uint8_t WPU1 : 1;
        uint8_t WPU2 : 1;
        uint8_t WPU3 : 1;
        uint8_t WPU4 : 1;
        uint8_t WPU5 : 1;
        uint8_t WPU6 : 1;
        uint8_t WPU7 : 1;
    };
    uint8_t value;
} WPU_t;

/**
 * @brief Analog mode control on GPIO
 */
typedef union {
    struct {
        uint8_t ANS0 : 1;
        uint8_t ANS1 : 1;
        uint8_t ANS2 : 1;
        uint8_t ANS3 : 1;
        uint8_t ANS4 : 1;
        uint8_t ANS5 : 1;
        uint8_t ANS6 : 1;
        uint8_t ANS7 : 1;
    };
    uint8_t value;
} ANSEL_t;



/** Define actual memory-mapped registers*/
#define LATA  (*(volatile PORTA_t*) 0xF82) ///< Output Latch Register for PORTA
#define TRISA (*(volatile PORTA_t*) 0xF87) ///< Data Direction Register for PORTA
#define PORTA (*(volatile PORTA_t*) 0xF8C) ///< Input Register for PORTA

#define LATB  (*(volatile PORTA_t*) 0xF83) ///< Output Latch Register for PORTB
#define TRISB (*(volatile PORTA_t*) 0xF88) ///< Data Direction Register for PORTB
#define PORTB (*(volatile PORTA_t*) 0xF8D) ///< Input Register for PORTB

#define LATC  (*(volatile PORTA_t*) 0xF84) ///< Output Latch Register for PORTC
#define TRISC (*(volatile PORTA_t*) 0xF89) ///< Data Direction Register for PORTC
#define PORTC (*(volatile PORTA_t*) 0xF8E) ///< Input Register for PORTC

#define INTCON   (*(volatile INTCON_t*) 0xFF2) ///< INTCON Register

#define WPUA (*(volatile WPU_t*) 0xF0B) ///< Weak Pull up Register for PORTA
#define WPUB (*(volatile WPU_t*) 0xF13) ///< Weak Pull up Register for PORTB
#define WPUC (*(volatile WPU_t*) 0xF1B) ///< Weak Pull up Register for PORTC

#define ANSELA (*(volatile ANSEL_t*) 0xF0C) ///< Analog mode secetion Register for PORTA
#define ANSELB (*(volatile ANSEL_t*) 0xF14) ///< Analog mode secetion Register for PORTB
#define ANSELC (*(volatile ANSEL_t*) 0xF1C) ///< Analog mode secetion Register for PORTC

#endif	/* PIC18F45Q10_REGS_H */

