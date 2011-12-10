#include "Timer.h"

Timer::Timer(){}
Timer::~Timer(){}
Uint32 Timer::GetTicks(){
    return SDL_GetTicks();
}
void Timer::Delay(Uint32 milliseconds){
    SDL_Delay(milliseconds);
}