cmake_minimum_required(VERSION 3.0)
project(BSTree)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(tree STATIC \${CMAKE_CURRENT_SOURCE_DIR}/source/tree.cpp)

include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main \${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)
