#include "FileSystem.h"
#include <fstream>
#include <iostream>

//Constructor
FileSystem::FileSystem() : currentDirectory(systemName), directories() {
    std::cout << "What would you like to name your system? ";
    std::cin >> systemName;
};

//Deconstructor
FileSystem::~FileSystem() {};

//Adds a directory to the file system
void FileSystem::addDirectory(const Directory& directory) {
    directories.push_back(directory);
    currentDirectory = directory;
}

//Creates a File
void FileSystem::addFile(const File& file) {
    //add the file to the current directory
    currentDirectory.addFile(file);
}
    
//Deletes a File
void FileSystem::deleteFile(File& file) {
    std::remove(file.getName().c_str());
}

//Writes to a File
void FileSystem::writeFile(File& file, const std::string& content) {
    for(auto& directory : directories) {
        //get all the files in the directory
        auto files = directory.getFiles();
        //find the file
        auto it = std::find(files.begin(), files.end(), file);
        if(it != files.end()) {
            //write the content to the file
            it->write(content);
            return;
        }
    }
}

//Reads from a File
std::string FileSystem::readFile(File& file) {
    for(auto& directory : directories) {
        //get all the files in the directory
        auto files = directory.getFiles();
        //find the file
        auto it = std::find(files.begin(), files.end(), file);
        if(it != files.end()) {
            //write the content to the file
            it->read();
            return;
        }
    }
}

//Returns the current directory
Directory& FileSystem::getCurrentDirectory() {
    return currentDirectory;
}