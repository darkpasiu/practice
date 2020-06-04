# Set the compiler options
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O0 -Wall -fprofile-arcs -ftest-coverage -coverage -fno-inline")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create TESTS variable
set(TESTS "tests")

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/${TESTS}/CMakeFiles/${TESTS}.dir)
message("-- Object files will be output to: ${OBJECT_DIR}")

# Set the sources
set(sources
    tests.cpp
    ../src/date.cpp
    )
# Set Include directories
include_directories(
    src/
    ../src/
    )

# Create the executable
add_executable(${TESTS} ${sources})

# Link the executable to the library. Since the library has
# public include directories we will use those link directories when building
# tests
target_link_libraries (${TESTS} LINK_PUBLIC gtest gtest_main date)

# Testing
#enable_testing()

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p gcoverage
    COMMAND ${CMAKE_MAKE_PROGRAM} ${TESTS}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

add_custom_command(TARGET gcov
    COMMAND echo "=================== TESTS ===================="
    COMMAND ${CMAKE_BINARY_DIR}/${TESTS}/${TESTS}
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/tests/*.cpp -o ${OBJECT_DIR}
    COMMAND echo "-- Source diretorie: ${CMAKE_SOURCE_DIR}/${TESTS}/"
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/gcoverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
    )

add_dependencies(gcov ${TESTS})

# Create the lcov target. Run result tests with 'make lcov'
add_custom_target(lcov
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND mkdir -p lcoverage
    )
add_custom_command(TARGET lcov
    COMMAND echo "=================== LCOV ===================="
    COMMAND echo "-- Passing lcov tool under code coverage"
    COMMAND lcov --capture --rc lcov_branch_coverage=1 --directory ../ --output-file ${CMAKE_BINARY_DIR}/lcoverage/main_coverage.info
    COMMAND echo "-- Generating HTML output files"
    COMMAND genhtml ${CMAKE_BINARY_DIR}/lcoverage/main_coverage.info --output-directory ${CMAKE_BINARY_DIR}/lcoverage --rc lcov_branch_coverage=1
    )

add_dependencies(lcov gcov)

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES gcoverage)

# Create the gcov-clean target. This cleans the build as well as generated
# .gcda and .gcno files.
add_custom_target(init
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/gcoverage/*
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/lcoverage/*
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/valgrind/*
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
