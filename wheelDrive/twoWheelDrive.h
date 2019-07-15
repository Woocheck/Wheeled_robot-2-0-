/* 
* TwoWheelDrive.h
*
* Created: 13.07.2019 
* Author: Woocheck
*/


#ifndef __TWO_WHEEL_DRIVE_CLASS_H__
#define __TWO_WHEEL_DRIVE_CLASS_H__


#include "../pin_settings.h"
#include "../dcMotor/DCmotor.h"



class TwoWheelDrive
{
	private:               
		DcMotor leftDC;
		DcMotor rightDC;

	public:
		TwoWheelDrive():
			leftDC(  PIN_LEFT_A, PIN_LEFT_B , PIN_LEFT_ENABLE ),
			rightDC( PIN_RIGHT_A, PIN_RIGHT_B , PIN_RIGHT_ENABLE )
		{
			wiringPiSetup();
		};
		~TwoWheelDrive();
		
		void driveControll( int leftSpeed, int rightSpeed );
		void stop();
	private:
		TwoWheelDrive( const TwoWheelDrive &c );
		TwoWheelDrive& operator=( const TwoWheelDrive &c );

}; 

#endif 

