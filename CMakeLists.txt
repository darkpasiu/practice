cmake_minimum_required(VERSION 3.6)

project(practice)

set(CMAKE_CXX_STANDARD 11)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build"
)

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate
include_directories(googletest-src/googlemock/include)
include_directories(googletest-src/googletest/include)

# Add sources
add_subdirectory(src)

# Create a library called "Date" which includes the source file "date.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (date date.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (date PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# The executable code is here
add_subdirectory(apps)

add_executable(practice main.cpp)
target_link_libraries(practice date gtest gtest_main)
