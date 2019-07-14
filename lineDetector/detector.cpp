/* 
* detector.h
*
* Created: 21.05.2019 20:30:00
* Author: Woocheck
*/


#include <algorithm>
#include <vector>
#include <iostream>

#include "detector.h"



void Detector::readSensorsState()
{
   for(int sensorNumer { 0 } ; sensorNumer < sensor.size() ; sensorNumer++ )
   {
      sensorsState.at( sensorNumer ) = digitalRead ( sensor.at( sensorNumer ) );
   }
};

std::vector<int> Detector::getSensorsState()
{
   return sensorsState;
};

void Detector::printSensorsState()
{
   std::cout << "sensors state: " << std::endl;
   for( int state : sensorsState )
   {
      std::cout << state << " , ";
   }

   std::cout << std::endl;
} 