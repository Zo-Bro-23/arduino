#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(EEPROM.read(0));
Serial.println(EEPROM.read(1));
Serial.println(EEPROM.read(5));
Serial.println(EEPROM.read(6));
Serial.println(EEPROM.read(7));
Serial.println(EEPROM.read(8));
Serial.println(EEPROM.read(9));
Serial.println(EEPROM.read(10));
EEPROM.write(0, 1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
