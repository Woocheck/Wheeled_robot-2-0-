/* 
* regulatorPD.h
*
* Created: 07.05.2019
* Author: Woocheck
*/

#ifndef __REGUlATOR_PD_CLASS_H__
#define __REGUlATOR_PD_CLASS_H__




class RegulatorPD 
{
   private:
   
   double proportionalParameter;
   double derivateParameter;
   double previousError {0};
   double integral;

   public:
   RegulatorPD() = default;
   RegulatorPD( double Kp, double Kd ):
               proportionalParameter ( Kp ),
               derivateParameter ( Kd ) {};
   ~RegulatorPD() {};
   
   double calculate( double );
};   

#endif