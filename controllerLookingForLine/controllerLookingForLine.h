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
        Timer timeBetweenRadiusChange;
        TwoWheelDrive& drive;
        Detector& lineDetector;

        int increaseSpeedForBiggerRadius { 5 };
        int leftWheelSpeed { 50 };
        int rightWheelSpeed { 0 };
        int timeToPassFullCircle { 3 };
        
    public:
        ControllerLookingForLine( TwoWheelDrive& drv, Detector& detector ):
            drive( drv ),
            lineDetector( detector ){};

        void startLooking( int nominalSpeed );
        void resetTimeCount();
        bool isTimeToChangeRadius();
        bool isFoundTheLine();
        void stopVechicle();
        void increaseRadius();
        void verifiesMovementCorrectness();
};

#endif 