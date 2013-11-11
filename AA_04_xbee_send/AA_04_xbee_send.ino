void setup() {
 
Serial.begin(9600);
}

void loop() {

  delay(2000);
  Serial.write('N');
  delay(2000);
  Serial.write('F');
}
