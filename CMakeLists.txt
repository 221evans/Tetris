cmake_minimum_required(VERSION 3.28)
project(Tetris)

set(CMAKE_CXX_STANDARD 26)

find_package(raylib 3.0.0 QUIET) # Let CMake find the installed raylib package

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)

    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/3.0.0.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()

endif()

add_executable(Tetris main.cpp
        grid.h
        grid.cpp
        block.h
        position.h
        position.cpp
        block.cpp
        colors.h
        colors.cpp)

target_link_libraries(Tetris PUBLIC raylib)







