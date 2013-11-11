void servoInit()
{
  servos[0].attach(WHEEL_R);
  servos[1].attach(WHEEL_L);
  
  delay(20);
  
  servos[0].write(105);
  delay(500);
  servos[0].write(90);
  delay(20);
  
  servos[1].write(75);
  delay(500);
  servos[1].write(90);
  delay(20);
  
  
}
void trivialInit()
{
  Serial.begin(9600);
  valueHandle=LOW;
  valueBase=LOW;
  state=STILL;
  midiclorians=0;
  fade_mini=0;
  Serial.println("OK");
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LIGHT, OUTPUT);
  for(int i=0;i<255;i++)
  {
    analogWrite(LIGHT,i);
    delay(50);
  }
  analogWrite(LIGHT,0);
}
