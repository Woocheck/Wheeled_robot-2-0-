#ifndef  __PUT_VEHICLE_ONLINE__
#define __PUT_VEHICLE_ONLINE__

#include "../lineDetector/detector.h"
#include "../RoadControler/RoadControler.h"

class PutVehicleOnLine
{
    Gpio gpio;
    Detector& frontDetector_;
    Detector& rearDetector_;

    int speed_ { 50 };
    int angle_ { 0 };
    int rotationTime_ { 5000 };

    RoadControler& roadControler_;
    bool vechicleOnLine_ { false };
    
    public:
        PutVehicleOnLine( Detector& fDet, Detector& rDet, RoadControler& controller ):
            frontDetector_( fDet ),
            rearDetector_( rDet ),
            roadControler_( controller ){};
        bool setOptimalPositionOnLine();
        bool isVehicleOnLine();
    private:
        bool isSetOnLine( Detector& detector );
        bool isPassedRotationTime();

};

#endif 

