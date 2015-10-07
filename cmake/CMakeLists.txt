cmake_minimum_required(VERSION 3.4)
project(cppdk CXX)
enable_testing()

set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_C_FLAGS_RELEASE "-Wall -O2")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_BUILD_TYPE Release)
set(SERIAL "0.0.1")
set(SOSERIAL "1")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build)

add_library(cppdk SHARED
 ../src/cppdk/io/File.cpp
 ../src/cppdk/lang/Boolean.cpp
 ../src/cppdk/lang/Double.cpp
 ../src/cppdk/lang/Long.cpp
 ../src/cppdk/lang/Strings.cpp
 ../src/cppdk/util/ArrayList.cpp
 ../src/cppdk/util/HashMap.cpp
)
#set_target_properties(cppdk PROPERTIES VERSION ${SERIAL} SOVERSION ${SOSERIAL})


include_directories(../src/cppdk/io)
include_directories(../src/cppdk/lang)
include_directories(../src/cppdk/util)
add_executable(FileTest.out
 ../test/cppdk/io/FileTest.cpp
)
target_link_libraries(FileTest.out cppdk)
add_test(NAME FileTest COMMAND ../build/FileTest.out)
