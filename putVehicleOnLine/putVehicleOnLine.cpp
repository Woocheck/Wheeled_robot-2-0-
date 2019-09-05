#include <set>
#include <algorithm>
#include <chrono>

#include "./putVehicleOnLine.h"
#include "../timer/timer.h"


bool PutVehicleOnLine::setOptimalPositionOnLine()
{
    bool onPosition {false};
    
    speed_ = 50;
    angle_ = 0;
    int time { 2000 };
    roadControler_.goByTimePeriod( time, speed_, angle_ );

    speed_ = 0;
    angle_ = 80;
    roadControler_.go( speed_, angle_ );
    while( !isVehicleOnLine() || isPassedRotationTime() )
    {
        if( isVehicleOnLine() )
            onPosition = true;
        else
            onPosition = false;
    };
    return onPosition;
}

bool PutVehicleOnLine::isVehicleOnLine()
{   
    return isSetOnLine( frontDetector_ ) && isSetOnLine( rearDetector_ );
}

bool PutVehicleOnLine::isSetOnLine( Detector& detector )
{
    detector.readSensorsState();
    auto sensors = detector.getSensorsState();

    auto result = std::any_of( std::begin( sensors ), std::end( sensors ), 
                []( const int & sensorValue )
                { 
                   return sensorValue == 0;
                });
    
    return result;
}

bool PutVehicleOnLine::isPassedRotationTime()
{   
    static MillisecondIntervalCounter rotationInterval( rotationTime_ );
    return rotationInterval.isPased();
}