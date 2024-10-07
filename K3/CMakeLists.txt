cmake_minimum_required(VERSION 3.28)
project(K3)

set(CMAKE_CXX_STANDARD 17)

add_executable(K3 main.cpp
        cl_base.cpp
        cl_base.h
        cl_1.cpp
        cl_1.h
        cl_2.cpp
        cl_2.h
        cl_3.cpp
        cl_3.h
        cl_4.cpp
        cl_4.h
        cl_5.cpp
        cl_5.h
        cl_application.cpp
        cl_application.h)
