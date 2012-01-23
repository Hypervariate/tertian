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

	Animation animation = Animation();
	Animation::LoadAnimation("librarian_idle", &animation);
	

	
	Timer timer;
	float delta_time;
	string frame_name;
	int x = WINDOW_WIDTH/2;
	int y = WINDOW_HEIGHT/2;
    while(sdlApp.IsRunning()) {
		delta_time = timer.GetDt();   
		string frame_name = animation.UpdateAnimation(delta_time);
		
		if(Keyboard::GetKey("Up"))
			y--;
		if(Keyboard::GetKey("Down"))
			y++;
		if(Keyboard::GetKey("Left"))
			x--;
		if(Keyboard::GetKey("right"))
			x++;
		if(Keyboard::GetKey("s"))
			animation.StopAnimation();
		if(Keyboard::GetKey("a"))
			animation.PauseAnimation();
		if(Keyboard::GetKey("p"))
			animation.PlayAnimation();
		

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



