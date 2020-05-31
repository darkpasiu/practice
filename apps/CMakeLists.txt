# Add executable called "app" that is built from the source files
# "main.cpp". The extensions are automatically found.
add_executable (app main.cpp)

# Link the executable to the "date" library. Since the "date" library has
# public include directories we will use those link directories when building
# app
target_link_libraries (app LINK_PUBLIC date)
