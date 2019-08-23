# CMakeLists.txt

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(lozti)

include(CTest)

# Enable C++11
if(CMAKE_VERSION VERSION_LESS "3.1")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        list(APPEND CMAKE_CXX_FLAGS "-std=gnu++11")
    endif()
else()
    set(CMAKE_CXX_STANDARD 11)
endif()

# Enable compiler warnings
list(APPEND Lozti_CFLAGS -Wall -Werror)

add_subdirectory(core)
add_subdirectory(app)

# vim:set sw=4 ts=4 et:
