#include <Servo.h> 
#define WHEEL 8
Servo servo;
int pos;
void setup() {
  servo.attach(WHEEL);
  pos=0;
 
  servo.write(90);
  delay(200);
  servo.write(179);
  delay(599);
  servo.write(90);
  delay(29);
  Serial.begin(9600);
}

void loop() {
   if(Serial.available()>0)
  {
    pos=GetFromSerial();
    Serial.println(pos);
     servo.write(pos);
  }
  
  delay(50);
}

int GetFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}
