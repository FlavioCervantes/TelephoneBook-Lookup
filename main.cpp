/*
 * INSTRUCTION:
 *     This is a C++ starting code for Homework Group1.
 *     When you finish the development, download this file and submit to Canvas
 *     according to the submission instructions.
 *
 *     Please DO NOT change the name of the main procecure "main()"
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: Telepone Book Look-up
 * Abstract: This program comes with an arbitrary list of people and their phone numbers. Users can perform a look-up by first name, last name, or phone number.
 * Names: Monica Um, Flavio Cervantes, Raquel Zuelke
 * Date: 02/13/2026
 * Flavio's Github Repo: https://github.com/FlavioCervantes/TelephoneBookLookup
 * Video Demo: https://www.youtube.com/watch?v=IUC6MidNojw
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Record {
private:
    string firstName;
    string lastName;
    string phone;

public:
    Record(string first, string second, string ph) {
        firstName = first;
        lastName = second;
        phone = ph;
    }

    string getFirstName() { 
        return firstName; 
    }
    string getLastName(){ 
        return lastName; 
    }
    string getPhone(){ 
        return phone;
    }

    // Setters
    void setFirstName(string name){ 
        firstName = name; 
    }
    void setLastName(string name) { 
        lastName = name; 
    }
    void setPhone(string ph){ 
        phone = ph; 
    }
};

// call functions prior to there are no issues later
void driver(vector<Record>& x);
void sortByFirstName(vector<Record>& x);
void sortByLastName(vector<Record>& x);
void sortByPhone(vector<Record>& x);
int searchFirstName(vector<Record>& x, string name);
int searchLastName(vector<Record>& x, string name);
int searchByPhone(vector<Record>& x, string phone);
void printRecord(vector<Record>& x, int index);
void printSortedList(vector<Record>& x);

int main() {
    vector<Record> phonebook;

    // to read in data
    ifstream file("input.txt"); 

    if (!file.is_open()) {
        cout << "Error: Could not open input.txt" << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) {     
        // skip any blank lines  
        if (line.empty()) continue;       

        // Split the line by whitespace
        istringstream iss(line);
        string first;
        string last;
        string phone;
        iss >> first >> last >> phone;

        // Create record and add to the vector
        phonebook.push_back(Record(first, last, phone));
    }

    file.close();

    driver(phonebook);

    return 0;
}

// print record based on search, or inform user the search came up empty
void printRecord(vector<Record>& x, int index) {
    if (index == -1) {
        cout << "Record not found." << endl;
    } 
    else {
        cout << "Record found:" << endl;
        cout << "  First Name : " << x[index].getFirstName()  << endl;
        cout << "  Last Name  : " << x[index].getLastName() << endl;
        cout << "  Phone      : " << x[index].getPhone()      << endl;
    }
}

// responsible for giving search options to user
void driver(vector<Record>& x) {
    cout << endl;
    cout << "To Search by FIRST NAME enter 1" << endl;
    cout << "To search by LAST NAME  enter 2" << endl;
    cout << "To search by PHONE      enter 3" << endl;

    int selection;
    cin >> selection;

    // since binary search requires sorting, the option the user selects dictates which info will be sorted
    if (selection == 1) {
        sortByFirstName(x);
        cout << "Enter FIRST NAME: " << endl;
        string name;
        cin >> name;
        cout << endl;
        int val = searchFirstName(x, name);
        printRecord(x, val);
        
        cout << endl;
    } 
    else if (selection == 2) {
        sortByLastName(x);
        cout << "Enter LAST NAME: " << endl;
        string name;
        cin >> name;
        cout << endl;
        int val = searchLastName(x, name);
        printRecord(x, val);

        cout << endl;
    } 
    else if (selection == 3) {
        sortByPhone(x);
        cout << "Enter PHONE in format: XXX-XXX-XXXX " << endl;
        string phone;
        cin >> phone;
        cout << endl;
        int val = searchByPhone(x, phone);
        printRecord(x, val);

        cout << endl;
    }
}

// first names sorting
void sortByFirstName(vector<Record>& x) {
    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = i + 1; j < (int)x.size(); j++) {

            if (x[i].getFirstName() > x[j].getFirstName()) {

                // save values at this position
                string tempFirstName  = x[i].getFirstName();
                string tempLastName = x[i].getLastName();
                string tempPhone      = x[i].getPhone();

                // copy position j into position i
                x[i].setFirstName(x[j].getFirstName());
                x[i].setLastName(x[j].getLastName());
                x[i].setPhone(x[j].getPhone());

                // copy saved values into position j
                x[j].setFirstName(tempFirstName);
                x[j].setLastName(tempLastName);
                x[j].setPhone(tempPhone);
            }
        }
    }
}

// sort by last name
void sortByLastName(vector<Record>& x) {
    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = i + 1; j < (int)x.size(); j++) {

            if (x[i].getLastName() > x[j].getLastName()) {

                string tempFirstName  = x[i].getFirstName();
                string tempLastName = x[i].getLastName();
                string tempPhone      = x[i].getPhone();

                x[i].setFirstName(x[j].getFirstName());
                x[i].setLastName(x[j].getLastName());
                x[i].setPhone(x[j].getPhone());

                x[j].setFirstName(tempFirstName);
                x[j].setLastName(tempLastName);
                x[j].setPhone(tempPhone);
            }
        }
    }
}

// sort by phone number
void sortByPhone(vector<Record>& x) {
    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = i + 1; j < (int)x.size(); j++) {

            if (x[i].getPhone() > x[j].getPhone()) {

                string tempFirstName  = x[i].getFirstName();
                string tempLastName = x[i].getLastName();
                string tempPhone      = x[i].getPhone();

                x[i].setFirstName(x[j].getFirstName());
                x[i].setLastName(x[j].getLastName());
                x[i].setPhone(x[j].getPhone());

                x[j].setFirstName(tempFirstName);
                x[j].setLastName(tempLastName);
                x[j].setPhone(tempPhone);
            }
        }
    }
}

// this function is to handle case sensitivity
int compareCase(string a, string b) {
    // convers to lowercase to compare
    for (int i  = 0; i < (int)a.length(); i++) {
        a[i] = tolower(a[i]);
    }

    for (int i = 0; i < (int)b.length(); i++) {
        b[i] = tolower(b[i]);
    }

    if (a == b) {
        return 0;
    }
    if (a < b) {
        return -1;
    }

    return 1;
}

// binary search utilized for first name searching
int searchFirstName(vector<Record>& x, string name) {
    int low  = 0;
    int high = (int)x.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // to help eliminate case sensitivity
        int ignoreCase = compareCase(x[mid].getFirstName(), name);

        if (ignoreCase == 0) {
            return mid;
        }
        else if (ignoreCase < 0) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }
    // person not found
    return -1; 
}

// binary search for lsat name
int searchLastName(vector<Record>& x, string name) {
    int low  = 0;
    int high = (int)x.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // to help eliminate case sensitivity
        int ignoreCase = compareCase(x[mid].getLastName(), name);

        if (ignoreCase == 0) {
            return mid;
        }
        else if (ignoreCase < 0) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }
    return -1;
}

// binary search by phone number
int searchByPhone(vector<Record>& x, string phone) {
    int low  = 0;
    int high = (int)x.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (x[mid].getPhone() == phone) {
            return mid;
        } else if (x[mid].getPhone() < phone) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// prints the sorted list
void printSortedList(vector<Record>& x) {
    for (int i = 0; i < (int)x.size(); i++) {
        cout << x[i].getFirstName() << ", ";
        cout << x[i].getLastName() << ", ";
        cout << x[i].getPhone() << ", Location: " << i << endl;
    }
}