boolean capacitiveHandleUpdate(){
  boolean isCapInput=false;
 
  valueHandle = readCapacitivePin(HANDLE_CAP); 
  //Serial.println(valueHandle);
  
   if(valueHandle>touchedCutoff)
  {
    
    if(state==FORWARD || state==TURNING_RIGHT || state==TURNING_LEFT)
    {
      state=PAUSE;    
      Serial.println('T');
    }
    isCapInput=true;
    
  }
  else
  {
    if(last_state==PAUSE)
    {
      state=GO_BACK_TO_FORWARD;
      lastChangeState=millis();
    }
  }
  return isCapInput;
}
boolean capacitiveBaseUpdate(){
  boolean isCapInput=false;
 
  valueBase = readCapacitivePin(BASE_CAP); 
  
  //Serial.println(valueBase);
   if(valueBase>touchedCutoff)
  {
    
    if(state==FORWARD || state==TURNING_RIGHT || state==TURNING_LEFT)
    {
      state=PAUSE;    
      Serial.println('T');
    }
    isCapInput=true;
    
  }
  else
  {
    if(last_state==PAUSE)
    {
      state=GO_BACK_TO_FORWARD;
      lastChangeState=millis();
    }
  }
  return isCapInput;
}



uint8_t readCapacitivePin(int pinToMeasure){
  // This is how you declare a variable which
  //  will hold the PORT, PIN, and DDR registers
  //  on an AVR
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  byte bitmask;
  if ((pinToMeasure >= 0) && (pinToMeasure <= 7)){
    port = &PORTD;
    ddr = &DDRD;
    bitmask = 1 << pinToMeasure;
    pin = &PIND;
  }
  if ((pinToMeasure > 7) && (pinToMeasure <= 13)){
    port = &PORTB;
    ddr = &DDRB;
    bitmask = 1 << (pinToMeasure - 8);
    pin = &PINB;
  }
  if ((pinToMeasure > 13) && (pinToMeasure <= 19)){
    port = &PORTC;
    ddr = &DDRC;
    bitmask = 1 << (pinToMeasure - 13);
    pin = &PINC;
  }
  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  delay(1);
  // Make the pin an input WITHOUT the internal pull-up on
  *ddr &= ~(bitmask);
  // Now see how long the pin to get pulled up
  int cycles = 16000;
  for(int i = 0; i < cycles; i++){
    if (*pin & bitmask){
      cycles = i;
      break;
    }
  }
  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  return cycles;
}
