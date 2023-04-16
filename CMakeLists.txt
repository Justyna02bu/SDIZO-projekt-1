cmake_minimum_required(VERSION 3.24)
project(SIZO_P)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(.)

add_executable(SIZO_P
        Czaso.cpp
        Czaso.h
        Drzewo.cpp
        Drzewo.h
        Kopiec.cpp
        Kopiec.h
        Lista.cpp
        Lista.h
        Menu.cpp
        Opcje.cpp
        Opcje.h
        Tablica.cpp
        Tablica.h
        Testy.cpp
        Testy.h)
