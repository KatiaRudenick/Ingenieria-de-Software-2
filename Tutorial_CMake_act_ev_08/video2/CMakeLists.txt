cmake_minimum_required(VERSION 3.8)

project(HelloWorldProject)

add_subdirectory(my_library)

add_executable(hello main.cpp)

target_link_libraries(hello my_library)