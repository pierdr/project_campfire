
import processing.serial.*;
import spacebrew.*;

String server="spacebrew.local";
String name="project_campfire";
String description ="cool as a robot moving";
Spacebrew sb;
Serial port;


void setup() {
  size(600, 400);
  sb = new Spacebrew( this );
  sb.addSubscribe( "full_throttle", "boolean" );
  sb.addSubscribe( "starboard", "boolean" );
  sb.addSubscribe( "port", "boolean" );
  sb.addSubscribe( "haul_down", "boolean" );
  sb.addSubscribe("fire","range");
  
  sb.addPublish( "barricade", "boolean",true);
  sb.addPublish( "midiclorians", "range",0 );
  sb.addPublish( "manipulation", "boolean",true); 
  sb.connect(server, name, description );
  try
  {
  String arduinoPort=Serial.list()[6];
  port = new Serial(this, arduinoPort, 9600);
  }catch(Exception e)
  {
    
  }
}

void draw() {
  try{
  if (port.available()>0)
  {
    int inByte=port.read();
    println(inByte);
    if (inByte=='T')
    {
      sb.send( "manipulation", true);
    }
    else if (inByte=='D')
    {
      sb.send( "barricade", true);
    }
    else if (inByte=='0')
    {
      int tmp=parseInt(inByte);
      sb.send("midiclorians",parseInt( map(tmp, 0, 5, 0, 1023)));
    }
    else if (inByte=='1')
    {
      int tmp=parseInt(inByte);
      sb.send("midiclorians",parseInt( map(tmp, 0, 5, 0, 1023)));
    }
    else if (inByte=='2')
    {
      int tmp=parseInt(inByte);
      sb.send("midiclorians",parseInt( map(tmp, 0, 5, 0, 1023)));
    }
    else if (inByte=='3')
    {
      int tmp=parseInt(inByte);
      sb.send("midiclorians",parseInt( map(tmp, 0, 5, 0, 1023)));
    }
    else if (inByte=='4')
    {
      int tmp=parseInt(inByte);
      sb.send("midiclorians",parseInt( map(tmp, 0, 5, 0, 1023)));
    }
    else if (inByte=='5')
    {
      int tmp=parseInt(inByte);
      sb.send("midiclorians", parseInt(map(tmp, 0, 5, 0, 1023)));
    }
  }
  }
  catch(Exception e)
  {
    
  }
}


void onBooleanMessage( String name, boolean value ) {
  println("got boolean message " + name + " : " + value);  
  char a= 'w' ;
  if (name.equals("full_throttle"))
  {
    a='F';
  }
  else if (name.equals("starboard"))
  {
    a='R';
  }
  else if (name.equals("port"))
  {
    a='L';
  }
  else if (name.equals("haul_down"))
  {
    a='S';
  }
  println("sending an "+a+ " and the name is "+name);
  port.write(a);
}

void onRangeMessage( String name, int value ){
  println("got range message " + name + " : " + value);
  if(name.equals("fire"))
  {
    char b=' ';
    if (value<170)
    {
      
      b='0';
    }
    else if (value>=170 && value<340)
    {
       b='1';
    }
    else if (value>=340 && value<510)
    {
       b='2';
     }
    else if (value>=510 && value<680)
    {
       b='3';    }
    else if (value>=680 && value<850)
    {
      b='4';   }
    else if (value>=850)
    {
       b='5'; 
     }
    port.write(b);
  }
}
