cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

project (crace-razy)

find_package(PkgConfig)

include (cmake/use_cxx11.cmake)

use_cxx11 ()

add_executable (crace-razy
	./allegro/color.cpp
	./allegro/color.hpp
	./allegro/event.cpp
	./allegro/event.hpp
	./allegro/line.cpp
	./allegro/line.hpp
	./allegro/polygon.cpp
	./allegro/polygon.hpp
	./allegro/vector.cpp
	./allegro/vector.hpp
	./allegro/vertex.cpp
	./allegro/vertex.hpp
	./earth.cpp
	./earth.hpp
	./game.cpp
	./game.hpp
	./main.cpp
	./object.cpp
	./object.hpp
	./track.cpp
	./track.hpp
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
