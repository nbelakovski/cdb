set -e
mkdir -p build
cd build
cmake ..
make
cd ../test
mkdir -p build
cd build
echo "exit" | cmake ..

