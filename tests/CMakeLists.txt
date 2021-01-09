
link_libraries( axl.util )

add_executable( "axl.util.lib" "lib.cpp" )
add_executable( "axl.util.string" "String.cpp" )
add_executable( "axl.util.wstring" "WString.cpp" )

set_target_properties(
	"axl.util.lib"
	"axl.util.string"
	"axl.util.wstring"
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${AXLUTIL_RUNTIME_DIR}"
)