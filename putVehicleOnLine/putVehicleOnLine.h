#ifndef  __PUT_VEHICLE_ONLINE__
#define __PUT_VEHICLE_ONLINE__

#include "../lineDetector/detector.h"
#include "../RoadController/RoadController.h"

class PutVehicleOnLine
{
    Gpio gpio;
    Detector& frontDetector_;
    Detector& rearDetector_;

    int speed_ { 50 };
    int angle_ { 0 };
    int rotationTime_ { 5000 };

    RoadController& roadController_;
    bool vechicleOnLine_ { false };
    
    public:
        PutVehicleOnLine( Detector& fDet, Detector& rDet, RoadController& controller ):
            frontDetector_( fDet ),
            rearDetector_( rDet ),
            roadController_( controller ){};
        bool setOptimalPositionOnLine();
        bool isVehicleOnLine();
    private:
        bool isSetOnLine( Detector& detector );
        bool isPassedRotationTime();

};

#endif 

