# core/test/CMakeLists.txt

set(modname "core")

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(Boost 1.54.0 REQUIRED COMPONENTS
    unit_test_framework
    )

file(GLOB_RECURSE MAIN
    ../../test/*.cpp
    ../../test/*.hpp
    )

file(GLOB_RECURSE TESTS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" *.cpp)
foreach(testcpp ${TESTS})
    get_filename_component(basename "${testcpp}" NAME_WE)
    set(testname "test-${modname}-${basename}")

    add_executable("${testname}"
        ${MAIN}
        "${testcpp}"
        )

    target_link_libraries("${testname}"
        PUBLIC
            ${Boost_LIBRARIES}
            "lozti-${modname}"
        )

    target_include_directories("${testname}"
        PUBLIC
            ${Boost_INCLUDE_DIRS}
            ../include
        )

    target_compile_options("${testname}"
        PUBLIC
            ${Boost_CFLAGS_OTHER}
            ${Lozti_CFLAGS}
        )

    add_test("${modname}-${basename}" "${testname}")
endforeach()

# vim:set sw=4 ts=4 et:
