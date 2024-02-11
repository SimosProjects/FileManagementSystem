#include "Directory.h"
#include <algorithm>

//Constructor definition
Directory::Directory(const std::string& name) : name(name), files(), subdirectories() {}

//Deconstrutor definition
Directory::~Directory() {}

//Add a file to the files list in the directory
void Directory::addFile(const File& file) {
    files.push_back(file);
}

//Removes a file from a directory by filename
void Directory::removeFile(const std::string& fileName) {
    //Find the file
    auto it = std::find_if(files.begin(), files.end(), [fileName](File& file) {
        return file.getName() == fileName;
    });

    //Remove file from list
    if(it != files.end()) {
        files.erase(it);
    }
}

//Adds a subdirectory to the subdirectories list of the directory
void Directory::addSubdirectory(const Directory& directory) {
    subdirectories.push_back(directory);
}

//Removes a subdirectory from the directory
void Directory::removeSubdirectory(const std::string& subdirectoryName) {
    //Find subdirectory
    auto it = std::find_if(subdirectories.begin(), subdirectories.end(), [subdirectoryName](Directory& subdirectory){
        return subdirectory.getName() == subdirectoryName;
    });

    //Remove subdirectory
    if(it != subdirectories.end()) {
        subdirectories.erase(it);
    }
}

//Returns the name of a directory
std::string Directory::getName() {
    return name;
}

//Returns the files in the directory
std::vector<File> Directory::getFiles() {
    return files;
}