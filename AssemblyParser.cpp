//
// Created by marc on 8/12/19.
//

#include "AssemblyParser.h"

AssemblyParser::AssemblyParser(std::string &asmFile, std::string &workDir)
        :outfile(asmFile), workDir(workDir)
{

}



void AssemblyParser::convertLine(std::string line) {
    std::string res;
    line = line.substr(0, line.find('\r')); //
    line = line.substr( 0, line.find('/'));
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    if (!line.empty()) {
        if (AssemblyParser::firstRun) {
            if (line.find('(') != std::string::npos) {
                // label
                line = line.substr(1, line.find(')') - 1);
                // label er ikke set før - så vi gemmer rom index
                table.addValue(line, AssemblyParser::lineNumber);
                // label er set før - vi ændre værdien
//                SymbolTable::symbolTable.find(line)->second = AssemblyParser::lineNumber;
                // ignore instruction
                AssemblyParser::lineNumber--;
            }
        } else {
            if (line.find('(') == std::string::npos){
                if (line.find('@') != std::string::npos) {
                    // A-instruction
                    line = line.substr(line.find('@') + 1, line.length());
                    // if [0] is not a number -> symbol
                    if (!isdigit(line[0])) { // TODO: expand to look at all digits
                        // this is symbol
                        // see if symbol exists in symboltable
                        if (table.findSymbol(line) != -1) {
                            // We found symbol
                            line = std::to_string(table.findSymbol(line));
                            std::stringstream cnv(line);
                            int val = 0;
                            cnv >> val;
                            instructions += (AParser::numToBinary(val) + "\r");
//                        AssemblyParser::lineNumber++;
                        } else { // Symbol not found
                            // symbol (Ram pointer)
                            // Ram pointer
                            table.addValue(line, AssemblyParser::ramPointer);
                            // Save in instruction
                            instructions += (AParser::numToBinary(AssemblyParser::ramPointer) + "\r");
                            AssemblyParser::ramPointer++;
                        }
                    } else {
                        // A-instruction is a digit (@453)
                        std::stringstream cnv(line);
                        int val = 0;
                        cnv >> val;
                        instructions += (AParser::numToBinary(val) + "\r");
//                    AssemblyParser::lineNumber++;
                    }
                } else {
                    // C-instruction
                    CParser cparser;
                    instructions += (cparser.parseInstruction(line) + "\r");
//                AssemblyParser::lineNumber++;
                }
            }
        }
        if(AssemblyParser::firstRun){
            AssemblyParser::lineNumber++;
        }
    }
}


//void AssemblyParser::convertFile(std::ifstream &) {}

void AssemblyParser::convertFile(const std::string& sfile) {
    std::string line;
    std::ifstream file;

    // Remove all comments
//    this -> removeComments(sfile);
    for (int i = 0; i < 2; ++i) {
        if (i>=1)
            AssemblyParser::firstRun = false;
        file.open(sfile);
        if(file.is_open()){
            while (getline(file, line)){
//            this -> removeComments(sfile);
                convertLine(line);
            }
            file.close();
        }
        else{
            std::cout << "File error" << std::endl;
        }
    }
    this -> createHack();
}

void AssemblyParser::createHack() {
    std::string loc = workDir + outfile + ".hack";
    std::ofstream out(loc);
    if (out.is_open()){
        std::cout << "Outputting file to location: " << std::endl;
        std::cout << loc << std::endl;
        out << instructions;
        out.close();
    } else {
        std::cout <<  "File couldn't be created" << std::endl;
    }
}

void AssemblyParser::removeComments(std::string line) {
    line = line.substr( 0, line.find('/'));
    // Count lines
    if (line[0] == ('(')){
        table.addValue(line, AssemblyParser::lineNumber);
        line = "";
    } else {
        AssemblyParser::lineNumber++;
    }
    // find labels
}


