cmake_minimum_required(VERSION 3.4)
project(viola CXX)
enable_testing()

set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_BUILD_TYPE Release)
set(SERIAL "0.0.1")
set(SOSERIAL "1")
set(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++11 -stdlib=libc++")

set(root ../.. CACHE STRING description FORCE)
set(src ${root}/src/viola CACHE STRING description FORCE)
set(test ${root}/test/viola CACHE STRING description FORCE)
set(build ${root}/build/viola CACHE STRING description FORCE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${build}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${build}/test)

file(GLOB ALL_SRC "${src}/**/*.cpp")
add_library(viola SHARED
 ${ALL_SRC}
)

# test
file(GLOB MY_PUBLIC_HEADERS "${src}/**/*.h")
file(COPY ${MY_PUBLIC_HEADERS} DESTINATION ${build}/include)
file(COPY ${src}/viola.h DESTINATION ${build}/include)
include_directories(${build}/include)

#include_directories(${src})
#include_directories(${src}/assert)
#include_directories(${src}/exception)
#include_directories(${src}/http)
#include_directories(${src}/io)
#include_directories(${src}/lang)
#include_directories(${src}/math)
#include_directories(${src}/net)
#include_directories(${src}/time)
#include_directories(${src}/log)
#include_directories(${src}/util)


add_executable(AssertTest.out
 ${test}/assert/AssertTest.cpp
)
target_link_libraries(AssertTest.out viola)
add_test(NAME AssertTest COMMAND ${build}/test/AssertTest.out)

add_executable(ExceptionTest.out
 ${test}/exception/ExceptionTest.cpp
)
target_link_libraries(ExceptionTest.out viola)
add_test(NAME ExceptionTest COMMAND ${build}/test/ExceptionTest.out)

add_executable(FileReaderTest.out
 ${test}/io/FileReaderTest.cpp
)
target_link_libraries(FileReaderTest.out viola)
add_test(NAME FileReaderTest COMMAND ${build}/test/FileReaderTest.out)

add_executable(FileTest.out
 ${test}/io/FileTest.cpp
)
target_link_libraries(FileTest.out viola)
add_test(NAME FileTest COMMAND ${build}/test/FileTest.out)

add_executable(DoubleTest.out
 ${test}/lang/DoubleTest.cpp
)
target_link_libraries(DoubleTest.out viola)
add_test(NAME DoubleTest COMMAND ${build}/test/DoubleTest.out)

add_executable(ObjectTest.out
 ${test}/lang/ObjectTest.cpp
)
target_link_libraries(ObjectTest.out viola)
add_test(NAME ObjectTest COMMAND ${build}/test/ObjectTest.out)

add_executable(StringsTest.out
 ${test}/lang/StringsTest.cpp
)
target_link_libraries(StringsTest.out viola)
add_test(NAME StringsTest COMMAND ${build}/test/StringsTest.out)

add_executable(SystemTest.out
 ${test}/lang/SystemTest.cpp
)
target_link_libraries(SystemTest.out viola)
add_test(NAME SystemTest COMMAND ${build}/test/SystemTest.out)

add_executable(AppenderTest.out
 ${test}/log/AppenderTest.cpp
)
target_link_libraries(AppenderTest.out  viola)
add_test(NAME AppenderTest COMMAND ${build}/test/AppenderTest.out)

add_executable(LoggerTest.out
 ${test}/log/LoggerTest.cpp
)
target_link_libraries(LoggerTest.out viola)
add_test(NAME LoggerTest COMMAND ${build}/test/LoggerTest.out)

add_executable(ArrayListTest.out
 ${test}/util/ArrayListTest.cpp
)
target_link_libraries(ArrayListTest.out viola)
add_test(NAME ArrayListTest COMMAND ${build}/test/ArrayListTest.out)

add_executable(EntryTest.out
 ${test}/util/EntryTest.cpp
)
target_link_libraries(EntryTest.out viola)
add_test(NAME EntryTest COMMAND ${build}/test/EntryTest.out)

add_executable(HashMapTest.out
 ${test}/util/HashMapTest.cpp
)
target_link_libraries(HashMapTest.out viola)
add_test(NAME HashMapTest COMMAND ${build}/test/HashMapTest.out)

