cmake_minimum_required(VERSION 3.0.12)
project(deducing_type)

add_compile_options(-std=c++14)

include_directories(
    include
)

add_executable(template_type src/template_type_test.cpp)