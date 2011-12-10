#include <iostream>
#include "Graphics.h"
#include "Timer.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "woo!";

    Graphics::Initialize();
    Timer::Delay(1000);
    Graphics::Deinitialize();

    SDL_Quit();
    
    return 0;
}