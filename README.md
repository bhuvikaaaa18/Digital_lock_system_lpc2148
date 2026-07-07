# Digital Lock System for LPC2148

A firmware project implementing a password-based digital lock control system for the ARM-based LPC2148 microcontroller.

## Overview

This project demonstrates embedded systems development using the LPC2148 microcontroller, featuring a secure password authentication system with UART serial communication. The system continuously prompts users for password entry, validates credentials, and provides access control feedback.

## Features

- **4-Digit Password Authentication**: Hardcoded security mechanism ("5555") for access control
- **UART Serial Interface**: Full-duplex communication for user input/output via UART0
- **Input Masking**: Password characters masked as asterisks (*) for security
- **Access Feedback**: Clear status messages for successful/failed authentication attempts
- **Low-Level Hardware Control**: Direct register manipulation for microcontroller peripherals

## Hardware Requirements

- **Microcontroller**: ARM LPC2148 (ARM7TDMI core)
- **Oscillator**: Crystal oscillator for clock generation
- **Serial Interface**: UART0 for debugging and user communication
- **Power Supply**: 3.3V regulated power

## Project Structure

```
lock.c              # Main firmware source code
README.md           # Project documentation
.gitignore          # Git ignore configuration
```

## Code Architecture

### Main Components

**UART0 Initialization** (`uart0_init()`)
- Configures serial communication at 9600 baud rate
- Sets pin configuration for UART0 (P0.0 and P0.1)
- Establishes 8-bit data, 1 stop bit, no parity

**Password Verification** (`main()`)
- Infinite loop prompting for password entry
- Receives 4 characters from UART input
- Compares input with stored password
- Outputs access granted/denied message

**Utility Functions**
- `uart0_tx()`: Transmit single character via UART
- `uart0_rx()`: Receive single character from UART
- `uart0_string()`: Transmit string via UART
- `delay()`: Software-based delay function

## Compilation

To compile this project:

1. Use ARM GCC compiler or Keil uVision IDE
2. Include LPC214x header files
3. Link against LPC2148 runtime libraries
4. Program the resulting binary to microcontroller flash memory

```bash
arm-none-eabi-gcc -mcpu=arm7tdmi -o lock.elf lock.c
arm-none-eabi-objcopy -O binary lock.elf lock.bin
```

## Default Password

Current password: **5555**

To change the password, modify the `pass` array in `lock.c`:
```c
unsigned char pass[5] = "XXXX";  // Replace XXXX with desired password
```

## Serial Communication

- **Baud Rate**: 9600
- **Data Bits**: 8
- **Stop Bits**: 1
- **Parity**: None
- **Flow Control**: None

Connect via any terminal emulator (PuTTY, minicom, etc.)

## Security Note

⚠️ This project uses hardcoded passwords and basic authentication for educational purposes only. For production systems, implement secure key storage and advanced authentication mechanisms.

## Development Notes

- Direct register access assumes knowledge of LPC2148 architecture
- VPBDIV set to 0x01 for 1:1 peripheral clock ratio
- Baud rate divisor calculated for 9600 baud at standard oscillator frequency
- Delay function is software-based; for precise timing, consider timer peripherals

## License

This is a resume/educational project demonstrating embedded systems programming concepts.

## Author

Created as a resume project showcasing ARM microcontroller programming skills.
