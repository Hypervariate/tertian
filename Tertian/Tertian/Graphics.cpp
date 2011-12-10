#include "Graphics.h"

SDL_Surface *Graphics::m_buffer;    //back buffer
SDL_Surface *Graphics::m_screen;    //screen buffer

//------------------------------------------------------
//Graphics core constructor
Graphics::Graphics(){}

//------------------------------------------------------
//Graphics core destructor
Graphics::~Graphics(){}
//------------------------------------------------------
//Initialization routine for the graphics core
bool Graphics::Initialize(){
    
    SDL_Init(SDL_INIT_VIDEO);
    m_screen = SDL_SetVideoMode(1280, 800, 32, SDL_SWSURFACE);
    m_buffer = SDL_LoadBMP("hello.bmp");
    SDL_BlitSurface(m_buffer, NULL, m_screen, NULL);
    SDL_Flip(m_screen);
    
    return true;
}
//------------------------------------------------------
//Deinitialization routine for the graphics core
bool Graphics::Deinitialize(){
    SDL_FreeSurface(m_buffer);
    SDL_FreeSurface(m_screen);

    return true;
}