#include<bits/stdc++.h>
using namespace std;

class User {
public:
    std::string id;
    std::string name;
    long long signupTime;

    User(const std::string& id, const std::string& name, long long signupTime)
        : id(id), name(name), signupTime(signupTime) {
        if (name.length() < 2) {
            throw std::invalid_argument("Name must be at least 2 characters.");
        }
        if (signupTime < 31536000000LL) {  // Minimum time: year 1850 in milliseconds
            throw std::invalid_argument("Signup time is too early.");
        }
    }
};

class GetSetService {
private:
    std::unordered_map<std::string, User> users;
    std::string validUsername = "admin";
    std::string validPassword = "password";

public:
    bool authenticate(const std::string& username, const std::string& password) {
        return username == validUsername && password == validPassword;
    }

    void setUser(const std::string& id, const std::string& name, long long signupTime, const std::string& username, const std::string& password) {
        if (!authenticate(username, password)) {
            throw std::invalid_argument("Authentication failed.");
        }
        users[id] = User(id, name, signupTime);
    }

    User getUserById(const std::string& id, const std::string& username, const std::string& password) {
        if (!authenticate(username, password)) {
            throw std::invalid_argument("Authentication failed.");
        }
        if (users.find(id) == users.end()) {
            throw std::invalid_argument("User not found.");
        }
        return users[id];
    }

    std::unordered_map<std::string, User> listAllUsers(const std::string& username, const std::string& password) {
        if (!authenticate(username, password)) {
            throw std::invalid_argument("Authentication failed.");
        }
        return users;
    }
};
