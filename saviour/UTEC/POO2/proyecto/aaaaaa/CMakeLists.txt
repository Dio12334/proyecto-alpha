cmake_minimum_required(VERSION 3.10)

project(ProyectoFinal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXE_LINKER_FLAGS "-lstdc++fs -pthread")
link_libraries(stdc++fs)

file(GLOB SOURCES "src/*")

add_executable(proyectoFinal src/main.cpp)
