cmake_minimum_required(VERSION 3.14)
project(2dshadowcasting C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib/SDL2-2.0.10)
add_subdirectory(lib/libft)

include_directories(include)
include_directories(lib/SDL2-2.0.10/include)
include_directories(lib/libft/include)

aux_source_directory(src src)

add_executable(2dshadowcasting ${src})

target_link_libraries(2dshadowcasting SDL2)
target_link_libraries(2dshadowcasting libft)
