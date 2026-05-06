# Lab08 Q2 - Random Access File Operations

## Overview
This lab demonstrates random access (binary) file I/O operations for managing hardware tool inventory records.

## What It Does
- Creates and manages a `hardware.dat` file using random access (binary) mode
- Stores tool records using a `ToolList` class with: record number, tool name, quantity, cost
- Provides a menu-driven interface with these operations:
  1. **List all records**: Display all non-empty tool records
  2. **Delete a record**: Remove a record by record number
  3. **Update a record**: Modify fields (recordno, toolname, quantity, cost)
  4. **Exit**: End the program

## How to Run
1. Open the solution in Visual Studio:
   ```
   lab08_Q2.sln
   ```
2. Build and run the project
3. The program initializes with sample data automatically
4. Select options from the menu to manage records

## Key Details
- Uses binary file format for direct record access
- Records are accessed by position using seekp() and seekg()
- Fixed-size records allow direct access to any record by record number
- The ToolList class manages data with getter/setter methods
- Empty records have record number = 0
- class.h is required for this project (may need to be created)