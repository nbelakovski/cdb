#!/bin/bash

set -ex

cd "$( dirname "${BASH_SOURCE[0]}" )"

mkdir -p build
cd build
cmake ..
make
cd ../test
mkdir -p build
cd build
echo "exit" | cmake ..
