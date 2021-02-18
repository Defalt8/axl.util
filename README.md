# axl.util

A simple C++ utilities library.

## Version

- Latest version: 1.5.11

## Library Headers

- [include/axl.util/everything.hpp](/include/axl.util/everything.hpp) - Includes every header in the library.
- [include/axl.util/lib.hpp](/include/axl.util/lib.hpp) - The library header. Contains library version.
- [include/axl.util/types.hpp](/include/axl.util/types.hpp) - Defines certain data types.
- [include/axl.util/String.hpp](/include/axl.util/String.hpp) - An string class.
- [include/axl.util/WString.hpp](/include/axl.util/WString.hpp) - A wide-char string class.
- [include/axl.util/File.hpp](/include/axl.util/File.hpp) - File operations.
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

## Requirements

- CMake 3.10 or above.
- Any C and C++ SDK that can be accessed through a command line. (MSVC, MinGW) If you have Visual Studio or CodeBlocks then you are set.

## How to get started

- Clone this repo into the a directory and execute these commands to build the library.
  - git clone https://github.com/defalt8/axl.util.git
  - cd axl.util
  - mkdir out\\build
  - cd out\\build
  - cmake -B . -S ../../ (or with a generator of your choosing.) cmake -G \<generator\> -B . -S ../../
  - cmake --build .

## CMake Options

Default values are marked **bold**.

- Library specific options
  - AXLUTIL_TYPE=[**STATIC**|SHARED]
  - AXLUTIL_BUILD_TESTS=[**ON**|OFF]
  - AXLUTIL_BUILD_TOOLS=[**ON**|OFF]
  - AXLUTIL_INSTALL_HEADERS=[**ON**|OFF]
  - AXLUTIL_INSTALL_ARCHIVES=[**ON**|OFF]
  - AXLUTIL_INSTALL_BINARIES=[**ON**|OFF]
- General options
  - BUILD_TESTS=[ON|**OFF**]
  - BUILD_TOOLS=[ON|**OFF**]
  - INSTALL_HEADERS=[**ON**|OFF]
  - INSTALL_ARCHIVES=[**ON**|OFF]
  - INSTALL_BINARIES=[**ON**|OFF]
  
