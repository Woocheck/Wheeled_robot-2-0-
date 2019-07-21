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
void MainRoadController::regulation()
{
    auto leftEncoderPulses = _leftEncoder.getNumeberOfPulses(); 
    auto rightEncoderPulses = _rightEncoder.getNumeberOfPulses();
    
    auto enkoderTranslation = leftEncoderPulses + rightEncoderPulses;
    auto enkoderRotation = leftEncoderPulses - rightEncoderPulses;

    auto profilertrTranslation = profiler.getTranslation();
    auto profilertrRotation = profiler.getRotation();

    auto errorTranslation = profilertrTranslation - enkoderTranslation;
    auto errorRotation = profilertrRotation - enkoderRotation;

    auto pwmTranslation = translationRegulator.calculate(errorTranslation);
    auto pwmRotation = rotationRegulator.calculate(errorRotation);

    auto nextLeftPWM = pwmTranslation + pwmRotation;
    auto nextRightPWM = pwmTranslation + pwmRotation;

    _drive.driveControll( nextLeftPWM, nextRightPWM );
}

void MainRoadController::setDistanceAndAngle( const int& distance, const int& angle )
        {
            _distance = distance;
            _angle = angle;
            regulation();
        }