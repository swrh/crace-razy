# app/CMakeLists.txt

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(Boost 1.54.0 REQUIRED COMPONENTS
    program_options
    )

file(GLOB_RECURSE SOURCES
    ../include/*.hpp
    ./*.cpp
    ./*.hpp
    )

add_executable(lozti-app
    ${SOURCES}
    )

target_link_libraries(lozti-app PUBLIC
    ${Boost_LIBRARIES}
    lozti-core
    )

target_include_directories(lozti-app PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ../include
    )

target_compile_options(lozti-app PUBLIC
    ${Boost_CFLAGS_OTHER}
    ${Lozti_CFLAGS}
    )

# vim:set sw=4 ts=4 et:
