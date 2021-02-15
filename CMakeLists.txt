cmake_minimum_required(VERSION 3.19.4)

project(MiniNES VERSION 0.0.1)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
        "选择一个构建类型，Release/Debug"
        FORCE)
endif()

set(BUILD_STATIC FALSE CACHE STRING
    "设置为静态链接库")

set(CMAKE_MODULE_PATH 
    "${CMAKE_SOURCE_DIR}/cmake/Modules/;"
    "${CMAKE_MODULE_PATH};"
    "${CMAKE_SOURCE_DIR}")

find_package( SFML 2 COMPONENTS audio graphics window system REQUIRED)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
else()
    set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
    message("\nSFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
    message("Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()

include_directories("./include")
add_executable(MiniNES "main.cpp")
target_link_libraries(MiniNES ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
