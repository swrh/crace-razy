# test/CMakeLists.txt

cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

# Enable C++11
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_package (Boost 1.54.0 REQUIRED COMPONENTS
    unit_test_framework
    )

file (GLOB_RECURSE SOURCES
    ../include/*.hpp
    ./*.cpp
    ./*.hpp
    )

add_executable (lozti-test
    ${SOURCES}
    )

target_link_libraries (lozti-test PUBLIC
    ${Boost_LIBRARIES}
    lozti-core
    )

target_include_directories (lozti-test PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ../include
    )

target_compile_options (lozti-test PUBLIC
    ${Boost_CFLAGS_OTHER}
    )

# vim:set sw=4 ts=4 et:
