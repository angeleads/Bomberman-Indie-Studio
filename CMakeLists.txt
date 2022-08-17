# Cmake Version
cmake_minimum_required(VERSION 3.17)
# Project name
project(bomberman)

# Usage: 
if (NOT raylib_FOUND) 
    INCLUDE(FetchContent) 
    FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        SET(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        SET(raylib_FOUND TRUE)
    endif()
    file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp")
    file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
    add_executable(${PROJECT_NAME})
    include_directories(include)
    target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES} ${PROJECT_HEADERS})
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
endif()