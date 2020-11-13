cmake_minimum_required( VERSION 3.17 )

project( axl.utils )

# Configure
option( BUILD_TESTS OFF )
if( "${LIBRARY_TYPE}" STREQUAL "" )
	set( LIBRARY_TYPE "STATIC" )
endif()
if( "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	set( CMAKE_BUILD_TYPE "Debug" )
endif()

# Configure library type
if( "${LIBRARY_TYPE}" STREQUAL "MODULE" )
	set( LIB_TYPE "MODULE" )
elseif( "${LIBRARY_TYPE}" STREQUAL "SHARED" )
	set( LIB_TYPE "SHARED" )
else()
	set( LIB_TYPE "STATIC" )
endif()
add_compile_definitions( ${LIB_TYPE} )

# Configure build type
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
	add_compile_definitions( DEBUG )
	add_compile_options( -Og )
elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
	add_compile_definitions( NDEBUG )
	add_compile_options( -O3 )
endif()

# Configure install dirs
if( "${CMAKE_INSTALL_INCDIR}" STREQUAL "" )
set( CMAKE_INSTALL_INCDIR include )
endif()
if( "${CMAKE_INSTALL_LIBDIR}" STREQUAL "" )
	set( CMAKE_INSTALL_LIBDIR lib )
endif()
if( "${CMAKE_INSTALL_BINDIR}" STREQUAL "" )
	set( CMAKE_INSTALL_BINDIR bin )
endif()

set( CMAKE_CXX_STANDARD 11 )

# Print configurations
message( "Project: ${PROJECT_NAME}" )
message( "LIBRARY_TYPE= ${LIBRARY_TYPE}" )
message( "CMAKE_BUILD_TYPE= ${CMAKE_BUILD_TYPE}" )
message( "CMAKE_CXX_STANDARD= ${CMAKE_CXX_STANDARD}" )
message( "CMAKE_INSTALL_PREFIX= ${CMAKE_INSTALL_PREFIX}" )
message( "CMAKE_INSTALL_INCDIR= ${CMAKE_INSTALL_INCDIR}" )
message( "CMAKE_INSTALL_LIBDIR= ${CMAKE_INSTALL_LIBDIR}" )
message( "CMAKE_INSTALL_BINDIR= ${CMAKE_INSTALL_BINDIR}" )
message( "BUILD_TESTS= ${BUILD_TESTS}" )
message( "------------------------------------------" )

include_directories( include )
add_subdirectory( src )
if( ${BUILD_TESTS} )
	add_subdirectory( tests )
endif()

# Install
install( FILES
	"include/axl.utils/lib.hpp"
	DESTINATION "${CMAKE_INSTALL_INCDIR}/axl.utils"
)
install( TARGETS
	axl.utils
	ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
	LIBRARY DESTINATION "${CMAKE_INSTALL_BINDIR}"
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
	CONFIGURATIONS "" Debug Release
)