#include "File.h"

//Constructor definition
File::File(const std::string& name) {
    name = name;
    content = "";
}

//Returns the file contents
std::string File::read() {
    return content;
}

//Writes the file contents
void File::write(const std::string& str) {
    content = str;
}

//Returns the size of the file contents
int File::getSize() {
    return content.size();
}

//Returns the file name
std::string File::getName() {
    return name;
}