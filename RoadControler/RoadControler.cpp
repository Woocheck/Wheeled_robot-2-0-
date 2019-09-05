

#include "./RoadControler.h"

void RoadControler::goByTimePeriod( const int& time, 
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

void RoadControler::go( const int& speed, const int& angle )
{
    _nominalSpeed = speed;
    _angle = angle;
    _drive.driveControll( _nominalSpeed - _angle,
                              _nominalSpeed + _angle );
}

void RoadControler::setTimePeriod( const int& time)
{
    _timePeriod = time;
};

bool RoadControler::isPeriodPassed()
{
    static MillisecondIntervalCounter rideInterval( _timePeriod );
    return rideInterval.isPased();;
};