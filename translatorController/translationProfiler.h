#ifndef __TRANSLATION_PROFILER__
#define __TRANSLATION_PROFILER__

#include "./profiler.h"

class TranslationProfiler:public Profiler
{
    TranslationProfiler(int acceleration , int targetSpeed):
                    Profiler( acceleration, targetSpeed ){};

    private:
    int calculateNextStepSeed();
};

#endif