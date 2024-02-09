#include "File.h"

//Constructor definition
File::File(const std::string& name) {
    m_name = name;
    m_content = "";
}

//Returns the file contents
std::string File::read() {
    return m_content;
}

//Writes the file contents
void File::write(const std::string& str) {
    m_content = str;
}

//Returns the size of the file contents
int File::getSize() {
    return m_content.size();
}