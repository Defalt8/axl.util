cmake_minimum_required( VERSION 3.17 )

# Library
add_library( axl.utils ${LIB_TYPE}
	"lib.cpp"
	"String.cpp"
)
# Target compile definitions
if( "${LIB_TYPE}" STREQUAL "SHARED" )
	target_compile_definitions( axl.utils PRIVATE BUILD_SHARED )
elseif( "${LIB_TYPE}" STREQUAL "MODULE" )
	target_compile_definitions( axl.utils PRIVATE BUILD_MODULE )
endif()
# Target properties
set_target_properties( axl.utils PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
	set_target_properties( axl.utils PROPERTIES
		ARCHIVE_OUTPUT_NAME axl.utilsd
		LIBRARY_OUTPUT_NAME axl.utilsd
		RUNTIME_OUTPUT_NAME axl.utilsrd
	)
else()
	set_target_properties( axl.utils PROPERTIES
		ARCHIVE_OUTPUT_NAME axl.utils
		LIBRARY_OUTPUT_NAME axl.utils
		RUNTIME_OUTPUT_NAME axl.utilsr
	)
endif()