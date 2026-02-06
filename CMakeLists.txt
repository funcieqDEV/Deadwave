cmake_minimum_required(VERSION 3.10)
project(Deadwave)
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)
add_executable(Deadwave
    main.cpp
    engine/engine.cpp
    entities/player/player.cpp
    entities/zombie/zombie.cpp
    entities/spawner/spawner.cpp
    engine/scene/scene_manager.cpp
)

target_link_libraries(Deadwave PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf SDL2_image::SDL2_image)
