#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL.h>
#include <map>
#include <iostream>

using namespace std;


class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

    static void AnalyzeEvents(SDL_Event* event);
    static bool GetKey(const char* key_name);
    static void PrintKeyInfo( SDL_KeyboardEvent *key );

private:
    static map<SDL_Keycode, bool> keys;
    

};

#endif