
project(deque_app)
set(EXE_SOURCES
        main.cpp
        )
set(INC_DIR ../lib/deque.h)
add_executable(${PROJECT_NAME} ${EXE_SOURCES} ${INC_DIR})
#target_link_libraries(${PROJECT_NAME} PUBLIC ${UTILS_LIBRARIES} )
#target_include_directories(${PROJECT_NAME} PUBLIC ${UTILS_INCLUDE_DIRS})
