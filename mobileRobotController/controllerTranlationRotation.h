/* 
* routeControll.h
*
* Created: 15.07.2019 21:50:45
* Author: Woocheck
*/


#ifndef __TWO_WHEEL_DRIVE_CLASS_H__
#define __TWO_WHEEL_DRIVE_CLASS_H__

enum class VehicleState { ride, stop, braking };

struct Parameters 
{
    VehicleState state = VehicleState::ride;
    float targetSpeed { 0 };
    float nextSpeed { 5 };
    float currentSpeed { 0 };
    float acceleration { 0 };
    int roadToPass { 0 };
    int targetDistance { 0 };

    Parameters( float tSp, float acc, float tDist ): 
                targetSpeed( tSp ),
                acceleration( acc ), 
                targetDistance( tDist) {};
};

class RouteController
{
    private:
        Parameters _translator;
        Parameters _rotator;
    
    public:
        RouteController(): _translator( 50, 5, 100 ), _rotator( 50, 5, 0 ) {};
        int getTranslation();
        int getRotation();
};

#endif
