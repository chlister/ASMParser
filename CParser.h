//
// Created by marc on 8/12/19.
//

#ifndef UNTITLED_CPARSER_H
#define UNTITLED_CPARSER_H

#include <iostream>
#include <map>

class CParser {
public:
    std::string parseInstruction(const std::string);
private:
    std::string getMapValue(std::string, char);
     std::map <std::string, std::string> dest  = {
            {"null", "000"},
            {"", "000"},
            {"M", "001"},
            {"D", "010"},
            {"A", "100"},
            {"MD", "011"},
            {"AM", "101"},
            {"AD", "110"},
            {"AMD", "111"}
    };
     std::map <std::string, std::string> comp= {
            {"0", "0101010"},
            {"1", "0111111"},
            {"-1", "0111010"},
            {"D", "0001100"},
            {"A", "0110000"},
            {"M", "1110000"},
            {"!D", "0001101"},
            {"!A", "0110011"},
            {"!M", "1110011"},
            {"-D", "0001111"},
            {"-A", "0110011"},
            {"-M", "1110011"},
            {"D+1", "0011111"},
            {"A+1", "0110111"},
            {"M+1", "1110111"},
            {"D-1", "0001110"},
            {"A-1", "0110010"},
            {"M-1", "1110010"},
            {"D+A", "0000010"},
            {"D+M", "1000010"},
            {"D-A", "0010011"},
            {"D-M", "1010011"},
            {"A-D", "0000111"},
            {"M-D", "1000111"},
            {"D&A", "0000000"},
            {"D&M", "1000000"},
            {"D|A", "0010101"},
            {"D|M", "1010101"}
    };
     std::map <std::string, std::string> jmp= {
            {"null", "000"},
            {"", "000"},
            {"JGT", "001"},
            {"JEQ", "010"},
            {"JGE", "011"},
            {"JLT", "100"},
            {"JNE", "101"},
            {"JLE", "110"},
            {"JMP", "111"}
    };
};


#endif //UNTITLED_CPARSER_H
