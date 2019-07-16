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
			leftDC(  Gpio::engineLeftA, Gpio::engineLeftB , Gpio::engineLeftEnable ),
			rightDC( Gpio::engineRightA, Gpio::engineRightB , Gpio::engineRightEnable )
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

