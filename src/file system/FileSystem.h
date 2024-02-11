#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "File.h"
#include <string>

class FileSystem {
public:
    //Constructor definition
    FileSystem();

    //Destructor definition
    ~FileSystem();

    //Creates a File in memory
    File createFile(const std::string& filename);
    
    //Deletes a File from memory
    void deleteFile(File& file);

    //Writes to a File into memory
    void writeFile(File& file, const std::string content);

    //Reads from a File in memory
    std::string readFile(File& file);
};

#endif