cmake_minimum_required(VERSION 3.27)
project(willdb)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()