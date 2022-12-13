#
project(deque_lib)
#set(LIB_SOURCES deque.cpp deque.h)
#add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})
file(GLOB SOURCES *.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

# —----------------------------------------------------------------------------
# 2 | Libs
# —----------------------------------------------------------------------------
add_library(${PROJECT_NAME} ${SOURCES})

set(UTILS_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(UTILS_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)