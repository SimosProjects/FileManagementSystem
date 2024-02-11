#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "File.h"
#include "Directory.h"
#include <string>

class FileSystem {
public:
    //Constructor definition
    FileSystem();

    //Destructor definition
    ~FileSystem();

    //Adds a directory in the file system
    void addDirectory(const Directory& directory);

    //Creates a File
    void addFile(const File& file);
    
    //Deletes a File
    void deleteFile(File& file);

    //Writes to a File
    void writeFile(File& file, const std::string& content);

    //Reads from a File
    std::string readFile(File& file);

    //Gets the current directory
    Directory& getCurrentDirectory();

private:
    std::string systemName;
    Directory currentDirectory;
    std::vector<Directory> directories;
};

#endif