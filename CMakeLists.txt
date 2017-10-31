cmake_minimum_required(VERSION 2.8) 
project(todocli)
set(TODOCLI_VERSION_MAJOR 1)
set(TODOCLI_VERSION_MINOR 0)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR} include)
file(GLOB SOURCES "src/*.c")

add_executable(todocli ${SOURCES})
target_link_libraries(todocli ${CURSES_LIBRARIES} menu)
