cmake_minimum_required(VERSION 3.8)
project(ProjectSFML)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/Game.cpp src/Game.h src/main.cpp src/Tile.cpp src/Tile.h src/Level.cpp src/Level.h src/TextManager.cpp src/TextManager.h src/Block.h src/Block.cpp src/Window.cpp src/Window.h src/IState.h src/PlayState.cpp src/PlayState.h src/MainMenuState.cpp src/MainMenuState.h src/LevelWinState.cpp src/LevelWinState.h src/GameWinState.cpp src/GameWinState.h)
add_executable(ProjectSFML ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ProjectSFML ${SFML_LIBRARIES})
endif()