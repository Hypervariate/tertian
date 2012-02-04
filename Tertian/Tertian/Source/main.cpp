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
#include "LevelGrid.h"
#include "XMLFileReader.h"


SDLApplication sdlApp;


int main(int argc, char *argv[])
{
    
    g_SDLwindow = NULL;
    g_SDLwindow = SDL_CreateWindow("Tertian", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	sdlApp.Initialize(g_SDLwindow);


	XMLFileReader file_reader = XMLFileReader();
	file_reader.OpenFile("Data/Animations/test.xml");
	file_reader.GetToken("frame");
	file_reader.GetToken("framerate");
	file_reader.GetToken("behavior");
	


	//set up the animation collection
	AnimationCollection ac = AnimationCollection();
	ac.InsertAnimation("librarian_attack");
	ac.InsertAnimation("librarian_idle");
		
	LevelGrid level = LevelGrid(5,4,3);
	 //  Access array elements

   
	int block_size = 32;
	
	Timer timer;
	float delta_time;
	string frame_name;
	int x = WINDOW_WIDTH/2 + 100;
	int y = WINDOW_HEIGHT/2;
	
    while(sdlApp.IsRunning()) {
		delta_time = timer.GetDt();   
		
		
		//move the animation frame around
		if(Keyboard::GetKey("Up"))
			y--;
		if(Keyboard::GetKey("Down"))
			y++;
		if(Keyboard::GetKey("Left"))
			x--;
		if(Keyboard::GetKey("right"))
			x++;
		if(Keyboard::GetKey("s"))
			ac.StopActiveAnimation();
		if(Keyboard::GetKey("a"))
			ac.PauseActiveAnimation();
		if(Keyboard::GetKey("p"))
			ac.PlayActiveAnimation();
		
		
		
		//select the active animation 
		if(Keyboard::GetKey("1"))
			ac.SetActiveAnimation("librarian_idle");
		if(Keyboard::GetKey("2"))
			ac.SetActiveAnimation("librarian_attack");

		//get the current animation frame name
		frame_name = ac.UpdateActiveAnimation(delta_time);
		
		//blit the animation frame
        Graphics::BlitImage(frame_name, x, y);
		

	
		Graphics::Print("[S]top  animation.", 0, 12);
		Graphics::Print("P[a]use animation.", 0, 24);
		Graphics::Print("[P]lay  animation.", 0, 36);
		Graphics::Print("Select animation [1]/[2] ", 0, 48);
		

		Graphics::DrawLevelBlock(WINDOW_WIDTH/2,	   WINDOW_HEIGHT/2);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 128, WINDOW_HEIGHT/2);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 - 128, WINDOW_HEIGHT/2);

		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 - 64, WINDOW_HEIGHT/2 - 32);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 64, WINDOW_HEIGHT/2 - 32);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2 + 64, WINDOW_HEIGHT/2 - 53);
		Graphics::DrawLevelBlock(WINDOW_WIDTH/2,	  WINDOW_HEIGHT/2 - 64);

		Graphics::SetDrawColor();
		for(int i = 0; i < level.GetSizeX(); i++)
			for(int j = 0; j < level.GetSizeY(); j++)
				for(int k = 0; k < level.GetSizeZ(); k++){
					Graphics::DrawRect(block_size * i + block_size, block_size * j + block_size, block_size, block_size);
					int value = level.GetCell(i,j,k);
					Graphics::Print(value, block_size * i + block_size + k*8, block_size * j + block_size + k*8);
				}
			

		sdlApp.Update(timer.GetDt());

#if _DEBUG
	//printf("time :%f\n", timer.GetDt());
#endif	
		
		
    }
    
    SDL_DestroyWindow(g_SDLwindow);

    return 0;
}



