cmake_minimum_required(VERSION 3.27.0 FATAL_ERROR)
project(project_e LANGUAGES C)

set(COMPIL_OPTIONS
	-Wall
	-Wextra
	-Wpedantic
)
set(COMPILE_FEATURES 
	c_std_23
)
set(SDL_PATH external/SDL2-2.26.5/x86_64-w64-mingw32)

add_library(engine SHARED)
add_subdirectory(engine)

add_executable(game)
add_subdirectory(game)

add_executable(engine_tests)
add_subdirectory(engine_tests)