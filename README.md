# SC2107 Lab Repository

This repository contains the code and supporting materials for the SC2107 lab sessions, based on the Texas Instruments MSP432P401R microcontroller platform. It includes a range of practical exercises covering embedded programming, input/output, interrupt handling, timers, sensors, motor control, and UART communication.

## Overview

The projects in this repository are organized by lab session and progressively build on core embedded systems concepts:

- Lab 1: introductory programming with C and assembly, plus simple I/O and hardware setup
- Lab 2: GPIO and reflectance sensing, finite-state machine logic
- Lab 3: interrupts, SysTick timing, and motor control with timer-based PWM
- Lab 4: ADC-based IR sensing, filtering, and tachometer/timer capture
- Reference and support projects: UART testing, SysTick demonstrations, and reusable code examples

## Repository Structure

- Lab1/
  - Lab1_Assembly/
  - Lab1_C_Programming/
  - Lab1ref_InputOutput/
  - Lab1ref_SimpleProject_asm/
  - Lab1ref_SineFunction/
  - Lab1ref_TExaS/
  - SC2107-Lab1-Handoutv5M.docx
- Lab2/
  - Lab2_FSM/
  - Lab2_ReflectanceGPIO/
  - Lab2ref_GPIO/
- Lab3/
  - Lab3_Bump_Reflectance_Systick/
  - Lab3_TimerCompare_Motor/
  - Lab3ref_EdgeInterrupt/
  - Lab3ref_SimpleMotors/
- Lab4/
  - Lab4_ADC_IRSensors/
  - Lab4_TimerCapture_Tach/
- SysTick/
- RefLab_UART/
- README.md

## Hardware and Tools

This lab work is designed for:

- Texas Instruments MSP432P401R LaunchPad
- Code Composer Studio (CCS)
- C and assembly programming
- Embedded debugging and flashing via the MSP432 development board

## Learning Objectives

By completing the labs in this repository, students will gain experience in:

- Writing and debugging embedded C and assembly code
- Configuring GPIO and peripheral registers
- Using interrupts and timer-driven execution
- Reading sensor inputs and processing analog signals
- Implementing state machines for robot behavior
- Controlling motors and understanding pulse-width modulation
- Communicating with external devices through UART

## How to Use This Repository

1. Open the relevant lab folder in Code Composer Studio.
2. Build the project for the MSP432P401R target.
3. Flash the compiled program to the LaunchPad.
4. Run the program and observe behavior on the board.
5. Review the associated source files to understand the implementation and hardware configuration.

## Notes

- Some folders contain example/reference projects and debug-generated files alongside the main sources.
- The repository is intended primarily for academic lab work and learning purposes.
- Students should refer to the lab handouts and course instructions for assignment-specific requirements and expected outputs.

## Contributors

This repository is used for SC2107 laboratory coursework and practical embedded systems exercises.

## License

This project is intended for academic use within the course context.
