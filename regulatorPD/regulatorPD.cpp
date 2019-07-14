
#include "./regulatorPD.h"

double RegulatorPD::calculate(double error)
{
   
    double outputP = proportionalParameter * error; 

    double derivative = (error - previousError);
    double outputD = derivateParameter * derivative;

    double output = outputP + outputD;

    previousError = error;

    return output;
};
