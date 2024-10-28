cmake_minimum_required(VERSION 3.30)
project(Blatt2)

set(CMAKE_CXX_STANDARD 14)

#set(GCC_COVERAGE_COMPILE_FLAGS "-lgtest -lgtest_main -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wextra" )

# Main
add_executable(Blatt2 main.cpp
        )

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test executable
add_executable(Position_Test test/Position_Test.cpp src/Position.cpp src/Position.h)
target_link_libraries(Position_Test ${GTEST_LIBRARIES} pthread)

