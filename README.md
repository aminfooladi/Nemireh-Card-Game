# 🎴 Nemireh — Console Card Game

> **A strategic multiplayer card game built from the ground up with C++ and Object-Oriented Programming.**

Nemireh is a turn-based console card game focused on strategy, player interaction, special card effects, team mechanics, and intelligent computer opponents.

The project was built not only as a playable game, but also as a practical exploration of **Object-Oriented Programming, game-state management, AI logic, persistence, input validation, and terminal UI design**.

---

## ✨ Features

* 👥 **2–5 players** per match
* 🤖 **Two AI difficulty levels** — Easy & Hard
* 🃏 **10+ special card mechanics**
* 💾 **Save & Load** support
* 🔐 **Account system & password validation**
* 🎨 **Colored terminal interface**
* 🏆 **Persistent score tracking**
* 🤝 **Team mechanics**
* ⏪ **NaKheir counter system**
* 🧠 **Hard AI** with opponent card-count awareness
* 🖥️ **Windows console support**
* 🧱 Built with **Object-Oriented Programming**

---

# 🎮 About the Project

Nemireh is a turn-based multiplayer card game where every decision can change the flow of the match.

Players can play cards individually or combine them according to the game's rules. Special cards introduce unique mechanics such as stealing cards, skipping turns, manipulating the deck, protecting players, and forcing opponents into difficult situations.

The game also features **AI-controlled opponents**, allowing players to experience the game even without a full group of human players.

The main goal of the project was simple:

> **Build a complete game while learning how to design and manage a non-trivial C++ application.**

---

# 🃏 Special Cards

One of the core elements of Nemireh is its collection of special cards.

| Card                  | Type   | Effect                                            |
| --------------------- | ------ | ------------------------------------------------- |
| **NaKheir**           | Medium | Cancels the effect of another card                |
| **NaroyNakar**        | Medium | Forces an opponent to play two turns in a row     |
| **JimFang**           | Good   | Skips your turn without drawing a card            |
| **BajSibyl**          | Medium | Takes one random card from an opponent            |
| **GharOghati**        | Medium | Shuffles the main deck                            |
| **Talebin**           | Good   | Allows the player to look at the top 3 cards      |
| **KhanzarPanzar 1–4** | Medium | Two matching cards can be used to steal a card    |
| **AjalMoadlagh**      | Bad    | Eliminates the player if drawn without protection |
| **Shafaye Ajal**      | Good   | Protects the player from AjalMoadlagh             |

---

# ⏪ NaKheir Counter System

**NaKheir** introduces an additional counter mechanic to the game.

Certain card effects can be interrupted using NaKheir cards, creating another layer of strategy around when to play powerful cards and when to save a counter.

This mechanic encourages players to think ahead instead of relying only on the cards in their hand.

---

# 🎯 How to Play

### 1️⃣ Login or Create an Account

Players can log in to an existing account or create a new one.

The password system validates the required password characteristics during account creation.

---

### 2️⃣ Choose a Game Mode

Players can:

* ▶️ Start a new game
* 💾 Load a previously saved game

---

### 3️⃣ Select the Number of Players

Choose between:

```text
2 – 5 Players
```

---

### 4️⃣ Initial Cards

Each player starts with:

* 🃏 **4 random cards**
* 🛡️ **1 Shafaye Ajal card**

---

### 5️⃣ Take Your Turn

During a turn, a player can choose from several actions:

* 🃏 Play one card
* 🃏🃏 Play two identical cards
* 🃏🃏🃏 Play three identical cards
* 🃏 Play five different cards
* 🎴 Draw a card from the deck
* ⏸️ Stop / pause the game

Special cards may trigger additional effects depending on the current game state.

---

### 6️⃣ Win the Match

Players must carefully manage their cards and use special effects strategically.

The **last player standing wins the match** and receives a point.

---

# 🤖 AI System

Nemireh includes two levels of computer-controlled opponents.

### 🟢 Easy AI

The Easy AI uses simpler gameplay decisions and provides a more straightforward opponent.

### 🔴 Hard AI

The Hard AI uses additional information about the current game state.

It can take the **number of cards held by opponents** into consideration when making decisions, resulting in more strategic behavior.

---

# 🖥️ Terminal UI

Nemireh is designed to provide more than a basic text-based experience.

The terminal interface uses:

* 🎨 ANSI escape sequences
* 🃏 Colored cards
* 📦 Box-drawing characters
* 📋 Structured menus
* 🖥️ Console-based layouts
* ✨ Clear game-state presentation

## 📸 Preview

> Add screenshots or a short gameplay GIF here.

For the best presentation, consider showing:

```text
Main Menu
    ↓
Player Hand
    ↓
Game State
    ↓
Special Card
    ↓
Game Result
```

---

# 🛠️ Tech Stack

| Technology                      | Purpose                                |
| ------------------------------- | -------------------------------------- |
| **C++20**                       | Main programming language              |
| **Object-Oriented Programming** | Game architecture                      |
| **ANSI Escape Codes**           | Terminal colors                        |
| **Windows API**                 | Windows-specific console functionality |
| **File I/O**                    | Data persistence                       |
| **Visual Studio / MSBuild**     | Build environment                      |

### C++ Concepts Used

* Classes & Objects
* Encapsulation
* Operator Overloading
* Template Functions
* Dynamic Memory
* File Streams
* STL Containers
* Input Validation
* Game State Management
* AI Logic
* Data Persistence

---

# 🏗️ Architecture

The project is organized around the main entities of the game:

```text
                    ┌───────────────┐
                    │     Game      │
                    │   Game State  │
                    └───────┬───────┘
                            │
              ┌─────────────┼─────────────┐
              │             │             │
              ▼             ▼             ▼
         ┌─────────┐   ┌─────────┐   ┌─────────┐
         │ Player  │   │  Deck   │   │  Card   │
         └────┬────┘   └─────────┘   └─────────┘
              │
        ┌─────┴─────┐
        │           │
        ▼           ▼
      Human         AI
                  ├── Easy
                  └── Hard
```

The architecture separates major game responsibilities into different components, making the project easier to understand and extend.

---

# 📁 Project Structure

```text
Nemireh/
│
├── main.cpp
├── main.h
│
├── Game.h
├── Game.cpp
│
├── Player.h
├── Player.cpp
│
├── Card.h
├── Card.cpp
│
├── Deck.h
├── Deck.cpp
│
├── main.vcxproj
│
├── players_account.txt
│
└── README.md
```

### Main Components

**`Game`**
Handles the main game flow, turns, game state, and gameplay logic.

**`Player`**
Represents players and manages player-related information and AI behavior.

**`Card`**
Represents cards and their properties.

**`Deck`**
Handles deck operations and card management.

**`main.cpp`**
Acts as the entry point of the application and starts the main game flow.

---

# 💾 Save & Load

Nemireh supports persistent game data through a Save / Load system.

Players can save their progress and continue their game later.

The project uses text-file persistence for storing account and game-related information.

```text
players_account.txt
```

This feature provided practical experience with:

* File I/O
* Serialization
* Deserialization
* Persistent state
* Data restoration

---

# 🔐 Account & Password System

Nemireh includes a basic player account system.

During account creation, password validation checks requirements such as:

* Minimum length
* Uppercase characters
* Lowercase characters
* Special characters

> ⚠️ **Security Note:** Passwords are currently stored in plain text. This implementation is intended for educational purposes and should not be considered production-grade authentication.

---

# 🏆 Score System

Nemireh tracks player scores across matches.

Winning a match awards the player a point, allowing the project to maintain a longer-term competitive scoring system.

---

# 🧠 What I Learned

Building Nemireh provided practical experience in several areas of software development.

### 🧱 Object-Oriented Design

The project models major game concepts as separate classes:

```text
Card
Player
Deck
Game
```

Each component has its own responsibilities within the overall game architecture.

### 🔄 Game State Management

The game contains multiple states and transitions:

```text
Login
  ↓
Menu
  ↓
Game Setup
  ↓
Player Turn
  ↓
Card Effect
  ↓
Next Turn
  ↓
Win / Elimination
  ↓
Game End
```

### 🤖 Artificial Intelligence

Implementing two AI levels provided experience with:

* Decision making
* Randomized actions
* Opponent information
* Card-counting logic
* Game-state analysis

### 💾 Persistence

The Save / Load system provided hands-on experience with:

* File streams
* Data serialization
* State restoration
* Persistent game information

### 🖥️ Terminal UI

The interface introduced practical experience with:

* ANSI colors
* Console formatting
* Box-drawing characters
* Menu design
* Structured terminal output

---

# ⚠️ Known Limitations

Nemireh is primarily an educational project, so there are several areas that can still be improved.

### 🪟 Windows Only

The current implementation relies on Windows-specific functionality such as:

```cpp
#include <Windows.h>
```

and:

```cpp
system("cls");
```

Therefore, the current version is intended to run on Windows.

### 🧪 No Automated Tests

The game logic is currently tested manually.

Adding unit and integration tests would improve reliability and make future development easier.

### 🔐 Plain-Text Password Storage

Passwords are currently stored without secure hashing.

A future version should use an appropriate password-hashing mechanism.

### 🧹 Memory Management

Some parts of the implementation could benefit from modern C++ memory-management practices such as RAII and smart pointers.

### 🔍 Input Validation

Some functions could benefit from stronger bounds checking and more defensive input handling.

### 🧩 Project Organization

Some functionality could be separated into smaller modules to improve maintainability.

---

# 🔮 Future Improvements

Possible future improvements include:

### 🧩 Better Architecture

Split larger parts of the project into dedicated modules:

```text
Login
Menu
Game
AI
Cards
Persistence
UI
```

### 🌍 Cross-Platform Support

Replace Windows-specific functionality with portable C++ alternatives and support:

```text
Windows
Linux
macOS
```

### 🧪 Automated Testing

Add tests for:

* Deck operations
* Card effects
* Player actions
* Win conditions
* Save / Load
* AI decisions

### 🔐 Secure Authentication

Replace plain-text password storage with secure password hashing.

### 🗄️ Better Data Storage

Replace text-file persistence with a structured storage solution such as:

```text
JSON
SQLite
```

### 🎨 Graphical Interface

Create a future GUI version using technologies such as:

* Qt
* SFML

### 🤖 Advanced AI

Improve the Hard AI with deeper game-state analysis and more sophisticated decision-making.

### 📦 CMake

Introduce CMake to simplify project configuration and improve portability.

### 🌐 Localization

Add support for multiple languages.

---

# 🗺️ Roadmap

```text
[x] Core card system
[x] Player system
[x] Multiplayer gameplay
[x] Special cards
[x] Easy AI
[x] Hard AI
[x] Account system
[x] Save / Load
[x] Score tracking
[x] Terminal UI

[ ] Automated tests
[ ] Cross-platform support
[ ] Password hashing
[ ] Better persistence
[ ] Advanced AI
[ ] GUI version
[ ] CMake support
[ ] Localization
```

---

# 🙏 Acknowledgments

The **card color scheme** was designed with assistance from **DeepSeek**.

The game logic, architecture, and main implementation were written by me.

The project was inspired by classic Middle-Eastern card-game concepts and social-deduction mechanics.

---

# 👤 Author

## Amin Fooladi

**Computer Engineering Student at University of Isfahan · C++ & Backend Enthusiast**

### Interests

```text
C++
Backend Development
Object-Oriented Design
Software Architecture
Game Development
```

### 🔗 Contact

* **GitHub:** `@aminfooladi`
* **Telegram:** `@Amin_fld`

---

# ⭐ Support the Project

If you enjoyed Nemireh, consider:

⭐ **Starring the repository**

🍴 **Forking the project**

🐛 **Opening an issue**

💡 **Sharing an idea or improvement**

Every star and piece of feedback is appreciated!

---

<div align="center">

# 🎴 Nemireh

### A strategic console card game built with C++

**Code · Strategy · Cards · Survive**

⭐ **Thanks for checking out the project!**

</div>
