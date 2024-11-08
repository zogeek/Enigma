cmake_minimum_required(VERSION 3.27)
project(spaceinvader C)

set(CMAKE_C_STANDARD 11)

set(SDL2_PATH "C:\\Users\\ziyad\\Documents\\SDL2\\SDL2-2.28.5\\x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "C:\\Users\\ziyad\\Documents\\SDL2\\SDL2_image-2.7.1\\x86_64-w64-mingw32")
set(SDL2_TTF_PATH "C:\\Users\\ziyad\\Documents\\SDL2\\SDL2_ttf-2.20.2\\x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_executable(spaceinvader main.c
        Game.c
        Game.h
        Mainmenu.h
        Mainmenu.c)

target_link_libraries(spaceinvader ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
