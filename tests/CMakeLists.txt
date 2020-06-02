# Set the compiler options
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/tests/CMakeFiles/tests.dir)
message("-- Object files will be output to: ${OBJECT_DIR}")

# Add executable called "tests" that is built from the source files
# "tests.cpp". The extensions are automatically found.
add_executable (tests tests.cpp)

# Link the executable to the library. Since the library has
# public include directories we will use those link directories when building
# tests
target_link_libraries (tests LINK_PUBLIC gtest gtest_main date)

# Testing
enable_testing()

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p gcoverage
    COMMAND ${CMAKE_MAKE_PROGRAM} tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

add_custom_command(TARGET gcov
    COMMAND ${CMAKE_BINARY_DIR}/tests/tests
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/tests/*.cpp -o ${OBJECT_DIR}
    COMMAND echo "-- Source diretorie: ${CMAKE_SOURCE_DIR}/tests/"
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/gcoverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
    )

add_dependencies(gcov tests)

# Create the lcov target. Run result tests with 'make lcov'
add_custom_target(lcov
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND mkdir -p lcoverage
    )
add_custom_command(TARGET lcov
    COMMAND echo "=================== LCOV ===================="
    COMMAND echo "-- Passing lcov tool under code coverage"
    COMMAND lcov --capture --directory ../ --output-file ${CMAKE_BINARY_DIR}/lcoverage/main_coverage.info
    COMMAND echo "-- Generating HTML output files"
    COMMAND genhtml ${CMAKE_BINARY_DIR}/lcoverage/main_coverage.info --output-directory ${CMAKE_BINARY_DIR}/lcoverage
    )

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES gcoverage)

# Create the gcov-clean target. This cleans the build as well as generated
# .gcda and .gcno files.
add_custom_target(init
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
