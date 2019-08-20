#ifndef __CONTROLL_LOOKING_FOR_LINE_H__
#define __CONTROLL_LOOKING_FOR_LINE_H__

#include <vector>
#include <chrono>

#include "../wheelDrive/twoWheelDrive.h"
#include "../lineDetector/detector.h"
#include "../timer/timer.h"

class ControllerLookingForLine
{
    private:
        TwoWheelDrive& drive_;
        Detector& lineDetector_;

        int increaseSpeedForBiggerRadius_ { 5 };
        int leftWheelSpeed_ { 50 };
        int rightWheelSpeed_ { 0 };
        int timeToPassFullCircle_ { 3000 };
        
    public:
        ControllerLookingForLine( TwoWheelDrive& drv, Detector& detector ):
            drive_( drv ),
            lineDetector_( detector ){};

        void startLooking( int nominalSpeed );
        bool isTimeToChangeRadius();
        bool isFoundTheLine();
        void stopVechicle();
        void increaseRadius();
        void verifiesMovementCorrectness();
};

#endif 