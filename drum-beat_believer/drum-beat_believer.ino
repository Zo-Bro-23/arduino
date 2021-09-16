#include <Keyboard.h>
int i;
void setup() {
  // put your setup code here, to run once:
Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0; i<216; i++){
Keyboard.write('k');
delay(500);
Keyboard.write('v');
delay(500);
Keyboard.write('e');
delay(500);
Keyboard.write('k');
delay(166.666666667);
Keyboard.write('k');
delay(166.666666667);
Keyboard.write('k');
delay(166.666666667);
  }
delay(10000);//ekkkkekkekkk
}
