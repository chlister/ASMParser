cmake_minimum_required(VERSION 3.14)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp source/ArrayUtility.cpp header/ArrayUtility.h SymbolTable.cpp SymbolTable.h CParser.cpp CParser.h AParser.cpp AParser.h AssemblyParser.cpp AssemblyParser.h)