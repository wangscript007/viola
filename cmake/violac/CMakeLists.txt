cmake_minimum_required(VERSION 3.4)
project(violac C)
enable_testing()

set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_BUILD_TYPE Release)
set(SERIAL "0.0.1")
set(SOSERIAL "1")

set(root ../.. CACHE STRING description FORCE)
set(src ${root}/src/violac CACHE STRING description FORCE)
set(test ${root}/test/violac CACHE STRING description FORCE)
set(build ${root}/build/violac CACHE STRING description FORCE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${build}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${build}/test)


file(GLOB ALL_SRC "${src}/**/*.c")
add_library(violac SHARED
 ${ALL_SRC}
)

# test
file(GLOB MY_PUBLIC_HEADERS "${src}/**/*.h")
file(COPY ${MY_PUBLIC_HEADERS} DESTINATION ${build}/include)
file(COPY ${src}/violac.h DESTINATION ${build}/include)
include_directories(${build}/include)

add_executable(ArrayListTest.out
 ${test}/util/ArrayListTest.c
)
target_link_libraries(ArrayListTest.out violac)
add_test(NAME ArrayListTest COMMAND ${build}/test/ArrayListTest.out)