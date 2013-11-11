
const int LIGHT_SENSOR=A1;


int level=0;

void setup(){

  Serial.begin(9600);

}

void loop()
{


  level=analogRead(LIGHT_SENSOR);
  Serial.write(level);

  delay(20);
}



