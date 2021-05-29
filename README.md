# axl.util

A simple C++ utilities library.

## Version

- Latest version: 1.8.19 alpha

## Requirements

- [CMake](https://cmake.org/) 3.4 or above.
- Any C and C++ SDK that can be accessed through a command line. ([MSVC](https://visualstudio.microsoft.com/), MinGW) If you have Visual Studio or [CodeBlocks](https://www.codeblocks.org/) then you are set.

## How to get started

- Clone this repo into the a directory and execute these commands to build the library.
  - `git clone https://github.com/defalt8/axl.util.git`
  - `cd axl.util`
  - `mkdir out\\build`
  - `cmake -B out/build -S .`
  - or with a generator of your choosing: `cmake -G <generator> -B out/build -S .`
  - `cmake --build out/build`

## CMake Options

Default values are marked **bold**.

- Library specific options
  - `AXLUTIL_TYPE`=[**STATIC**|SHARED] - The library type to build. If `BUILD_SHARED_LIBS` is set to `TRUE`, then  the library type will be `SHARED`.
  - `AXLUTIL_BUILD_TESTS`=[TRUE|FALSE] -- Builds tests by default if the project is being built standalone.
  - `AXLUTIL_INSTALL_HEADERS`=[TRUE|FALSE] -- installs headers by default if the project is being built standalone.
  - `AXLUTIL_ARCHIVE_DIR`=`${PROJECT_BINARY_DIR}/lib` -- The path to build library archive outputs to.
  - `AXLUTIL_RUNTIME_DIR`=`${PROJECT_BINARY_DIR}/bin` -- The path to build library runtime outputs to.

## Including into your CMake projects

- Just set the cmake options listed above *(\*optional)* and include this cmake project into yours.
  - `set( AXLUTIL_ARCHIVE_DIR ${PROJECT_BINARY_DIR}/lib )`
  - `set( AXLUTIL_RUNTIME_DIR ${PROJECT_BINARY_DIR}/bin )`
  - `add_subdirectory( "<path to this project>" axl.util )`
  - `target_link_libraries( <your_target> PUBLIC axl.util )`

## Library Headers

- [include/axl.util/everything.hpp](/include/axl.util/everything.hpp) - Includes every header in the library.
- [include/axl.util/lib.hpp](/include/axl.util/lib.hpp) - The library header. Contains library version.
- [include/axl.util/types.hpp](/include/axl.util/types.hpp) - Defines certain data types.
- [include/axl.util/String.hpp](/include/axl.util/String.hpp) - An string class.
- [include/axl.util/WString.hpp](/include/axl.util/WString.hpp) - A wide-char string class.
- [include/axl.util/File.hpp](/include/axl.util/File.hpp) - File operations.
- [include/axl.util/Random.hpp](/include/axl.util/Random.hpp) - Random number generator functions.
- [include/axl.util/allocators.hpp](/include/axl.util/allocators.hpp) - Allocator class.
- [include/axl.util/ds/Array.hpp](/include/axl.util/ds/Array.hpp)  - Array class
- [include/axl.util/ds/Node.hpp](/include/axl.util/ds/Node.hpp) - Defines different node types. (UniNode, BiNode, PolyNode)
- [include/axl.util/ds/List.hpp](/include/axl.util/ds/List.hpp) - Defines different node types. (UniList, ...)
- [include/axl.util/uc/Clock.hpp](/include/axl.util/uc/Clock.hpp) - Clock class for cheking past time.
- [include/axl.util/uc/Time.hpp](/include/axl.util/uc/Time.hpp) - Time class for calculating delta time.
- [include/axl.util/uc/Tracer.hpp](/include/axl.util/uc/Tracer.hpp) - Tracer class for testing data structures.
- [include/axl.util/uc/Object.hpp](/include/axl.util/uc/Object.hpp) - Object class to handle object creation and destruction on an interface level.
- [include/axl.util/uc/Child.hpp](/include/axl.util/uc/Child.hpp) - Child class to handle object relations on an interface level.
- [include/axl.util/uc/Parent.hpp](/include/axl.util/uc/Parent.hpp) - Child class to handle object relations on an interface level.
