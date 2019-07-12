/* 
* DC_motor_class.cpp
*
* Created: 15.03.2019 18:47:58
* Author: Woocheck
*/

#include <cmath>
#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/wiringPi.h"
#include "/home/user/workspace_Wheeled_robot/Wheeled_robot_2/wiringPi/wiringPi/softPwm.h"
#include "./DCmotor.h" 


DcMotor::~DcMotor()
{
}

void DcMotor::setDirection(Direction demandedDirection)
{
	DcMotor::direction=demandedDirection;
	if (direction==Direction::forward)
	{
		digitalWrite (pinA, HIGH); 
		digitalWrite (pinB,  LOW); 
	}
	else if(direction==Direction::backward)
	{
		digitalWrite ( pinA, LOW ); 
		digitalWrite ( pinB, HIGH );
	}
}


void DcMotor::setSpeed( volatile int demandedSpeed )
{	
	if(demandedSpeed < 0)
	{
		speed = 0;
	}
	else if( demandedSpeed > 100 )
	{
		speed = 100;
	}
	else
	{
		speed = demandedSpeed;
	}
	
	softPwmWrite( pinEnable, speed);
}

void DcMotor::start()
{
	setDirection( direction );
	softPwmWrite( pinEnable, speed );
}

void DcMotor::stop()
{
	digitalWrite ( pinA, LOW ); 
	digitalWrite ( pinB, LOW );
}


void DcMotor::control( int demandedSpeed )
{
	if( demandedSpeed >= 0 ) {
		setDirection( Direction::forward );
	}
	else {
		setDirection( Direction::backward );
	} 
	setSpeed( std::abs( demandedSpeed ) ); 
	start();
}
