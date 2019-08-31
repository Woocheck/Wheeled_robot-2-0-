
/* 
* controllerTranslationRotation.h.h
*
* Created: 15.07.2019 21:50:45
* Author: Woocheck
*/

#include <algorithm>
#include <cstdlib>

#include "./controllerTranlationRotation.h"

void RouteController::setDistanceAndAngle( int distance, int angle )
{
    _translator.targetDistance = distance;
    _rotator.targetDistance = angle;
};

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
    calculateTranslation();
    return static_cast<int>( _translator.currentSpeed ) ;
};

int RouteController::getRotation()
{
    calculateRotation();
    return static_cast<int>( _rotator.currentSpeed );
};

bool RouteController::needToBrake()
{
    return ((_translator.currentSpeed - _translator.nextSpeed) *
            (_translator.currentSpeed - _translator.nextSpeed) /(2*_translator.acceleration)) 
            >= (_translator.targetDistance - _translator.roadToPass);

};

bool RouteController::needToRotationBrake()
{
    return ((_rotator.currentSpeed - _rotator.nextSpeed) *
            (_rotator.currentSpeed - _rotator.nextSpeed) /(2*_rotator.acceleration)) 
            >= (std::abs(_rotator.targetDistance) - std::abs(_rotator.roadToPass));
};

bool RouteController::reachedDestination()
{
    return _translator.targetDistance >= _translator.roadToPass 
            || ( _translator.state == VehicleState::braking && _translator.currentSpeed == 0 );
}

bool RouteController::reachedAngle()
{
    return  _translator.state == VehicleState::braking && _translator.currentSpeed == 0;

}
     