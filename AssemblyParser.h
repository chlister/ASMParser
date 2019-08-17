//
// Created by marc on 8/12/19.
//

#ifndef UNTITLED_ASSEMBLYPARSER_H
#define UNTITLED_ASSEMBLYPARSER_H



#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "CParser.h"
#include "AParser.h"
#include "SymbolTable.h"

class AssemblyParser {
public:
    AssemblyParser(std::string &asmFile, std::string& workDir);
    // constructor takes file input (Start with no ctor)
    // Convert Line (A- or C-instruction
    void convertLine(std::string);
    void convertFile(const std::string&);



private:
    std::string instructions;
    std::string outfile;
    std::string workDir;
    void createHack();
    void removeComments(std::string);

    inline static int lineNumber = 0;
    inline static int ramPointer = 16;
    inline static bool firstRun = true;
    SymbolTable table;
};


#endif //UNTITLED_ASSEMBLYPARSER_H