cmake_minimum_required(VERSION 3.20)
project(COP_3003_Programming_II LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find every main.cpp anywhere under the repo
file(GLOB_RECURSE PROGRAM_MAIN_FILES
     RELATIVE "${CMAKE_SOURCE_DIR}"
     "${CMAKE_SOURCE_DIR}/**/main.cpp")

foreach(MAIN_FILE IN LISTS PROGRAM_MAIN_FILES)
    # MAIN_FILE example: Assignment-1 (Classes and Objects Basics)/Bank Management System/main.cpp
    get_filename_component(PARENT_DIR "${MAIN_FILE}" DIRECTORY)   # .../Bank Management System
    # Build a target name from the path but strip illegal chars: only [A-Za-z0-9_]
    string(REPLACE "/" "_" TARGET_NAME_RAW "${PARENT_DIR}")
    # Replace spaces and hyphens with underscores first (optional clarity)
    string(REPLACE " " "_" TARGET_NAME_RAW "${TARGET_NAME_RAW}")
    string(REPLACE "-" "_" TARGET_NAME_RAW "${TARGET_NAME_RAW}")
    # Nuke everything not [A-Za-z0-9_]
    string(REGEX REPLACE "[^A-Za-z0-9_]" "_" TARGET_NAME "${TARGET_NAME_RAW}")
    # Collapse multiple underscores (purely cosmetic)
    string(REGEX REPLACE "_+" "_" TARGET_NAME "${TARGET_NAME}")
    # Ensure the name starts with a letter (CMake plays nicer)
    string(REGEX REPLACE "^[^A-Za-z]+" "prog_" TARGET_NAME "${TARGET_NAME}")

    add_executable(${TARGET_NAME} "${MAIN_FILE}"
            In-Class-Assignment-Arrays/main.cpp)

    if (MSVC)
        target_compile_options(${TARGET_NAME} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
