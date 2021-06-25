set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE )
set( DEBUG_SUFFIX "" )
set( TYPE_SUFFIX "" )

if( "${AXLUTIL_TYPE}" MATCHES "[Ss][Hh][Aa][Rr][Ee][Dd]" OR BUILD_SHARED_LIBS )
	set( AXLUTIL_TYPE SHARED )
else()
	set( AXLUTIL_TYPE STATIC )
	set( TYPE_SUFFIX s )
endif()

if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	set( DEBUG_SUFFIX d )
endif()

add_library( axl.util ${AXLUTIL_TYPE}
	"lib.cpp"
	"String.cpp"
	"WString.cpp"
	"Directory.cpp"
	"File.cpp"
	"Random.cpp"
	"Serial.cpp"
	"Protocol.cpp"
	"protocols/V0.cpp"
	"utils.cpp"
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
	"${AXLUTIL_INCLUDE_DIR}/axl.util/Directory.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/Random.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/Serial.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/Protocol.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/protocols/V0.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/utils.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/allocators.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Array.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Node.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/List.hpp"
	"${AXLUTIL_INCLUDE_DIR}/axl.util/ds/Map.hpp"
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

if( "${AXLUTIL_TYPE}" STREQUAL "SHARED" )
	target_compile_definitions( axl.util PUBLIC AXLUTIL_SHARED )
else()
	target_compile_definitions( axl.util PUBLIC AXLUTIL_STATIC )
endif()

if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	target_compile_definitions( axl.util PRIVATE DEBUG )
elseif( "${CMAKE_BUILD_TYPE}" MATCHES "[Rr][Ee][Ll]" )
	target_compile_definitions( axl.util PRIVATE NDEBUG )
endif()

set_target_properties( axl.util PROPERTIES
	ARCHIVE_OUTPUT_NAME "axl.util${TYPE_SUFFIX}${DEBUG_SUFFIX}"
	LIBRARY_OUTPUT_NAME "axl.util${TYPE_SUFFIX}${DEBUG_SUFFIX}"
	RUNTIME_OUTPUT_NAME "axl.util${TYPE_SUFFIX}${DEBUG_SUFFIX}"
	ARCHIVE_OUTPUT_DIRECTORY "${AXLUTIL_ARCHIVE_DIR}"
	LIBRARY_OUTPUT_DIRECTORY "${AXLUTIL_LIBRARY_DIR}"
	RUNTIME_OUTPUT_DIRECTORY "${AXLUTIL_RUNTIME_DIR}"
)

install( TARGETS axl.util
	ARCHIVE DESTINATION "lib"
	LIBRARY DESTINATION "bin"
	RUNTIME DESTINATION "bin"
)
