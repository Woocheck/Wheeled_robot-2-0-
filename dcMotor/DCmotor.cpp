/* 
* DCmotor.h
*
* Created: 13.07.2019 21:10:08
* Author: Woocheck
*/

#include <cmath>
#include <wiringPi.h>
#include <softPwm.h>
#include "./DCmotor.h" 


DcMotor::~DcMotor()
{
}

void DcMotor::setDirection(Direction demandedDirection)
{
	direction_ = demandedDirection;
	if (direction_ == Direction::forward)
	{
		digitalWrite (pinA_, HIGH); 
		digitalWrite (pinB_,  LOW); 
	}
	else if(direction_ == Direction::backward)
	{
		digitalWrite ( pinA_, LOW ); 
		digitalWrite ( pinB_, HIGH );
	}
}


void DcMotor::setSpeed( volatile int demandedSpeed )
{	
	if(demandedSpeed < 0)
	{
		speed_ = 0;
	}
	else if( demandedSpeed > 100 )
	{
		speed_ = 100;
	}
	else
	{
		speed_ = demandedSpeed;
	}
	
	softPwmWrite( pinEnable_, speed);
}

void DcMotor::start()
{
	setDirection( direction_ );
	softPwmWrite( pinEnable_, speed_ );
}

void DcMotor::stop()
{
	digitalWrite ( pinA_, LOW ); 
	digitalWrite ( pinB_, LOW );
	setSpeed( 0 );
}


void DcMotor::control( int demandedSpeed )
{
	if( demandedSpeed >= 0 ) 
	{
		setDirection( Direction::forward );
	}
	else 
	{
		setDirection( Direction::backward );
	} 

	setSpeed( std::abs( demandedSpeed ) ); 
	start();
}
