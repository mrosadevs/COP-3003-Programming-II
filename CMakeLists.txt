cmake_minimum_required(VERSION 3.20)
project(COP_3003_Programming_II LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find every main.cpp nested anywhere under the repo
file(GLOB_RECURSE PROGRAM_MAIN_FILES
     RELATIVE "${CMAKE_SOURCE_DIR}"
     "${CMAKE_SOURCE_DIR}/**/main.cpp")

foreach(MAIN_FILE IN LISTS PROGRAM_MAIN_FILES)
    # Build a readable target name based on its folder path
    get_filename_component(PARENT_DIR "${MAIN_FILE}" DIRECTORY)
    string(REPLACE "/" "_" TARGET_NAME_RAW "${PARENT_DIR}")
    string(REPLACE " " "_" TARGET_NAME "${TARGET_NAME_RAW}")

    add_executable(${TARGET_NAME} "${MAIN_FILE}")

    if (MSVC)
        target_compile_options(${TARGET_NAME} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
