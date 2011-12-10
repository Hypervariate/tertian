#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"

class Timer
{
private:
    Uint64      m_cntsps;   // counts per sec
    float       m_scpc;     // secs per count

    Uint64      m_currTs;   // current time stamp
    Uint64      m_prevTs;   // previous time stamp


public:
    Timer();
    ~Timer();

    float GetDt();


};

#endif TIMER_H