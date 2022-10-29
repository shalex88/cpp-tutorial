cmake_minimum_required(VERSION 3.22)

include(cmake/vcpkg.cmake)

set(CMAKE_CXX_STANDARD 17)

project(cpp-tutorial)

add_subdirectory(beginner_tutorial)
add_subdirectory(design_patterns)
