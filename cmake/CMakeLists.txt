cmake_minimum_required(VERSION 3.4)

project(cppdk CXX)

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
)
#set_target_properties(cppdk PROPERTIES VERSION ${SERIAL} SOVERSION ${SOSERIAL})


include_directories(../src/cppdk/io)
add_executable(FileTest.out
 ../test/cppdk/io/FileTest.cpp
)
target_link_libraries(FileTest.out cppdk)
