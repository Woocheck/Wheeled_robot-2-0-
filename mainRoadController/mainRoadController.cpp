/* 
* mainRoadControll.h
*
* Created: 19.07.2019 
* Author: Woocheck
*/

#include "./mainRoadController.h"

void MainRoadController::setInicialisationParameters( 
    const int& distance, const int& acceleration )
{
    
}

int MainRoadController::calculateTranslation( int leftPulses, int rightPulses )
{
    auto enkoderTranslation = leftPulses + rightPulses;
    auto profilertrTranslation = profiler.getTranslation();
    auto errorTranslation = profilertrTranslation - enkoderTranslation;
    return translationRegulator.calculate(errorTranslation);
}

int MainRoadController::calculateRotation( int leftPulses, int rightPulses )
{
    auto enkoderRotation = leftPulses - rightPulses;
    auto profilertrRotation = profiler.getRotation();
    auto errorRotation = profilertrRotation - enkoderRotation;
    return rotationRegulator.calculate(errorRotation);
}

void MainRoadController::setNextStep()
{
    auto translation = calculateTranslation( _leftEncoder.getNumeberOfPulses(),
                                             _rightEncoder.getNumeberOfPulses() );
    auto rotation = calculateRotation( _leftEncoder.getNumeberOfPulses(), 
                                    _rightEncoder.getNumeberOfPulses() );

    auto nextLeftPWM = translation + rotation;
    auto nextRightPWM = translation + rotation;

    _drive.driveControll( nextLeftPWM, nextRightPWM );
}

void MainRoadController::setDistanceAndAngle( const int& distance, const int& angle )
        {
            _distance = distance;
            _angle = angle;
            setNextStep();
        }