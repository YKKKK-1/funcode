cmake_minimum_required(VERSION 3.22)
project(Travelgame)

set(CMAKE_CXX_STANDARD 14)

include_directories(SourceCode/Header)

add_executable(Travelgame
        SourceCode/Header/CommonAPI.h
        SourceCode/Header/LessonX.h
        SourceCode/Src/CommonAPI.a
        SourceCode/Src/LessonX.cpp
        SourceCode/Src/Main.cpp)
