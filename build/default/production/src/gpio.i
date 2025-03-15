# 1 "src/gpio.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 285 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "src/gpio.c" 2
# 11 "src/gpio.c"
# 1 "includes/gpio.h" 1
# 15 "includes/gpio.h"
# 1 "includes/pic18f45q10_regs.h" 1
# 15 "includes/pic18f45q10_regs.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/musl_xc8.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/stdint.h" 2 3
# 26 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/bits/alltypes.h" 1 3
# 133 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/bits/alltypes.h" 3
typedef unsigned __int24 uintptr_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/bits/alltypes.h" 3
typedef __int24 intptr_t;
# 164 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "C:\\Program Files\\Microchip\\xc8\\v3.00\\pic\\include\\c99/stdint.h" 2 3
# 16 "includes/pic18f45q10_regs.h" 2


typedef union{
    struct{
        uint8_t RA0 : 1;
        uint8_t RA1 : 1;
        uint8_t RA2 : 1;
        uint8_t RA3 : 1;
        uint8_t RA4 : 1;
        uint8_t RA5 : 1;
        uint8_t RA6 : 1;
        uint8_t RA7 : 1;

    };
    uint8_t value;
}PORTA_t;

typedef union{
    struct{
        uint8_t RA0 : 1;
        uint8_t RA1 : 1;
        uint8_t RA2 : 1;
        uint8_t RA3 : 1;
        uint8_t RA4 : 1;
        uint8_t RA5 : 1;
        uint8_t RA6 : 1;
        uint8_t RA7 : 1;

    };
    uint8_t value;
}PORTB_t;

typedef union{
    struct{
        uint8_t RA0 : 1;
        uint8_t RA1 : 1;
        uint8_t RA2 : 1;
        uint8_t RA3 : 1;
        uint8_t RA4 : 1;
        uint8_t RA5 : 1;
        uint8_t RA6 : 1;
        uint8_t RA7 : 1;

    };
    uint8_t value;
}PORTC_t;




typedef union {
    struct {
        uint8_t : 1;
        uint8_t INT0EDG : 1;
        uint8_t INT1EDG : 1;
        uint8_t INT2EDG : 1;
        uint8_t : 2;
        uint8_t IPEN : 1;
        uint8_t GIE : 1;
    };
    uint8_t value;
} INTCON_t;




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
# 16 "includes/gpio.h" 2
# 1 "includes/config.h" 1
# 17 "includes/gpio.h" 2







typedef enum {
    GPIO_INPUT = 1,
    GPIO_OUTPUT = 0
} gpio_direction_t;


typedef enum {
    GPIO_HIGH = 1,
    GPIO_LOW = 0
} gpio_state_t;






void GPIO_Init(void);







void GPIO_SetDirection(unsigned char port, unsigned char pin, gpio_direction_t direction);







void GPIO_Write(unsigned char port, unsigned char pin, unsigned char value);
# 69 "includes/gpio.h"
unsigned char GPIO_Read(unsigned char port, unsigned char pin);
# 84 "includes/gpio.h"
unsigned char GPIO_ReadDebounced(unsigned char port, unsigned char pin);
# 94 "includes/gpio.h"
void GPIO_WritePort(unsigned char port, uint8_t value);
# 106 "includes/gpio.h"
uint8_t GPIO_ReadPort(unsigned char port);
# 118 "includes/gpio.h"
uint8_t GPIO_ReadPortDebounced(unsigned char port);






void GPIO_EnablePullUp(unsigned char port, unsigned char pin);






void GPIO_DisablePullUp(unsigned char port, unsigned char pin);






void GPIO_SetDigitalMode(unsigned char port, unsigned char pin);
# 12 "src/gpio.c" 2

void GPIO_Init(void) {
    (*(volatile PORTA_t*) 0xF87).value = 0b00000000;
    (*(volatile PORTA_t*) 0xF88).value = 0b11111111;
    (*(volatile PORTA_t*) 0xF89).value = 0b00000000;

    (*(volatile PORTA_t*) 0xF82).value = 0b00000000;
    (*(volatile PORTA_t*) 0xF83).value = 0b00000000;
    (*(volatile PORTA_t*) 0xF84).value = 0b00000000;
}

void GPIO_SetDirection(unsigned char port, unsigned char pin, gpio_direction_t direction) {
    if (pin > 7) return;

    switch (port) {
        case 0:
            (*(volatile PORTA_t*) 0xF87).value = (direction) ? ((*(volatile PORTA_t*) 0xF87).value | (uint8_t)(1 << pin)) : ((*(volatile PORTA_t*) 0xF87).value & (uint8_t)~(1 << pin));
            break;
        case 1:
            (*(volatile PORTA_t*) 0xF88).value = (direction) ? ((*(volatile PORTA_t*) 0xF88).value | (uint8_t)(1 << pin)) : ((*(volatile PORTA_t*) 0xF88).value & (uint8_t)~(1 << pin));
            break;
        case 2:
            (*(volatile PORTA_t*) 0xF89).value = (direction) ? ((*(volatile PORTA_t*) 0xF89).value | (uint8_t)(1 << pin)) : ((*(volatile PORTA_t*) 0xF89).value & (uint8_t)~(1 << pin));
            break;
    }
}

void GPIO_Write(unsigned char port, unsigned char pin, unsigned char value) {
    if (pin > 7) return;

    (*(volatile INTCON_t*) 0xFF2).GIE = 0;

    switch (port) {
        case 0:
            (*(volatile PORTA_t*) 0xF82).value = (value) ? ((*(volatile PORTA_t*) 0xF82).value | (uint8_t)(1 << pin)) : ((*(volatile PORTA_t*) 0xF82).value & (uint8_t)~(1 << pin));
            break;
        case 1:
            (*(volatile PORTA_t*) 0xF83).value = (value) ? ((*(volatile PORTA_t*) 0xF83).value | (uint8_t)(1 << pin)) : ((*(volatile PORTA_t*) 0xF83).value & (uint8_t)~(1 << pin));
            break;
        case 2:
            (*(volatile PORTA_t*) 0xF84).value = (value) ? ((*(volatile PORTA_t*) 0xF84).value | (uint8_t)(1 << pin)) : ((*(volatile PORTA_t*) 0xF84).value & (uint8_t)~(1 << pin));
            break;
    }

    (*(volatile INTCON_t*) 0xFF2).GIE = 1;
}

unsigned char GPIO_Read(unsigned char port, unsigned char pin) {
    if (pin > 7) return 0;

    switch (port) {
        case 0:
            return ((*(volatile PORTA_t*) 0xF87).value & (1 << pin)) ? (((*(volatile PORTA_t*) 0xF8C).value >> pin) & 0x01) : (((*(volatile PORTA_t*) 0xF82).value >> pin) & 0x01);
        case 1:
            return ((*(volatile PORTA_t*) 0xF88).value & (1 << pin)) ? (((*(volatile PORTA_t*) 0xF8D).value >> pin) & 0x01) : (((*(volatile PORTA_t*) 0xF83).value >> pin) & 0x01);
        case 2:
            return ((*(volatile PORTA_t*) 0xF89).value & (1 << pin)) ? (((*(volatile PORTA_t*) 0xF8E).value >> pin) & 0x01) : (((*(volatile PORTA_t*) 0xF84).value >> pin) & 0x01);
        default:
            return 0;
    }
}

unsigned char GPIO_ReadDebounced(unsigned char port, unsigned char pin) {
    uint8_t stable_value, temp_value;
    uint8_t debounce_counter = 5;

    stable_value = GPIO_Read(port, pin);

    for (uint8_t i = 0; i < debounce_counter; i++) {
        temp_value = GPIO_Read(port, pin);
        if (temp_value != stable_value) {
            i = 0;
            stable_value = temp_value;
        }
    }

    return stable_value;
}

void GPIO_WritePort(unsigned char port, uint8_t value) {
    (*(volatile INTCON_t*) 0xFF2).GIE = 0;

    switch (port) {
        case 0:
            (*(volatile PORTA_t*) 0xF82).value = value;
            break;
        case 1:
            (*(volatile PORTA_t*) 0xF83).value = value;
            break;
        case 2:
            (*(volatile PORTA_t*) 0xF84).value = value;
            break;
    }

    (*(volatile INTCON_t*) 0xFF2).GIE = 1;
}

uint8_t GPIO_ReadPort(unsigned char port) {
    switch (port) {
        case 0:
            return ((*(volatile PORTA_t*) 0xF87).value == 0xFF) ? (*(volatile PORTA_t*) 0xF8C).value : (*(volatile PORTA_t*) 0xF82).value;
        case 1:
            return ((*(volatile PORTA_t*) 0xF88).value == 0xFF) ? (*(volatile PORTA_t*) 0xF8D).value : (*(volatile PORTA_t*) 0xF83).value;
        case 2:
            return ((*(volatile PORTA_t*) 0xF89).value == 0xFF) ? (*(volatile PORTA_t*) 0xF8E).value : (*(volatile PORTA_t*) 0xF84).value;
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

void GPIO_EnablePullUp(unsigned char port, unsigned char pin) {
    switch (port) {
        case 0:
            (*(volatile WPU_t*) 0xF0B).value |= (1 << pin);
            break;
        case 1:
            (*(volatile WPU_t*) 0xF13).value |= (1 << pin);
            break;
        case 2:
            (*(volatile WPU_t*) 0xF1B).value |= (1 << pin);
            break;
    }
}

void GPIO_DisablePullUp(unsigned char port, unsigned char pin) {
    switch (port) {
        case 0:
            (*(volatile WPU_t*) 0xF0B).value &= ~(1 << pin);
            break;
        case 1:
            (*(volatile WPU_t*) 0xF13).value &= ~(1 << pin);
            break;
        case 2:
            (*(volatile WPU_t*) 0xF1B).value &= ~(1 << pin);
            break;
    }
}

void GPIO_SetDigitalMode(unsigned char port, unsigned char pin) {
    switch (port) {
        case 0:
            (*(volatile ANSEL_t*) 0xF0C).value &= ~(1 << pin);
            break;
        case 1:
            (*(volatile ANSEL_t*) 0xF14).value &= ~(1 << pin);
            break;
        case 2:
            (*(volatile ANSEL_t*) 0xF1C).value &= ~(1 << pin);
            break;
    }
}
