#include <EEPROM.h>;

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
long time = 0;
String API = "skJADOsu90dDj9ad0OD0ao9ds0KDAS";
boolean change_pin = false;
boolean unlock = false;
boolean change_limit = false;
boolean verification = false;

void setup() {
  // put your setup code here, to run once:
pinMode(2, INPUT_PULLUP);
pinMode(3, OUTPUT);
Serial.begin(9600);
}
void loop() {
  digitalWrite(3, LOW);

  // put your main code here, to run repeatedly:
 if (digitalRead(2) == LOW && locked == true){
    digitalWrite(3, HIGH);
    ringing = true;
    Serial.println("Ringing!");
    time = millis();
  }else if (ringing == true){
    if (limit != 0){
    if ((millis() - time) > (limit * 60000)){
        digitalWrite(3, LOW);
        ringing = false;
    }else{
      Serial.println("Ringing!");
      digitalWrite(13, HIGH);
    }
  }
  }if(ringing == false){
    digitalWrite(3, LOW);
  }
  if (Serial.available() > 0){
input = Serial.readString();
    if (input == "PIN"){
        change_pin = true;
        change_limit = false;
        unlock = false;
        verification = false;
        Serial.println("PIN!");
    }else if(input == "UNLOCK"){
      Serial.println("UNLOCK!");
        change_pin = false;
        change_limit = false;
        unlock = true;
        verification = false;
    }else if(input == "LIMIT"){
      Serial.println("LIMIT!");
        change_pin = false;
        change_limit = true;
        unlock = false;
        verification = false;
    }else if(input == "VERIFY"){
      change_pin = false;
      change_limit = false;
      unlock = false;
      verification = true;
      Serial.println("VERIFY!");
    }else{
       if(change_pin == true){
        if(locked == false){
         EEPROM.write(5, input[0]);
         EEPROM.write(6, input[1]);
         EEPROM.write(7, input[2]);
         EEPROM.write(8, input[3]);
         EEPROM.write(9, input[4]);
         EEPROM.write(10,input[5]);
         pin1 = EEPROM.read(5);
         pin2 = EEPROM.read(6);
         pin3 = EEPROM.read(7);
         pin4 = EEPROM.read(8);
         pin5 = EEPROM.read(9);
         pin6 = EEPROM.read(10);
         Serial.println("Success!");
        }change_pin = false;
       }else if(change_limit == true){
         if(locked == false){
             EEPROM.write(0, Serial.read());
             Serial.println("Limit changed!");
        }    change_limit = false;

       }else if(unlock == true){
         if(pin1 == input[0] && pin2 == input[1] && pin3 == input[2] && pin4 == input[3] && pin5 == input[4] && pin6 == input[5]){
           locked = false;
           ringing = false;
           Serial.println("Unlocked!");
         }unlock = false;
      }else if(verification == true){
        if(input == API){
         Serial.println("Verified!"); 
        }else{
         Serial.println("Nop!"); 
        }verification = false;
    }
  }
}
}
