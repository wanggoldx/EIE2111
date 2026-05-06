# Lab09 - Simple Guessing Game

## Overview
This lab demonstrates a simple Windows Forms application with radio buttons and picture display.

## What It Does
- A guessing game where the user tries to guess which image (Snake or Hedgehog) will appear
- Two radio buttons for selection: option 1 (Snake) or option 2 (Hedgehog)
- Randomly selects the answer (1 or 2)
- Displays the corresponding image based on the random result
- Shows a message box indicating whether the guess was correct or wrong

## How to Run
1. Open the solution in Visual Studio:
   ```
   lab09.sln
   ```
2. Build and run the project (F5 or Ctrl+F5)
3. A window will appear with:
   - Two radio button options
   - A picture box showing a default image
   - A Submit/OK button
4. Select one option and click Submit to see the result

## Key Details
- Uses `.NET Framework` Windows Forms
- Images are stored in the `bin/Debug/images/` folder:
  - `back.jpg` - default image
  - `s1.jpg` - snake image
  - `h1.jpg` - hedgehog image
- Random answer range: 1-2 (inclusive)
- Images are loaded at runtime using `Image.FromFile()`