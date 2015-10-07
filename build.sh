#!/bin/sh
echo "build start."

rm -rf build
cd cmake
cmake .
make 
make test
cd ..

echo "build finished."
