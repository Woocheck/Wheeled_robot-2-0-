/* 
* detector.h
*
* Created: 21.05.2019 20:30:00
* Author: Woocheck
*/


#ifndef __DETECTOR_H__
#define __DETECTOR_H__

#include <vector>
#include <iostream>
#include <wiringPi.h>


class Detector 
{
   private:
      std::vector<int> sensor { 0, 0, 0, 0, 0 };
      std::vector<int> sensorsState { 0, 0, 0, 0, 0 };

   public:
      Detector(){};
      Detector(int pin1, int pin2, int pin3, int pin4, int pin5 )
      {
         wiringPiSetup();
         sensor.at( 0 ) = pin1;
         sensor.at( 1 ) = pin2;
         sensor.at( 2 ) = pin3;
         sensor.at( 3 ) = pin4;
         sensor.at( 4 ) = pin5;

         for(int sensorNumber : sensor)
         {
            std::cout << "sensor numer: " << sensorNumber;
            pinMode ( sensorNumber, INPUT );
            std::cout << " sensor value: " << digitalRead ( sensorNumber ) << std::endl;
         }
         
      }

      void readSensorsState();
      std::vector<int> getSensorsState();
      void printSensorsState();
};

 
#endif