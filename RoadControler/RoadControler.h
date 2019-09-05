/* 
* mainRoadControll.h
*
* Created: 19.07.2019 
* Author: Woocheck
*/

#ifndef __MAIN_ROAD_CONTROLLER__
#define __MAIN_ROAD_CONTROLLER__

#include "../encoder/encoder.h"
#include "../wheelDrive/twoWheelDrive.h"
#include "../timer/timer.h"

class RoadControler
{
    private:
        int _distance { 0 };
        int _angle{ 0 };
        int _nominalSpeed {50};

        Encoder& _leftEncoder;
        Encoder& _rightEncoder;
        TwoWheelDrive& _drive;
        Timer timer;
        int _timePeriod { 0 };


    public:
        RoadControler( Encoder& left, Encoder& reight, TwoWheelDrive& dr ):
            _leftEncoder( left ),
            _rightEncoder( reight ),
            _drive( dr ){}
        void goByTimePeriod( const int& time, 
                const int& speed, const int& angle );
        void go( const int& speed, const int& angle );
    private:
        void setTimePeriod( const int& time );
        bool isPeriodPassed(); 
};


#endif