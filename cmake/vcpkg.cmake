include(FetchContent)
message(STATUS "${CMAKE_CURRENT_BINARY_DIR}")
FetchContent_Declare(
    vcpkg
    GIT_REPOSITORY https://github.com/Microsoft/vcpkg.git
    GIT_TAG 2022.10.19
)
FetchContent_MakeAvailable(vcpkg)

set(CMAKE_TOOLCHAIN_FILE "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "")
