# common/CMakeLists.txt

cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

# Enable C++11
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_package (Boost 1.54.0 REQUIRED COMPONENTS
    )

find_package (PkgConfig)

pkg_check_modules (SDL2 REQUIRED
    sdl2
    )

file (GLOB_RECURSE SOURCES
    ../include/*.hpp
    ./*.cpp
    ./*.hpp
    )

add_library (lozti-common SHARED
    ${SOURCES}
    )

target_link_libraries (lozti-common PUBLIC
    ${Boost_LIBRARIES}
    ${SDL2_LIBRARIES}
    )

target_include_directories (lozti-common PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ../include
    )

target_compile_options (lozti-common PUBLIC
    ${Boost_CFLAGS_OTHER}
    ${SDL2_CFLAGS_OTHER}
    )

# vim:set sw=4 ts=4 et:
