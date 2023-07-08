target_compile_options(engine_tests PRIVATE
	${COMPILE_OPTIONS}
)

target_compile_features(engine_tests PRIVATE
	${COMPILE_FEATURES}
)

target_sources(engine_tests PRIVATE
	src/main.c
)

target_include_directories(engine_tests PRIVATE
	../engine/include
	include
)

target_link_libraries(engine_tests PRIVATE
	engine
)