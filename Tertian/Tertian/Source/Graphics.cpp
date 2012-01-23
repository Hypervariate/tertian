#include "Graphics.h"

SDL_Surface *Graphics::m_buffer;		
SDL_Surface *Graphics::m_fontBuffer;    
vector<TTF_Font*> Graphics::m_fonts;	
map<string, SDL_Surface*> Graphics::m_images;
SDL_Color Graphics::m_drawColor;	
SDL_Renderer *Graphics::m_renderer = NULL;
SDL_Texture *Graphics::m_bufferTexture;
SDL_Rect Graphics::m_tempRect;

bool Graphics::renderTextures = true;
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
	m_buffer = SDL_CreateRGBSurface(0,WINDOW_WIDTH,WINDOW_HEIGHT,32,0,0,0,0);
    
	m_bufferTexture = NULL;
	m_bufferTexture = SDL_CreateTextureFromSurface(m_renderer, m_buffer);
	
    return true;

}

//------------------------------------------------------
void Graphics::Update()
{

	if(renderTextures)
	{
		SDL_DestroyTexture(m_bufferTexture);
		m_bufferTexture = SDL_CreateTextureFromSurface(m_renderer, m_buffer);
		SDL_RenderCopy(m_renderer, m_bufferTexture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}
	
	
	ClearBackBuffer();

}
void Graphics::ClearBackBuffer(){
	SetDrawColor(0, 0, 0);
	SDL_RenderClear(m_renderer);
	SDL_FillRect(m_buffer, NULL, 0);
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
	SDL_Surface* surface;
	map<string,SDL_Surface*>::iterator it;
    for ( it=m_images.begin() ; it != m_images.end(); it++ )
    {
		surface = it->second;
        SDL_FreeSurface(surface);
        surface=NULL;
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
	DrawLine(x - width, y + height,	x - width,		y); //90

	DrawLine(x + width, y,			x,				y - size); //45
	DrawLine(x + width, y,			x,				y + size); //310
	DrawLine(x + width, y + height,	x,				y + size + height); //310
	DrawLine(x + width, y + height,	x + width,		y); //90	
}
void Graphics::BlitImage(string index, int x, int y){
	char* name = (char*)index.c_str();
	bool success = true;
	if(m_images[name] == NULL)
		success = LoadImage(name);
	if(!success){
		cout << "Could not load image " << name << endl;
		return;
	}
	
	//cout << name << endl;

	SDL_Surface* image = m_images[name];
	SDL_Rect rcDest = { x - image->w/2, y - image->h/2, 0, 0 };
	SDL_BlitSurface ( image, NULL, m_buffer, &rcDest );
	
	
	
	
}
void Graphics::RenderTextures(bool true_or_false){
	renderTextures = true_or_false;
}
bool Graphics::IsRenderingTextures(){
	return renderTextures;
}
bool Graphics::LoadImage(char* image_name)
{
	//check if image already exists
	if(m_images[image_name] != NULL)
	{
		SDL_Surface* surface = m_images[image_name];
        SDL_FreeSurface(surface);
        surface=NULL;
	}

	char path[MAX_PATH_LENGTH];

	for(int i = 0; i < MAX_PATH_LENGTH; i++)
		path[i] = '\0';

	strcat(path, IMAGE_DIRECTORY);
	strcat(path, image_name);
	strcat(path, IMAGE_EXTENSION);	

	SDL_Surface *image = IMG_Load ( path );
	if ( !image )
    {
      cout << "IMG_Load: " <<  IMG_GetError () ;
      return false;
    }
	m_images[image_name] = image;

	return true;
}