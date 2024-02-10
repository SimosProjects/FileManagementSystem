#ifndef FILE_H
#define FILE_H

#include <string>

class File {
public:
    //Constructor
    File(const std::string& name);

    //File operation methods
    std::string read();
    void write(const std::string& str);
    std::string getName();
    int getSize();

private:
    std::string m_name; //member variable to store the filename
    std::string m_content;//member variable to store the file contents
    int m_size; //member variable to store the file size
};

#endif