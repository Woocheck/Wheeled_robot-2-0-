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

}

void MainRoadController::setDistanceAndAngle( const int& distance, const int& angle )
        {
            _distance = distance;
            _angle = angle;
            regulation();
        }