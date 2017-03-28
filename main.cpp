#include <SDL.h>
#include <SDL_image.h>

#include <string>

#include <err.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int
main(int argc, char *argv[])
{
    bool quit = false;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        errx(EXIT_FAILURE, "error initializing sdl: %s", SDL_GetError());

    int flags = IMG_INIT_PNG;
    if ((IMG_Init(flags) & flags) != flags)
        errx(EXIT_FAILURE, "could not initialize png support: %s", IMG_GetError());

    SDL_Window *window = SDL_CreateWindow("Crace Razy", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    if (window == NULL)
        errx(EXIT_FAILURE, "error creating sdl window: %s", SDL_GetError());

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
        errx(EXIT_FAILURE, "error creating sdl renderer: %s", SDL_GetError());

    SDL_Surface *image = IMG_Load("res/car1.png");
    if (image == NULL)
        errx(EXIT_FAILURE, "error loading vehicles image: %s", IMG_GetError());

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    if (texture == NULL)
        errx(EXIT_FAILURE, "error creating sdl texture: %s", SDL_GetError());

    SDL_Event event;

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type) {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                quit = true;
                break;
            }
        }

        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();

    SDL_Quit();

    return 0;
}

// vim:set sw=4 ts=4 et:
