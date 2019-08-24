#include "./controllerLineFollower.h"


void ControllerLineFollower::setSpeed( int demandetSpeed )
{
	speed_ = demandetSpeed;
};

int ControllerLineFollower::getSpeed()
{
	return speed_;
};

void ControllerLineFollower::setSensorsState( std::vector<int> sensorsToWrite )
{
   for( int i {0} ; i < 5 ; i++ )
   {
      if( sensorsToWrite[i] ) 
        sensorsState_.at( i ) = 0;
      else
        sensorsState_.at( i ) = 1;
   }
};

void ControllerLineFollower::calculateError()
{
	double errorValue = 0;				
	int numberOfDetections = 0;						
	
	int importance = 10;						
	
	if( offTheRoad_ )	importance = 5;
	
	for( int i=0; i<5; i++ )
	{
		errorValue += sensorsState.at( i )*( i-2 ) * importance;
		numberOfDetections += sensorsState_.at( i );
	}
	
	if( numberOfDetections != 0 )	
	{
		errorValue /= numberOfDetections;
		previousError_ = errorValue;
	}
	else				
	{
		if( previousError_ < -20 )	
		{
			errorValue = -40;	
			offTheRoad_ = 1;
		}
		else if( previousError_ > 20 )			
		{
			errorValue = 40;					
			offTheRoad_ = 2;		
		}
		else
			errorValue = 0;
	}
	
	if( offTheRoad_ == 1 && errorValue >= 0 )	
	  offTheRoad_ = 0;
	else if( offTheRoad_ == 2 && errorValue <= 0 )
	  offTheRoad_ = 0;
	
	calculatedError_ = regulator_.calculate( errorValue );
}

double ControllerLineFollower::getCalculatedError()
{
   return calculatedError_;
}

void ControllerLineFollower::setDirection( int correction )
{
	int leftWheelSpeed = speed_ + correction ;
	int rightWheelSpeed = speed_ - correction ;

	drive.driveControll( leftWheelSpeed, rightWheelSpeed );
};