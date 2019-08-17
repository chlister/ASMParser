#include <iostream>
#include "header/ArrayUtility.h"
# include "AssemblyParser.h"

int FileExists( char *filename);
int makeFile ();

using namespace std;

int main()
{
    string workDir = "/home/marc/Documents/School/nand2tetris/nand2tetris/projects/06/";
    string foldername = "add/";
    string assName = "Add.asm";

    // Make console input
    cout << "The current work directory is: " << workDir << endl;
    cout << "Type a valid folder: " << ends;
    getline(cin, foldername);
    cout << "Type a valid asm file to convert: ";
    getline(cin, assName);
    workDir += foldername + "/";
    string fname = workDir +  assName + ".asm";
    cout << "Converting file: " << endl;
    cout << fname << endl;

    AssemblyParser parser(assName, workDir);

//    std::ifstream file;
//    std::ifstream* fileptr = &file;
//    fileptr->open("~/Documents/School/nand2tetris softwaresuite-20190805/nand2tetris/projects/06/add/Add.asm");
    // open this:

//    if (FileExists(fname) == 0) {
//        std::cout << "could not open file" << std::endl;
//    } else {
//        std::cout << "File exists, and can be opened" << std::endl;
//
//    }
    parser.convertFile(fname);
    return 0;
}

int makeFile () {
    std::ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    else std::cout << "Unable to open file";
    return 0;
}

int FileExists( char *filename)
{
    std::ifstream inFile (filename);
    if (inFile.fail())
        return 0;
    else
        return 1;
//    std::cout << "Function fileexists encounted a line of code that should ";
//    std::cout << "have been impossible to reach.\n \n";
}
