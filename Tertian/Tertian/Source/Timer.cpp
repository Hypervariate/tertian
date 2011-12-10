#include "Timer.h"

Timer::Timer()
{
    m_cntsps    = 0;
    m_scpc      = 0.0f;
    m_currTs    = 0;
    m_prevTs    = 0;
  

    m_cntsps = SDL_GetPerformanceFrequency();
    m_scpc = 1.0f / (float)m_cntsps;

    m_prevTs = SDL_GetPerformanceCounter();
}
Timer::~Timer()
{

}

float Timer::GetDt()
{
    m_currTs = 0;
    m_currTs = SDL_GetPerformanceCounter();

    return (m_currTs - m_prevTs)*m_scpc;
}
