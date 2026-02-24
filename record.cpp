#include <iostream>
#include <string>
using namespace std;

class Record {
private:
    string firstName;
    string lastName;
    string phone;

public:
    Record(string firstName, string lastName, string phone) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->phone = phone;
    }

    // getters
    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getPhone() {
        return phone;
    }

    // setters
    void setFirstName(string newFirstName) {
        this->firstName = newFirstName;
    }

    void setLastName(string newLastName) {
        this->lastName = newLastName;
    }

    void setPhone(string newPhone) {
        this->phone = newPhone;
    }

};