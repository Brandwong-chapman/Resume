#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
using namespace std;

class FileProcessor{
    public:
        FileProcessor(string nameOfFile);
        ~FileProcessor();
        void write(string input);
        void writeLine(string input);
        void enter();
    private:
        ofstream outFP;
};

#endif