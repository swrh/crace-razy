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

get_property(COVERAGE_TARGETS GLOBAL PROPERTY COVERAGE_TARGETS)
get_property(COVERAGE_ADD_TRACEFILES GLOBAL PROPERTY COVERAGE_ADD_TRACEFILES)
if(COVERAGE_TARGETS AND COVERAGE_ADD_TRACEFILES)
    add_custom_target("coverage"
        DEPENDS ${COVERAGE_TARGETS}
        COMMAND lcov --quiet --directory "${CMAKE_BINARY_DIR}" ${COVERAGE_ADD_TRACEFILES} --output-file "${CMAKE_BINARY_DIR}/coverage-total.info"
        COMMAND genhtml --quiet --output-directory "${CMAKE_BINARY_DIR}/coverage" "${CMAKE_BINARY_DIR}/coverage-total.info"
        )
endif()

# vim:set sw=4 ts=4 et:
