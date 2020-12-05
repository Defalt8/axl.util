# axl.util

A simple C++ utilities library.

## Version

- Latest version: 1.0.2

## Library Headers

- [axl.util/lib.hpp](/include/axl.util/lib.hpp) - The library header. Contains library version.
- [axl.util/String.hpp](/include/axl.util/String.hpp) - A string class.
- [axl.util/WString.hpp](/include/axl.util/WString.hpp) - A wide-char string class.

## Requirements

- Windows operating system. (Linux and other platforms implementations are on the way)
- CMake 3.10 or above.
- Any C and C++ SDK that can be accessed through a command line. (MSVC, MinGW) If you have Visual Studio or CodeBlocks then you are set.

## How to get started

- Clone this repos into the a directory and execute these commands to build the library.
  - git clone https://github.com/defalt8/axl.util.git
  - cd template.axl.util
  - mkdir out\\build
  - cd out\\build
  - cmake -B . -S ../../ (or with a generator of your choosing.) cmake -G \<generator\> -B . -S ../../
  - cmake --build .

## CMake Options

Default values are marked **bold**.
- LIBAXLUTIL_TYPE=[**STATIC**|SHARED]
- BUILD_TESTS=[ON|**OFF**]
- LIBAXLUTIL_BUILD_TESTS=[**ON**|OFF]
- BUILD_TOOLS=[ON|**OFF**]
- LIBAXLUTIL_BUILD_TOOLS=[**ON**|OFF]
- INSTALL_HEADERS=[**ON**|OFF]
- INSTALL_ARCHIVES=[**ON**|OFF]
- INSTALL_BINARIES=[**ON**|OFF]
- LIBAXLUTIL_INSTALL_HEADERS=[**ON**|OFF]
- LIBAXLUTIL_INSTALL_ARCHIVES=[**ON**|OFF]
- LIBAXLUTIL_INSTALL_BINARIES=[**ON**|OFF]

  
