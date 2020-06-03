# add compilation flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -Wall -ggdb3")

# Add executable called "app" that is built from the source file
# "main.cpp". The extensions are automatically found.
add_executable (app main.cpp)

# Link the executable to the "date" library. Since the "date" library has
# public include directories we will use those link directories when building
# app
target_link_libraries (app LINK_PUBLIC date)

# Create the valgrindv target.
add_custom_target(valgrind
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND mkdir -p valgrind
    )
add_custom_command(TARGET valgrind
    COMMAND echo "=================== valgrind ===================="
    COMMAND echo "-- Generating valgrind xml output file"
    COMMAND valgrind --leak-check=full
                     --show-leak-kinds=all
                     --track-origins=yes
                     --xml=yes
                     --xml-file=${CMAKE_BINARY_DIR}/valgrind/valgrind_memcheck.xml
                     ${CMAKE_BINARY_DIR}/apps/app
    COMMAND echo "-- Valgrind xml output file can be found in: ${CMAKE_BINARY_DIR}/valgrind/"
    )
add_dependencies(valgrind app)
