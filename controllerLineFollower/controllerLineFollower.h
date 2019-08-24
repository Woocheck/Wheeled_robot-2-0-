#ifndef __CONTROLL_LINE_FOLLOWER_H__
#define __CONTROLL_LINE_FOLLOWER_H__

#include <vector>

#include "../regulatorPD/regulatorPD.h"
#include "../wheelDrive/twoWheelDrive.h"

class ControllerLineFollower
{
private:
   std::vector<int> sensorsState_ { 0, 0, 0, 0, 0 };
   double calculatedError_ {0};
   int previousError_ {0};
   int offTheRoad_ {0};
   int error_ {0};
   const double Kp_ {2};
   const double Kd_ {0.5};

   int speed_ {50};

   TwoWheelDrive& drive_;
   RegulatorPD regulator_;

public:
   ControllerLineFollower( TwoWheelDrive& dr ):
      drive( dr ), 
      regulator( Kp_, Kd_ ) {};
   ~ControllerLineFollower(){};

   void setSpeed( int speed );
   int getSpeed();
   void setSensorsState( std::vector<int> sensorsToWrite );
   void calculateError();
   double getCalculatedError();
   void setDirection( int correstion );
};

#endif 
