#ifndef __TRANSLATION_CONTROLLER__
#define __TRANSLATION_CONTROLLER__


#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "../encoder/encoder.h"
#include "./translationProfiler.h"
#include "./rotationProfiler.h"
#include "../regulatorPD/regulatorPD.h"
#include "../wheelDrive/twoWheelDrive.h"

class DriveController
{
    TwoWheelDrive& drive_;
    Encoder& leftEncoder_;
    Encoder& rightEncoder_;

    RegulatorPD translationRegulator_;
    RegulatorPD rotationRegulator_;
    
    const float translationKp_ { 1 };
    const float translationKd_ { 0,25 };
    const float rotationKp_ { 1 };
    const float rotationKd_ { 0,25 };

    struct sigaction sa;
    struct itimerval timer;

public:
    DriveController( TwoWheelDrive& drive, Encoder& lEnc, Encoder& rEnc ):
                    drive_( drive ),
                    leftEncoder_( lEnc ),
                    rightEncoder_( rEnc ),
                    translationRegulator_( translationKp_, translationKd_ ),
                    rotationRegulator_( rotationKp_, rotationRegulator_ )
    {
        

        memset (&sa, 0, sizeof (sa));
        sa.sa_handler = &timer_handler;
        sigaction (SIGVTALRM, &sa, NULL);

        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
        
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 10000;
        
        setitimer (ITIMER_VIRTUAL, &timer, NULL);
    };
    
    void move( int distance, int angle );
    void timer_handler (int signum);
}

#endif 
