//
// Created by marc on 8/12/19.
//

#include "SymbolTable.h"

int SymbolTable::findSymbol(std::string key) {
    int res = -1;
    auto dd = symbolTable.find(key);
    if (dd == symbolTable.end()) {
        //handle the error
    } else {
        int value = dd -> second;
        res = value;
    }
    return res;
}

void SymbolTable::addValue(std::string key, int value) {
    symbolTable.insert(std::pair<std::string, int>(key, value));
}
