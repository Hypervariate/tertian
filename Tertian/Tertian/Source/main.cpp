#include <SDL.h>

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Utilities/SDLUtils.h"
#include "SDLApplication.h"
#include "Utilities/GlobalDefines.h"

#include "SDL_gfxPrimitives.h"
#include "Animation.h"


SDLApplication sdlApp;


int main(int argc, char *argv[])
{
    
    g_SDLwindow = NULL;
    g_SDLwindow = SDL_CreateWindow("Tertian", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	sdlApp.Initialize(g_SDLwindow);
	
	Animation animation;
	animation.LoadAnimation("librarian_idle");
	int frame_index = 0;
	char* frame_name;

    while(sdlApp.IsRunning()) {
		Graphics::SetDrawColor(255, 127, 0);
		
		if(Keyboard::GetKey("Up"))
			Graphics::RenderTextures(true);
		if(Keyboard::GetKey("Down"))
			Graphics::RenderTextures(false);

		frame_index = ++frame_index % animation.GetFrameCount();
		frame_name = animation.GetFrameName(frame_index);
		Graphics::BlitImage(frame_name);
		
		Graphics::Print("press [Down] [Up] to toggle textures.", 0, 0);
		

		Graphics::DrawLevelBlock(WINDOW_WIDTH/2,	  WINDOW_HEIGHT/2);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 128, WINDOW_HEIGHT/2);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 - 128, WINDOW_HEIGHT/2);

		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 - 64,  WINDOW_HEIGHT/2 - 32);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 64, WINDOW_HEIGHT/2 - 32);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 64, WINDOW_HEIGHT/2 - 53);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 - 64);

		

		sdlApp.Update();
		
		
    }
    
    SDL_DestroyWindow(g_SDLwindow);

    return 0;
}



