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

    //Gets the files within the directory
    std::vector<File> getFiles();

private:
    std::string name;//variable for directory name
    std::vector<File> files;//list of files in the directory
    std::vector<Directory> subdirectories;//list of subdirectories in the directory
};

#endif