#include <set>
#include <algorithm>

#include "./putVehicleOnLine.h"

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
    return !isSetOnLine( frontDetector_ ) && !isSetOnLine( rearDetector_ );
};

bool PutVehicleOnLine::isSetOnLine( Detector& detector )
{
    detector.readSensorsState();
    auto sensors = detector.getSensorsState();

    auto result = std::any_of( std::begin( sensors ), std::end( sensors ), 
                []( const auto& sensorValue )
                { 
                   return sensorValue == 1;
                });
    
    return result;
}

bool PutVehicleOnLine::isPassedFiveSeconds()
{
    return ( millis()%5000) == 0;
}