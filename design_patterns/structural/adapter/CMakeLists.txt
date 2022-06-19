cmake_minimum_required(VERSION 3.16)

project(adapter)

set(CMAKE_CXX_STANDARD 20)

find_package(RapidJSON CONFIG REQUIRED)
find_package(restclient-cpp CONFIG REQUIRED)

include_directories(inc)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "inc/*.h")

add_compile_options(-Wall -Wextra -Wpedantic)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE restclient-cpp)

# Install resources
file(
    COPY ${CMAKE_CURRENT_LIST_DIR}/files
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
