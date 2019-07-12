/* 
* DC_motor_class.h
*
* Created: 15.03.2019 18:47:58
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
	volatile int speed;


public:
	
	DcMotor() = delete;
	DcMotor(int a, int b, int enable):
					pinA {a},
					pinB {b},
					pinEnable {enable} {
						
		wiringPiSetup();
		pinMode (pinA, OUTPUT);
		pinMode (pinB, OUTPUT) ;
		softPwmCreate(pinEnable, 100, 100);
	};
	
	~DcMotor(); 
				   						
	void setSpeed(int demanded_speed);
	void setDirection(Direction demandedDirection);
	void start();
	void stop();
	void control(int demanded_speed);
	
private:
	DcMotor( const DcMotor &c );
	DcMotor& operator=( const DcMotor &c );

}; 

#endif 
