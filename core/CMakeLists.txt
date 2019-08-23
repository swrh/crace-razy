# core/CMakeLists.txt

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(Boost 1.54.0 REQUIRED COMPONENTS
    )

find_package(PkgConfig)

file(GLOB_RECURSE SOURCES
    ../include/*.hpp
    ./*.cpp
    ./*.hpp
    )

add_library(lozti-core SHARED
    ${SOURCES}
    )

target_link_libraries(lozti-core PUBLIC
    ${Boost_LIBRARIES}
    )

target_include_directories(lozti-core PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ../include
    )

target_compile_options(lozti-core PUBLIC
    ${Boost_CFLAGS_OTHER}
    ${Lozti_CFLAGS}
    )

# vim:set sw=4 ts=4 et:
