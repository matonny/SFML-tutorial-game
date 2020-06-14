# The minimum version of CMake required
cmake_minimum_required(VERSION 3.15)
# The project name
project(MyProject)
# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 14)
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(gfs main.cpp Game.cpp Game.h SplashScreen.cpp SplashScreen.h MainMenu.cpp MainMenu.h VisibleGameObject.cpp VisibleGameObject.h PlayerPaddle.cpp PlayerPaddle.h)
target_link_libraries (gfs sfml-graphics sfml-window sfml-system)