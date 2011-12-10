
#include <SDL.h>

#include "Utilities/SDLUtils.h"
#include "SDLApplication.h"
#include "Utilities/GlobalDefines.h"

SDL_Surface* g_SDLwindow;
SDLApplication sdlApp;



int main(int argc, char *argv[])
{

    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        checkSDLError();
        return 0;
    }

    g_SDLwindow = SDL_SetVideoMode(1280, 800, 32, SDL_SWSURFACE);

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



