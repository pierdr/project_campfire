void sendLightIntensity()
{

  char rangeLight='-1';
  if(midiclorians<5)
  {
    rangeLight='0';
  }
  else if(midiclorians>=5 && midiclorians<10)
  {
    rangeLight='1';
  }
  else if(midiclorians>=10 && midiclorians<15)
  {
    rangeLight='1';
  }
  else if(midiclorians>=15 && midiclorians<20)
  {
    rangeLight='2';
  }
   else if(midiclorians>=20 && midiclorians<25)
  {
    rangeLight='3';
  }
  else if(midiclorians>=25 && midiclorians<30)
  {
    rangeLight='4';
  }
  else if(midiclorians>=30)
  {
    rangeLight='5';
  }
  Serial.println(midiclorians);
}


