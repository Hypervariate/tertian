#include "Graphics.h"

SDL_Surface *Graphics::m_buffer;    //back buffer
SDL_Surface *Graphics::m_screen;    //screen buffer
SDL_Surface *Graphics::m_fontBuffer;    //buffer for blitting fonts
vector<TTF_Font*> Graphics::m_fonts;
SDL_Color Graphics::m_fontColor;
SDL_Renderer *Graphics::m_renderer = NULL;
SDL_Texture *Graphics::m_bufferTexture;
//------------------------------------------------------
//Graphics core constructor
Graphics::Graphics(){}

//------------------------------------------------------
//Graphics core destructor
Graphics::~Graphics(){}
//------------------------------------------------------
//Initialization routine for the graphics core
bool Graphics::Initialize(SDL_Window* window)
{

    

    if(TTF_Init()==-1) 
    {
        cout << TTF_GetError();
        return false;
    }

    LoadFont("acknowledge");

   
    
    //m_screen = SDL_SetVideoMode(WINDOW_WIDTH,WINDOW_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
    m_renderer = NULL;
    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	

	m_buffer = NULL;
	m_buffer = SDL_LoadBMP("img/hello.bmp");
	
    
	m_bufferTexture = NULL;
	m_bufferTexture = SDL_CreateTextureFromSurface(m_renderer, m_buffer);
	

    /*m_buffer = SDL_LoadBMP("img/hello.bmp");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, m_buffer);
    SDL_FreeSurface(m_buffer);*/
    

    Uint32 rmask, gmask, bmask, amask;
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
    #else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
    #endif

   /* m_buffer = SDL_CreateRGBSurface(    SDL_SWSURFACE, 
                                        m_screen->clip_rect.w, 
                                        m_screen->clip_rect.h, 
                                        SCREEN_BPP, 
                                        rmask, gmask, bmask, amask);*/
    
   
    //apply the surface to the screen
    SetFontColor(255, 0, 0);

    return true;
}
//------------------------------------------------------
void Graphics::Update()
{
	
	
	SDL_DestroyTexture(m_bufferTexture);
	m_bufferTexture = SDL_CreateTextureFromSurface(m_renderer, m_fontBuffer);
	
	SDL_RenderClear(m_renderer);

	SDL_RenderCopy(m_renderer, m_bufferTexture, NULL, NULL);

    SDL_SetRenderDrawColor(m_renderer, 255, 127, 0, 255);
    SDL_RenderDrawLine(m_renderer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	
	SDL_RenderPresent(m_renderer);


}

//------------------------------------------------------
//Deinitialization routine for the graphics core
bool Graphics::Deinitialize(){
    SDL_FreeSurface(m_buffer);
    SDL_DestroyTexture(m_bufferTexture);
	SDL_FreeSurface(m_screen);

    TTF_Font* font;
    for(int i = m_fonts.size()-1; i > -1 ; i--)
    {
        font = m_fonts.at(i);
        TTF_CloseFont(font);
        font=NULL;
    }

	
    SDL_DestroyRenderer(m_renderer);

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
void Graphics::Print(char* text, int x, int y, int font)
{
    SDL_FreeSurface(m_fontBuffer);
    m_fontBuffer = TTF_RenderText_Solid(m_fonts.at(font), text, m_fontColor);
    m_fontBuffer->clip_rect.x = x;
    m_fontBuffer->clip_rect.y = y;
    SDL_BlitSurface(m_fontBuffer, NULL, m_buffer, &m_fontBuffer->clip_rect);
}
void Graphics::Print(int i, int x, int y, int font)
{
	char buffer[32];
	//scanf("%d", &i);
	itoa(i, buffer, 10);
	Print(buffer, x, y, font);
}
void Graphics::SetFontColor(Uint8 red, Uint8 green, Uint8 blue)
{
    m_fontColor.r = red;
    m_fontColor.g = green;
    m_fontColor.b = blue;
}
void Graphics::DrawLine(int x1, int y1, int x2, int y2)
{
    
}
