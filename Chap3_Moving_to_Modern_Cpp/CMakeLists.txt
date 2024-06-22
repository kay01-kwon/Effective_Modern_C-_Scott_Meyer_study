cmake_minimum_required(VERSION 3.0.12)
add_compile_options(-std=c++14)

include_directories(
    include
)

add_executable(item7 src/item7.cpp
include/class_item7.cpp)