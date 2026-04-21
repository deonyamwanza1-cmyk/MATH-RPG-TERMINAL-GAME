# Terminal Math-RPG

A lightweight, terminal-based Role-Playing Game written entirely in C++. Players select a character class, battle randomly generated enemies, and execute attacks by solving quick math challenges. 

This project was developed to solidify core C++ concepts, including Object-Oriented Programming (OOP), dynamic memory allocation, and command-line application structure.

## 🎮 Gameplay Features
* **Dynamic Character Classes:** Choose between Warrior, Mage, or Rogue, each with unique HP and damage scaling.
* **Randomized Enemy Encounters:** Face off against enemies with varying hit percentages and damage output using `<cstdlib>` random number generation.
* **Math-Based Combat:** Attacks require solving randomly generated math equations under pressure.
* **Clean Terminal UI:** Utilizes ANSI escape sequences to clear the screen and manage text flow between combat rounds.

## 🛠️ Tech Stack & Concepts
* **Language:** C++
* **Object-Oriented Programming:** Encapsulation via `Player` and `Enemy` classes.
* **Memory Management:** Dynamic object creation using pointers and the `new`/`delete` keywords to handle memory safely without leaks.
* **Standard Libraries:** `<iostream>`, `<string>`, `<cstdlib>`, `<ctime>`.

## 🚀 How to Build and Run

### Linux / macOS (g++)
To compile and run the game using the `g++` compiler from your terminal:
1. Clone the repository: `git clone https://github.com/YourUsername/YourRepoName.git`
2. Navigate to the directory: `cd YourRepoName`
3. Compile the code: `g++ main.cpp -o math_rpg`
4. Run the executable: `./math_rpg`

### Windows (Visual Studio / MSVC)
1. Clone the repository and open the folder in Visual Studio.
2. Ensure your build configuration is set to `Debug` or `Release` (x64).
3. Build the solution (`Ctrl + Shift + B`).
4. Run the program without debugging (`Ctrl + F5`).

## 📸 Preview
![Math-RPG Gameplay Correct Answer Screen](combatCorrectAnswer.png)
![Math-RPG Gameplay Incorrect Answer Screen](combatIncorrectAnswer.png)
![Math-RPG Gameplay Victory Screen](VictoryScreen.png)
