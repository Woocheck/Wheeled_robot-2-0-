#ifndef __CONTROLL_LINE_FOLLOWER_H__
#define __CONTROLL_LINE_FOLLOWER_H__

#include <vector>

#include "../regulatorPD/regulatorPD.h"
#include "../wheelDrive/twoWheelDrive.h"

class ControllerLineFollower
{
private:
   std::vector<int> sensorsState { 0, 0, 0, 0, 0 };
   double calculatedError {0};
   int previousError {0};
   int offTheRoad {0};
   int error {0};
   const double Kp {2};
   const double Kd {1};

   int speed {50};

   TwoWheelDrive& drive;
   RegulatorPD regulator;

public:
   ControllerLineFollower( TwoWheelDrive& dr ):
      drive( dr ), 
      regulator( Kp, Kd ) {};
   ~ControllerLineFollower(){};

   void setSpeed( int speed );
   int getSpeed();
   void setSensorsState( std::vector<int> sensorsToWrite );
   void calculateError();
   double getCalculatedError();
   void setDirection( int correstion );
};

#endif 
