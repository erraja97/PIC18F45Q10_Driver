# **PIC18F45Q10 Driver Development from Scratch**
## **Overview**
This project is a **low-level driver development framework** for the **PIC18F45Q10** microcontroller.  
The goal is to build **bare-metal drivers from scratch**, **without using `xc.h`**, and create a structured, modular, and reusable embedded software system.

---

## **? Features Implemented So Far**
- **Custom GPIO Driver** (Digital I/O, Debounce, Internal Pull-ups)
- **Manual MCU Register Definitions** (`pic18f45q10_regs.h`)
- **Standalone Configuration Bits** (`config_bits.h`)
- **Multiple Example Programs** (`examples/`)
- **Git Version Control for Clean Development Process**
- **Future Plans:** GPIO Interrupts, Timers, UART, ADC, Arduino-like HAL

---

## **1.Development Environment**
| **Component**      | **Version / Details** |
|--------------------|----------------------|
| **MPLAB X IDE**    | v6.x                 |
| **XC8 Compiler**   | v3.x                 |
| **Microcontroller**| PIC18F45Q10          |
| **Oscillator**     | 20MHz External Crystal |
| **Programmer**     | PICkit 4              |

---

## **2.Project Structure**
```
/PIC18F45Q10_Bootcamp
  ??? src/
  ?     ??? main.c             // Entry point, selects example to run
  ?     ??? gpio.c             // GPIO driver implementation
  ??? include/
  ?     ??? pic18f45q10_regs.h // Custom register definitions
  ?     ??? gpio.h             // GPIO API declarations
  ?     ??? config.h           // Board-specific default configurations
  ?     ??? config_bits.h      // MCU Configuration Bits
  ??? examples/
  ?     ??? example_blink_led.c       // LED Blink Test
  ?     ??? example_push_button.c     // Push Button Handling
  ?     ??? example_gpio_interrupt.c  // GPIO Interrupt Example (Upcoming)
  ??? MPLABX_Project/         // MPLAB X project files (auto-generated)
  ??? .gitignore
  ??? README.md               // Project documentation (this file)
```
? **All example programs are in `examples/`, and `main.c` dynamically loads them.**

---

## **3.Implemented Drivers**
### **? GPIO Driver (`gpio.h`, `gpio.c`)**
- **Supports Input & Output Configuration**
- **Uses `LATx` for Outputs & `PORTx` for Inputs**
- **Provides Single-Bit & 8-Bit Port Control**
- **Supports Internal Pull-Up Resistors**
- **Debounce Handling for Noisy Inputs**
- **Ensures Safe Read-Modify-Write (RMW) Operations**

#### **? GPIO API Functions**
| **Function** | **Description** |
|-------------|----------------|
| `GPIO_Init()` | Initializes all GPIO ports. |
| `GPIO_SetDirection(port, pin, direction)` | Sets a pin as INPUT or OUTPUT. |
| `GPIO_EnablePullUp(port, pin)` | Enables weak pull-ups. |
| `GPIO_SetDigitalMode(port, pin)` | Disables analog mode, forces digital I/O. |
| `GPIO_Write(port, pin, value)` | Writes `HIGH` or `LOW` to a pin. |
| `GPIO_Read(port, pin)` | Reads current pin state. |
| `GPIO_ReadDebounced(port, pin)` | Reads a pin with debounce filtering. |
| `GPIO_WritePort(port, value)` | Writes an 8-bit value to a full port. |
| `GPIO_ReadPort(port)` | Reads an 8-bit value from a port. |

---

## **4.MCU Configuration Bits (`config_bits.h`)**
We wrote **custom configuration settings** to ensure the correct system behavior.

| **Feature**   | **Setting** |
|--------------|------------|
| **Oscillator** | 20MHz External Crystal (`HS`) |
| **Master Clear (`MCLR`)** | Enabled |
| **Brown-Out Reset (`BOR`)** | Enabled |
| **Watchdog Timer (`WDT`)** | Disabled |
| **Low-Voltage Programming (`LVP`)** | Disabled |

? **Tested & Verified that BOR, WDT, and MCLR behave correctly.**

---

## **5.Example Test Programs**
We moved all test programs to `examples/`, keeping `main.c` unchanged.

### ? **1. Blinking LED Test (`example_blink_led.c`)**
- **Toggles RA0 every 500ms.**
- **Ensures `_XTAL_FREQ` (20MHz) is correctly applied.**

### ? **2. Push Button Test (`example_push_button.c`)**
- **Reads RB0 (button) and toggles RA0 (LED).**
- **Uses `GPIO_ReadDebounced()` to prevent false triggers.**
- **Enables Weak Pull-Up & Digital Mode for Input Pins.**

### ? **3. GPIO Interrupt Test (`example_gpio_interrupt.c`)** _(Upcoming)_
- **Uses External Interrupt (`INT0`) on RB0 to toggle RA0.**
- **Demonstrates event-driven GPIO handling.**

? **Switching Between Tests:**  
Change this in `main.c`:
```c
#define EXAMPLE_MODE  2  // (1: Blink LED, 2: Push Button, 3: GPIO Interrupt)
```

---

