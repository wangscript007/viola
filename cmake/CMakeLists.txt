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

add_library(cppdk SHARED
 ../src/cppdk/io/File.cpp
 ../src/cppdk/lang/Integer.cpp
 ../src/cppdk/lang/Strings.cpp
 ../src/cppdk/lang/Object.cpp
 ../src/cppdk/util/ArrayList.cpp
 ../src/cppdk/util/Entry.cpp
 ../src/cppdk/util/HashMap.cpp
 ../src/cppdk/util/HashSet.cpp
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

add_executable(StringsTest.out
 ../test/cppdk/lang/StringsTest.cpp
)
target_link_libraries(StringsTest.out cppdk)
add_test(NAME StringsTest COMMAND ../build/StringsTest.out)

add_executable(EntryTest.out
 ../test/cppdk/util/EntryTest.cpp
)
target_link_libraries(EntryTest.out cppdk)
add_test(NAME EntryTest COMMAND ../build/EntryTest.out)

add_executable(HashMapTest.out
 ../test/cppdk/util/HashMapTest.cpp
)
target_link_libraries(HashMapTest.out cppdk)
add_test(NAME HashMapTest COMMAND ../build/HashMapTest.out)

