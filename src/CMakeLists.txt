
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE )
if( BUILD_SHARED_LIBS )
	set( AXLUTIL_TYPE SHARED )
endif()

add_library( axl.util ${AXLUTIL_TYPE}
	"lib.cpp"
	"String.cpp"
	"WString.cpp"
	"File.cpp"
	"uc/Clock.cpp"
	"uc/Time.cpp"
	"uc/Tracer.cpp"
	"uc/Object.cpp"
	"uc/Child.cpp"
	"uc/Parent.cpp"

	"${AXLUTIL_INCLUDE_DIR}/axl.util/everything.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/lib.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/types.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/String.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/WString.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/File.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/allocators.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Array.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Node.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/List.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Tracer.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Clock.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Time.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Object.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Child.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Parent.hpp"
)
target_include_directories( axl.util PUBLIC "${AXLUTIL_INCLUDE_DIR}" )
target_compile_definitions( axl.util
	PRIVATE AXLUTIL_BUILD
	PRIVATE AXLUTIL_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
	PRIVATE AXLUTIL_VERSION_MINOR=${PROJECT_VERSION_MINOR}
	PRIVATE AXLUTIL_VERSION_PATCH=${PROJECT_VERSION_PATCH}
)

if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	target_compile_definitions( axl.util PRIVATE DEBUG )
	set( DEBUG_SUFFIX d )
elseif( "${CMAKE_BUILD_TYPE}" MATCHES "[Rr][Ee][Ll]" )
	target_compile_definitions( axl.util PRIVATE NDEBUG )
	set( DEBUG_SUFFIX "" )
endif()

if( "${AXLUTIL_TYPE}" STREQUAL "STATIC" )
	target_compile_definitions( axl.util PUBLIC AXLUTIL_STATIC )
	set( TYPE_SUFFIX s )
elseif( "${AXLUTIL_TYPE}" STREQUAL "SHARED" )
	target_compile_definitions( axl.util PUBLIC AXLUTIL_SHARED )
	set( TYPE_SUFFIX "" )
endif()

set_target_properties( axl.util PROPERTIES
	ARCHIVE_OUTPUT_NAME "axl.util${TYPE_SUFFIX}${DEBUG_SUFFIX}"
	RUNTIME_OUTPUT_NAME "axl.util${TYPE_SUFFIX}${DEBUG_SUFFIX}"
	ARCHIVE_OUTPUT_DIRECTORY "${AXLUTIL_ARCHIVE_DIR}"
	RUNTIME_OUTPUT_DIRECTORY "${AXLUTIL_RUNTIME_DIR}"
)
### Install
if( AXLUTIL_INSTALL_ARCHIVES AND AXLUTIL_INSTALL_BINARIES )
	install( TARGETS axl.util
		ARCHIVE DESTINATION "lib"
		RUNTIME DESTINATION "bin"
	)
elseif( AXLUTIL_INSTALL_ARCHIVES )
	install( TARGETS axl.util ARCHIVE DESTINATION "lib" )
elseif( AXLUTIL_INSTALL_BINARIES )
	install( TARGETS axl.util RUNTIME DESTINATION "bin" )
endif()

if( AXLUTIL_INSTALL_HEADERS )
	install( FILES 
		"${AXLUTIL_INCLUDE_DIR}/axl.util/everything.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/lib.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/types.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/String.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/WString.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/File.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/allocators.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/allocators.inl"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Array.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Array.inl"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Node.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Node.inl"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/List.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/List.inl"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Clock.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Time.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Tracer.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Tracer.inl"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Object.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Child.hpp"
		"${AXLUTIL_INCLUDE_DIR}/axl.util/uc/Parent.hpp"
		DESTINATION "include/axl.util" )
endif()
