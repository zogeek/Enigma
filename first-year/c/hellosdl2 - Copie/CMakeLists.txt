cmake_minimum_required(VERSION 3.26)
project(hellosdl2 C)

set(CMAKE_C_STANDARD 11)

set(SDL2_PATH "C:\\Users\\ziyad\\Documents\\SDL2-2.28.5\\x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(hellosdl2 main.c)

target_link_libraries(hellosdl2 ${SDL2_LIBRARY})
