cmake_minimum_required(VERSION 3.0)

set(RoughButter_SOURCES
    src/main.cpp
)

add_executable(RoughButter ${RoughButter_SOURCES})
target_link_libraries(RoughButter ffi dl)