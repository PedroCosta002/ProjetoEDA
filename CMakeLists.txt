cmake_minimum_required(VERSION 3.27)
project(ProjetoEDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetoEDA main.cpp
        pecas.cpp
        pecas.h
        seccoes.cpp
        seccoes.h
        outrasfunc.cpp
        outrasfunc.h)
