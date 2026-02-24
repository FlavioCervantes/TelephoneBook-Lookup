// Telephone Book Lookup Application
// Created by Code Busters || 2026

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

const std::string DATA_FILE = "contacts.dat";

// Load contacts from file into map
void loadContacts(std::map<std::string, std::string>& contacts) {
    std::ifstream file(DATA_FILE);
    if (!file.is_open()) return;

    std::string name, phone;
    while (std::getline(file, name) && std::getline(file, phone)) {
        contacts[name] = phone;
    }
    file.close();
}

// Save all contacts from map to file
void saveContacts(const std::map<std::string, std::string>& contacts) {
    std::ofstream file(DATA_FILE);
    if (!file.is_open()) {
        std::cerr << "Error: Could not save contacts to file.\n";
        return;
    }
    for (const auto& entry : contacts) {
        file << entry.first << "\n" << entry.second << "\n";
    }
    file.close();
}

// Convert string to lowercase for case-insensitive search
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Add a new contact
void addContact(std::map<std::string, std::string>& contacts) {
    std::string name, phone;
    std::cout << "Enter contact name: ";
    std::getline(std::cin, name);
    if (name.empty()) {
        std::cout << "Name cannot be empty.\n";
        return;
    }
    if (contacts.count(name)) {
        std::cout << "Contact '" << name << "' already exists. Use update to change it.\n";
        return;
    }
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone);
    if (phone.empty()) {
        std::cout << "Phone number cannot be empty.\n";
        return;
    }
    contacts[name] = phone;
    saveContacts(contacts);
    std::cout << "Contact added successfully.\n";
}

// Lookup a contact by name (case-insensitive partial match)
void lookupContact(const std::map<std::string, std::string>& contacts) {
    std::string query;
    std::cout << "Enter name to search: ";
    std::getline(std::cin, query);
    if (query.empty()) {
        std::cout << "Search query cannot be empty.\n";
        return;
    }

    std::string queryLower = toLower(query);
    bool found = false;
    std::cout << "\n--- Search Results ---\n";
    for (const auto& entry : contacts) {
        if (toLower(entry.first).find(queryLower) != std::string::npos) {
            std::cout << "Name:  " << entry.first << "\n"
                      << "Phone: " << entry.second << "\n"
                      << "----------------------\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No contacts found matching '" << query << "'.\n";
    }
}

// Display all contacts
void displayAll(const std::map<std::string, std::string>& contacts) {
    if (contacts.empty()) {
        std::cout << "The telephone book is empty.\n";
        return;
    }
    std::cout << "\n--- All Contacts (" << contacts.size() << ") ---\n";
    for (const auto& entry : contacts) {
        std::cout << "Name:  " << entry.first << "\n"
                  << "Phone: " << entry.second << "\n"
                  << "----------------------\n";
    }
}

// Update an existing contact's phone number
void updateContact(std::map<std::string, std::string>& contacts) {
    std::string name, phone;
    std::cout << "Enter contact name to update: ";
    std::getline(std::cin, name);
    auto it = contacts.find(name);
    if (it == contacts.end()) {
        std::cout << "Contact '" << name << "' not found.\n";
        return;
    }
    std::cout << "Current phone: " << it->second << "\n";
    std::cout << "Enter new phone number: ";
    std::getline(std::cin, phone);
    if (phone.empty()) {
        std::cout << "Phone number cannot be empty.\n";
        return;
    }
    it->second = phone;
    saveContacts(contacts);
    std::cout << "Contact updated successfully.\n";
}

// Delete a contact
void deleteContact(std::map<std::string, std::string>& contacts) {
    std::string name;
    std::cout << "Enter contact name to delete: ";
    std::getline(std::cin, name);
    auto it = contacts.find(name);
    if (it == contacts.end()) {
        std::cout << "Contact '" << name << "' not found.\n";
        return;
    }
    contacts.erase(it);
    saveContacts(contacts);
    std::cout << "Contact deleted successfully.\n";
}

// Print the menu
void printMenu() {
    std::cout << "\n============================\n";
    std::cout << "   Telephone Book Lookup\n";
    std::cout << "   Code Busters || 2026\n";
    std::cout << "============================\n";
    std::cout << "1. Add contact\n";
    std::cout << "2. Lookup contact\n";
    std::cout << "3. Display all contacts\n";
    std::cout << "4. Update contact\n";
    std::cout << "5. Delete contact\n";
    std::cout << "6. Exit\n";
    std::cout << "============================\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::map<std::string, std::string> contacts;
    loadContacts(contacts);

    int choice;
    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: addContact(contacts);    break;
            case 2: lookupContact(contacts); break;
            case 3: displayAll(contacts);    break;
            case 4: updateContact(contacts); break;
            case 5: deleteContact(contacts); break;
            case 6:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid option. Please choose 1-6.\n";
        }
    }
}
