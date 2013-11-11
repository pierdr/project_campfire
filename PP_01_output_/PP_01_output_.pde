import spacebrew.*;
import processing.serial.*;

String server="sandbox.spacebrew.cc";
String name="Owen_Jane_Pier_Takeshi_Output";
String description ="Lamb switch very very easy";

boolean isLampOn=false;
boolean broadcastedValue=false;
long event=0;
PImage knock;

Spacebrew sb;

Serial port;

void setup() {
  size(displayWidth, displayHeight);
  background(0);
  knock=loadImage("KnockKnock.jpg");
  // instantiate the spacebrewConnection variable
  sb = new Spacebrew( this );



  



  // declare your subscribers
  sb.addSubscribe( "switch", "boolean" );

  // connect!
  sb.connect(server, name, description );
  
  String arduinoPort=Serial.list()[6];
  println(Serial.list());
  port = new Serial(this, arduinoPort, 9600);
}

void draw() {
    
  if (isLampOn)
  {
    background(255);
    image(knock, (displayWidth/2-knock.width/2), (displayHeight/2-knock.height/2));
  }
  else
  {
    background(0);
  }
  stroke(0);
  if (millis()-event>1000)
  {
    if (isLampOn)
    {
      isLampOn=false;
      byte a='c';
      port.write(a);
    }
  }
  if (port.available()>0)
  {
    int inByte=port.read();
    println(inByte);
  }

}

void onBooleanMessage( String name, boolean value ) {
  println("got range message " + name + " : " + value);
  if (value)
  {
    if (millis()-event>1000)
    {
      this.isLampOn=true;
      byte a='a';
      port.write(a);
      event=millis();
    }
  }
  else
  {
    this.isLampOn=false;
  }
}
boolean sketchFullScreen() {
  return true;
}
void keyPressed()
{
  if (millis()-event>1000)
  {
    this.isLampOn=true;
    port.write(1);
    event=millis();
  }
}

