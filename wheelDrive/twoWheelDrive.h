/* 
* TwoWheelDrive.h
*
* Created: 13.07.2019 
* Author: Woocheck
*/


#ifndef __TWO_WHEEL_DRIVE_CLASS_H__
#define __TWO_WHEEL_DRIVE_CLASS_H__

#include <memory>

#include "../pin_settings.h"
#include "../dcMotor/DCmotor.h"

class TwoWheelDrive
{
	private:               
		std::shared_ptr<Engine> leftDC;
		std::shared_ptr<Engine> rightDC;

	public:
		TwoWheelDrive( std::shared_ptr<Engine> lDC, std::shared_ptr<Engine> rDC ):
			leftDC( std::move( lDC ) ),
			rightDC( std::move( rDC ))
		{
			wiringPiSetup();
		};
		
		void driveControll( int leftSpeed, int rightSpeed );
		void stop();
	private:
		TwoWheelDrive( const TwoWheelDrive &c );
		TwoWheelDrive& operator=( const TwoWheelDrive &c );
}; 

#endif 

