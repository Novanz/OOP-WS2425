cmake_minimum_required(VERSION 3.29.6)
project(Blatt7)

set(CMAKE_CXX_STANDARD 20)

#set(GCC_COVERAGE_COMPILE_FLAGS "-lgtest -lgtest_main -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -Wall -Wextra" )

# Main
add_executable(Blatt7 src/Position.cpp src/Position.h
        src/City.cpp
        src/City.h
        #test/City_test.cpp
        src/PositionSorter.h
        #test/Position_test.cpp
        test/ToString_test.cpp
)

# GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

# Test executable
#add_executable(Position_Test test/Position_Test.cpp src/position.cpp src/Position.h)
#target_link_libraries(Position_Test ${GTEST_LIBRARIES} pthread)

