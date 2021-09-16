void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(10, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(10, map(analogRead(A0), 185, 890, 0, 255));
}
