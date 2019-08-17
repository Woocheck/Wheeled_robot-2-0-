
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

void ControllerLookingForLine::resetTimeCount()
{
    timeBetweenRadiusChange.start();
};

bool ControllerLookingForLine::isTimeToChangeRadius()
{
    std::chrono::seconds fullFullCircleDuration( timeToPassFullCircle );
    timeBetweenRadiusChange.stop();
    // std::cout << " r: " << fullFullCircleDuration.count() << "  dd: "<< timeBetweenRadiusChange.getDuration().count()<<"\n";
    auto result = fullFullCircleDuration.count() <= timeBetweenRadiusChange.getDuration().count();
    if(result)std::cout << result << "\n";
    return result ;
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
        std::cout << "*";
        increaseSpeedForBiggerRadius++;
        drive.driveControll( leftWheelSpeed, 
            rightWheelSpeed + increaseSpeedForBiggerRadius ); 
        resetTimeCount();
    } 
};
