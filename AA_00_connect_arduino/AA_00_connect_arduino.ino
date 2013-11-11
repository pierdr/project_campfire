const int led=11;
const int led1=10;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
   Serial.begin (9600);
   digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(Serial.available()>0){
    byte inByte=Serial.read();
    if(inByte=='a')
    {
     // digitalWrite(led1,LOW);
      digitalWrite(led,HIGH);
      delay(1000);
      //Serial.println();  
    }
    else
    {
     digitalWrite(led,LOW);
     delay(50); 
    }
  }
  else
  {
  // digitalWrite(led1,HIGH); 
  }
}
