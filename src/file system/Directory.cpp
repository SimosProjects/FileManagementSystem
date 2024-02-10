#include "Directory.h"
#include <algorithm>

//Constructor definition
Directory::Directory(const std::string& name) : m_name(name), m_files(), m_subdirectories() {}

//Deconstrutor definition
Directory::~Directory() {}

//Add a file to the files list in the directory
void Directory::addFile(const File& file) {
    m_files.push_back(file);
}

//Removes a file from a directory by filename
void Directory::removeFile(const std::string& fileName) {
    //Find the file
    auto it = std::find_if(m_files.begin(), m_files.end(), [fileName](File& file) {
        return file.getName() == fileName;
    });

    //Remove file from list
    if(it != m_files.end()) {
        m_files.erase(it);
    }
}

//Adds a subdirectory to the subdirectories list of the directory
void Directory::addSubdirectory(const Directory& directory) {
    m_subdirectories.push_back(directory);
}

//Removes a subdirectory from the directory
void Directory::removeSubdirectory(const std::string& subdirectoryName) {
    //Find subdirectory
    auto it = std::find_if(m_subdirectories.begin(), m_subdirectories.end(), [subdirectoryName](Directory& subdirectory){
        return subdirectory.getName() == subdirectoryName;
    });

    //Remove subdirectory
    if(it != m_subdirectories.end()) {
        m_subdirectories.erase(it);
    }
}

//Returns the name of a directory
std::string Directory::getName() {
    return m_name;
}