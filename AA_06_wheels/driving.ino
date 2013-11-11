void moveForward()
{
    servos[0].write(100);
    servos[1].write(82);
    
}
void turnLeft()
{
  servos[0].write(105);
  servos[1].write(105);
  
}
void turnRight()
{
  servos[0].write(75);
  servos[1].write(75);
  
}
void moveReverse()
{
  servos[0].write(75);
  servos[1].write(105);
}
void stopMoving()
{
  servos[0].write(90);
  servos[1].write(90);
}

void stateUpdate()
{
  if(state!=last_state)
  {
    
    switch(state)
    {
      case STILL:
        stopMoving();
      break;
      case FORWARD:
        moveForward();
      break;
      case TURNING_RIGHT:
        lastChangeState=millis();
        turnRight();
      break;
      case TURNING_LEFT:
        if(last_state!=PAUSE)
        {
          lastChangeState=millis();
          turnLeft();
        }
      break;
      case REVERSE:
        moveReverse();
      break;
      case PAUSE:
        stopMoving(); 
      break;
   }
   last_state=state;
  }
  if(millis()-lastChangeState>450)
  {
    if(state==TURNING_RIGHT || state==TURNING_LEFT)
    {
      state=FORWARD;
    }
    if(state==GO_BACK_TO_FORWARD)
    {
      state=FORWARD;
    }
    if(state==REVERSE)
    {
      state=TURNING_RIGHT;
    }
  }
}
