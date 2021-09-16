#include <AFMotor.h>

AF_DCMotor solenoid(1, MOTOR12_64KHZ);

void setup() {
  // put your setup code here, to run once:
solenoid.setSpeed(255);
Serial.begin(9600);
pinMode(2, INPUT);
pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
solenoid.run(BACKWARD);
}
