#include "Mouse.h"

bool Mouse::m_mouseButtonLeft = false;
bool Mouse::m_mouseButtonMiddle = false;
bool Mouse::m_mouseButtonRight = false;


int Mouse::m_mouseWheelScrollDirection = 0;

int Mouse::m_x = 0;
int Mouse::m_y = 0;



Mouse::Mouse(){}
Mouse::~Mouse(){}


void Mouse::AnalyzeEvents(SDL_Event* event)
{

	

	//mouse coordinates
	switch( event->type )
    {
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&m_x, &m_y);
			break;
        default:
			break;
    }
	
	//mouse wheel
	m_mouseWheelScrollDirection = 0;
	switch( event->button.button )
    {
		case SDL_BUTTON_WHEELUP:
			m_mouseWheelScrollDirection = 1;
			break;
		case SDL_BUTTON_WHEELDOWN:
			m_mouseWheelScrollDirection = -1;
			break;
		default:
			break;
	}

	// left mouse button
	if( SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))	   
		m_mouseButtonLeft = true;
	else
		m_mouseButtonLeft = false;

	// middle mouse button
	if( SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))	   
		m_mouseButtonMiddle = true;
	else
		m_mouseButtonMiddle = false;

	// right mouse button
	if( SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))	   
		m_mouseButtonRight = true;
	else
		m_mouseButtonRight = false;

	
}
int Mouse::GetX()
{
	return m_x;
}
int Mouse::GetY()
{
	return m_y;
}
bool Mouse::GetMouseButtonLeft()
{
	return m_mouseButtonLeft;
}
bool Mouse::GetMouseButtonMiddle()
{
	return m_mouseButtonMiddle;
}
bool Mouse::GetMouseButtonRight()
{
	return m_mouseButtonRight;
}
int Mouse::GetMouseWheelDirection()
{
	return m_mouseWheelScrollDirection;
}