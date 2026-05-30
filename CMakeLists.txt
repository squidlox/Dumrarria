#this cMake file is ai generated i dont wanna learn how to do this yet

cmake_minimum_required(VERSION 3.20)
project(Dumrarria)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Locate the SDL3 package on the system
find_package(SDL3 REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)
# 2. Define your executable and its source files
add_executable(Dumrarria
        src/main.cpp
        src/globalDataStructs.h
        src/EntityClass.h
        src/EntityClass.cpp
        src/EngineUpdates.cpp
        src/playerClass.cpp
        src/playerClass.h
        src/RenderEntities.cpp
        src/RenderEntities.h
        src/game.cpp
        src/game.h
        src/InputHandler.cpp
        src/InputHandler.h
        src/AppContext.h
        src/Enemy.cpp
        src/Enemy.h
        src/UserInterface.cpp
        src/UserInterface.h
        src/Camera.cpp
        src/Camera.h
        src/TextureManager.cpp
        src/TextureManager.h
)

#target_compile_options(Dumrarria PRIVATE -Wall -Wextra -g -O0 -fno-omit-frame-pointer -fsanitize=address)
#target_link_options(Dumrarria PRIVATE -fsanitize=address)
# 3. Link SDL3 to your project
# This automatically handles both the include directories and the compiled library binaries
target_link_libraries(Dumrarria PRIVATE SDL3::SDL3)
target_link_libraries(Dumrarria PRIVATE $<IF:$<TARGET_EXISTS:SDL3_image::SDL3_image-shared>,SDL3_image::SDL3_image-shared,SDL3_image::SDL3_image-static>)
