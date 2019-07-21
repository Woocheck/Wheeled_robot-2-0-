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
#include "../translationRotation/controllerTranlationRotation.h"
#include "../regulatorPD/regulatorPD.h"


class MainRoadController
{
    private:
        int _distance {};
        int _angle{};
        int _nominalSpeed {0};
        int _acceleration {0};
        Encoder& _leftEncoder;
        Encoder& _rightEncoder;
        
        TwoWheelDrive& _drive;
        RouteController profiler;
        RegulatorPD translationRegulator;
        RegulatorPD rotationRegulator;


    public:
        MainRoadController( Encoder& left, Encoder& reight, TwoWheelDrive& dr ):
            _leftEncoder( left ),
            _rightEncoder( reight ),
            _drive( dr ),
            profiler( 100, 1, 1000, 0){}
        void setInicialisationParameters( const int& distance, const int& angle);
        void regulation();

        void setDistanceAndAngle( const int& distance, const int& angle );
};


#endif