cmake_minimum_required(VERSION 3.0)
project(my_raylib_game CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# Adding Raygui
FetchContent_Declare(
    raygui
    GIT_REPOSITORY "https://github.com/raysan5/raygui.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raygui)

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/sources/*.cpp")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/sources/")

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES}  "sources/ui.h" "sources/pickables.h" "sources/pickables.cpp" "sources/animation.h")
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE} ${raygui_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

# Raygui inclusion (no linking needed)
target_compile_definitions(${PROJECT_NAME} PRIVATE RAYGUI_SUPPORT_ICONS)
