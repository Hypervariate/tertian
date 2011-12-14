#ifndef GLOBALDEFINES_H_
#define GLOBALDEFINES_H_

#define WINDOW_TITLE "Tertian v0.000000000000001"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define SCREEN_BPP 32


#if defined(_SDL_H)
#else
#include<SDL.h>
#endif



static SDL_Window* g_SDLwindow = 0;

#endif