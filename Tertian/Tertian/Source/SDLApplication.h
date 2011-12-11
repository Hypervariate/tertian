
#ifndef SDLAPPLICATION_H_
#define SDLAPPLICATION_H_

#include "Timer.h"
#include "../Keyboard.h"

class SDLApplication
{
private:
    Timer   m_timer;
    bool    m_bRunning;


    // Todo:: Include Application States


public:
    SDLApplication();
    SDLApplication(const SDLApplication& rhs) {};
    ~SDLApplication();

    SDLApplication operator=(const SDLApplication& rhs) {};

    void Initialize();
    void Update();
    void Shutdown();

    bool IsRunning() { return m_bRunning; }


};
#endif

