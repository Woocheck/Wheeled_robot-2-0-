#include "./controllerLineFollower.h"


void ControllerLineFollower::setSpeed( int demandetSpeed )
{
	speed = demandetSpeed;
};

int ControllerLineFollower::getSpeed()
{
	return speed;
};

void ControllerLineFollower::setSensorsState( std::vector<int> sensorsToWrite )
{
   for( int i {0} ; i < 5 ; i++ )
   {
      if( sensorsToWrite[i] ) 
        sensorsState.at( i ) = 0;
      else
        sensorsState.at( i ) = 1;
   }
};

void ControllerLineFollower::calculateError()
{
	double errorValue = 0;				
	int numberOfDetections = 0;						
	
	int importance = 10;						
	
	if( isOffTheRoad )	
	    importance = 5;
	
	for( int i=0; i<5; i++ )
	{
		errorValue += sensorsState.at( i )*( i-2 ) * importance;
		numberOfDetections += sensorsState.at( i );
	}
	
	if( numberOfDetections != 0 )	
	{
		errorValue /= numberOfDetections;
		previousError = errorValue;
	}
	else				
	{
		if( previousError < -20 )	
		{
			errorValue = -40;	
			offTheRoad = 1;
		}
		else if( previousError > 20 )			
		{
			errorValue = 40;					
			offTheRoad = 2;		
		}
		else
			errorValue = 0;
	}
	
	if( isOfTheRoad == 1 && errorValue >= 0 )	
	  isOfTheRoadd = 0;
	else if( isOfTheRoad == 2 && errorValue <= 0 )
	  isOfTheRoad = 0;
	
	calculatedError = regulator.calculate( errorValue );
}

double ControllerLineFollower::getCalculatedError()
{
   return calculatedError;
}

void ControllerLineFollower::setDirection( int correction )
{
	int leftWheelSpeed = speed + correction ;
	int rightWheelSpeed = speed - correction ;

	drive.driveControll( leftWheelSpeed, rightWheelSpeed );
};
