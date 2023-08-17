add_library(engine SHARED)

target_compile_options(engine PRIVATE ${COMPILE_OPTIONS})
target_compile_features(engine PRIVATE ${COMPILE_FEATURES})

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
	${GLFW_include_path}
	${GLEW_include_path}
	rendering/include
	models/include
)

target_link_libraries(engine PRIVATE
	opengl32
	${GLFW_lib_path}
	${GLEW_lib_path}
)

add_custom_command(
    TARGET engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/engine/libengine.dll
    ${CMAKE_SOURCE_DIR}/libengine.dll
)
message("   libengine.dll will be copied at the end of building")