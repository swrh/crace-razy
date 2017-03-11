cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

project (crace-razy
	VERSION 0.0.1
	LANGUAGES CXX
	)

set (CMAKE_CXX_STANDARD 11)

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
