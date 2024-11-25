cmake_minimum_required(VERSION 3.29)
project(DanielSoria_Caso_Final_Integrador_tema3)

set(CMAKE_CXX_STANDARD 14)

include_directories(Labmain)

add_executable(DanielSoria_Caso_Final_Integrador_tema3
    Labmain/load_script.cpp
    main.cpp)
