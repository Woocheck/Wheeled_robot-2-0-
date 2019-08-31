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
   const int pinA_;
   const int pinB_;
   int currentStatusPinA_;
   int previousStatusPinA_;
   int statusPinB_;
   int numberOfPulses_;
   
   enum class Direction { forward, backward };
   Direction rotationDirection_;  
  
  public:
  Encoder() = default;
  Encoder( int a, int b ):
         pinA_ { a },
         pinB_ { b }
  {
      wiringPiSetup();
      pinMode ( pinA_, INPUT ) ;
	    pinMode ( pinB_, INPUT ) ;
      
      rotationDirection_ = Direction::forward;
  }
  
  void resetNumberOfPulses();
  void readDistance();
  int getNumeberOfPulses();

      
};
  

#endif

