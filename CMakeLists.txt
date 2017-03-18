cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

project (crace-razy)

find_package(PkgConfig)

include (cmake/use_cxx11.cmake)

use_cxx11 ()

add_executable (crace-razy
	./allegro/event.cpp
	./allegro/event.hpp
	./allegro/polygon.cpp
	./allegro/polygon.hpp
	./earth.cpp
	./earth.hpp
	./game.cpp
	./game.hpp
	./line.cpp
	./line.hpp
	./main.cpp
	./object.cpp
	./object.hpp
	./track.cpp
	./track.hpp
	./vector.cpp
	./vector.hpp
	./vertex.cpp
	./vertex.hpp
	)

pkg_check_modules(ALLEGRO REQUIRED
	allegro-5.0
	allegro_primitives-5.0
	)

target_link_libraries (crace-razy
	${ALLEGRO_LIBRARIES}
	)

target_include_directories(crace-razy PUBLIC
	${ALLEGRO_INCLUDE_DIRS}
	)

target_compile_options(crace-razy PUBLIC
	${ALLEGRO_CFLAGS_OTHER}
	)
