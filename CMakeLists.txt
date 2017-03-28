cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

project (crace-razy)

find_package(PkgConfig)

include (cmake/use_cxx11.cmake)

use_cxx11 ()

add_executable (crace-razy
	./exception.cpp
	./exception.hpp
	./main.cpp
	./sdl.cpp
	./sdl.hpp
	./sdl/error.cpp
	./sdl/error.hpp
	./sdl/exception.cpp
	./sdl/exception.hpp
	./sdl/img.cpp
	./sdl/img.hpp
	./sdl/img/error.cpp
	./sdl/img/error.hpp
	./sdl/types.hpp
	)

pkg_check_modules(SDL2 REQUIRED
	sdl2
	SDL2_image
	)

target_link_libraries (crace-razy
	${SDL2_LIBRARIES}
	)

target_include_directories(crace-razy PUBLIC
	${SDL2_INCLUDE_DIRS}
	)

target_compile_options(crace-razy PUBLIC
	${SDL2_CFLAGS_OTHER}
	)
