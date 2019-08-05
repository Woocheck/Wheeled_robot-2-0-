/*
 * Linefollower_1.cpp
 *
 * Created: 14.03.2019 18:31:32
 * Author : Woocheck
*/


#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <algorithm>


#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/wiringPi.h"
#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/softPwm.h"

#include "./pin_settings.h"

#include "./dcMotor/DCmotor.h"
#include "./wheelDrive/twoWheelDrive.h"
#include "./encoder/encoder.h"
#include "./lineDetector/detector.h"
#include "./controllerLineFollower/controllerLineFollower.h"
#include "./controllerLookingForLine/controllerLookingForLine.h"
#include "./timer/timer.h"
#include "./mainRoadController/mainRoadController.h"



void regulationInLineFollowerMode();
void lookingForLineMode();
bool isPassed20ms();
bool isOn();
void readLeftEncoderChange();
void readRightEncoderChange();
void readDetectorChange();

bool isLineDetected();

Detector lineDetector( gpio.frontSensor_1, gpio.frontSensor_2, gpio.frontSensor_3,
                       gpio.frontSensor_4, gpio.frontSensor_5 );
Detector rearLineDetector( gpio.rearSensor_1, gpio.rearSensor_2, gpio.rearSensor_3,
                       gpio.rearSensor_4, gpio.rearSensor_5  );

Encoder leftEncoder( gpio.encoderLeftA, gpio.encoderLeftB );
Encoder rightEencoder( gpio.encoderRightA, gpio.encoderRightB );
TwoWheelDrive drive;
MainRoadController mainController( leftEncoder, rightEencoder, drive );
ControllerLineFollower lineFollowerControl( drive );
ControllerLookingForLine lineSeeker( drive, lineDetector );

int main(void)
{
  wiringPiSetup();
	
  wiringPiISR ( gpio.encoderRightB, INT_EDGE_BOTH, &readRightEncoderChange ); 
  wiringPiISR ( gpio.encoderLeftB, INT_EDGE_BOTH, &readLeftEncoderChange );

  wiringPiISR (gpio.frontSensor_1, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.frontSensor_2, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.frontSensor_3, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.frontSensor_4, INT_EDGE_BOTH, &readDetectorChange ); 
  wiringPiISR (gpio.frontSensor_5, INT_EDGE_BOTH, &readDetectorChange ); 

  int nominalSpeed { 55 };
	lineFollowerControl.setSpeed( nominalSpeed );
  
  if(!isOn()) 
  {
    lineSeeker.startLooking( nominalSpeed );
    
    while( lineSeeker.isNotFoundTheLine() )
    {
      lineSeeker.verifiesMovementCorrectness();
    }
    
    lineSeeker.stopVechicle();
  }

  while(1)
  {
		if( !isOn() && isPassed20ms() )
		{
			lineDetector.readSensorsState();
	    lineFollowerControl.setSensorsState( lineDetector.getSensorsState() );
      lineFollowerControl.calculateError();

	    int correction = static_cast<int>( lineFollowerControl.getCalculatedError() );
      lineFollowerControl.setDirection( correction );	
		}
  }
}



 bool isPassed20ms()
 {
	 return ( millis()%20) == 0;
 };

 bool isOn()
 {
   pinMode ( gpio.OnButton, INPUT ) ;
	 return digitalRead ( gpio.OnButton ); 
 }

void readRightEncoderChange()
{
  rightEencoder.readDistance();
};

void readLeftEncoderChange()
{
  leftEncoder.readDistance();
};

void readDetectorChange()
{
	lineDetector.readSensorsState();
	lineDetector.printSensorsState();	
};


