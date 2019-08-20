
#include <vector>
#include <algorithm>



#include <wiringPi.h>
#include "../wheelDrive/twoWheelDrive.h"
#include "../timer/timer.h"
#include "./controllerLookingForLine.h"

void ControllerLookingForLine::startLooking( int nominalSpeed )
{
    leftWheelSpeed = nominalSpeed;
    int rightWheelSpeed { 0 };
    drive.driveControll( leftWheelSpeed, rightWheelSpeed );
    timeBetweenRadiusChange.start();
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
  lineDetector.readSensorsState();
  std::vector<int> sensorsState = lineDetector.getSensorsState();
  bool result = std::any_of( std::begin( sensorsState ), std::end( sensorsState ), 
                             []( const int & sensor ) { return sensor != 1; } );
  return !result;

};

void ControllerLookingForLine::stopVechicle()
{
    drive.stop();
}

void ControllerLookingForLine::verifiesMovementCorrectness()
{
    
    if( isTimeToChangeRadius() )
    {
        increaseSpeedForBiggerRadius++;
        rightWheelSpeed += increaseSpeedForBiggerRadius;
        drive.driveControll( leftWheelSpeed, rightWheelSpeed ); 
    } 
};
