cmake_minimum_required(VERSION 3.31)
project(jsoon)

set(CMAKE_CXX_STANDARD 20)

add_executable(jsoon
        src/main.cpp
        src/lexer.cpp
        src/token.cpp
        src/parser.cpp
)

target_include_directories(jsoon PRIVATE include)
