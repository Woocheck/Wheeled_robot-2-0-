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


class RoadController
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
        RoadController( Encoder& left, Encoder& reight, TwoWheelDrive& dr ):
            _leftEncoder( left ),
            _rightEncoder( reight ),
            _drive( dr ),
            profiler( 40, 1, 0, 0),
            translationRegulator( 1, 0 ),
            rotationRegulator( 1, 0 ){}
        void setInicialisationParameters( const int& distance, const int& angle);
        void setDistanceAndAngle( const int& distance, const int& angle );

    private:
        int calculateTranslation( int leftPulses, int rightPulses );
        int calculateRotation( int leftPulses, int rightPulses );
        void setNextStep();
};


#endif