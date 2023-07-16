target_compile_options(main PRIVATE
	${COMPILE_OPTIONS}
)

target_compile_features(main PRIVATE
	${COMPILE_FEATURES}
)

target_sources(main PRIVATE
	src/main.c
)

target_include_directories(main PRIVATE
	../engine/include
	../file_reader/include
	include
)

target_link_libraries(main PRIVATE
	engine
)