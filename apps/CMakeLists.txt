# Add executable called "app" that is built from the source files
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
    COMMAND valgrind --tool=memcheck --leak-check=full --show-reachable=yes --undef-value-errors=yes --track-origins=yes --child-silent-after-fork=no --trace-children=no --xml=yes --xml-file=${CMAKE_BINARY_DIR}/valgrind/valgrind_memcheck.xml ${CMAKE_BINARY_DIR}/apps/app
    )
add_dependencies(valgrind app)
