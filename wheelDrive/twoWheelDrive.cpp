/* 
* TwoWheelDrive.h
*
* Created: 13.07.2019 
* Author: Woocheck
*/

#include "./twoWheelDrive.h"
#include "../pin_settings.h"
#include "../dcMotor/DCmotor.h"

void TwoWheelDrive::driveControll( int leftSpeed, int rightSpeed )
{
	leftDC->control( leftSpeed );
	rightDC->control( rightSpeed );
};

void TwoWheelDrive::stop()
{
	driveControll( 0, 0 );
}