# Lab07 Q1 - Bubble Sort

## Overview
This lab demonstrates the bubble sort algorithm by sorting integers passed as command-line arguments in descending order.

## What It Does
- Takes up to 5 integers as input via command-line arguments
- Sorts them in descending order using bubble sort
- Outputs the sorted numbers

## How to Run
1. Open the solution in Visual Studio:
   ```
   lab07_Q1.sln
   ```
2. Build and run the project
3. Pass integers as command-line arguments, e.g.:
   ```
   lab07_Q1.exe 5 3 8 1 4
   ```

The program accepts 1-5 integers. If more than 5 are provided, it displays an error message.

## Key Details
- Uses 1-based array indexing (a[1] to a[argc-1])
- Bubble sort compares adjacent elements and swaps if the left is smaller than the right
- Results are printed space-separated