String s;
long duration;
int distance;
#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR34_64KHZ);
AF_DCMotor motor2(2, MOTOR34_64KHZ);
void setup() {
  // put your setup code here, to run once:
pinMode(10, OUTPUT);
pinMode(9, INPUT);
Serial.begin(9600);
motor1.setSpeed(255);
motor2.setSpeed(255);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(10, LOW);
delayMicroseconds(2);
digitalWrite(10, HIGH);
delayMicroseconds(10);
digitalWrite(10, LOW);
duration = pulseIn(9, HIGH);
distance = duration*0.034/2;
//Sensor centimeters

if(Serial.available() > 0){
  s = Serial.read();
}

  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);

if(distance < 10 and distance > 0){
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
}
if(distance > 1750 or distance < 2){
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
}
/*if(s == "f"){
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}
if(s == "b"){
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
if(s == "l"){
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}
if(s == "r"){
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}
if(s == "s"){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}*/
//Serial.print(s);
Serial.println(distance);
delay(250);
}
