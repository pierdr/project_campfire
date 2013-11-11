void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(Serial.available()>0)
  {
    switch(GetFromSerial())
    {
    case 'N':
      digitalWrite(13,HIGH);
      break;
    case 'F':
      digitalWrite(13,LOW);
      break;
    }
  }
 
}
int GetFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}

