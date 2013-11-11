boolean commUpdate()
{
  boolean incomingCommunication=false;
  if(Serial.available()>0)
  {
    incomingCommunication=true;
    switch(getFromSerial())
    {
    case 'F':
      Serial.println("X");
      state=FORWARD;
      break;
    case 'R':
      Serial.println("X");
      state=TURNING_RIGHT;
      break;
    case 'L':
      Serial.println("X");
      state=TURNING_LEFT;
      break;
    case 'V':
      Serial.println("X");
      state=REVERSE;
      break;
    case 'S':
      Serial.println("X");
      state=STILL;
      break;
    case 'a':
      Serial.println("X");
      midiclorians=0;
    case 's':
      midiclorians=1;
      Serial.println("X");
    case 'd':
      midiclorians=2;
      Serial.println("X");
    case 'f':
      midiclorians=8;
      Serial.println("X");
    case 'g':
      midiclorians--;
      Serial.println("X");
    case 'h':
      midiclorians++;
    case 'j':
      midiclorians+=4;
      Serial.println("X");
    default:
      Serial.println("-");
      incomingCommunication=false;
      break;
    }
  }
  return  incomingCommunication;
}

int getFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}





