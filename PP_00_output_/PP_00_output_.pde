import spacebrew.*;

String server="sandbox.spacebrew.cc";
String name="Owen_Jane_Pier_Takeshi_Output";
String description ="Lamb switch very very easy";

boolean isLampOn=false;
boolean broadcastedValue=false;
long event=0;

Spacebrew sb;

void setup() {
  size(displayWidth, displayHeight);
  background(0);

  // instantiate the spacebrewConnection variable
  sb = new Spacebrew( this );

 

  // declare your subscribers
  sb.addSubscribe( "switch", "boolean" );

  // connect!
  sb.connect(server, name, description );
  
}

void draw() {
  if(isLampOn)
  {
    background(255);
  }
  else
  {
    background(0);
  }
  stroke(0);
  if(millis()-event>5000)
  {
    event=0;
  }
}

void onBooleanMessage( String name, boolean value ){
  println("got range message " + name + " : " + value);
  if(value)
  {
    if(millis()-event>5000)
    {
      this.isLampOn=true;
      event=millis();
    }
  }
  else
  {
    this.isLampOn=false;
  }
}
