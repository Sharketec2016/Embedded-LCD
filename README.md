# Embedded-LCD
Firmware for manipulating a Hitachi HD44780U LCD. Referenced [Datasheet](https://circuitdigest.com/sites/default/files/HD44780U.pdf) 
Microprocessor ATMega328P through Arduino Nano pcb. Firmware sets up nano for displaying "Hello World" onto LCD screen. 

## Contents
- PlatformIo Initialization
- src/main.c -> Firmware


## Pinout of LCD and Nano

RS ---> Pin 10, or PB2
 | R/W ---> Pin 9, or PB1
 | EN ---> Pin 8, or PB0
 | PD0 - PD7  => D0 - D7

## Dependencies 
- [Avrdudes/AVR](https://github.com/avrdudes/avr-libc)
- [Arduino C Library](https://docs.arduino.cc/libraries/)
