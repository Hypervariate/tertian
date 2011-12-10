#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL.h"
#include "SDL_ttf.h"

#include <iostream>
#include <vector>
using namespace std;

class Graphics{
private:
    static SDL_Surface *m_buffer;        //back buffer
    static SDL_Surface *m_screen;        //screen buffer
    static SDL_Surface *m_fontBuffer;    //buffer for blitting fonts


    static vector<TTF_Font*> m_fonts;

public:
    Graphics();
    ~Graphics();

    static bool Initialize();
    static bool Deinitialize();
    
    static bool LoadFont(const char* font_name);

};

#endif