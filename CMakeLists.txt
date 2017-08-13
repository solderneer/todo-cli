cmake_minimum_required(VERSION 2.8) 
project(main)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(main src/main.cpp)
target_link_libraries(main ${CURSES_LIBRARIES})
