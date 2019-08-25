/* 
* encoder.h
*
* Created: 01.05.2019
* Author: Woocheck
*/

#include <wiringPi.h>
#include <softPwm.h>
#include "../pin_settings.h"

#include "./encoder.h"
#include "../dcMotor/DCmotor.h"

void Encoder::resetNumberOfPulses()
{
  numberOfPulses_ = 0;
}
void Encoder::readDistance()
{
  int currentStatusPinA_ = digitalRead (pinA);
  if((previousStatusPinA_ == LOW) && currentStatusPinA_==HIGH)
  {
    int statusPinB_ = digitalRead (pinB);
    if(statusPinB_ == LOW && rotationDirection_ == Direction::forward )
    {
      rotationDirection_ == Direction::backward;
    }
    else if(statusPinB_ == HIGH && rotationDirection_ == Direction::backward )
    {
      rotationDirection_ == Direction::forward;
    }
  }
  previousStatusPinA_ = currentStatusPinA_;

  if(rotationDirection_ == Direction::forward)  
    numberOfPulses_++;
  else  
    numberOfPulses_--;

}

int Encoder::getNumeberOfPulses()
{
  return numberOfPulses_;
};

