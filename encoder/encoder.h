/* 
* encoder.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#ifndef __ENCODER_H__
#define __ENCODER_H__

#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/wiringPi.h"
#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/softPwm.h"
#include "../pin_settings.h"
#include "../dcMotor/DCmotor.h"

class Encoder 
{
  //variables
  private:
   const int pinA;
   const int pinB;
   int currentStatusPinA;
   int previousStatusPinA;
   int statusPinB;
   int numberOfPulses;
   
   enum class Direction { forward, backward };
   Direction rotationDirection;
   bool wayside;
   bool result;
  
  //functions
  public:
  Encoder() = default;
  Encoder( int a, int b ):
         pinA { a },
         pinB { b }
  {
      wiringPiSetup();
      pinMode ( pinA, INPUT ) ;
	    pinMode ( pinB, INPUT ) ;
      
      rotationDirection = Direction::forward;
  }
  
  void readDistance();
  int getNumeberOfPulses();

      
};
  

#endif

