//
// Created by marc on 8/12/19.
//

#include "AParser.h"

std::string AParser::numToBinary(int x){
    // convert number to binary
    std::string res;
    int a[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i, j;
    for (i=0; x > 0; i++){
        a[i]=x%2;
        x=x/2;
    }
    for (j=(sizeof(a)/sizeof(a[0]))-1; j >= 0 ; j--){
        res += std::to_string(a[j]);
    }
    //std::cout << "res: " << res << std::endl; // Test result
    return res;
}
