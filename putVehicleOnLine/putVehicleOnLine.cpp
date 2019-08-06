#include <set>
#include <algorithm>

#include "./putVehicleOnLine.h"

void PutVehicleOnLine::setOptimalPositionOnLine()
{

}

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