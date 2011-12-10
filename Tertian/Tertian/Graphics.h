#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL.h"

class Graphics{
private:
    static SDL_Surface *m_buffer;    //back buffer
    static SDL_Surface *m_screen;    //screen buffer

public:
    Graphics();
    ~Graphics();

    static bool Initialize();
    static bool Deinitialize();

};

#endif