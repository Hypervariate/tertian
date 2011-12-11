#ifndef GRAPHICS_H
#define GRAPHICS_H


#include "SDL.h"
#include "SDL_ttf.h"

#include "Utilities/GlobalDefines.h"

#include <iostream>
#include <vector>
using namespace std;

class Graphics{
private:
    static SDL_Surface *m_buffer;        //back buffer
    static SDL_Surface *m_screen;        //screen buffer
    static SDL_Surface *m_fontBuffer;    //buffer for blitting fonts


    static vector<TTF_Font*> m_fonts;
    static SDL_Color m_fontColor;

public:
    Graphics();
    ~Graphics();

    static bool Initialize();
    static bool Deinitialize();
    
    static bool LoadFont(const char* font_name);
    static void Print(char* text, int x, int y, int font = 0);

    static void SetFontColor(Uint8 red = 127, Uint8 green = 127, Uint8 blue = 127);

};

#endif