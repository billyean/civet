add_executable(leak
        src/main.cpp)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
target_compile_options(leak PRIVATE -fsanitize=address)
target_link_options(leak PRIVATE -fsanitize=address)

set_target_properties(leak PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
)