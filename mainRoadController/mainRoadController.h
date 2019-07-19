/* 
* mainRoadControll.h
*
* Created: 19.07.2019 
* Author: Woocheck
*/

#ifndef __MAIN_ROAD_CONTROLLER__
#define __MAIN_ROAD_CONTROLLER__

#include "../translationRotation/controllerTranlationRotation.h"
#include "../encoder/encoder.h"
#include "../wheelDrive/twoWheelDrive.h"


class MainRoadController
{
    private:
        int _distance {};
        int _angle{};
        Encoder& _leftEncoder;
        Encoder& _rightEncoder;


    public:
        MainRoadController( Encoder& left, Encoder& reight, TwoWheelDrive& ):
            _leftEncoder( left ),
            _rightEncoder( reight ) {};
        
        void regulation();

        void setDistanceAndAngle( const int& distance, const int& angle )
        {
            _distance = distance;
            _angle = angle;
            regulation();
        }
};


#endif