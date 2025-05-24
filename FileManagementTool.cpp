#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// File Writing operation
void WriteToFile(const string& filename) {
    ofstream outfile(filename.c_str());
    if (!outfile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    cout << "Enter the text to write to the file (Type END to finish): " << endl;
    string line;
    while (getline(cin, line)) {
        if (line == "END" || line == "end" || line == "End") {
            break;
        }
        outfile << line << endl;
    }
    outfile.close();
    cout << "Data written successfully." << endl;
}

// File Appending Operation
void AppendToFile(const string& filename) {
    ofstream outfile(filename.c_str(), ios::app);
    if (!outfile) {
        cout << "Error opening the file for appending!" << endl;
        return;
    }
    cout << "Enter text to append to the file (Type END to finish):" << endl;
    string line;
    while (getline(cin, line)) {
        if (line == "END" || line == "End" || line == "end") {
            break;
        }
        outfile << line << endl;
    }
    outfile.close();
    cout << "Data appended successfully." << endl;
}

// File Reading Operation
void ReadFromFile(const string& filename) {
    ifstream infile(filename.c_str());
    if (!infile) {
        cout << "Error opening the file for reading!" << endl;
        return;
    }
    cout << "\n--- File Content ---" << endl;
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();
    cout << "--- End of the File ---" << endl;
}

// Main Function
int main() {
    string filename = "App_data.txt";
    int choice;

    do {
        cout << "\n ---- File Management Tool ----\n";
        cout << "Choose the number according to the operations below:\n";
        cout << "1. Write to file (overwrite)\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from buffer

        switch (choice) {
            case 1:
                WriteToFile(filename);
                break;
            case 2:
                AppendToFile(filename);
                break;
            case 3:
                ReadFromFile(filename);
                break;
            case 4:
                cout << "Exiting program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
