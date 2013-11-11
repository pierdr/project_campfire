const int CAP=2;
const int LED=13;
const int touchedCutoff = 21;
int valueSensor;


void setup() {
valueSensor=LOW;
pinMode(LED, OUTPUT);
Serial.begin(9600);
}

void loop() {
   valueSensor = readCapacitivePin(CAP); 
   Serial.println(valueSensor);
   if(valueSensor>touchedCutoff)
    {
      valueSensor=HIGH;
    }
    else
    {
      valueSensor=LOW;
    }
    digitalWrite(LED,valueSensor);
    delay(100);
    digitalWrite(LED,LOW);
}
