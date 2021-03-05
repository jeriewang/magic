cmake_minimum_required(VERSION 3.09)

project(magicWrapper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
find_package (Python REQUIRED Interpreter Development)

#add_executable(${PROJECT_NAME} magicWrapper.h magicWrapper.c)
#target_link_libraries(${PROJECT_NAME} PRIVATE magic)

add_subdirectory(pybind11)
include_directories(${Python_INCLUDE_DIRS})
pybind11_add_module(${PROJECT_NAME} MODULE pythonWrapper.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE magic)
configure_file(__init__.py __init__.py COPYONLY)