cmake_minimum_required(VERSION 3.4)
project(cppdk CXX)
enable_testing()

set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_BUILD_TYPE Release)
set(SERIAL "0.0.1")
set(SOSERIAL "1")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build)
set(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++11 -stdlib=libstdc++")

set(src ../src/cpp CACHE STRING description FORCE)
set(test ../test/cpp CACHE STRING description FORCE)
set(build ../build CACHE STRING description FORCE)

add_library(cppdk SHARED
 ${src}/ext/Assert.cpp
 ${src}/io/File.cpp
 ${src}/lang/Integer.cpp
 ${src}/lang/Strings.cpp
 ${src}/lang/Object.cpp
 ${src}/util/ArrayList.cpp
 ${src}/util/Entry.cpp
 ${src}/util/HashMap.cpp
 ${src}/util/HashSet.cpp
)
#set_target_properties(cppdk PROPERTIES VERSION ${SERIAL} SOVERSION ${SOSERIAL})


include_directories(${src}/ext)
include_directories(${src}/io)
include_directories(${src}/lang)
include_directories(${src}/util)

add_executable(FileTest.out
 ${test}/io/FileTest.cpp
)
target_link_libraries(FileTest.out cppdk)
add_test(NAME FileTest COMMAND ${build}/FileTest.out)

add_executable(StringsTest.out
 ${test}/lang/StringsTest.cpp
)
target_link_libraries(StringsTest.out cppdk)
add_test(NAME StringsTest COMMAND ${build}/StringsTest.out)

add_executable(EntryTest.out
 ${test}/util/EntryTest.cpp
)
target_link_libraries(EntryTest.out cppdk)
add_test(NAME EntryTest COMMAND ${build}/EntryTest.out)

add_executable(HashMapTest.out
 ${test}/util/HashMapTest.cpp
)
target_link_libraries(HashMapTest.out cppdk)
add_test(NAME HashMapTest COMMAND ${build}/HashMapTest.out)

