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
    _timePeriod = time;
    setTimePeriod( _timePeriod );
    while( !isPeriodPassed() )
    {
        go( _nominalSpeed, _angle );        
    }

};

void RoadController::go( const int& speed, const int& angle )
{
    _nominalSpeed = speed;
    _angle = angle;
    _drive.driveControll( _nominalSpeed - _angle,
                              _nominalSpeed + _angle );
}

void RoadController::setTimePeriod( const int& time)
{
    _timePeriod = time;
};

bool RoadController::isPeriodPassed()
{/*
    std::chrono::seconds periodInSeconds( _timePeriod );
    timer.stop();
    auto result = periodInSeconds.count() <= timer.getDuration().count();
    return result ;*/
    static MillisecondIntervalCounter rideInterval( _timePeriod );
    return rideInterval.isPased();;
};