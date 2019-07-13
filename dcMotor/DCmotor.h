/* 
* DCmotor.h
*
* Created: 13.07.2019 21:10:08
* Author: Woocheck
*/


#ifndef __DC_MOTOR_CLASS_H__
#define __DC_MOTOR_CLASS_H__


#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/wiringPi.h"
#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/softPwm.h"

class DcMotor
{

private:
	enum class Direction { forward, backward };
	volatile int  pinA;
	volatile int  pinB;
	volatile int  pinEnable;

	volatile Direction direction = Direction::forward;
	volatile int speed { 0 };


public:
	
	DcMotor() = delete;
	DcMotor( int a, int b, int enable ):
					pinA { a },
					pinB { b },
					pinEnable { enable } 
	{					
		wiringPiSetup();
		pinMode ( pinA, OUTPUT );
		pinMode ( pinB, OUTPUT ) ;
		softPwmCreate( pinEnable, 100, 100 );
	};
	
	~DcMotor(); 
				   						
	void control( int demanded_speed );
	
private:

	void setSpeed( int demanded_speed );
	void setDirection( Direction demandedDirection );
	void start();
	void stop();

	DcMotor( const DcMotor &c );
	DcMotor& operator=( const DcMotor &c );

}; 

#endif 
