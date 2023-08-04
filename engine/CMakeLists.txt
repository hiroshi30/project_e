target_compile_options(engine PRIVATE
	${COMPILE_OPTIONS}
)

target_compile_features(engine PRIVATE
	${COMPILE_FEATURES}
)

target_sources(engine PRIVATE
	rendering/src/matrix.c
	rendering/src/vector3.c
	rendering/src/vector4.c
	rendering/src/render2d.c
	rendering/src/set.c
	rendering/src/mesh.c
	models/src/obj_reader.c
	rendering/src/camera.c
	rendering/src/render3d.c
)

target_include_directories(engine PRIVATE
	../${SDL_PATH}/include
	rendering/include
	models/include
)

target_link_directories(engine PRIVATE
	../${SDL_PATH}/lib
)

target_link_libraries(engine PRIVATE
	SDL2main
	SDL2
	mingw32
)