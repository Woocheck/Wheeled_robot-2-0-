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



void regulationInLineFollowerMode();
void lookingForLineMode();
bool isPassed20ms();
bool isOn();
void readLeftEncoderChange();
void readRightEncoderChange();
void readDetectorChange();

bool isLineDetected();

Detector lineDetector( PIN_SENSOR_1, PIN_SENSOR_2, PIN_SENSOR_3,
                       PIN_SENSOR_4, PIN_SENSOR_5 );

TwoWheelDrive drive;
ControllerLineFollower lineFollowerControl( drive );
ControllerLookingForLine lineSeeker( drive, lineDetector );

int main(void)
{
  wiringPiSetup();
	
  wiringPiISR ( PIN_ENCODER_RIGHT_B, INT_EDGE_BOTH,  &readRightEncoderChange ) ; 
  wiringPiISR ( PIN_ENCODER_LEFT_B, INT_EDGE_BOTH,  &readLeftEncoderChange ) ;

  wiringPiISR (PIN_SENSOR_1, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_2, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_3, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_4, INT_EDGE_BOTH,  &readDetectorChange ) ; 
  wiringPiISR (PIN_SENSOR_5, INT_EDGE_BOTH,  &readDetectorChange ) ; 

  int nominalSpeed { 60 };
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
		if(!isOn())
		{
		  if(isPassed20ms())
		  {
				regulationInLineFollowerMode();	
		  }
		}
  }
}

void regulationInLineFollowerMode()
{
  lineDetector.readSensorsState();

	lineFollowerControl.setSensorsState( lineDetector.getSensorsState() );
  lineFollowerControl.calculateError();
  
	int correction = static_cast<int>( lineFollowerControl.getCalculatedError() );
  lineFollowerControl.setDirection( correction );
};

 bool isPassed20ms()
 {
	 return ( millis()%20) == 0;
 };

 bool isOn()
 {
   pinMode ( PIN_BUTTON, INPUT ) ;
	 return digitalRead (PIN_BUTTON); 
 }

void readRightEncoderChange()
{
  // drive.readRightEncoder();
  // drive.printEncodersNumberOfPulses();
};

void readLeftEncoderChange()
{
  // drive.readLeftEncoder();
  // drive.printEncodersNumberOfPulses();
};

void readDetectorChange()
{
	lineDetector.readSensorsState();
	lineDetector.printSensorsState();	
};


