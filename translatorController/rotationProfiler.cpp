#include "./profiler.h"
#include "./rotationProfiler.h"

int RotationProfiler::calculateNextStepSeed()
{   
    float result { 0 };
    if(Profiler::targetSpeed_ > 0) 
        result += Profiler::currentSpeed_; 
    else 
        result -= Profiler::currentSpeed_; 
    return  static_cast<int>( result );
}