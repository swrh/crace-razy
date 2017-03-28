#if !defined(_SDL_HPP_)
#define _SDL_HPP_

#include <SDL.h>
#include <SDL_image.h>

#include <memory>
#include <stdexcept>

namespace sdl {

typedef std::shared_ptr<SDL_Renderer> renderer;
typedef std::shared_ptr<SDL_Surface> surface;
typedef std::shared_ptr<SDL_Texture> texture;
typedef std::shared_ptr<SDL_Window> window;

struct
exception
: std::exception
{
    const std::string message;

    exception(const std::string &message);
    virtual ~exception() throw();

    virtual const char *what() const throw();
};

/**
 * @see SDL_CreateWindow
 */
window create_window(const std::string &title, unsigned int width, unsigned int height);

/**
 * @see SDL_CreateRenderer
 */
renderer create_renderer(window &w, int index, uint32_t flags);

/**
 * @see SDL_CreateTextureFromSurface
 */
texture create_texture_from_surface(renderer &r, surface &s);

namespace img {

/**
 * @see IMG_Load
 */
surface load(const std::string &filename);

}

}

#endif // !defined(_SDL_HPP_)

// vim:set sw=4 ts=4 et tw=120:
