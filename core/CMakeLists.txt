# core/CMakeLists.txt

cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

# Enable C++11
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_package (Boost 1.54.0 REQUIRED COMPONENTS
    )

find_package (PkgConfig)

file (GLOB_RECURSE SOURCES
    ../include/*.hpp
    ./*.cpp
    ./*.hpp
    )

add_library (lozti-core SHARED
    ${SOURCES}
    )

target_link_libraries (lozti-core PUBLIC
    ${Boost_LIBRARIES}
    )

target_include_directories (lozti-core PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ../include
    )

target_compile_options (lozti-core PUBLIC
    ${Boost_CFLAGS_OTHER}
    )

# vim:set sw=4 ts=4 et:
