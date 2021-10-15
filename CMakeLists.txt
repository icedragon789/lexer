cmake_minimum_required(VERSION 3.15)
project(lexer)

set(CMAKE_CXX_STANDARD 14)

add_executable(lexer main.cpp enums.hpp Token.hpp Token.cpp tools.hpp tools.cpp Lexer.hpp Lexer.cpp)