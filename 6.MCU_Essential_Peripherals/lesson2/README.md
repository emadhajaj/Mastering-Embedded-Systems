# Calculator

The calculator does not deal with decimals, it will **only take integers and show integers**

![2-24-2024 (08-06-03)](https://github.com/emadhajaj/Mastering-Embedded-Systems/assets/106942924/34bf2a23-07d1-406b-85f1-1fe1656214cd)


## Overview
The calculator.c program is a simple calculator application designed to run on an ATmega32 microcontroller. It utilizes a 4x4 keypad for input and an HD44780-based LCD for displaying results. The calculator supports basic arithmetic operations such as addition, subtraction, multiplication, and division.

## Setup
Pin Configuration
Data Pins: PA4-PA7 are used as data pins for the LCD.
Control Pins: PB1-PB3 are used as control pins for the LCD.
Keypad Pins: The keypad pins are configured according to the configuration specified in KEYPAD_4x4_config.h.

## Calculate(): Performs arithmetic calculations based on user input and displays the result on the LCD.

1. **Parsing the Number**:
   - It loops through an array `intArray` containing individual digits of a number.
   - It calculates the actual number represented by these digits using a formula based on powers of 10 and stores it in the variable `number`.

2. **Performing Arithmetic Operations**:
   - Based on the previously entered operator (`prevOperator`), it performs arithmetic operations (`+`, `-`, `*`, `/`) on the current result and the newly calculated number (`result`).
   - Division operation checks if the divisor (the newly calculated number) is not zero to avoid division by zero error.

3. **Displaying the Result on LCD**:
   - It clears the LCD display.
   - If the result is zero, it directly displays '0'.
   - If the result is negative, it displays '-' and then proceeds to display the absolute value of the result.
   - It calculates the number of digits in the result and then displays each digit on the LCD display.

4. **Resetting Variables**:
   - It resets variables such as `number`, `digits`, and `intArray` to prepare for the next calculation.
   - It clears the `intArray` by setting all elements to zero.

