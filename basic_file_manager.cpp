#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void listFiles() {
    system("dir"); // Windows command to list files
}

void createDirectory(const string& dirName) {
    string command = "mkdir " + dirName;
    system(command.c_str());
    cout << "Directory created: " << dirName << endl;
}

void copyFile(const string& source, const string& destination) {
    ifstream src(source.c_str(), ios::binary);
    ofstream dst(destination.c_str(), ios::binary);
    dst << src.rdbuf();
    cout << "File copied from " << source << " to " << destination << endl;
}

void moveFile(const string& source, const string& destination) {
    string command = "move " + source + " " + destination;
    system(command.c_str());
    cout << "File moved from " << source << " to " << destination << endl;
}

int main() {
    string command;

    while (true) {
        cout << "Commands: list, create, copy, move, exit" << endl;
        cout << "Enter command: ";
        getline(cin, command);

        if (command == "list") {
            listFiles();
        } else if (command == "create") {
            string dirName;
            cout << "Enter directory name: ";
            getline(cin, dirName);
            createDirectory(dirName);
        } else if (command == "copy") {
            string source, destination;
            cout << "Enter source file path: ";
            getline(cin, source);
            cout << "Enter destination file path: ";
            getline(cin, destination);
            copyFile(source, destination);
        } else if (command == "move") {
            string source, destination;
            cout << "Enter source file path: ";
            getline(cin, source);
            cout << "Enter destination file path: ";
            getline(cin, destination);
            moveFile(source, destination);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command." << endl;
        }
    }
    return 0;
}
