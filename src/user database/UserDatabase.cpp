#include "UserDatabase.h"
#include <algorithm>

//Constructor definition
UserDatabase::UserDatabase() {}

//Deconstructor definition
UserDatabase::~UserDatabase() {}

//Adds a user to the database
void UserDatabase::addUser(const std::string& username, const std::string& password) {
    //Check if user already exits
    auto it = std::find_if(m_users.begin(), m_users.end(), [username](User& user){
        return user.username == username;
    });

    //Add new user to the database
    if(it != m_users.end()) {
        m_users.push_back(UserDatabase::User{username, password});
    }
}

//Removes a user from the database
void UserDatabase::removeUser(const std::string& username) {
    //Find the user
    auto it = std::find_if(m_users.begin(), m_users.end(), [username](User& user){
        return user.username == username;
    });

    //Remove the user from the database
    if(it != m_users.end()) {
        m_users.erase(it);
    }
}

//Checks if a user exists in the user database
bool UserDatabase::userExists(const std::string& username) {
    auto it = std::find_if(m_users.begin(), m_users.end(), [username](User& user){
        return user.username == username;
    });

    //checks if user is in list of users in database
    if(it != m_users.end()) {
        return true;
    }
    return false;
}

//Authenticates user on login
bool UserDatabase::authenticateUser(const std::string& username, const std::string& password) {
    //find user in database
    for(const auto& user : m_users) {
        if(user.username == username) {
            //check if passords match and return
            return user.password == password;
        }
    }
    return false;
}