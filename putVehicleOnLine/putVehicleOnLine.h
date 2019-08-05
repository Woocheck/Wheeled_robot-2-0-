#ifndef  __PUT_VEHICLE_ONLINE__
#define __PUT_VEHICLE_ONLINE__

#include "../encoder/encoder.h"
#include "../RoadController/RoadController.h"

class PutVehicleOnLine
{
    Encoder& frontEncoder;
    Encoder& rearEncoder;

    RoadController& roadController;
    
    public:
        PutVehicleOnLine( Encoder& frontEn, Encoder& rearEn, RoadController& controller )
}

#endif 

