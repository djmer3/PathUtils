cmake_minimum_required(VERSION 3.16)
project(path_utils LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

enable_testing()

add_subdirectory(test)

