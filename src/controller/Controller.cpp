#include "Controller.h"

//Constructor
Controller::Controller() {};

//Deconstructor
Controller::~Controller() {};

//Login to file management system
void Controller::login(const std::string& username, const std::string& password) {
    //check if user is logged in already
    if(!loggedInUser.empty()) {
        //check if username exists in the user database
        if(!userDatabase.userExists(username)) {
            //authenticate user
            if(userDatabase.authenticateUser(username, password)) {
                loggedInUser = username;
                isLoggedIn = true;
            }
        }
    }
}

//Logout of file management system
void Controller::logout() {
    if(!isLoggedIn) {
        loggedInUser.erase();
        isLoggedIn = false;
    }
}

//Creates a directory and adds the directory to the file system
void Controller::createDirectory(const std::string& directoryName) {
    Directory newDirectory(directoryName);
    fileSytem.addDirectory(newDirectory);
}

//Removes a directory
void Controller::removeDirectory(const std::string& directoryName) {
    
}

//Creates a file
void Controller::createFile(const std::string& filename) {
    //create a new file
    File newFile(filename);

    //add new file to the file system
    fileSytem.getCurrentDirectory().addFile(newFile);
}