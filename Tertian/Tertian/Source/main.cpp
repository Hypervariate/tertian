
#include <SDL.h>

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
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
            
            
            if(Keyboard::GetKey("Escape"))
                break;

				//mouse demo
				int i = - 48;
				Graphics::Print("Mouse",WINDOW_WIDTH/2, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print("X =",WINDOW_WIDTH/2, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print("Y =",WINDOW_WIDTH/2, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print("L =",WINDOW_WIDTH/2, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print("M =",WINDOW_WIDTH/2, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print("R =",WINDOW_WIDTH/2, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print("W =",WINDOW_WIDTH/2, WINDOW_HEIGHT/2+i); i+=12;
				 i = - 36;
			
				Graphics::Print((int)Mouse::GetX(),WINDOW_WIDTH/2+24, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print((int)Mouse::GetY(),WINDOW_WIDTH/2+24, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print((int)Mouse::GetMouseButtonLeft(),WINDOW_WIDTH/2+24, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print((int)Mouse::GetMouseButtonMiddle(),WINDOW_WIDTH/2+24, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print((int)Mouse::GetMouseButtonRight(),WINDOW_WIDTH/2+24, WINDOW_HEIGHT/2+i); i+=12;
				Graphics::Print((int)Mouse::GetMouseWheelDirection(),WINDOW_WIDTH/2+24, WINDOW_HEIGHT/2+i); i+=12;
			
			sdlApp.Update();
        }

        sdlApp.Shutdown();


    }
    
 
    SDL_Quit();
    
    return 0;
}



