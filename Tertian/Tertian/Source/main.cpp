
#include <SDL.h>

#include "Utilities/SDLUtils.h"
#include "SDLApplication.h"
#include "Utilities/GlobalDefines.h"

//SDL_Window* g_SDLwindow

SDLApplication sdlApp;

int main(int argc, char *argv[])
{

    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        checkSDLError();
        return 0;
    }

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


        }

        sdlApp.Shutdown();


    }
    
 
    SDL_Quit();
    
    return 0;
}



