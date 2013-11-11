import spacebrew.*;
import processing.serial.*;

String server="sandbox.spacebrew.cc";
String name="pier_light";
String description ="Light sensor";

Spacebrew sb;

Serial port;

void setup() {
  size(100, 100);
  background(0);
  sb = new Spacebrew( this );
  sb.addPublish("light_intensity", 0);
  sb.connect(server, name, description );
  
  String arduinoPort=Serial.list()[6];
  println(Serial.list());
  port = new Serial(this, arduinoPort, 9600);
}

void draw() {
 
  if (port.available()>0)
  {
    int inByte=port.read();
    println(inByte);
  }

}

