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
    std::string m_name; //member variable to store the filename
    std::string m_content;//member variable to store the file contents
    int m_size; //member variable to store the file size
};

#endif