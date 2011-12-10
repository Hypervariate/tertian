#ifndef STDUTILS_H_
#define STDUTILS_H_




#if _DEBUG
#include <stdio.h>
#endif

static void checkSDLError(int line = -1)
{
#ifndef _DEBUG
    const char *error = SDL_GetError();
    if (*error != '\0')
    {
        printf("SDL Error: %s\n", error);
        if (line != -1)
            printf(" + line: %i\n", line);
        SDL_ClearError();
    }
#endif
}



#endif