#include "Graphics.h"

SDL_Surface *Graphics::m_buffer;    //back buffer
SDL_Surface *Graphics::m_screen;    //screen buffer
SDL_Surface *Graphics::m_fontBuffer;    //buffer for blitting fonts
vector<TTF_Font*> Graphics::m_fonts;

//------------------------------------------------------
//Graphics core constructor
Graphics::Graphics(){}

//------------------------------------------------------
//Graphics core destructor
Graphics::~Graphics(){}
//------------------------------------------------------
//Initialization routine for the graphics core
bool Graphics::Initialize()
{
    if(TTF_Init()==-1) {
        cout << "SDL_ttf failed to initialize.\n";
        return false;
    }
    LoadFont("acknowledge");

    SDL_Init(SDL_INIT_VIDEO);
    m_buffer = SDL_LoadBMP("hello.bmp");


   /* SDL_Color color;
    color.r = 1;
    color.g = 1;
    color.b = 1;
    m_fontBuffer = TTF_RenderText_Solid(m_fonts.at(0), "Rendering a ttf font print, bro!", color);
    SDL_BlitSurface(m_fontBuffer, NULL, m_buffer, NULL);*/
    
    
    
    
    SDL_BlitSurface(m_buffer, NULL, m_screen, NULL);
    SDL_Flip(m_screen);

   
       
    
    
    
    return true;
}
//------------------------------------------------------
//Deinitialization routine for the graphics core
bool Graphics::Deinitialize(){
    SDL_FreeSurface(m_buffer);
    SDL_FreeSurface(m_screen);

    TTF_Font* font;
    for(int i = m_fonts.size()-1; i > -1 ; i--)
    {
        font = m_fonts.at(i);
        TTF_CloseFont(font);
        font=NULL;
    }

    return true;
}
bool Graphics::LoadFont(const char* font_name)
{
    const unsigned int path_length = 256;
    char path[path_length];
    for(int i = 0; i < path_length; i++)
        path[i] = '\0';
    strcat(path, "Data/Fonts/");
    strcat(path, font_name);
    strcat(path, ".ttf");	
    
    cout << "Loading font " << path;
    // load font.ttf at size 16 into font
    TTF_Font *font = TTF_OpenFont(path, 16);
    if(!font) {
        cout << " Failed.\n" << TTF_GetError() << "\n";
        return false;
    }
    cout << " Success.\n";
    m_fonts.push_back(font);
    
    return true;
}