#include <err.h>
#include <stdlib.h>

#include <stdexcept>

#include <SDL.h>

using namespace std;

static void
run()
{
}

int
main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        errx(EXIT_FAILURE, "error initializing sdl: %s", SDL_GetError());

    int exit_code = EXIT_SUCCESS;

    try {
        run();
    } catch (exception &e) {
        warnx("unhandled exception: %s", e.what());
        exit_code = EXIT_FAILURE;
    }

    SDL_Quit();

    return exit_code;
}

// vim:set sw=4 ts=4 et tw=120:
