include(FetchContent)
message(STATUS "${CMAKE_CURRENT_BINARY_DIR}")
FetchContent_Declare(vcpkg
    GIT_REPOSITORY https://github.com/Microsoft/vcpkg.git
)
FetchContent_MakeAvailable(vcpkg)

if(DEFINED vcpkg_SOURCE_DIR AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
endif()
