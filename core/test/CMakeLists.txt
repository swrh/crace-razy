# core/test/CMakeLists.txt

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(Boost 1.54.0 REQUIRED COMPONENTS
    unit_test_framework
    )

file(GLOB_RECURSE SOURCES
    ../include/*.hpp
    *.cpp
    *.hpp
    ../../test/*.cpp
    ../../test/*.hpp
    )

add_executable(test-core
    ${SOURCES}
    )

target_link_libraries(test-core
    PUBLIC
        ${Boost_LIBRARIES}
        lozti-core
    )

target_include_directories(test-core
    PUBLIC
        ${Boost_INCLUDE_DIRS}
        ../include
    )

target_compile_options(test-core
    PUBLIC
        ${Boost_CFLAGS_OTHER}
        ${Lozti_CFLAGS}
    )

add_test(core test-core)

# vim:set sw=4 ts=4 et:
