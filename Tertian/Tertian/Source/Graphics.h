#ifndef GRAPHICS_H
#define GRAPHICS_H


#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_gfxPrimitives.h"
#include "SDL_image.h"

#include "Utilities/GlobalDefines.h"
#include <map>

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

#define IMAGE_DIRECTORY "Data/Images/"
#define IMAGE_EXTENSION ".png"

class Graphics{
private:
    static SDL_Surface *m_buffer;        //back buffer
	static SDL_Texture *m_bufferTexture; //new back buffer
    static SDL_Surface *m_fontBuffer;    //buffer for blitting fonts
    static SDL_Renderer *m_renderer;

    static vector<TTF_Font*> m_fonts;
    static SDL_Color m_drawColor;

	static SDL_Rect m_tempRect;
    static bool renderTextures;

	static map<string, SDL_Surface*> m_images;

public:
    Graphics();
    ~Graphics();

    static bool Initialize(SDL_Window* window);
	static void Update();
    static bool Deinitialize();
	static void ClearBackBuffer();

    static void DrawLine(int x1 = 0, int y1 = 0, int x2 = WINDOW_WIDTH, int y2 = WINDOW_HEIGHT);
	static void DrawRect(int x = 0, int y = 0, int w = 32, int h = 32);
	static void DrawFillRect(int x = 0, int y = 0, int w = 32, int h = 32);
	static void DrawPoint(int x = WINDOW_WIDTH/2, int y = WINDOW_HEIGHT/2);

	static void DrawLevelBlock(int x, int y);
    
    static bool LoadFont(const char* font_name);
    static void Print(char* text, int x = 0, int y = 0, int font = 0);
	static void Print(int i, int x = 0, int y = 0, int font = 0);

    static void SetDrawColor(Uint8 red = 127, Uint8 green = 127, Uint8 blue = 127, Uint8 alpha = 255);
	static void BlitImage(string index, int x = WINDOW_WIDTH/2, int y = WINDOW_HEIGHT/2);

	static void RenderTextures(bool true_or_false);
	static bool IsRenderingTextures();
	static bool LoadImage(char* image_name);
};

#endif