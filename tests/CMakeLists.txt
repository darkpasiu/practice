# Add executable called "tests" that is built from the source files
# "tests.cpp". The extensions are automatically found.
add_executable (tests tests.cpp)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# tests
target_link_libraries (tests LINK_PUBLIC gtest gtest_main date)
