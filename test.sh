#!/bin/bash

set -ex

cd "$( dirname "${BASH_SOURCE[0]}" )"

cd test
mkdir build
cd build
echo "exit" | cmake ..
echo "help" | cmake ..
echo "dump" | cmake ..
echo '${CMAKE_AR}' | cmake ..
echo '${CMAKE_ARC}' | cmake ..

# cleanup
cd ..
rm -rf build

