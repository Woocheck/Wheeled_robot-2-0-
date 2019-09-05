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
  numberOfPulses = 0;
}
void Encoder::readDistance()
{
  int currentStatusPinA = digitalRead (pinA);
  if((previousStatusPinA == LOW) && currentStatusPinA==HIGH)
  {
    int statusPinB = digitalRead (pinB);
    if(statusPinB == LOW && rotationDirection == Direction::forward )
    {
      rotationDirection == Direction::backward;
    }
    else if(statusPinB == HIGH && rotationDirection == Direction::backward )
    {
      rotationDirection == Direction::forward;
    }
  }
  previousStatusPinA = currentStatusPinA;

  if(rotationDirection == Direction::forward)  
    numberOfPulses++;
  else  
    numberOfPulses--;
}

int Encoder::getNumeberOfPulses()
{
  return numberOfPulses;
};

