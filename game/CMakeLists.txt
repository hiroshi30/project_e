add_executable(main)

target_compile_options(main PRIVATE ${COMPILE_OPTIONS})
target_compile_features(main PRIVATE ${COMPILE_FEATURES})

target_sources(main PRIVATE
	src/main.c
)

target_include_directories(main PRIVATE
	${CMAKE_SOURCE_DIR}/engine/rendering/include
	${CMAKE_SOURCE_DIR}/engine/models/include
	include
)

target_link_libraries(main PRIVATE
	engine
)

add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/game/main.exe
    ${CMAKE_SOURCE_DIR}/main.exe
)
message("   main.exe will be copied at the end of building")