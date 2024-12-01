# cmake_minimum_required() should be called prior to this top-level project()
# 3.5 minimum a priori. Taking a lower version as min will make recent CMake
# version complain about the deprecation version older than 3.5.
# Might require higher version for specific features.
cmake_minimum_required( VERSION 3.5 FATAL_ERROR )

# Define project
project( advent-of-code )

include_directories(submodules/cpp-generic-toolbox/include)
include_directories(include)

add_executable( d01p1 src/day01/part1/code.C )
add_executable( d01p2 src/day01/part2/code.C )
