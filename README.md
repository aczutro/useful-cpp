# useful-cpp
A collection of commonly-used functions for C++ programs.

Copyright 2005 - 2020 Alexander Czutro

This library provides various functions that are needed often when creating C++
applications, for example a function that prints a customised error message and
terminates the application, or a function that prints to STDOUT raw memory
contents at given locations, very useful for debugging.

The library also includes useful numerical tests (for example, is a number
even, odd, within a range, or one of a given list of options?) and byte-level
functions (for example, easy concatenation of bytes into words and reverse
unpacking).

Note that, despite the name of this project (`useful-cpp`), the name of the
library and of the namespace is `aczutro`.  This name was chosen to absolutely
avoid name clashes with other "useful" libraries that might be out there.
Feel free to change that name to something that makes more sense to you.

## Examples

See https://github.com/aczutro/czren for an example application that uses this
library.

## Documentation

The comments in header file `src/libaczutro.h` provide the necessary information
on how to use each function.

## Installation

### Building

#### Linux and Unix derivates

```shell script
cd /path/to/useful-cpp
make
```

#### Windows

Use the provided CMake script `src/CMakeLists.txt`.  Most IDEs, including
Visual Studio know what to do with it.

If you have a stand-alone installation of CMake, open the Windows Command
Prompt and do the following:

```shell
cd C:\path\to\useful-cpp
mkdir build
cd build
cmake ..\src [-DCMAKE_INSTALL_PREFIX=<INSTALL_DIRECTORY>]
cmake --build .
```

### Installing

The building process creates a static library file `build/libaczutro.a`.
(`build\aczutro.lib` on Windows).  This, along with the header file
`src/libaczutro.h` is all you need, and I assume you know what to do with
these files.

#### Linux and Unix derivates

`make install` will copy these files to `$HOME/.local/lib/libaczutro` and
`$HOME/.local/include/libaczutro`.   You can override these locations by
changing the value of the variable `CMAKE_INSTALL_PREFIX` in the `Makefile`
script.

#### Windows

`cmake --build . --target install` should do something sensible depending
on the value you specified when calling cmake to create the build system.

#### Dynamic library

If you prefer to have a dynamic library (`.so`/`.dll`), look for the
`add_library` line in `src/CMakeLists.txt` and replace the keyword
`STATIC` by `SHARED`.
