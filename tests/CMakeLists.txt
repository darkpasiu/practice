# Set the compiler options
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Add executable called "tests" that is built from the source files
# "tests.cpp". The extensions are automatically found.
add_executable (tests tests.cpp)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# tests
target_link_libraries (tests LINK_PUBLIC gtest gtest_main date)
