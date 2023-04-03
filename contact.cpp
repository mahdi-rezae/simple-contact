#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

string name, number, email;

bool validateEmail(string check_email) {
    const regex pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");

    return regex_match(check_email, pattern);
}

void addContact() {
    ofstream contact_file("contact.txt", ios_base::app);

    cout << "\nAdd your number & email as example.\nEnter a number for each name:\n\nExample: 910####### || info@example.com\n\n";

    cout << "Number:\t";
    cin >> number;
    contact_file << "Number: " << number << " | ";

    cout << "Name:\t";
    cin >> name;
    contact_file << "Name:" << name << " | ";

    cout << "Email:\t";
    cin >> email;

    if (validateEmail(email))
        contact_file << "Email:" << email << "\n";
    else
        cout << "Email not saved!\tCheck your email & TRY AGAIN!";

    cout << endl << "--------------------\n\n";
    contact_file.close();
}

void contactList() {
    string getContent;

    ifstream openFile("contact.txt");
    if (openFile.is_open()) {
        while (!openFile.eof()) {
            openFile >> getContent;
            cout << getContent << endl;
        }
    }
}

void searchContact() {
    bool found = false;

    ifstream myfile("contact.txt");
    string keyword;

    cout << "\nEnter Name to search : ";
    cin >> keyword;

    while (myfile >> number >> name >> email) {
        if (keyword == name) {
            cout << "\n\n\n\t\tCONTACT DETAILS";
            cout << "\n\nNumber : " << number;
            cout << "\nName : " << name;
            cout << "\nEmail : " << email;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nContact not found!";
    }

    cout << endl << endl;
}

int main() {
    int menu;

    cout << "\n###\t Welcome to Contact Manager \t###\n\n";
    cout << "\tMENU\n" << "--------------------\n" <<
         "[1] Add a New Contact\n" <<
         "[2] Show Contacts\n" <<
         "[3] Search in Contacts\n" <<
         "[0] Exit\n" <<
         "--------------------\n" <<
         "Enter your choice: ";
    cin >> menu;
    cout << "--------------------\n";

    switch (menu) {
        case 1:
            addContact();
            break;

        case 2:
            contactList();
            break;

        case 3:
            searchContact();
            break;

        case 0:
            break;

        default:
            cout << "Enter proper option!";

    }
} 

