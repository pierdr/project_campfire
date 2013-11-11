
const int LIGHT_SENSOR=A1;


int level=0;

void setup(){
 
  Serial.begin(9600);
  
}

void loop()
{
  
  
      level=analogRead(LIGHT_SENSOR);
      Serial.println(level);
     // level=map(level,0,1023,0,5);
      //Serial.println(level);
      Serial.println();
     
   delay(20);
}


