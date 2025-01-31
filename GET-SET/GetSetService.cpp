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