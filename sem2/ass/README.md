# Address Book 2 (EIE2111 Assignment 2)

A Windows desktop application for managing address book records with contact information including name, email, and telephone number.

## Project Overview

This application provides a graphical user interface (GUI) for creating, searching, viewing, and deleting address book records. It consists of two main components:

1. **C++ DLL (Addressbk2dll)**: A native Windows DLL that handles low-level file operations with binary storage
2. **C# Windows Forms Application (Addressbk2 graphical)**: The GUI frontend that users interact with

The application stores records in a binary file (`addressbk2.dat`) using a linked list data structure in the C++ layer, while the C# GUI provides a user-friendly interface for all operations.

## Features

- **Initialize**: Initialize the address book with 4 default sample records
- **Create New Record**: Add new contact records (name, email, telephone number)
- **Search**: Search for records by name, email, or telephone number
- **Delete**: Remove existing records
- **View**: Browse through all records with navigation buttons

## Data Structure

Each record contains:
- Name (string, max 99 characters)
- Email (string, max 99 characters)
- Telephone Number (integer)
- Next pointer (for linked list implementation)

## Prerequisites

- **Operating System**: Windows
- **Development Environment**: Visual Studio 2019 or later
- **.NET Framework**: .NET Framework 4.7.2 or higher

## Setup Instructions

### 1. Build the C++ DLL

1. Open `completed ass2\Addressbk2dll\Addressbk2dll.sln` in Visual Studio
2. Build the solution in Release or Debug configuration (x64 or x86)
3. The DLL will be generated at: `Addressbk2dll\Debug\Addressbk2dll.dll`

### 2. Copy the DLL

Copy `Addressbk2dll.dll` to the `Addressbk2 graphical\bin\Debug\` folder where the C# application expects it.

### 3. Open the C# Project

Open `completed ass2\Addressbk2 graphical\Addressbk2 graphical.sln` in Visual Studio.

### 4. Build and Run

1. Build the solution in Visual Studio
2. Press F5 or click Run to launch the application

## How to Use

### Main Menu

The application presents a main menu with 6 options:

| Option | Description |
|--------|-------------|
| Initialize | Initialize address book with 4 sample records |
| Create | Add new record(s) |
| Search | Search for existing records |
| Delete | Remove a record |
| View | Browse through all records |
| Exit | Close the application |

### Creating Records

1. Select "Create" from the main menu
2. Enter the number of records to create (1-10)
3. Fill in the information for each record:
   - **Name**: Letters and spaces only
   - **Email**: Must contain "@" (not as first or last character)
   - **Telephone**: Exactly 8 digits
4. Click "Next" to proceed to the next record or "Submit" to save

### Searching Records

1. Select "Search" from the main menu
2. Choose search criteria: Name, Email, or Telephone
3. Enter the search information
4. Click "Search" to find matching records

### Deleting Records

1. Select "Delete" from the main menu
2. Choose the field to match: Name, Email, or Telephone
3. Enter the information to match
4. Click "Delete" - confirm the deletion in the popup dialog

### Viewing Records

1. Select "View" from the main menu
2. Use "Previous" and "Next" buttons to navigate through records
3. The label shows current position (e.g., "Record 1 of 4")

## File Locations

- **Data File**: `addressbk2.dat` (created in the application directory)
- **Temp File**: `temp.txt` (used for C++/C# communication)
- **DLL**: `Addressbk2dll.dll` (must be in the same directory as the executable)

## Important Notes from the Assignment PDF

1. **Binary File Format**: The address book data is stored in binary format in `addressbk2.dat`
2. **Linked List Implementation**: Records are managed using a linked list data structure
3. **DLL Communication**: The C++ DLL and C# GUI communicate via:
   - `temp.txt` file for passing string data
   - Direct function calls via P/Invoke for operations
4. **Sample Data**: The initialization function creates 4 default records:
   - Lawrence Cheung (enccl@eie.polyu.edu.hk, 27666131)
   - Helon Wong (helonwong@yahoo.com.hk, 94665888)
   - Simon Sui (ss123@gmail.com, 64441234)
   - Mary Ho (ho.mary10@netvigator.com, 21111112)
5. **Record Limit**: Maximum 10 records can be created at once
6. **Data Validation**: Input validation is performed for name (letters only), email (must contain @), and telephone (8 digits)

## Project Structure

```
completed ass2/
├── Addressbk2dll/                    # C++ DLL project
│   ├── Addressbk2dll/
│   │   ├── Addressbk2dll.cpp        # Main DLL functions
│   │   ├── Record2.cpp             # Record class implementation
│   │   └── Record2.h               # Record class header
│   └── Addressbk2dll.sln
├── Addressbk2 graphical/            # C# Windows Forms project
│   ├── Addressbk2 graphical/
│   │   ├── Program.cs             # Application entry point
│   │   ├── Form1.cs               # Main menu form
│   │   ├── Form2.cs               # Create record form
│   │   ├── Choice3.cs              # Search form
│   │   ├── choice4.cs              # Delete form
│   │   ├── choice5.cs              # View records form
│   │   └── create_record_enter_info.cs  # Enter info form
│   └── Addressbk2 graphical.sln
└── ass2/                          # Console version (reference)
    └── ass2.cpp
```

## Troubleshooting

- **DLL Not Found**: Ensure `Addressbk2dll.dll` is in the `bin\Debug` folder
- **File Access Error**: Close the application if `addressbk2.dat` is locked by another process
- **Build Errors**: Ensure Visual Studio has the proper C++ and C# tools installed