cmake_minimum_required(VERSION 3.20)
project(COP_3003_Programming_II LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Put built binaries in build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find every main.cpp (and catch common typo: mian.cpp)
file(GLOB_RECURSE PROGRAM_MAIN_FILES
        RELATIVE "${CMAKE_SOURCE_DIR}"
        "${CMAKE_SOURCE_DIR}/**/main.cpp"
        "${CMAKE_SOURCE_DIR}/**/mian.cpp"
)

if(NOT PROGRAM_MAIN_FILES)
    message(WARNING "No main.cpp (or mian.cpp) files found under ${CMAKE_SOURCE_DIR}")
endif()

# Helper: build a safe, unique target name from a relative path
function(make_target_name out_var path_rel)
    get_filename_component(_dir  "${path_rel}" DIRECTORY)
    get_filename_component(_stem "${path_rel}" NAME_WE)

    # If main.cpp is at repo root, use the file stem; otherwise use the folder path
    if(_dir STREQUAL "")
        set(_base "${_stem}")
    else()
        set(_base "${_dir}")
    endif()

    # Sanitize: slashes, spaces, dashes, weird chars → underscores; collapse repeats
    string(REPLACE "/" "_" _base "${_base}")
    string(REPLACE " " "_" _base "${_base}")
    string(REPLACE "-" "_" _base "${_base}")
    string(REGEX REPLACE "[^A-Za-z0-9_]" "_" _base "${_base}")
    string(REGEX REPLACE "_+" "_" _base "${_base}")
    # Ensure it starts with a letter
    string(REGEX REPLACE "^[^A-Za-z]+" "prog_" _base "${_base}")

    # Ensure uniqueness if two paths sanitize to the same name
    set(_candidate "${_base}")
    set(_i 1)
    while(TARGET "${_candidate}")
        math(EXPR _i "${_i}+1")
        set(_candidate "${_base}_${_i}")
    endwhile()

    set(${out_var} "${_candidate}" PARENT_SCOPE)
endfunction()

# One target per discovered main file, compiled with warnings on
foreach(MAIN_FILE IN LISTS PROGRAM_MAIN_FILES)
    # Extra safety in case file vanishes during configure
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/${MAIN_FILE}")
        message(WARNING "Skipping missing source: ${MAIN_FILE}")
        continue()
    endif()

    make_target_name(TGT "${MAIN_FILE}")
    add_executable(${TGT} "${MAIN_FILE}"
            Polymorphism-Testing/main.cpp
            "Tutroing Kev/main.cpp"
            Assignment-6-Hybrid-Inheritance/main.cpp
            Assignment-7-Polymorphism/Problem-1/main.cpp
            Assignment-7-Polymorphism/Problem-2/main.cpp
            Assignment-7-Polymorphism/Problem-2/main.cpp
            Assignment-7-Polymorphism/Problem-3/main.cpp
            Assignment-7-Polymorphism/Problem-4/main.cpp
            Assignment-7-Polymorphism/Problem-5/main.cpp)

    if (MSVC)
        target_compile_options(${TGT} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${TGT} PRIVATE -Wall -Wextra -Wpedantic)
    endif()

    message(STATUS "Added target ${TGT} -> ${MAIN_FILE}")
endforeach()