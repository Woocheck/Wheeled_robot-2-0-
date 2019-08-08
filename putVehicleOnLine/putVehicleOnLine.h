#ifndef  __PUT_VEHICLE_ONLINE__
#define __PUT_VEHICLE_ONLINE__

#include "../lineDetector/detector.h"
#include "../RoadController/RoadController.h"

class PutVehicleOnLine
{
    Detector& frontDetector_;
    Detector& rearDetector_;

    int distance_ { 200 };
    int angle_ { 0 };

    RoadController& roadController_;
    bool vechicleOnLine_ { false };
    
    public:
        PutVehicleOnLine( Detector& fDet, Detector& rDet, RoadController& controller ):
            frontDetector_( fDet ),
            rearDetector_( rDet ),
            roadController_( controller ) 
            { 
                controller.setInicialisationParameters( distance_, angle_ );
            };
        bool setOptimalPositionOnLine();
        bool isVehicleOnLine();
    private:
        bool isSetOnLine( Detector& detector );
        bool isPassedFiveSeconds();

};

#endif 

