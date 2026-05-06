# 2048 Game - EIE2111 Mini Project

A Windows Forms implementation of the popular 2048 sliding tile puzzle game, developed as a mini project for the EIE2111 course.

## Project Overview

This is a C# Windows Forms application that implements the classic 2048 game:

- **Objective**: Slide numbered tiles (2, 4, 8, 16, ...) to combine matching numbers until reaching 2048
- **Game Board**: 4x4 grid
- **Controls**: Arrow keys (Up, Down, Left, Right) to move all tiles in that direction
- **Scoring**: Points are awarded when tiles combine (e.g., 2+2=4 gives 4 points)

## Project Structure

The project has two versions:

| Folder | Description |
|--------|-------------|
| `2048/` | Basic version with classic gameplay |
| `2048plus/` | Enhanced version with additional features |

Both versions contain the same core code. The 2048plus folder includes additional resources (images, sound files) needed for the enhanced features.

## Game Modes

### Mode 1: Classic (Endless)
- Play until you can no longer make moves
- No target score - play for the highest score possible

### Mode 2: Challenge Mode
- Target score: 350 points
- Includes a **Bomb feature** - click the bomb button to place a bomb (-1) on an empty tile
- The bomb destroys itself and any adjacent tile when triggered (moving the bomb into another tile)
- Win condition: Reach score > 350

## Dependencies

- **.NET Framework 4.7.2**
- **Visual Studio 2019** or later (recommended)
- Windows OS (required for Windows Forms)

## Required Resources

The following files must be present in the `bin/Debug` folder for the game to run:

### Image Files
- `0.png` - Empty cell background
- `2.png`, `4.png`, `8.png`, `16.png`, `32.png`, `64.png`, `128.png`, `256.png`, `512.png`, `1024.png`, `2048.png` - Tile images
- `2048table.png` - Board background/table image

### Data Files
- `2048combine.wav` - Sound effect for tile combining
- `ranking.txt` - Leaderboard data (created automatically)

## How to Run

### Option 1: Visual Studio
1. Open the solution file:
   - For basic version: `2048.sln`
   - For plus version: `2048plus.sln`
2. Press **F5** or click **Start** to build and run

### Option 2: Compiled Executable
Run directly from the Debug folder:
```
2048plus\2048\bin\Debug\2048.exe
```

## How to Play

### Starting the Game
1. Enter your name in the text box
2. Select game mode:
   - **Mode 1**: Classic endless
   - **Mode 2**: Challenge with target score
3. Click **Start** to begin

### Controls
- **↑ / ↓ / ← / →**: Move all tiles in that direction
- **Bomb button**: Place a bomb (Mode 2 only, one bomb per game)

### Scoring
- Points are added when tiles combine
- Example: 2+2=4 adds 4 points to your score
- Your final score is saved to the leaderboard

### Game Over
- Classic mode: No valid moves remaining
- Challenge mode: Score exceeds 350 (win condition)

## Leaderboard

High scores are stored in `ranking.txt` in the format:
```
PlayerName Score
```

The game tracks the top 5 scores and displays them on the game over screen.

## Key Code Files

| File | Description |
|------|-------------|
| `Form1.cs` | Login/mode selection screen |
| `Form2.cs` | Main game board and logic |
| `Form3.cs` | Game over and leaderboard screen |
| `Program.cs` | Application entry point |

## Technical Details

### Game Logic (Form2.cs)
- Board represented as `int[4,4]` array
- Tiles store numeric values (0 = empty, 2, 4, 8... = tile values)
- Bomb is represented as -1
- Movement logic:
  1. Slide tiles in direction
  2. Handle bomb collisions
  3. Combine matching tiles
  4. Slide again to fill gaps

### Sound
- Uses `System.Media.SoundPlayer` for audio feedback when tiles combine
- File: `2048combine.wav`

## Notes

- This is a Windows Forms application and requires Windows to run
- The game uses picture boxes for tile display, loading PNG images dynamically
- Chinese language is used in the UI (labels, messages)