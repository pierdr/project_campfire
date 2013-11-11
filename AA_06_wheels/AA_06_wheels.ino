#include <Servo.h>
#define WHEEL_R   8
#define WHEEL_L   7
#define HANDLE_CAP   2
#define BASE_CAP     4
#define TRIG_PIN  13
#define ECHO_PIN  12
#define LIGHT     6

#define STILL                 0
#define FORWARD               1
#define TURNING_RIGHT         2
#define TURNING_LEFT          3
#define REVERSE               4
#define NO_STATE              -1
#define PAUSE                 5
#define GO_BACK_TO_FORWARD    6





/**
 * SERVO VARIABLES
 **/
Servo servos[2];

/**
 ** CAPACITIVE SENSOR
 **/
int valueHandle,valueBase;
const int touchedCutoff = 34;
const int touchedCutoff1 = 28;
int midiclorians;
int fade_mini;

/**
 *** EVENTS & STATES
 **/
int state=NO_STATE;

int remember_last=NO_STATE;
int last_state=NO_STATE;
int counter=0;

unsigned long lastChangeState=0;

/**
 **** DRIVING
 **/



void setup() {
  servoInit();
  trivialInit();
}

void loop() {

  if(!capacitiveHandleUpdate() && !commUpdate())
  {
    if(counter>6)
    {
      distanceUpdate();
      counter=0;
    }
  } 
  if(state==FORWARD)
  {
    counter++;
  }
  
  if(!capacitiveBaseUpdate())
  {
    if(fade_mini>2)
    {
      midiclorians--;
      
      if(midiclorians<0)
      {
        midiclorians=0;
      }
     // sendLightIntensity();
      fade_mini=0;
    }
  }
  else
  {
    if(fade_mini>7)
    {
      midiclorians++;
      if(midiclorians>255)
      {
        midiclorians=255;
      }
      //sendLightIntensity();
      fade_mini=0;
    }
  }
  analogWrite(LIGHT,midiclorians);
 
  fade_mini++;
  stateUpdate();
  delay(100);
}







