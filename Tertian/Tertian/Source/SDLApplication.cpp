#include "SDLApplication.h"

#include "Graphics.h"



SDLApplication::SDLApplication()
{
    
    m_bRunning = false;
}


SDLApplication::~SDLApplication()
{


}

void SDLApplication::Initialize(SDL_Window* window)
{
    Graphics::Initialize(window);



    m_bRunning = true;
}


void SDLApplication::Update()
{
    
    Keyboard::PollForEvents();
	Mouse::PollForEvents();
	Graphics::Update();
    

}


void SDLApplication::Shutdown()
{
    Graphics::Deinitialize();

    m_bRunning = false;
}