cmake_minimum_required(VERSION 2.8)
project(multi-agent-system)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
add_subdirectory(src)