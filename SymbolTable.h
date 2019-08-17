//
// Created by marc on 8/12/19.
//

#ifndef UNTITLED_SYMBOLTABLE_H
#define UNTITLED_SYMBOLTABLE_H

#include <iostream>
#include <map>

class SymbolTable {
public:
    int findSymbol(std::string);
    void addValue(std::string, int);
//    void replaceValue(std::string key);
    inline static std::map<std::string, int> symbolTable = {
            {"R0", 0},
            {"R1", 1},
            {"R2", 2},
            {"R3", 3},
            {"R4", 4},
            {"R5", 5},
            {"R6", 6},
            {"R7", 7},
            {"R8", 8},
            {"R9", 9},
            {"R10", 10},
            {"R11", 11},
            {"R12", 12},
            {"R13", 13},
            {"R14", 14},
            {"R15", 15},
            {"SCREEN", 16384},
            {"KBD", 24576},
            {"SP", 0},
            {"LCL", 1},
            {"ARG", 2},
            {"THIS", 3},
            {"THAT", 4}
    };
private:

};


#endif //UNTITLED_SYMBOLTABLE_H
