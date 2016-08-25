#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

int main(int argc, char** argv)
{
    printf("__GNUC__: 0x%08x\n", __GNUC__);

    const int W = 320, H = 240;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL2 & OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    SDL_GL_DeleteContext( context );
    SDL_DestroyWindow( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}
