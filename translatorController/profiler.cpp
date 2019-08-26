#include "../encoder/encoder.h"
#include "../wheelDrive/twoWheelDrive.h"
#include "../timer/timer.h"
#include "../regulatorPD/regulatorPD.h"
#include "./profiler.h"

void Profiler::calculate()
{
    

    if( state_ == State::ride && isNecessaryToBrake() )
    {
        state_ = State::breaking;
        targetSpeed_ = speedInNextStep_;
    }

    if( isReachedHisDestination() )
    {
        state_ = State::end;
        targetSpeed_ = speedInNextStep_;
    }

    if( currentSpeed_ < targetSpeed_ )
    {
        currentSpeed_ += acceleration_;
        if( currentSpeed_ > targetSpeed_ )
            currentSpeed_ = targetSpeed_;
    }

    passedRoad_ += calculateNextStepSeed();
};

bool Profiler::isNecessaryToBrake()
{
    auto fromSpeedCalculatedRestOfRoad = ( ( currentSpeed_ - speedInNextStep_ ) * 
                                ( currentSpeed_ + speedInNextStep_ ) )
                                /  ( 2 * acceleration_ );
    auto restOfRoad = totalRoadToPass_ - passedRoad_;
    
    if( fromSpeedCalculatedRestOfRoad >= restOfRoad )
        return true;
    else
        return false;   
};

bool Profiler::isReachedHisDestination()
{
    auto isRoadPassed = passedRoad_ >= totalRoadToPass_;
    auto isVehicleStopped = ( state_ == State::breaking ) && 
                            speedInNextStep_ == 0;
    if( isRoadPassed || isVehicleStopped )
        return true;
    else
        return false;
};

int Profiler::getPasedRoadValue()
{
    calculate();
    return passedRoad_;
};