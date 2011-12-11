
#include <SDL.h>

#include "../Keyboard.h"
#include "Utilities/SDLUtils.h"
#include "SDLApplication.h"
#include "Utilities/GlobalDefines.h"


//SDL_Window* g_SDLwindow

SDLApplication sdlApp;

int main(int argc, char *argv[])
{

    g_SDLwindow = SDL_CreateWindow(WINDOW_TITLE, 
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   WINDOW_WIDTH,
                                   WINDOW_HEIGHT,
                                   0);

    if(g_SDLwindow)
    {
        sdlApp.Initialize();

        while(sdlApp.IsRunning())
        {
            sdlApp.Update();
            Keyboard::PollForEvents();
            if(Keyboard::GetKey("Escape"))
                break;

        }

        sdlApp.Shutdown();


    }
    
 
    SDL_Quit();
    
    return 0;
}



