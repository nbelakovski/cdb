[![Build Status](https://travis-ci.com/nbelakovski/cdb.svg?branch=master)](https://travis-ci.com/nbelakovski/cdb) [![codecov](https://codecov.io/gh/nbelakovski/cdb/branch/master/graph/badge.svg)](https://codecov.io/gh/nbelakovski/cdb)
## Installation

From PPA
```
sudo add-apt-repository ppa:nbelakovski/cdb
sudo apt-get update
sudo apt-get install cdb
```

From source
```
git clone https://github.com/nbelakovski/cdb.git
cd cdb
mkdir build
cd build
cmake ..
make
sudo make install
```

This will install just two files, `/usr/bin/cdb` and `/usr/share/cmake/cdb/cdbConfig.cmake`

## Usage

In a CMakeLists.txt file, add

`find_package(cdb)`

and then call the break function anywhere you want to stop executation and examine the environment

`break()`

You can see an example in the test/ folder.

`break()` will take all of the cmake variables active in the current context and pass them to the cdb program which
will let you examine them. Exiting from that examination will continue the cmake process.

To list all variables currently known, type `dump`

```
) dump
CMAKE_AR=/usr/bin/ar
CMAKE_AUTOMOC_COMPILER_PREDEFINES=ON
CMAKE_AUTOMOC_MACRO_NAMES=Q_OBJECT
CMAKE_BASE_NAME=g++
...
```

To get the value of a particular variable, use ${var}

```
) ${CMAKE_AR}
/usr/bin/ar
) %{CMAKE_ARC}
CMAKE_ARC not found
```

## Notes

This is a pretty basic debugger. All it can do is show you some CMake variables, get some target properties*, and help you evaluate some if statements*.

It will need a pretty sincere overhaul to work more closely with CMake internals if it will ever get to the point where you'll be able to set variables, step through execution, etc.


\* Coming in a future release
