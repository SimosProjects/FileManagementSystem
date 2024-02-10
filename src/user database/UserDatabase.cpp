#include "UserDatabase.h"
#include <algorithm>

//Constructor definition
UserDatabase::UserDatabase() {}

//Deconstructor definition
UserDatabase::~UserDatabase() {}

//Adds a user to the database
void UserDatabase::addUser(const std::string username, const std::string password) {
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
void UserDatabase::removeUser(const std::string username) {
    //Find the user
    auto it = std::find_if(m_users.begin(), m_users.end(), [username](User& user){
        return user.username == username;
    });

    //Remove the user from the database
    if(it != m_users.end()) {
        m_users.erase(it);
    }
}