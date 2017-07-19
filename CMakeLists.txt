# CMakeLists.txt

cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

project (lozti)

# Enable C++11
set (CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_package (PkgConfig)

# Source files.
file (GLOB_RECURSE COMMON_SOURCES
	./src/*.cpp
	./src/*.hpp
	)

add_executable (lozti
	${COMMON_SOURCES}
	)

pkg_check_modules(SDL2 REQUIRED
	sdl2
	)

target_link_libraries (lozti
	${SDL2_LIBRARIES}
	)

target_include_directories(lozti PUBLIC
	${SDL2_INCLUDE_DIRS}
	)

target_compile_options(lozti PUBLIC
	${SDL2_CFLAGS_OTHER}
	)
