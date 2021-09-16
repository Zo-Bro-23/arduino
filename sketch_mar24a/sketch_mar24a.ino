String s;
#include <Servo.h>
Servo zo;

void setup() {
  // put your setup code here, to run once:
zo.attach(9);
Serial.begin(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
//zo.write(0);
//delay(540);
//zo.write(90);
//delay(1000);
if(Serial.available() > 0){
  s = Serial.readString();
}
if(s.indexOf("ok") >= 0){
  zo.write(0);
  delay(540);
  zo.write(90);
  s = "stop";
}
if(s.indexOf("stop") >= 0){
  zo.write(90);
}
Serial.print(s);
}
