cmake_minimum_required(VERSION 2.8.8)

project(an_alexico)

add_definitions("-std=c++11")

include_directories(src)
set(SRC
  src/alexical_an.cpp
)

#
# DEPS
#

find_package(Threads REQUIRED)

#
# BIN
#

add_library(core OBJECT ${SRC})
set(COMMON_LIBRARIES
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(an_alexico src/main.cpp $<TARGET_OBJECTS:core>)
add_executable(an_alexico_tests src/alexical_tests.cpp $<TARGET_OBJECTS:core>)
target_link_libraries(an_alexico ${COMMON_LIBRARIES})
target_link_libraries(an_alexico_tests ${COMMON_LIBRARIES})
