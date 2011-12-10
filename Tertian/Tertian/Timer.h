#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"

class Timer{
public:
    Timer();
    ~Timer();

    static Uint32 GetTicks();       //Get the number of milliseconds since program start
    static void Delay(Uint32 milliseconds); //Delay execution for n number of milliseconds


};

#endif TIMER_H