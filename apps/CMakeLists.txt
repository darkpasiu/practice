# Add executable called "app_exec" that is built from the source files
# "main.cpp". The extensions are automatically found.
add_executable (app_exec main.cpp)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (app_exec LINK_PUBLIC date)
