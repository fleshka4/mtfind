cmake_minimum_required(VERSION 3.18)
project(mtfind)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB ALL_SRCS src/*.cpp main.cpp)

add_executable(mtfind ${ALL_SRCS})

TARGET_LINK_LIBRARIES(mtfind pthread)
