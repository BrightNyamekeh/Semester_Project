#include <iostream>
#include <fstream>
#include <string>
//UEB3209222
using namespace std;

struct User {
    string username;
    string password;
};

void registerUser() {
    User user;
    cout << "Enter a username: ";
    cin >> user.username;
    cout << "Enter a password: ";
    cin >> user.password;

    ofstream file("database.txt", ios::app);
    file << user.username << " " << user.password << endl;
    file.close();

    cout << "Registration successful!" << endl;
}

bool loginUser() {
    User user;
    cout << "Enter your username: ";
    cin >> user.username;
    cout << "Enter your password: ";
    cin >> user.password;

    ifstream file("database.txt");
    string username, password;
    while (file >> username >> password) {
        if (username == user.username && password == user.password) {
            file.close();
            return true;
        }
    }
    file.close();

    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        if (loginUser()) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
