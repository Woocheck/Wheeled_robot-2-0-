#ifndef __TIMER_H__
#define __TIMER_H__

#include <iostream>
#include <chrono>
#include <ctime>
#include <typeindex>
#include <typeinfo>


struct DurationTime
{
    std::chrono::duration<double> duration;
    DurationTime() = default;
    DurationTime( std::chrono::duration<double> initialValue ): duration( initialValue ) {};   
};
class Timer
{
    private:
        std::string id;
        std::chrono::time_point<std::chrono::steady_clock> timerStart;
        std::chrono::time_point<std::chrono::steady_clock> timerStop;
        std::chrono::duration<double> duration;

    public:
        Timer() = default;
        Timer( const std::string& s ): id( s ){};

        void start()
        {
            timerStart = ( std::chrono::steady_clock::now() );
        }

        void stop()
        {
            timerStop = ( std::chrono::steady_clock::now()) ;
            duration = timerStop - timerStart;
        }

        std::chrono::duration<double> getDuration() const
        {
            return duration;
        }

        bool operator<(const Timer& compared ) const
        {
        return ( duration < compared.getDuration() );
        }
};

#endif

