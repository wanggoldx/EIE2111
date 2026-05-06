# Lab 6: Classes and Objects

## Overview

This lab covers object-oriented programming:
- Class definitions with member functions
- Object arrays
- Interactive reservation system
- Seat management

## How to Set Up

1. Open `lab6.sln` in Visual Studio
2. Build the solution

## How to Run

1. Open the solution in Visual Studio
2. Press `F5` or click Debug > Start Debugging

## Question: Airline Reservation System

A seat reservation system with:
- 6 seats total: 3 First Class + 3 Economy Class

### Menu Options

| Option | Action |
|--------|--------|
| 0 | Make reservation |
| 1 | Check seating |
| 2 | Exit |

### Reservation Process
- Input name, class (1=First, 0=Economy), number of seats
- System checks availability
- If not enough seats in requested class, offers upgrade option
- Displays confirmation or "next flight in 3 hours"

## Class Definition

```cpp
class abc {
    int check;      // 0 = empty, 1 = occupied
    string name;   // passenger name
public:
    void initialize();      // initialize seat
    int space();        // check if occupied
    void reservation();  // reserve seat
    void planeseating(); // display name
};
```

## Key Features

- Array of 6 abc objects
- First class: seats 0-2 (3 seats)
- Economy class: seats 3-5 (3 seats)
- Visual Studio required (uses C++ classes)

## Student

Lau Wang Chun (ID: 21100151d)