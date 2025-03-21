cmake_minimum_required(VERSION 4.00)
project(MultiAUV VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(proj_lib STATIC
    src/dag.cpp    
)

target_include_directories(proj_lib PUBLIC
    include
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} proj_lib)
