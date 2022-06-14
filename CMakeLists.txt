cmake_minimum_required (VERSION 3.8)

project (Plane_game)

find_package(SFML 2.4 COMPONENTS audio graphics window system REQUIRED)

add_executable (Plane_game "main.cpp" "Game.h" "Game.cpp" "Plane.h" "Plane.cpp" "Obstacle.h" "Obstacle.cpp")

target_link_libraries(Plane_game sfml-audio sfml-graphics sfml-window sfml-system)

set_target_properties(Plane_game PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#if (CMAKE_VERSION VERSION_GREATER 3.12)
 # set_property(TARGET Plane_game PROPERTY CXX_STANDARD 20)
#endif()
