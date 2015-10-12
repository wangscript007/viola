cmake_minimum_required(VERSION 3.4)
project(viola CXX)
enable_testing()

set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_BUILD_TYPE Release)
set(SERIAL "0.0.1")
set(SOSERIAL "1")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build/test)
set(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++11 -stdlib=libc++")

set(src ../src/viola CACHE STRING description FORCE)
set(test ../test/viola CACHE STRING description FORCE)
set(build ../build CACHE STRING description FORCE)

file(GLOB MY_PUBLIC_HEADERS "${src}/**/*.h")
file(COPY ${MY_PUBLIC_HEADERS} DESTINATION ${build}/include)

add_library(viola SHARED
 ${src}/ext/Assert.cpp
 ${src}/io/File.cpp
 ${src}/lang/Double.cpp
 ${src}/lang/Integer.cpp
 ${src}/lang/Strings.cpp
 ${src}/lang/Object.cpp
 ${src}/util/ArrayList.cpp
 ${src}/util/Entry.cpp
 ${src}/util/HashMap.cpp
 ${src}/util/HashSet.cpp
)
#set_target_properties(viola PROPERTIES VERSION ${SERIAL} SOVERSION ${SOSERIAL})


include_directories(${src}/ext)
include_directories(${src}/io)
include_directories(${src}/lang)
include_directories(${src}/util)

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

#add_executable(HashMapTest.out
# ${test}/util/HashMapTest.cpp
#)
#target_link_libraries(HashMapTest.out viola)
#add_test(NAME HashMapTest COMMAND ${build}/test/HashMapTest.out)

