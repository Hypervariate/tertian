#include "SDLApplication.h"

#include "Graphics.h"

SDL_Event SDLApplication::event;        //event for the listener

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
    SDL_PollEvent(&event);

	switch(event.type){
		case SDL_QUIT:
			m_bRunning = false;
			break;
	}
	

    Keyboard::AnalyzeEvents(&event);

	if(Keyboard::GetKey("Escape"))
		m_bRunning = false;

	Mouse::AnalyzeEvents(&event);

	float delta_time = m_timer.GetDt();
	

	Graphics::Update();
    

}


void SDLApplication::Shutdown()
{
    Graphics::Deinitialize();

    m_bRunning = false;
}

