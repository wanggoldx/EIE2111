# Lab08 Q1 - Sequential File Operations

## Overview
This lab demonstrates sequential file I/O operations for managing hardware tool inventory records.

## What It Does
- Creates and manages a `hardware.txt` file using sequential (text) access
- Stores tool records with: record number, tool name, quantity, cost
- Provides a menu-driven interface with these operations:
  1. **List all records**: Display all tool records
  2. **Delete a record**: Remove a record by record number
  3. **Update a record**: Modify fields (recordno, toolname, quantity, cost)
  4. **Exit**: End the program

## How to Run
1. Open the solution in Visual Studio:
   ```
   lab08_Q1.sln
   ```
2. Build and run the project
3. The program initializes with sample data automatically
4. Select options from the menu to manage records

## Key Details
- Uses text file format (space-separated values)
- Tool names with spaces are stored with underscores (`_`) and displayed with spaces
- Records are stored as plain text, requiring rewrite for modifications
- File operations use `ifstream` for reading and `ofstream` for writing