cmake_minimum_required(VERSION 2.8) 
project(main)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} include)
file(GLOB SOURCES "src/*.c")

add_executable(todocli ${SOURCES})
target_link_libraries(todocli ${CURSES_LIBRARIES})
