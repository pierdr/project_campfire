void distanceUpdate()
{
  long duration, distance;

  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
  //Serial.println(distance);
  if ( distance <= 5 && distance!=0){
    if(state==FORWARD && state!=TURNING_RIGHT && state!=TURNING_LEFT)
    {
      state=REVERSE;
      lastChangeState=millis();
      Serial.println('D');
    }
  }
  
}

