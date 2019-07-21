/* 
* controllerTranslationRotation.h
*
* Created: 15.07.2019 21:50:45
* Author: Woocheck
*/


#ifndef __CONTROLLER_TRANSLATION_ROTATION__
#define __CONTROLLER_TRANSLATION_ROTATION__

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
        RouteController(float nominalSpeed, float acceleration, float distance, float angle  ):
             _translator( nominalSpeed, acceleration, distance ),
             _rotator( nominalSpeed, acceleration, angle ) {};
        int getTranslation();
        int getRotation();
    private:
        void calculateTranslation();
        void calculateRotation();
        bool needToBrake();
        bool needToRotationBrake();
        bool reachedDestination();
        bool reachedAngle();
};

#endif
