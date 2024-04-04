#include "FileProcessor.h"

FileProcessor::FileProcessor(string nameOfFile){
    outFP.open(nameOfFile);
}

FileProcessor::~FileProcessor(){
    outFP.close();
}


void FileProcessor::write(string input){
    if (!outFP.is_open()) {
      std::cout << "Could not open file " << endl;
    }
     outFP << input;
}

void FileProcessor::writeLine(string input){
    if (!outFP.is_open()) {
      std::cout << "Could not open file " << endl;
    }
     outFP << input << std::endl;
}

void FileProcessor::enter(){
    if (!outFP.is_open()) {
      std::cout << "Could not open file " << endl;
    }
     outFP << std::endl;
}