//
//#include <SDL.h>
//
//#include "Keyboard.h"
//#include "Mouse.h"
//#include "Graphics.h"
//#include "Utilities/SDLUtils.h"
//#include "SDLApplication.h"
//#include "Utilities/GlobalDefines.h"
//
//#include "SDL_gfxPrimitives.h"
////SDL_Window* g_SDLwindow
//
//SDLApplication sdlApp;
//
//int main(int argc, char *argv[])
//{
//    
//    SDL_Window *win = NULL;
//    SDL_Renderer *renderer = NULL;
//    SDL_Texture *bitmapTex = NULL;
//    SDL_Surface *bitmapSurface = NULL;
//    int posX = 100, posY = 100, width = 320, height = 240;
//
//    win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);
//
//    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
//
//    bitmapSurface = SDL_LoadBMP("img/hello.bmp");
//    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
//    SDL_FreeSurface(bitmapSurface);
//
//    while (1) {
//        SDL_Event e;
//        if (SDL_PollEvent(&e)) {
//            if (e.type == SDL_QUIT) {
//                break;
//            }       
//        }
//
//        
//
//        SDL_RenderClear(renderer);
//        SDL_SetRenderDrawColor(renderer, 255, 127, 0, 255);
//        SDL_RenderDrawLine(renderer, 0, 0, width, height);
//        
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        //SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
//        SDL_RenderPresent(renderer);
//    }
//
//    SDL_DestroyTexture(bitmapTex);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(win);
//
//    return 0;
//}




#include <SDL.h>

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Utilities/SDLUtils.h"
#include "SDLApplication.h"
#include "Utilities/GlobalDefines.h"

#include "SDL_gfxPrimitives.h"


SDLApplication sdlApp;

int main(int argc, char *argv[])
{
    
    g_SDLwindow = NULL;
    g_SDLwindow = SDL_CreateWindow("Hello World", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	sdlApp.Initialize(g_SDLwindow);

    while (!Keyboard::GetKey("Escape") ) {
		Graphics::SetDrawColor(255, 127, 0);
		
		////Sample primatives
		/*Graphics::Print("Hi!", WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
		Graphics::DrawLine(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		Graphics::DrawRect();
		Graphics::DrawFillRect(32,32);
		Graphics::DrawPoint(64, 16);*/

		Graphics::DrawLevelBlock(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

		sdlApp.Update();
		
		
    }
    
    SDL_DestroyWindow(g_SDLwindow);

    return 0;
}



