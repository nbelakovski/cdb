[![Build Status](https://travis-ci.com/nbelakovski/cdb.svg?branch=master)](https://travis-ci.com/nbelakovski/cdb) [![codecov](https://codecov.io/gh/nbelakovski/cdb/branch/master/graph/badge.svg)](https://codecov.io/gh/nbelakovski/cdb)



## Installation

```
sudo add-apt-repository ppa:nbelakovski/cdb
sudo apt-get update
sudo apt-get install cdb
```

## Usage

In a CMakeLists.txt file, add

`find_package(cdb)`

and then call the break function anywhere you want to stop executation and examine the environment

`break()`

You can see an example in the test/ folder.

## Notes

This is a pretty basic debugger. All it can do is show you some CMake variables, get some target properties*, and help you evaluate some if statements*.

It will need a pretty sincere overhaul to work more closely with CMake internals if it will ever get to the point where you'll be able to set variables, step through execution, etc.


\* Coming in a future release
