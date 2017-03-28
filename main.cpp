#include "sdl/error.hpp"
#include "sdl.hpp"
#include "sdl/img.hpp"

#include <iostream>
#include <string>

#include <err.h>
#include <stdio.h>

#include <SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void
run_game()
{
    sdl::window window = sdl::create_window("Crace Razy", SCREEN_WIDTH, SCREEN_HEIGHT);
    sdl::renderer renderer = sdl::create_renderer(window, -1, 0);
    sdl::surface image = sdl::img::load("res/car1.png");
    sdl::texture texture = sdl::create_texture_from_surface(renderer, image);

    SDL_Event event;

    bool quit = false;
    while (!quit) {
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

        if (SDL_RenderClear(renderer.get())) {
            throw sdl::error("SDL_RenderClear");
        }
        SDL_RenderCopy(renderer.get(), texture.get(), NULL, NULL);
        SDL_RenderPresent(renderer.get());
    }
}

int
main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        errx(EXIT_FAILURE, "error initializing sdl: %s", SDL_GetError());

    int flags = IMG_INIT_PNG;
    if ((IMG_Init(flags) & flags) != flags) {
        SDL_Quit();
        errx(EXIT_FAILURE, "could not initialize png support: %s", IMG_GetError());
    }

    int exit_code = EXIT_SUCCESS;

    try {
        run_game();
    } catch (std::exception &ex) {
        warnx("unhandled exception: %s", ex.what());
        exit_code = EXIT_FAILURE;
    }

    IMG_Quit();

    SDL_Quit();

    return exit_code;
}

// vim:set sw=4 ts=4 et tw=120:
