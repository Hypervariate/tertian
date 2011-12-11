#include "Keyboard.h"

SDL_Event Keyboard::event;        //event for the listener
map<SDL_Keycode, bool> Keyboard::keys;

Keyboard::Keyboard(){}
Keyboard::~Keyboard(){}

void Keyboard::PollForEvents()
{
    SDL_PollEvent(&event);
    switch( event.type )
    {
        case SDL_KEYDOWN:
            keys[event.key.keysym.sym] = true;
            cout << "Key: " << SDL_GetKeyName( event.key.keysym.sym ) << endl;
            break;
        case SDL_KEYUP:
            keys[event.key.keysym.sym] = false;
            break;

        default:
            break;
    }
}
bool Keyboard::GetKey(const char* key_name)
{
    if(keys[SDL_GetKeyFromName(key_name)] == NULL)
        keys[SDL_GetKeyFromName(key_name)] = false;

   return  keys[SDL_GetKeyFromName(key_name)];

}