#!/bin/sh
echo "build start."

target=$1
if [ $# -ne 1 ]; then
 target=viola
fi

echo target: ${target}

rm -rf build/${target}
cd cmake/${target}
cmake .
make 
make test
cd ..

echo "build finished."
