target_compile_options(engine PRIVATE
	${COMPILE_OPTIONS}
)

target_compile_features(engine PRIVATE
	${COMPILE_FEATURES}
)

target_sources(engine PRIVATE
	src/matrix.c
	src/vector3.c
	src/vector4.c
	src/render2d.c
	src/set.c
	src/mesh.c
	src/obj_reader.c
	src/camera.c
	src/render3d.c
)

target_include_directories(engine PRIVATE
	../${SDL_PATH}/include
	include
)

target_link_directories(engine PRIVATE
	../${SDL_PATH}/lib
)

target_link_libraries(engine PRIVATE
	SDL2main
	SDL2
	mingw32
)