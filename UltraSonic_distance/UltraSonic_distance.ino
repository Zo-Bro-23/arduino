long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT);
pinMode(3, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2, LOW);
delayMicroseconds(2);
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite(2, LOW);
duration = pulseIn(3, HIGH);
distance = duration*0.034/2;
Serial.print("Distance");
Serial.println(distance);
//Serial.print("Duration");
//Serial.println(duration);
//Serial.print(digitalRead(10));
delay(1000);
}
