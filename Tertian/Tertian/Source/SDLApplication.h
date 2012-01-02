
#ifndef SDLAPPLICATION_H_
#define SDLAPPLICATION_H_

#include "Timer.h"
#include "Keyboard.h"
#include "Mouse.h"

class SDLApplication
{
private:
    Timer   m_timer;
    bool    m_bRunning;
	static SDL_Event event;        //event for the listener

    // Todo:: Include Application States


public:
    SDLApplication();
    SDLApplication(const SDLApplication& rhs) {};
    ~SDLApplication();

    SDLApplication operator=(const SDLApplication& rhs) {};

    void Initialize(SDL_Window* window);
    void Update(float fDt);
    void Shutdown();

    bool IsRunning() { return m_bRunning; }


};
#endif

