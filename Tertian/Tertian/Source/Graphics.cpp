#include "Graphics.h"

SDL_Surface *Graphics::m_buffer;    //back buffer
SDL_Surface *Graphics::m_screen;    //screen buffer
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
    
   // SDL_Init(SDL_INIT_VIDEO);
    m_screen = SDL_SetVideoMode(1280, 800, 32, SDL_SWSURFACE);

    m_buffer = SDL_LoadBMP("hello.bmp");
    SDL_BlitSurface(m_buffer, NULL, m_screen, NULL);
    SDL_Flip(m_screen);

    if(TTF_Init()==-1) {
        cout << "SDL_ttf failed to initialize.";
        return false;
    }

    // load font.ttf at size 16 into font
    TTF_Font *font;
    font=TTF_OpenFont("Data/Fonts/acknowledge.ttf", 16);
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        // handle error
    }
    m_fonts.push_back(font);
    
    
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
