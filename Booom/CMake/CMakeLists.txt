cmake_minimum_required(VERSION 3.5.1)
 
project(bomberman)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor -O3 -ffast-math")
set(PROJECT_LINK_LIBS libIrrlicht.a)

set	(
	SOURCES
	src/main.cpp
	src/interface/*.cpp
	src/game_engine/*.cpp
	)

link_directories(lib/irrlicht-1.8.4/lib/Linux /usr/X11R6/lib)
include_directories(lib/irrlicht-1.8.4/include /usr/X11R6/include)
add_executable(bomberman ${SOURCES})
target_link_libraries(bomberman ${PROJECT_LINK_LIBS} )
