# Lab07 Q2 - Doubly Linked List

## Overview
This lab demonstrates implementation and manipulation of a doubly linked list data structure in C++.

## What It Does
- Creates a doubly linked list with a specified number of nodes
- Supports the following operations:
  - **Insert at front**: Add a new node at the beginning
  - **Remove from front**: Remove the first node
  - **Insert at back**: Add a new node at the end
  - **Remove from back**: Remove the last node
  - **Insert before**: Insert a new node before a specific node
  - **Remove**: Delete a node with a specific value
- Prints the list in both forward and reverse directions

## How to Run
1. Open the solution in Visual Studio:
   ```
   lab07_Q2.sln
   ```
2. Build and run the project
3. Follow the on-screen prompts to:
   - Enter the number of items to create
   - Choose operations from the menu

## Key Details
- Each node contains: `number`, `prevPtr`, `nextPtr`
- The class `Doubly_linked_list` encapsulates node data and pointer management
- Forward traversal uses `GetNext()`
- Reverse traversal uses `GetPrev()` starting from the tail
- Menu-driven interface for interactive testing