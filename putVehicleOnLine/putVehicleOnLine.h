#ifndef  __PUT_VEHICLE_ONLINE__
#define __PUT_VEHICLE_ONLINE__

#include "../lineDetector/detector.h"
#include "../RoadController/RoadController.h"

class PutVehicleOnLine
{
    Detector& frontDetector;
    Detector& rearDetector;

    int distance_ { 200 };
    int angle_ { 0 };

    RoadController& roadController;
    
    public:
        PutVehicleOnLine( Detector& fDet, Detector& rDet, RoadController& controller ):
            frontDetector( fDet ),
            rearDetector( rDet ),
            roadController( controller ) 
            { 
                controller.setInicialisationParameters( distance_, angle_ );
            };
        void setOptimalPositionOnLine();

    private:
        bool isSetOnLine( Detector& detector );

};

#endif 

