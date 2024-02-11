#ifndef FILE_H
#define FILE_H

#include <string>

class File {
public:
    //Constructor
    File(const std::string& name);

    //Read a file
    std::string read();

    //Write to a file
    void write(const std::string& str);

    //Gets the name of a file
    std::string getName();

    //Gets the size of the data in a file
    int getSize();

private:
    std::string name; //variable to store the filename
    std::string content;//variable to store the file contents
    int size; //variable to store the file size
};

#endif