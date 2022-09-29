cmake_minimum_required(VERSION 3.16)
project(CS412_LoadBalancer)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS412_LoadBalancer main.cpp Server.cpp Server.h Request.cpp LoadBalancer.cpp LoadBalancer.h)