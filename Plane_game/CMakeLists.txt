cmake_minimum_required (VERSION 3.8)

project ("Plane_game")

add_executable (Plane_game "main.cpp" "Game.h" "Game.cpp" "Plane.h" "Plane.cpp" "Obstacle.h" "Obstacle.cpp")

target_link_libraries(Plane_game ${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib)
target_link_libraries(Plane_game ${CMAKE_SOURCE_DIR}/lib/sfml-system.lib)
target_link_libraries(Plane_game ${CMAKE_SOURCE_DIR}/lib/sfml-window.lib)
target_link_libraries(Plane_game ${CMAKE_SOURCE_DIR}/lib/sfml-network.lib)

include_directories(Plane_game ${CMAKE_SOURCE_DIR}/include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Plane_game PROPERTY CXX_STANDARD 20)
endif()
