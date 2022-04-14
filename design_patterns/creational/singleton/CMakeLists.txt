cmake_minimum_required(VERSION 3.16)
project(singleton)

set(CMAKE_CXX_STANDARD 20)

include_directories(inc)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "inc/*.h")

add_compile_options(-Wall -Wextra -Wpedantic)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
