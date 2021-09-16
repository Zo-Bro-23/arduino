#include <Joystick3.h>
int yaxis = 0;
int xaxis = 0;
void setup() {
  // put your setup code here, to run once:
Joystick[0].begin();
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
yaxis = map(analogRead(A0), 0, 1023, 127, -127);
Joystick[0].setYAxis(yaxis);
Serial.println(yaxis);
xaxis = map(analogRead(A1), 0, 1023, -127, 127);
Joystick[0].setXAxis(xaxis);
Serial.println(xaxis);
}
