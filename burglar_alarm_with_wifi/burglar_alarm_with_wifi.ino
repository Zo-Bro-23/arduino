/*
 * This is the official code for the ZSAT Jarvis home security monitor.
 * Copying this code for any use is both prohibited and illicit.
 * A modified version of this code can be obtained for personal use.
 * A list of all the variable formats used in this code is given below:
 * 
 * 
 */

#include <EEPROM.h>
#include <ESP8266WiFi.h>;

String input; 
boolean locked = true;
boolean ringing = false;
int pin1 = EEPROM.read(5);
int pin2 = EEPROM.read(6);
int pin3 = EEPROM.read(7);
int pin4 = EEPROM.read(8);
int pin5 = EEPROM.read(9);
int pin6 = EEPROM.read(10);
int limit = EEPROM.read(0);
char pin[] = pin1 + pin2 + pin3 + pin4 + pin5 + pin6;
unsigned long time_now;
String API = "skJADOsu90dDj9ad0OD0ao9ds0KDAS";
WiFiServer server(90);

void setup() {
pinMode(D4, INPUT_PULLUP);
pinMode(D3, OUTPUT);
Serial.begin(115200);
WiFi.mode(WIFI_AP);
WiFi.softAP("Zohan-Arduino");
server.begin();
}
void loop() {
  digitalWrite(D3, LOW);
 if (digitalRead(D4) == LOW && locked == true){
    digitalWrite(D3, HIGH);
    ringing = true;
    Serial.println("Ringing!");
    time_now = millis();
  }else if (ringing == true){
    if (limit != 0){
    if ((millis() - time_now) > (limit * 60000)){
        digitalWrite(D3, LOW);
        ringing = false;
    }else{
      Serial.println("Ringing!");
      digitalWrite(D3, HIGH);
    }
  }else{
    Serial.println("Ringing!");
    digitalWrite(D3, HIGH);
  }
  }else{
    digitalWrite(D3, LOW);
  }
if (Serial.available() > 0){
input = Serial.readString();
limit = input.toInt();
//    if (input == "PIN"){
//        change_pin = true;
//        change_limit = false;
//        unlock = false;
//        verification = false;
//        Serial.println("PIN!");
//    }else if(input == "UNLOCK"){
//      Serial.println("UNLOCK!");
//        change_pin = false;
//        change_limit = false;
//        unlock = true;
//        verification = false;
//    }else if(input == "LIMIT"){
//      Serial.println("LIMIT!");
//        change_pin = false;
//        change_limit = true;
//        unlock = false;
//        verification = false;
//    }else if(input == "VERIFY"){
//      change_pin = false;
//      change_limit = false;
//      unlock = false;
//      verification = true;
//      Serial.println("VERIFY!");
//    }else{
//       if(change_pin == true){
//        if(locked == false){
//         EEPROM.write(5, input[0]);
//         EEPROM.write(6, input[1]);
//         EEPROM.write(7, input[2]);
//         EEPROM.write(8, input[3]);
//         EEPROM.write(9, input[4]);
//         EEPROM.write(10,input[5]);
//         pin1 = EEPROM.read(5);
//         pin2 = EEPROM.read(6);
//         pin3 = EEPROM.read(7);
//         pin4 = EEPROM.read(8);
//         pin5 = EEPROM.read(9);
//         pin6 = EEPROM.read(10);
//         Serial.println("Success!");
//        }change_pin = false;
//       }else if(change_limit == true){
//         if(locked == false){
//             EEPROM.write(0, Serial.read());
//             Serial.println("Limit changed!");
//        }    change_limit = false;
//
//       }else if(unlock == true){
//         if(pin1 == input[0] && pin2 == input[1] && pin3 == input[2] && pin4 == input[3] && pin5 == input[4] && pin6 == input[5]){
//           locked = false;
//           ringing = false;
//           Serial.println("Unlocked!");
//         }unlock = false;
//      }else if(verification == true){
//        if(input == API){
//         Serial.println("Verified!"); 
//        }else{
//         Serial.println("Nop!"); 
//        }verification = false;
//    }
//  }
}
Serial.println(limit);
}
