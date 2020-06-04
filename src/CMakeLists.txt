# Create a library called "date" which includes the source file "date.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (date date.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to "date"
target_include_directories (date PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
