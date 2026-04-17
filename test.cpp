#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool userExists(const string& username) {
    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    if (username.empty()) {
        cout << "Username cannot be empty!\n";
        return;
    }

    if (userExists(username)) {
        cout << "Username already exists! Try another.\n";
        return;
    }

    cout << "Enter Password (min 6 characters): ";
    cin >> password;

    if (password.length() < 6) {
        cout << "Password too short!\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;

    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password;
    string u, p;
    bool found = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Login Successful!\n";
    else
        cout << "Invalid Username or Password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n====== LOGIN SYSTEM ======\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
