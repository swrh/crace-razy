cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

project (crace-razy)

include (cmake/use_cxx11.cmake)

use_cxx11 ()

add_executable (crace-razy
	earth.cpp
	earth.hpp
	game.cpp
	game.hpp
	line.cpp
	line.hpp
	main.cpp
	track.cpp
	track.hpp
	vector.cpp
	vector.hpp
	vertex.cpp
	vertex.hpp
	)

target_link_libraries (crace-razy
	allegro
	allegro_primitives
	)
