#ifndef __ROTATION_PROFILER__
#define __ROTATION_PROFILER__

#include "./profiler.h"

class RotationProfiler: public Profiler
{
    RotationProfiler(int acceleration , int targetSpeed):
                Profiler( acceleration, targetSpeed ){};

    private:
    int calculateNextStepSeed();
};

#endif