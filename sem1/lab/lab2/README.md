# Lab 2: Introduction to Classes

## Overview

This lab introduces object-oriented programming with classes:
- Creating class definitions (header files)
- Implementing class member functions
- Separate interface and implementation files
- Using class objects in main program

## Projects in This Folder

| Project | Description |
|---------|------------|
| Account | Bank account class with credit, debit, balance operations |
| GradeBook | Course management class with name display |

## How to Set Up

1. Open the Visual Studio solution file (`.sln`) in the project folder
2. Build the project to compile the class library first
3. The project uses standard C++ and requires no additional dependencies

## How to Run

1. Open the solution in Visual Studio
2. Build the solution (Ctrl+Shift+B)
3. Press `F5` or click Debug > Start Debugging

## Key Details

### Account Class
- **Constructor**: Initializes account balance (validates not negative)
- **credit()**: Adds amount to balance
- **debit()**: Withdraws amount (rejects if exceeds balance)
- **getBalance()**: Returns current balance

### GradeBook Class
- **Constructor**: Initializes with course name
- **setCourseName()**: Sets the course name
- **getCourseName()**: Returns the course name
- **displayMessage()**: Displays welcome message

## File Structure

- `.h` file: Class declaration
- `.cpp` file: Class implementation