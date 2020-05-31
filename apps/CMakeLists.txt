# Add executable called "appDemo" that is built from the source files
# "main.cpp". The extensions are automatically found.
add_executable (appDemo main.cpp)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# appDemo
target_link_libraries (appDemo LINK_PUBLIC date)
