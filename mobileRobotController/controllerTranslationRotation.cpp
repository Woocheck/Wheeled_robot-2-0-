
/* 
* routeControll.h
*
* Created: 15.07.2019 21:50:45
* Author: Woocheck
*/


#include "./controllerTranlationRotation.h"

void RouteController::calculateTranslation()
{
    if( _translator.state == VehicleState::ride && needToBrake() )
    {
        _translator.state = VehicleState::braking;
        _translator.targetSpeed = _translator.nextSpeed;
    }

    if( reachedDestination() )
    {
       _translator.state = VehicleState::stop;
       _translator.targetSpeed = _translator.nextSpeed; 
    }

    if( _translator.currentSpeed < _translator.targetSpeed )
    {
        _translator.currentSpeed += _translator.acceleration;
        if( _translator.currentSpeed > _translator.targetSpeed )
        {
            _translator.currentSpeed = _translator.targetSpeed;
        }
    }

    if( _translator.currentSpeed > _translator.targetSpeed )
    {
        _translator.currentSpeed -= _translator.acceleration;
        if( _translator.currentSpeed < _translator.targetSpeed )
        {
            _translator.currentSpeed = _translator.targetSpeed;
        }
    }
    _translator.roadToPass += _translator.currentSpeed;
    
};

void RouteController::calculateRotation()
{
    if( _rotator.state == VehicleState::ride && needToRotationBrake() )
    {
         _rotator.state = VehicleState::braking;
        _rotator.targetSpeed = _rotator.nextSpeed;
    }

    if( reachedAngle() )
    {
        _rotator.state = VehicleState::stop;
        _rotator.targetSpeed = _rotator.nextSpeed;
    }

    if( _rotator.currentSpeed < _rotator.targetSpeed )
    {
        _rotator.currentSpeed += _rotator.acceleration;
        if( _rotator.currentSpeed > _rotator.targetSpeed )
        {
            _rotator.currentSpeed = _rotator.targetSpeed;
        }
    }

    if( _rotator.currentSpeed > _rotator.targetSpeed )
    {
        _rotator.currentSpeed -= _rotator.acceleration;
        if( _rotator.currentSpeed < _rotator.targetSpeed )
        {
            _rotator.currentSpeed = _rotator.targetSpeed;
        }
    }

    if( _rotator.targetDistance > 0) 
        _rotator.roadToPass += _rotator.currentSpeed; 
    else 
        _rotator.roadToPass -= _rotator.currentSpeed;
}; 

int RouteController::getTranslation()
{

};

int RouteController::getRotation()
{

};

bool RouteController::needToBrake()
{
    return ((_translator.currentSpeed - _translator.nextSpeed) *
            (_translator.currentSpeed - _translator.nextSpeed) /(2*_translator.acceleration)) 
            >= (_translator.targetDistance - _translator.roadToPass);

};

bool RouteController::needToRotationBrake()
{

};

bool RouteController::reachedDestination()
{

}

bool RouteController::reachedAngle()
{

}
     