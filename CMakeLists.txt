cmake_minimum_required(VERSION 3.15)
project(PageRankAlgo)

set(CMAKE_CXX_STANDARD 14)

add_executable(PageRankAlgo main.cpp matrix.cpp matrix.hpp operations.cpp operations.hpp)