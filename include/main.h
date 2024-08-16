
void send_command(unsigned int command);
void send_character(unsigned int character);

#define clearLCD 0x01
#define returnHome 0x02

#define entryModeLR 0b00000110
#define entryModeRL 0b00000100

#define displayOn 0b00000100
#define displayOff 0b00000000

#define cursorOn 0b00000010
#define cursorOff 0b00000000

#define blinkOn 0b00000001
#define blinkOff 0b00000000

#define dataLength8bit 0b00010000
#define dataLength4bit 0b00000000

#define displayLinesTwo 0b00001000
#define displayLinesOne 0x00

#define font10Dots 0b00000100
#define font8Dots 0x00




