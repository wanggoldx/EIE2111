# Address Book Application

A C++ console application for managing contact information, including name, email, and telephone number.

## Project Overview

This is an interactive address book program that allows users to:
- **Initialize** the address book with sample contacts
- **Create** new person contact information with input validation
- **Lookup** person contact information by name, email, or telephone number
- **Display** all saved contacts

## Project Structure

```
EIE2111 Assignment/
├── Record/                      # Library project
│   └── Record/
│       ├── Record.h            # Record class declaration
│       ├── Record.cpp         # Record class implementation
│       └── Record.vcxproj     # Visual Studio project file
├── AddressBook/               # Main application project
│   └── AddressBook/
│       ├── AddressBook.cpp     # Main program entry point
│       ├── Record.h          # Copied from Record project (for linking)
│       └── AddressBook.vcxproj
└── AddressBook.sln           # Visual Studio solution
```

## Requirements

- **Microsoft Visual Studio 2019** or later with C++ development tools
- **Windows 10** or later

## Setup & Installation

1. Open the solution file `AddressBook.sln` in Visual Studio
2. The solution contains two projects:
   - `Record` (library)
   - `AddressBook` (main application)
3. Build the solution:
   - Right-click on the solution in Solution Explorer → **Build Solution**
   - Or press `Ctrl+Shift+B`

## Running the Application

1. Press `F5` in Visual Studio to run in Debug mode
   - Or locate the compiled executable at:
     ```
     AddressBook\AddressBook\x64\Debug\AddressBook.exe
     ```

## Menu Options

### Main Menu
1. **Initialize the address book** - Loads 4 sample contacts
2. **Create person contact information** - Add new contacts (max 10 at a time)
3. **Lookup person contact information** - Search by name/email/phone
4. **Lookup all person contact information** - Display all contacts
5. **Quit** - Exit the program

### Search Sub-Menu (Option 3)
- **a.** Search by name
- **b.** Search by email address
- **c.** Search by telephone number
- **d.** Return to main menu

## Input Validation

The program validates all user input:
- **Name**: Must contain only alphabetic characters and spaces
- **Email**: Must contain exactly one `@` symbol (not at start or end)
- **Telephone**: Must be an 8-digit number (10,000,000 to 99,999,999)

## Notes

- Maximum capacity: 100 contacts
- Data is stored in memory only (not persisted to file)
- The Record library must be built before the AddressBook application