#include <vector>
#include <algorithm>

#include "../wheelDrive/twoWheelDrive.h"
#include "../timer/timer.h"
#include "./controllerLookingForLine.h"

void ControllerLookingForLine::startLooking( int nominalSpeed )
{
    leftWheelSpeed = nominalSpeed;
    timeBetweenRadiusChange.start();
};

void ControllerLookingForLine::resetTimeCount()
{
    timeBetweenRadiusChange.start();
};

bool ControllerLookingForLine::isTimeToChangeRadius()
{
    return timeToPassFullCircle <= timeBetweenRadiusChange.getDuration();
};

bool ControllerLookingForLine::isNotFoundTheLine()
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
        drive.driveControll( leftWheelSpeed, 
            rightWheelSpeed + increaseSpeedForBiggerRadius ); 
        resetTimeCount();
    } 
};