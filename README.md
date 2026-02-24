# TelephoneBook-Lookup

A command-line Telephone Book lookup application written in C++.  
**Created by Code Busters || 2026**

## Features

- **Add** a new contact (name + phone number)
- **Lookup** contacts by name (case-insensitive partial match)
- **Display** all contacts in alphabetical order
- **Update** an existing contact's phone number
- **Delete** a contact
- **Persistent storage** – contacts are saved to `contacts.dat` and reloaded on next run

## Build

Requires a C++17-compatible compiler (e.g. `g++`).

```bash
g++ -std=c++17 -Wall -Wextra -o TelephoneBook TelephoneBook.cpp
```

## Run

```bash
./TelephoneBook
```

## Usage

After launching, choose from the interactive menu:

```
============================
   Telephone Book Lookup
   Code Busters || 2026
============================
1. Add contact
2. Lookup contact
3. Display all contacts
4. Update contact
5. Delete contact
6. Exit
============================
```