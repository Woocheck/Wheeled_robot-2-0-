/* 
* DCmotor.h
*
* Created: 13.07.2019 21:10:08
* Author: Woocheck
*/


#ifndef __DC_MOTOR_CLASS_H__
#define __DC_MOTOR_CLASS_H__


#include <wiringPi.h>
#include <softPwm.h>
#include "./engine.h"
class DcMotor: public Engine
{

private:
	enum class Direction { forward, backward };
	volatile const int pinA_;
	volatile const int pinB_;
	volatile const int pinEnable_;

	volatile Direction direction_ = Direction::forward;
	volatile int speed_ { 0 };


public:
	
	DcMotor() = delete;
	DcMotor( const int a, const int b, const int enable ):
					pinA_ { a },
					pinB_ { b },
					pinEnable_ { enable } 
	{					
		wiringPiSetup();
		pinMode ( pinA_, OUTPUT );
		pinMode ( pinB_, OUTPUT ) ;
		
		int initialValue { 100 };
		int pwmRange { 100 };
		softPwmCreate( pinEnable_, initialValue, pwmRange );
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
