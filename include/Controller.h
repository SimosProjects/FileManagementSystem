#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "FileSystem.h"
#include "UserDatabase.h"
#include <string>

class Controller {
public:
    //Constructor definition
    Controller();

    //Deconstructor definition
    ~Controller();

    //User database methods
    void login(const std::string& username, const std::string& password);
    void logout();

    //Directory methods
    void createDirectory(const std::string& directoryName);
    void removeDirectory(const std::string& directoryName);

    //File methods
    void viewFiles();
    void createFile(const std::string& filename);
    void deleteFile(const std::string& filename);
    void readFile(const std::string& filename);
    void writeFile(const std::string& filename, const std::string& content);

private:
    FileSystem fileSytem;
    UserDatabase userDatabase;
    std::string loggedInUser;
    static bool isLoggedIn;
};

#endif