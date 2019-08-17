/* 
* mainRoadControll.h
*
* Created: 19.07.2019 
* Author: Woocheck
*/

#include "./RoadController.h"

void RoadController::goByTimePeriod( const int& time, 
                    const int& speed, const int& angle )
{
    _nominalSpeed = speed;
    _angle = angle;
    setTimePeriod( 2 );
    while( !isPeriodPassed() )
    {
        go( _nominalSpeed, _angle );        
    }

};

void RoadController::go( int speed, int angle )
{
    _drive.driveControll( _nominalSpeed + _angle,
                              _nominalSpeed - angle );
}

void RoadController::setTimePeriod( int time)
{
    _timePeriod = time;
    timer.start();
};

bool RoadController::isPeriodPassed()
{
    std::chrono::seconds periodInSeconds( _timePeriod );
    timer.stop();
    auto result = periodInSeconds.count() <= timer.getDuration().count();
    return result ;
};