#include "SDLApplication.h"

#include "Graphics.h"



SDLApplication::SDLApplication()
{
    
    m_bRunning = false;
}


SDLApplication::~SDLApplication()
{


}

void SDLApplication::Initialize()
{
    Graphics::Initialize();



    m_bRunning = true;
}


void SDLApplication::Update()
{
    
    Keyboard::PollForEvents();
    

}


void SDLApplication::Shutdown()
{
    Graphics::Deinitialize();

    m_bRunning = false;
}