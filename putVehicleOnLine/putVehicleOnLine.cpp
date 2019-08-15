#include <set>
#include <algorithm>
#include <chrono>

#include "./putVehicleOnLine.h"
#include "../timer/timer.h"


bool PutVehicleOnLine::setOptimalPositionOnLine()
{
    int distance { 0 };
    int angle { 200 };
    bool onPosition {false};
    roadController_.setDistanceAndAngle( distance, angle );
    while( !isVehicleOnLine() || isPassedFiveSeconds() )
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
};

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

bool PutVehicleOnLine::isPassedFiveSeconds()
{
    using namespace std::literals;
    static bool countingInProgres { false };
    Timer fiveSecondsCounter;

    if( countingInProgres )
    {
        fiveSecondsCounter.stop();
        auto timePeriod = fiveSecondsCounter.getDuration();
        if( timePeriod >= 5s )
            {
                countingInProgres = false;
                return true;
            }
    }
    else
    {
        fiveSecondsCounter.start();
        countingInProgres = true;
        return false;
    }
    
}