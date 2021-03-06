  #include "VisionSensorsDevices.h"
#include "VisionSensor.h"
#include "pins_little_robot.h"
#include <elapsedMillis.h>

#define STOPPED 0
#define STOPPING 1
#define RUNNING 2
#define STARTING 3

elapsedMillis waitTime;

//boolean FirstBallFlag = true;
     
const int delayActions = 4000;
const int delayBallShotsTogglesHigh = 10;
const int delayBallShotsTogglesLow = 40;
//const int ballToggleTimes = 9999999;
//int toggleCounter;
    
void sensors_and_devices::init()
{ 
  //FirstBallFlag = true;
  //toggleCounter = 0;
  pinMode(PrepareBallPin, OUTPUT);
  digitalWrite(PrepareBallPin, LOW);
  
  pinMode(ShootBallPin, OUTPUT);
  digitalWrite(ShootBallPin, LOW);
  
  pinMode(ThrowNetPin, OUTPUT);
  digitalWrite(ThrowNetPin, LOW);
  
  back.initPin(BackSenzorPin);
  front.initPin(FrontSenzorPin);
  left.initPin(LeftSenzorPin);
  right.initPin(RightSenzorPin);
}

void sensors_and_devices::shootBall()
{
  //if(toggleCounter<=ballToggleTimes){
    if(waitTime>delayBallShotsTogglesHigh){
      digitalWrite(ShootBallPin, HIGH);
    }
    if(waitTime>(delayBallShotsTogglesHigh + delayBallShotsTogglesLow))
    {
      digitalWrite(ShootBallPin, LOW);
      //toggleCounter++;
      waitTime = 0;
    }
  //}
}

void sensors_and_devices::startShooting()
{
  digitalWrite(ShootBallPin, HIGH);
}

void sensors_and_devices::stopShooting()
{
   digitalWrite(ShootBallPin, LOW);
}

void sensors_and_devices::startSpinningBallTray()
{
  digitalWrite(PrepareBallPin, HIGH);
  waitTime = 0;
}

void sensors_and_devices::stopSpinningBallTray()
{
  digitalWrite(PrepareBallPin, LOW);
}

void sensors_and_devices::ThrowNet()
{
  digitalWrite(ThrowNetPin, HIGH);
  delay(delayActions);
  digitalWrite(ThrowNetPin, LOW);
}

int sensors_and_devices::detectColor()
{
  return analogRead(ColourSensorPin5);
}

void sensors_and_devices::ColourSensor()
{  
  blackLineDetected = !blackLineDetected;
}

