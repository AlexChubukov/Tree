cmake_minimum_required(VERSION 3.0)
project(BSTree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(main_out ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)

set(tree_out ${CMAKE_CURRENT_SOURCE_DIR}/sources/tree.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(tree STATIC ${tree_out})

add_executable(main ${main_out})

target_link_libraries(main tree)
