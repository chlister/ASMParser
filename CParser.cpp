//
// Created by marc on 8/12/19.
//

#include <algorithm>
#include "CParser.h"

std::string CParser::parseInstruction(std::string& instr) {
    std::string bres;
    std::string destSplit = "=";
    std::string jumpSplit = ";";
    // check if jump con
    if (instr.find(jumpSplit) == std::string::npos){
        // lookup dest
        std::string sdest = instr.substr(0, instr.find(destSplit));
        sdest.erase(std::remove_if(sdest.begin(), sdest.end(), ::isspace), sdest.end());
        // lookup comp
        std::string scomp = instr.substr(instr.find(destSplit)+1);
        scomp.erase(std::remove_if(scomp.begin(), scomp.end(), ::isspace), scomp.end());
        // jump is not allowed

        // Build the binary return
        // 111 - acccccc - ddd - jjj / M=!M - 111 1110011 001 000
        bres += "111";
        // acccccc
        bres += getMapValue(scomp, 'c');
        // ddd
        bres += getMapValue(sdest, 'd');
        // jjj
        bres += "000";
//        std::cout << bres << std::endl;
    }
    else {
        //Dest is not allowed in jmp
        // lookup comp
        std::string scomp = instr.substr(0, instr.find(jumpSplit));
        scomp.erase(std::remove_if(scomp.begin(), scomp.end(), ::isspace), scomp.end());
        // add jump
        std::string sjmp = instr.substr(instr.find(jumpSplit)+1);
        sjmp.erase(std::remove_if(sjmp.begin(), sjmp.end(), ::isspace), sjmp.end());

        // Build the binary return
        // 111 - acccccc - ddd - jjj
        bres += "111";
        // acccccc
        bres += getMapValue(scomp, 'c');
        // ddd
        bres += "000";
        // jjj
        bres += getMapValue(sjmp, 'j');
//        std::cout << bres << std::endl;
    }

    return bres;
}

std::string CParser::getMapValue(std::string key, char m) {
    std::string res;
    switch(m){
        case 'd':
        {
            auto dd = dest.find(key);
            if (dd == dest.end()) {
                //handle the error
            } else {
                std::string value = dd -> second;
                res = value;
            }}
            break;
        case 'j':        {
            auto jj = jmp.find(key);
            if (jj == jmp.end()) {
                //handle the error
            } else {
                std::string value = jj -> second;
                res = value;
            }
        }
            break;
        case 'c':
        {
            auto cc = comp.find(key);
            if (cc == comp.end()) {
                //handle the error
            } else {
                std::string value = cc -> second;
                res = value;
            }}
            break;
        default:
            break;

    }
    return res;

}
