#include <SDL.h>

#include <err.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int
main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Surface *screen_surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        errx(EXIT_FAILURE, "error initializing sdl: %s", SDL_GetError());

    window = SDL_CreateWindow("Crace Razy", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    if (window == NULL)
        errx(EXIT_FAILURE, "error creating sdl window: %s", SDL_GetError());

    screen_surface = SDL_GetWindowSurface(window);

    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 100, 50));

    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

// vim:set sw=4 ts=4 et:
