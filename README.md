# useful-cpp
A collection of commonly-used functions for C++ programs.

Copyright 2005 - 2017 Alexander Czutro

This library provides various functions that are needed often when creating C++
applications, for example a function that prints a customised error message and
terminates the application, or a function that prints to STDOUT raw memory
contents at given locations, very useful for debugging.

The library also includes useful numerical tests (for example, is a number
even, odd, within a range, or one of a given list of options?) and byte-level
functions (for example, easy concatenation of bytes into words and reverse
unpacking).

Note that, despite the name of this project (`useful-cpp`), the name of the
library and of the namespace in which all defined functions live is `aczutro`.
This name was chosen to absolutely avoid name clashes with other "useful"
libraries.

## Examples

See https://github.com/aczutro/czren for an example application that uses this
library.

## Documentation

The provided header file `include/libaczutro.h` specifies the provided
interface and contains all necessary information on how to use each function.

## Installing

Use the provided `Makefile` to compile the library, then move the whole file
tree to the final installation target (e.g. `/opt/useful-cpp`), and remember to
provide the include and library paths to your compiler
(`-I/opt/useful-cpp/include`) and linker (`-L/opt/useful-cpp/lib -laczutro`).
Don't forget the `#include <libaczutro.h>` line in your source code.

```shell
cd /path/to/useful-cpp
cd bin
make
cd ../../
mv useful-cpp /opt/
```

Alternatively, just copy files `include/libaczutro.h` and `lib/libaczutro.a` to
anywhere you like or anywhere that best suits your project's configuration.
However, see file `LICENCE` first.
