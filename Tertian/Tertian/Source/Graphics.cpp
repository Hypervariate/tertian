#include "Graphics.h"

SDL_Surface *Graphics::m_buffer;		//back buffer
SDL_Surface *Graphics::m_fontBuffer;    //buffer for blitting fonts
vector<TTF_Font*> Graphics::m_fonts;	//collection of all loaded fonts
SDL_Color Graphics::m_drawColor;	
SDL_Renderer *Graphics::m_renderer = NULL;
SDL_Texture *Graphics::m_bufferTexture;
SDL_Rect Graphics::m_tempRect;
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

    
    m_renderer = NULL;
    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	m_buffer = NULL;
	
    
	m_bufferTexture = NULL;
	m_bufferTexture = SDL_CreateTextureFromSurface(m_renderer, m_buffer);
	
    return true;

}

//------------------------------------------------------
void Graphics::Update()
{

	SDL_DestroyTexture(m_bufferTexture);
	m_bufferTexture = SDL_CreateTextureFromSurface(m_renderer, m_fontBuffer);
	SDL_RenderCopy(m_renderer, m_bufferTexture, NULL, NULL);
	
	SDL_RenderPresent(m_renderer);
	ClearBackBuffer();

}
void Graphics::ClearBackBuffer(){
	SetDrawColor(0, 0, 0);
	SDL_RenderClear(m_renderer);
}
//Deinitialization routine for the graphics core
bool Graphics::Deinitialize(){
    SDL_FreeSurface(m_buffer);
    SDL_DestroyTexture(m_bufferTexture);
	

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
    m_fontBuffer = TTF_RenderText_Solid(m_fonts.at(font), text, m_drawColor);
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
void Graphics::SetDrawColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    m_drawColor.r = red;
    m_drawColor.g = green;
    m_drawColor.b = blue;
	SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
}
//------------------------------------------------------
void Graphics::DrawLine(int x1, int y1, int x2, int y2){
	SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
}
void Graphics::DrawRect(int x, int y, int w, int h){
	m_tempRect.x = x;
	m_tempRect.y = y;
	m_tempRect.w = w;
	m_tempRect.h = h;

	SDL_RenderDrawRect(m_renderer, &m_tempRect);
}
void Graphics::DrawFillRect(int x, int y, int w, int h){
	m_tempRect.x = x;
	m_tempRect.y = y;
	m_tempRect.w = w;
	m_tempRect.h = h;

	SDL_RenderFillRect(m_renderer, &m_tempRect);
}
void Graphics::DrawPoint(int x, int y){
	SDL_RenderDrawPoint(m_renderer, x, y);
}
void Graphics::DrawLevelBlock(int x, int y){
	int size = 32;
	int height = (float)2/3*size;
	int width = size*2;
	

	DrawPoint(x,y);

	DrawLine(x - width, y,			x,				y - size); //45
	DrawLine(x - width, y,			x,				y + size); //310
	DrawLine(x - width, y + height,	x,				y + size + height); //310
	DrawLine(x - width, y + height,	x - width,	y); //90

	DrawLine(x + width, y,			x,				y - size); //45
	DrawLine(x + width, y,			x,				y + size); //310
	DrawLine(x + width, y + height,	x,				y + size + height); //310
	DrawLine(x + width, y + height,	x + width,	y); //90
	
    
	
}