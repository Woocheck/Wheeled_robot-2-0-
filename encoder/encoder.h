/* 
* encoder.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <wiringPi.h>
#include <softPwm.h>
#include "../pin_settings.h"
#include "../dcMotor/DCmotor.h"

class Encoder 
{
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
  
  	void resetNumberOfPulses();
  	void readDistance();
  	int getNumeberOfPulses();
};
  

#endif

