#ifndef MOUSE_H_
#define MOUSE_H_

#include <SDL.h>
#include <iostream>

using namespace std;

class Mouse{
public:
	Mouse();
	~Mouse();

	static void PollForEvents();

	static int GetX();
	static int GetY();

	static bool GetMouseButtonLeft();
	static bool GetMouseButtonMiddle();
	static bool GetMouseButtonRight();
	
	static int GetMouseWheelDirection();

	

private:
	static bool m_mouseButtonLeft;
	static bool m_mouseButtonMiddle;
	static bool m_mouseButtonRight;
	

	static int m_mouseWheelScrollDirection;

	static int m_x;
	static int m_y;

	static SDL_Event event;	//event for the listener

};
#endif