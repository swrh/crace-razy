# core/CMakeLists.txt

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(Boost 1.54.0 REQUIRED COMPONENTS
    unit_test_framework
    )

file(GLOB_RECURSE MODSOURCES
    include/*.hpp
    src/*.cpp
    src/*.hpp
    )

file(GLOB_RECURSE UNITTESTS
    test/*.cpp
    )

file(GLOB_RECURSE TESTSOURCES
    ../test/*.cpp
    ../test/*.hpp
    )

set(modname "core")
set(libname "lozti-${modname}")

#############
## Library ##
#############

add_library("${libname}" SHARED
    ${MODSOURCES}
    )

target_link_libraries("${libname}"
    PUBLIC
        ${Boost_LIBRARIES}
    )

target_include_directories("${libname}"
    PUBLIC
        ${Boost_INCLUDE_DIRS}
        include
    )

target_compile_options("${libname}"
    PUBLIC
        ${Boost_CFLAGS_OTHER}
        ${Lozti_CFLAGS}
    )

################
## Unit Tests ##
################

foreach(unitsource ${UNITTESTS})
    get_filename_component(unitname "${unitsource}" NAME_WE)
    set(testname "test-${modname}-${unitname}")

    add_executable("${testname}"
        ${TESTSOURCES}
        "${unitsource}"
        )

    target_link_libraries("${testname}"
        PUBLIC
            ${Boost_LIBRARIES}
            ${libname}
            gcov
        )

    target_include_directories("${testname}"
        PUBLIC
            ${Boost_INCLUDE_DIRS}
            include
        )

    target_compile_options("${testname}"
        PUBLIC
            ${Boost_CFLAGS_OTHER}
            ${Lozti_CFLAGS}
        )

    add_test("${modname}-${unitname}" "${testname}")
endforeach()

#########################
## Unit Tests Coverage ##
#########################

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    unset(coverage_covnames)
    unset(coverage_add_tracefiles)
    set(covprefix "coverage-${modname}")
    set(tmpfile "${CMAKE_CURRENT_BINARY_DIR}/coverage-tmp.info")

    foreach(unitsource ${UNITTESTS})
        get_filename_component(unitname "${unitsource}" NAME_WE)
        set(covname "${covprefix}-${unitname}")
        set(tracefile "${CMAKE_CURRENT_BINARY_DIR}/${covname}.info")

        add_executable("${covname}"
            ${TESTSOURCES}
            ${MODSOURCES}
            "${unitsource}"
            )

        target_link_libraries("${covname}"
            PUBLIC
                ${Boost_LIBRARIES}
                gcov
            )

        target_include_directories("${covname}"
            PUBLIC
                ${Boost_INCLUDE_DIRS}
                include
            )

        target_compile_options("${covname}"
            PUBLIC
                ${Boost_CFLAGS_OTHER}
                ${Lozti_CFLAGS}
                -O0 -g --coverage
            )

        add_custom_target("run-${covname}"
            DEPENDS "${covname}" "prepare-${covprefix}"
            COMMAND lcov --quiet --directory "${CMAKE_CURRENT_BINARY_DIR}" --zerocounters
            COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${covname}"
            COMMAND lcov --quiet --directory "${CMAKE_CURRENT_BINARY_DIR}" --capture --output-file "${tmpfile}" --base-directory "${CMAKE_CURRENT_SOURCE_DIR}" --no-external
            COMMAND lcov --quiet --extract "${tmpfile}"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src/${unitname}.\\*"
                    "${CMAKE_CURRENT_SOURCE_DIR}/test/${unitname}.\\*"
                    "${CMAKE_CURRENT_SOURCE_DIR}/include/lozti/${modname}/${unitname}.\\*"
                    --output-file "${tracefile}"
            )

        list(APPEND coverage_covnames "${covname}")
        list(APPEND coverage_add_tracefiles --add-tracefile "${tracefile}")
        list(APPEND coverage_targets "run-${covname}")
    endforeach()

    add_custom_target("prepare-${covprefix}"
        DEPENDS ${coverage_covnames}
        COMMAND lcov --quiet --directory "${CMAKE_CURRENT_BINARY_DIR}" --zerocounters
        COMMAND lcov --quiet --directory "${CMAKE_CURRENT_BINARY_DIR}" --capture --initial --output-file "${tmpfile}"
        COMMAND lcov --quiet --extract "${tmpfile}" "${CMAKE_CURRENT_SOURCE_DIR}/\\*" --output-file "${CMAKE_CURRENT_BINARY_DIR}/coverage-base.info"
        )

    add_custom_target("${covprefix}"
        DEPENDS ${coverage_targets}
        )

    set_property(GLOBAL PROPERTY COVERAGE_TARGETS ${COVERAGE_TARGETS} "${covprefix}")
    set_property(GLOBAL PROPERTY COVERAGE_ADD_TRACEFILES ${COVERAGE_ADD_TRACEFILES} --add-tracefile "${CMAKE_CURRENT_BINARY_DIR}/coverage-base.info" ${coverage_add_tracefiles})
endif()

# vim:set sw=4 ts=4 et:
