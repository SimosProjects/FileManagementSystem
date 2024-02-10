#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include "File.h"

class Directory {
public:
    //Constructor
    Directory(const std::string& name);

    //Deconstructor
    ~Directory();

    //Add a file to directory
    void addFile(const File& file);

    //Remove a file from directory
    void removeFile(const std::string& fileName);

    //Add a subdirectory to directory
    void addSubdirectory(const Directory& directory);

    //Remove a subdirectory from directory
    void removeSubdirectory(const std::string& subdirectoryName);

    //Gets the name of a directory
    std::string getName();

private:
    std::string m_name;//member variable for directory name
    std::vector<File> m_files;//member list of files in the directory
    std::vector<Directory> m_subdirectories;//member list of subdirectories in the directory
};

#endif