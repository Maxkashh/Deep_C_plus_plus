cmake_minimum_required(VERSION 3.10.2)

project(tests)
set(CMAKE_CXX_STANDARD 20)
set(INC_DIR ../../lib/deque.h)
add_executable(${PROJECT_NAME} unit_tests.cpp ${INC_DIR} )
target_link_libraries(${PROJECT_NAME} PUBLIC

        gtest
        gtest_main
         )