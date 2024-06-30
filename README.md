# **Chess Game**

Welcome to our Chess Game project! This game is built using Object-Oriented Programming (OOP) principles in C++.

# **Table of Contents**

- Introduction
- Features
- Installation
- Usage
- File Descriptions
- Contributors
- License

# **Introduction**

This project is a C++ implementation of the classic game of Chess. The game includes all standard chess pieces and follows the traditional rules of chess. It is designed to be run in a console environment. The project demonstrates the application of Object-Oriented Programming (OOP) principles in C++, with each chess piece represented as a class. The game features full gameplay functionality, including piece movement, capturing, and special moves like castling and en passant. It also includes basic input validation and game state management.

## **Key Features:**
### **Object-Oriented Design:** Each chess piece is implemented as a separate class, with a base class for shared functionality.
### **Standard Rules:** Implements all standard chess rules, including special moves.
### **Console Interface:** Designed to run in a terminal, providing a text-based interface for gameplay.
### **Move Validation:** Ensures that all moves are valid according to chess rules before updating the game state.
### **Game State Management:** Maintains and updates the board state, ensuring accurate tracking of piece positions and game progress.
# **Features**

- Full implementation of standard chess rules.
- Object-oriented design with separate classes for each type of piece.
- Simple and clean code structure.

# **Installation**

To run this chess game on your local machine, follow these steps:

1. Clone the repository
   ```
    git clone https://github.com/Jatin-31-Goel/Chess.git
   ```
3. Navigate to the project directory:
   ``` 
    cd Chess
   ```
5. Compile the code using a C++ compiler, for example:
   ```   
    g++ main.cpp 
   ```

4. Run the compiled program:
   ```
   ./chessgame
   ```
# **Reference for how to run the code**
![Screenshot 2024-06-29 151744](Screenshot%202024-06-29%20151744.png)

# **Usage**

After compiling and running the game, you can play chess directly in your console. The game will prompt you to make moves by entering the coordinates of the pieces.

# **Reference for how to play**

![Screenshot 2024-06-29 180614](Screenshot%202024-06-29%20180614.png)

# **File Descriptions**
- `main.cpp:` 
Contains the main function and the game loop, initializing the game, handling user input, and updating the game state after each move.

- `Bishop.cpp:`
Implements the Bishop piece, including its movement logic which allows diagonal movements on the chessboard, and includes methods to validate and update the Bishop's position.

- `Knight.cpp:`
Implements the Knight piece, defining its unique L-shaped movement on the chessboard, and contains methods to check the validity of moves and update its coordinates.

- `Rook.cpp:`
Implements the Rook piece, allowing horizontal and vertical movements, includes logic to check if the path is clear and updates its position on the board.

- `Queen.cpp:`
Implements the Queen piece by combining the movement logic of both the Rook and Bishop, enabling it to move any number of squares vertically, horizontally, or diagonally.

- `Pawn.cpp:`
Implements the Pawn piece, defining its forward movement and capture mechanics, includes logic for initial double-step move, en passant, and promotion.

- `King.cpp:`
Implements the King piece, includes logic for its single-step movement in any direction and special conditions like castling.

- `Chessboard.cpp:`
Implements the Chessboard class, which manages the game state, holds the positions of all pieces, and includes methods to initialize the board, print its current state, and validate moves.

# **Contributors**

- [Piyush Kumar](https://github.com/Piyushkumar2004)
- [Jatin Goel](https://github.com/member1)
- [Pranav Menon](https://github.com/member2)

# **License**

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.


