#ifndef GRAPHICS_H
#define GRAPHICS_H


#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_gfxPrimitives.h"

#include "Utilities/GlobalDefines.h"

#include <iostream>
#include <vector>
using namespace std;

class Graphics{
private:
    static SDL_Surface *m_buffer;        //back buffer
    static SDL_Surface *m_screen;        //screen buffer
    static SDL_Surface *m_fontBuffer;    //buffer for blitting fonts
    static SDL_Renderer *m_renderer;

    static vector<TTF_Font*> m_fonts;
    static SDL_Color m_fontColor;
    

public:
    Graphics();
    ~Graphics();

    static bool Initialize();
	static void Update();
    static bool Deinitialize();

    static void DrawLine(int x1, int y1, int x2, int y2);
    
    static bool LoadFont(const char* font_name);
    static void Print(char* text, int x, int y, int font = 0);
	static void Print(int i, int x, int y, int font = 0);

    static void SetFontColor(Uint8 red = 127, Uint8 green = 127, Uint8 blue = 127);

};

#endif