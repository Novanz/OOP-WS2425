cmake_minimum_required(VERSION 3.29.6)
project(Blatt9)

set(CMAKE_CXX_STANDARD 20)

#set(GCC_COVERAGE_COMPILE_FLAGS "-lgtest -lgtest_main -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wextra -std=c++20")

# Main
add_executable(Blatt9 src/Position.cpp src/Position.h
        src/City.cpp
        src/City.h
        src/Sorter.h
        #        test/B9_City_test.cpp
        test/Sorter_test.cpp
)

# GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

# Test executable
#add_executable(Position_Test test/Position_Test.cpp src/position.cpp src/Position.h)
#target_link_libraries(Position_Test ${GTEST_LIBRARIES} pthread)

