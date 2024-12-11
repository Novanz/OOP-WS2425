cmake_minimum_required(VERSION 3.29)
project(OOP)


set(CMAKE_CXX_STANDARD 20)

#set(GCC_COVERAGE_COMPILE_FLAGS "-lgtest -lgtest_main -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wextra -std=c++20")

#


set(MY_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/Blatt9)

# All source files and headers
file(GLOB_RECURSE SOURCE_FILES ${MY_PREFIX}/src/*.cpp ${MY_PREFIX}/src/*.h)
message(STATUS "Current SOURCE directory: ${SOURCE_FILES}")
# Switch between tasks
# FIXME: Tasks 1 to 4 are broken
# 1
#add_executable(Blatt1 Blatt1/main.cpp)
# 2
#add_executable(Blatt2 Blatt2/main.cpp)
# 3
#add_executable(Blatt3 Blatt3/main.cpp Blatt3/${SOURCE_FILES})
# Test executable
#add_executable(Position_Test Blatt3/test/Position_Test.cpp Blatt3/${CITY_POS_FILES})
#target_link_libraries(Position_Test ${GTEST_LIBRARIES} pthread)
# 4
#add_executable(Blatt4 Blatt4/${SOURCE_FILES} Blatt4/test/city_test.cpp)
# TODO: Add tasks 5 to 9
# 5

# 6

# 7

# 8

# 9
# TODO: Make single test executable
add_executable(Blatt9 ${SOURCE_FILES} Blatt9/test/Sorter_test.cpp
        #        test/B9_City_test.cpp
)
# TODO: Refactor to use function
# Function to add tasks
#function(add_task task_name)
#    set(MY_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/${task_name})
#    file(GLOB_RECURSE SOURCE_FILES ${MY_PREFIX}/src/*.cpp ${MY_PREFIX}/src/*.h)
#    add_executable(${task_name} ${SOURCE_FILES} ${MY_PREFIX}/test/*.cpp)
#endfunction()
#
## Add tasks
#add_task(Blatt1)
#add_task(Blatt2)
#add_task(Blatt3)
#add_task(Blatt4)
#add_task(Blatt5)
#add_task(Blatt6)
#add_task(Blatt7)
#add_task(Blatt8)
#add_task(Blatt9)
#add_task(Blatt10)

# CIty and Position source files
#set(CITY_POS_FILES
#        ${MY_PREFIX}/src/Position.cpp
#        ${MY_PREFIX}/src/Position.h
#        ${MY_PREFIX}/src/City.cpp
#        ${MY_PREFIX}/src/City.h
#)
# Debugging paths
#message(STATUS "Top-level source directory: ${CMAKE_SOURCE_DIR}")
#message(STATUS "Top-level build directory: ${CMAKE_BINARY_DIR}")
#message(STATUS "Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")
#message(STATUS "Current build directory: ${CMAKE_CURRENT_BINARY_DIR}")
# GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
