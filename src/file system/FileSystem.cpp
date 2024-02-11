#include "FileSystem.h"
#include <fstream>
#include <iostream>

//Constructor
FileSystem::FileSystem() {};

//Deconstructor
FileSystem::~FileSystem() {};

//Creates a File
File FileSystem::createFile(const std::string& filename) {
    //create a file object with given filename
    File newFile(filename);

    //create a new file with the given filename
    std::ofstream outputFile(filename);

    //close the file stream
    outputFile.close();

    return newFile;
}
    
//Deletes a File
void FileSystem::deleteFile(File& file) {
    std::remove(file.getName().c_str());
}

//Writes to a File
void FileSystem::writeFile(File& file, const std::string content) {
    //opens the file for writing
    std::ofstream outputFile(file.getName());

    //write to the file
    outputFile << content;

    //close file
    outputFile.close();
}

//Reads from a File
std::string FileSystem::readFile(File& file) {
    //opens the file to read
    std::ifstream inputFile(file.getName());

    //read the contents of the file by using an input iterator to interate over the input stream
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    //close the file
    inputFile.close();

    return content;
}