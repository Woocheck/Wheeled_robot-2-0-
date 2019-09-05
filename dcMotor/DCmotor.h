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

class Engine
{
  public:
	virtual void control( int demandedSpeed ) = 0;
};

class DcMotor: public Engine
{

  private:
	enum class Direction { forward, backward };
	volatile const int pinA;
	volatile const int pinB;
	volatile const int pinEnable;

	volatile Direction direction = Direction::forward;
	volatile int speed { 0 };


  public:	
	DcMotor() = delete;
	DcMotor( const int a, const int b, const int enable ):
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

}; 

#endif 
