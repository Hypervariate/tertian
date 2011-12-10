#include "ThirdParty/SDL/include/SDL.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    SDL_Surface *hello;
    SDL_Surface *screen;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    hello = SDL_LoadBMP("hello.bmp");
    SDL_BlitSurface(hello, NULL, screen, NULL);
    SDL_Flip(screen);
    SDL_Delay(2000);
    SDL_FreeSurface(hello);
    printf("SDL_Init failed: %s\n", SDL_GetError());
    SDL_Quit();
    return 0;
}