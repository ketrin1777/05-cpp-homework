cmake_minimum_required(VERSION 3.20.0)
project(Less VERSION 0.1.0 LANGUAGES C CXX)


file(GLOB project
    src/main.cpp
    src/list.cpp 
    src/list.h
)

add_executable(Less ${project})


# Продключаем Catch2
add_subdirectory(../Catch2 test-build)
file(GLOB project_test
    src/test-main.cpp
    src/list.cpp
    src/list.h
)


add_executable(Less_test ${project_test})
target_link_libraries(Less_test PRIVATE Catch2::Catch2)