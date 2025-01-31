#include<bits/stdc++.h>
using namespace std;

class User {
public:
    string id;
    string name;

    User(string id, string name) {
        if (name.length() < 2) {
            throw invalid_argument("Name must be at least 2 characters.");
        }
        this->id = id;
        this->name = name;
    }
};

class GetSetService {
private:
    map<string, User> users;  
    string validUsername = "admin";
    string validPassword = "password";

public:
    bool authenticate(string username, string password) {
        return username == validUsername && password == validPassword;
    }

    void setUser(string id, string name, string username, string password) {
        if (!authenticate(username, password)) {
            throw invalid_argument("Authentication failed.");
        }
        try {
            // Directly creating the User object and adding it to the map
            cout << "Setting user with ID: " << id << " and Name: " << name << endl;
            users[id] = User(id, name);
            cout << "User set successfully." << endl;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    User getUserById(string id, string username, string password) {
        if (!authenticate(username, password)) {
            throw invalid_argument("Authentication failed.");
        }
        if (users.find(id) == users.end()) {
            throw invalid_argument("User not found.");
        }
        return users[id];
    }

    map<string, User> listAllUsers(string username, string password) {
        if (!authenticate(username, password)) {
            throw invalid_argument("Authentication failed.");
        }
        return users;
    }
};

int main() {
    GetSetService service;

    try {
        // Simulate setting users
        service.setUser("1", "Himanshu Gupta", "admin", "password");
        service.setUser("2", "Alen Mark", "admin", "password");

        // Get user by ID
        User user = service.getUserById("1", "admin", "password");
        cout << "User ID: " << user.id << ", Name: " << user.name << endl;

        // List all users
        auto allUsers = service.listAllUsers("admin", "password");
        for (const auto& pair : allUsers) {
            cout << "User ID: " << pair.second.id << ", Name: " << pair.second.name << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
