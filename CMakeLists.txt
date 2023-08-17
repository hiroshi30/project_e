cmake_minimum_required(VERSION 3.27.0 FATAL_ERROR)
project(project_e LANGUAGES C)


option(engine_build "" ON)
option(game_build "" ON)


set(COMPILE_OPTIONS
	-Wall
	-Wextra
	-Wpedantic
)
set(COMPILE_FEATURES 
	c_std_23
)

set(GLFW_include_path ${CMAKE_SOURCE_DIR}/external/glfw-3.3.8.bin.WIN64/include)
set(GLFW_lib_path ${CMAKE_SOURCE_DIR}/external/glfw-3.3.8.bin.WIN64/lib-mingw-w64/glfw3.dll)

set(GLEW_include_path ${CMAKE_SOURCE_DIR}/external/glew-2.1.0/include)
set(GLEW_lib_path ${CMAKE_SOURCE_DIR}/external/glew-2.1.0/bin/Release/x64/glew32.dll)

if (engine_build)
	message("ENGINE BUILDING")
	add_subdirectory(engine)
endif()

if (game_build)
	message("GAME BUILDING")
	add_subdirectory(game)
endif()