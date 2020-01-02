#!/bin/bash

set -ex

cd "$( dirname "${BASH_SOURCE[0]}" )"

cd test
mkdir build
cd build
echo "exit" | cmake ..

# cleanup
cd ..
rm -rf build

