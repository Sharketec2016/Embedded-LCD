/*
 * Created on Thu Aug 15 2024
 *
 * Copy Right (C) | 2024 Embedded Knowledge
 *
 * Author: Matthew Buchkowski
---------------------------------------------------- */


#include <avr/io.h>
#include "Arduino.h"
#include <util/delay.h>
#include "main.h"


//Data line is connected to PORTD
//RS, R/W and EN are connected on PORTB

/*
  TODO:

  RS pin needs to be used to toggle between sending Commands or Data to the LCD screen. We will need to configure this in Data mode
  R/W pin toggles between the LCD either Reading data coming to it, or Writing data away from it. We need to configure this in Read mode for displaying
  Enable Pin is used to enable to R/W operation, which ever one it is. This one must always be held high. 


  RS ---> Pin 10, or PB2
  R/W ---> Pin 9, or PB1
  EN ---> Pin 8, or PB0

  PD0 - PD7  => D0 - D7
*/

#define displayMode 0b00001000 | displayOn | cursorOn | blinkOn
#define functionSet 0b00100000 | dataLength8bit | displayLinesTwo | font10Dots


#define RS PORTB2
#define EN PORTB0
#define RW PORTB1

void setup(){
  DDRB |= (1 << DDB2) | (1 << DDB1) | (1 << DDB0);
  DDRD = 0b11111111;
  PORTB = 0x00;
  
}



int main(void){
  setup();
  _delay_ms(1000);
  send_command(clearLCD);
  send_command(returnHome);
  send_command(functionSet); 
  send_command(displayMode);
  send_command(entryModeLR);




  send_character(0x48);
  send_character(0x65);
  send_character(0x6C);
  send_character(0x6C);
  send_character(0x6F);

  send_command(0b11000000);

  send_character(0x57);
  send_character(0x6F);
  send_character(0x72);
  send_character(0x6C);
  send_character(0x64);

}

void send_command(unsigned int command){ //this function will put the register set pin into a state where we can send command to configure the LCD screen. 
  PORTD = command;
  PORTB |= (0 << RS);
  _delay_ms(100);
  PORTB |= (1 << EN);
  _delay_ms(100);
  PORTB &= ~(1 << EN);

}

void send_character(unsigned int character){
  PORTD = character;
  PORTB |= (1 << RS); //PUTTING DEVICE INTO Data MODE
  _delay_ms(100);
  PORTB |= (1 << EN);
  _delay_ms(10);
  PORTB &= ~(1 << EN);
}


