cmake_minimum_required(VERSION 3.27)
project(casseBrique C)

set(CMAKE_C_STANDARD 11)

set(SDL2_PATH "C:\\Users\\ziyad\\Documents\\SDL2\\SDL2-2.28.5\\x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "C:\\Users\\ziyad\\Documents\\SDL2\\SDL2_image-2.0.1\\x86_64-w64-mingw32")
set(SDL2_TTF_PATH "C:\\Users\\ziyad\\Documents\\SDL2\\SDL2_ttf-2.0.14\\x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_executable(casseBrique main.c Game.c
        mainMenu.c mainMenu.h Game.h
)

target_link_libraries(casseBrique ${SDL2_LIBRARY})
target_link_libraries(casseBrique ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(casseBrique ${SDL2_TTF_LIBRARIES})