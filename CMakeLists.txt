cmake_minimum_required( VERSION 3.10 )

project( axl.util VERSION 1.0.0 DESCRIPTION "A simple C++ utilities library." )

set( LIBAXLUTIL_SUFFIX "" )
set( CMAKE_CXX_STANDARD 11 CACHE STRING "C++ compiler standard.")
set( LIBAXLUTIL_TYPE STATIC CACHE STRING "Library type." )
set( HEADERS_INSTALL_DIR "include" CACHE PATH "Relative path for header files to install." )
set( ARCHIVES_INSTALL_DIR "lib" CACHE PATH "Relative path for library archives to install." )
set( BINARY_INSTALL_DIR "bin" CACHE PATH "Relative path for runtime binaries to install." )
set( LIBAXLUTIL_EXPORT_DIR "${PROJECT_BINARY_DIR}/tests" CACHE PATH "Binary directory relative path for runtime binaries to build to." )
set( INSTALL_HEADERS ON CACHE BOOL "" )
set( INSTALL_ARCHIVES ON CACHE BOOL "" )
set( INSTALL_BINARIES ON CACHE BOOL "" )
set( BUILD_TESTS OFF CACHE BOOL "" )
set( LIBAXLUTIL_PRINT_CONFIGS OFF CACHE BOOL "" )

if( LIBAXLUTIL_PRINT_CONFIGS )
	message( NOTICE "CMAKE_CXX_STANDARD:= ${CMAKE_CXX_STANDARD}" )
	message( NOTICE "LIBAXLUTIL_TYPE:= ${LIBAXLUTIL_TYPE}" )
	message( NOTICE "CMAKE_BUILD_TYPE:= ${CMAKE_BUILD_TYPE}" )
	message( NOTICE "HEADERS_INSTALL_DIR:= ${HEADERS_INSTALL_DIR}" )
	message( NOTICE "ARCHIVES_INSTALL_DIR:= ${ARCHIVES_INSTALL_DIR}" )
	message( NOTICE "BINARY_INSTALL_DIR:= ${BINARY_INSTALL_DIR}" )
	message( NOTICE "LIBAXLUTIL_EXPORT_DIR:= ${LIBAXLUTIL_EXPORT_DIR}" )
	message( NOTICE "INSTALL_HEADERS:= ${INSTALL_HEADERS}" )
	message( NOTICE "INSTALL_ARCHIVES:= ${INSTALL_ARCHIVES}" )
	message( NOTICE "INSTALL_BINARIES:= ${INSTALL_BINARIES}" )
	message( NOTICE "BUILD_TESTS:= ${BUILD_TESTS}" )
endif()

if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	add_compile_definitions( DEBUG )
elseif( "${CMAKE_BUILD_TYPE}" MATCHES "[Rr][Ee][Ll]" )
	add_compile_definitions( NDEBUG )
endif()

include_directories( include )

add_subdirectory( src "axl.util" )
if( BUILD_TESTS )
	add_subdirectory( tests "tests" )
endif()

# install headers
if( INSTALL_HEADERS )
	install( FILES 
		"include/axl.util/lib.hpp"
		"include/axl.util/String.hpp"
		"include/axl.util/WString.hpp"
		DESTINATION "${CMAKE_INSTALL_PREFIX}/${HEADERS_INSTALL_DIR}/axl.util" )
endif()
