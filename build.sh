#!/bin/sh
echo "build start."

cd cmake
cmake .
make 
make test
cd ..

echo "build finished."
