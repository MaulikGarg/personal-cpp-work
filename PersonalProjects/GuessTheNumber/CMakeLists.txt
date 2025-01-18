# Minimum version for cmake
cmake_minimum_required(VERSION 3.10)

# Adding source files
set(SOURCES
    gameplay.cpp
    setFuncs.cpp
    inputClear.cpp
    )

# Making executable
add_executable(game ${SOURCES})
