project(cortex)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)
include_directories(${PROJECT_SOURCE_DIR})
add_definitions(-std=c++11 -O3)
add_subdirectory(src)
