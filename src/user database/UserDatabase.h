#ifndef USER_DATABASE_H
#define USER_DATABASE_H

#include <string>
#include <vector>

class UserDatabase {
public:
    //Constructor
    UserDatabase();

    //Deconstructor
    ~UserDatabase();

    //Adds a user and password to the database
    void addUser(const std::string username, const std::string password);

    //Removes a user from the database
    void removeUser(const std::string username);

private:
    //Defines a struct to store User info
    struct User {
        std::string username;
        std::string password;
    };

    std::vector<User> m_users;//member list of users
};

#endif