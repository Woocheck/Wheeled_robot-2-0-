
#include <vector>
#include <algorithm>



#include <wiringPi.h>
#include "../wheelDrive/twoWheelDrive.h"
#include "../timer/timer.h"
#include "./controllerLookingForLine.h"

void ControllerLookingForLine::startLooking( int nominalSpeed )
{
    leftWheelSpeed_ = nominalSpeed;
    int rightWheelSpeed_ { 0 };
    drive_.driveControll( leftWheelSpeed_, rightWheelSpeed_ );
};

bool ControllerLookingForLine::isTimeToChangeRadius()
{
    static MillisecondIntervalCounter intervalForNextRadiusChange( timeToPassFullCircle_ );
    auto isTime = intervalForNextRadiusChange.isPased();
    if( isTime )
        timeToPassFullCircle_ += 5;
    return isTime;
};

bool ControllerLookingForLine::isFoundTheLine()
{
  lineDetector_.readSensorsState();
  std::vector<int> sensorsState = lineDetector_.getSensorsState();
  bool result = std::any_of( std::begin( sensorsState ), std::end( sensorsState ), 
                             []( const int & sensor ) { return sensor != 1; } );
  return result;

};

void ControllerLookingForLine::stopVechicle()
{
    drive_.stop();
}

void ControllerLookingForLine::verifiesMovementCorrectness()
{
    if( isTimeToChangeRadius() )
    {
        rightWheelSpeed_ += increaseSpeedForBiggerRadius_;
        drive_.driveControll( leftWheelSpeed_, rightWheelSpeed_ ); 
    } 
};
