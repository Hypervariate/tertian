#include <SDL.h>

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Utilities/SDLUtils.h"
#include "SDLApplication.h"
#include "Utilities/GlobalDefines.h"
#include "Timer.h"

#include "SDL_gfxPrimitives.h"
#include "AnimationCollection.h"


SDLApplication sdlApp;


int main(int argc, char *argv[])
{
    
    g_SDLwindow = NULL;
    g_SDLwindow = SDL_CreateWindow("Tertian", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	sdlApp.Initialize(g_SDLwindow);

	AnimationCollection ac = AnimationCollection();
	//ac.InsertAnimation("librarian_idle");
	ac.InsertAnimation("librarian_attack");

	
	Timer timer;
	float delta_time;
	string frame_name;
	int x = WINDOW_WIDTH/2;
	int y = WINDOW_HEIGHT/2;
    while(sdlApp.IsRunning()) {
		delta_time = timer.GetDt();   
	
		
		if(Keyboard::GetKey("Up"))
			y -= 2;
		if(Keyboard::GetKey("Down"))
			y += 2;
		if(Keyboard::GetKey("Left"))
			x -= 2;
		if(Keyboard::GetKey("right"))
			x += 2;
		if(Keyboard::GetKey("s"))
			ac.StopActiveAnimation();
		if(Keyboard::GetKey("a"))
			ac.PauseActiveAnimation();
		if(Keyboard::GetKey("p"))
			ac.PlayActiveAnimation();

		
		frame_name = ac.UpdateActiveAnimation(delta_time);
	
		Graphics::BlitImage("librarian_idle_0", 50, 50);
		Graphics::BlitImage("librarian_idle_1", 100, 100);
		Graphics::BlitImage("librarian_idle_2", 100, 140);

		Graphics::BlitImage(frame_name, x, y);
		
		Graphics::Print("[Down] [Up] to toggle textures.", 0, 0);
		Graphics::Print("[S]top  animation.", 0, 12);
		Graphics::Print("P[a]use animation.", 0, 24);
		Graphics::Print("[P]lay  animation.", 0, 36);
		

		Graphics::DrawLevelBlock(WINDOW_WIDTH/2,	   WINDOW_HEIGHT/2);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 128, WINDOW_HEIGHT/2);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 - 128, WINDOW_HEIGHT/2);

		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 - 64, WINDOW_HEIGHT/2 - 32);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 64, WINDOW_HEIGHT/2 - 32);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 64, WINDOW_HEIGHT/2 - 53);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2,	  WINDOW_HEIGHT/2 - 64);

		

		sdlApp.Update(timer.GetDt());

#if _DEBUG
	//printf("time :%f\n", timer.GetDt());
#endif	
		
		
    }
    
    SDL_DestroyWindow(g_SDLwindow);

    return 0;
}



