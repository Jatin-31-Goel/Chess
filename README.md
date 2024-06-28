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

This project is a C++ implementation of the classic game of Chess. The game includes all standard chess pieces and follows the traditional rules of chess. It is designed to be run in a console environment.

# **Object-Oriented Programming (OOP)**
Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects," which can contain data and code. Data is in the form of fields (often known as attributes or properties), and code is in the form of procedures (often known as methods).
OOP has several key principles:
**Encapsulation:** This principle states that all important information is contained inside an object and only select information is exposed. In our chess game, each piece (like a bishop, knight, or rook) is an object that contains its own properties and methods.
**Abstraction:** This principle involves hiding complex implementation details and showing only the necessary features of an object. For example, the movement of each piece is abstracted into methods that are easy to use without knowing the underlying complexity.
**Inheritance:** This principle allows new classes to inherit properties and methods from existing classes. In our project, the Queen class inherits from both the Rook and Bishop classes, reusing and extending their functionalities.
**Polymorphism:** This principle allows objects of different classes to be treated as objects of a common superclass. It is most often used with inheritance. For instance, all chess pieces are treated as a type of base class Piece, allowing for a unified way to handle different pieces.
By leveraging OOP, our chess game is organized, modular, and easier to maintain and extend. Each class represents a different piece or part of the game, making the code more readable and manageable.
# **Features**

- Full implementation of standard chess rules.
- Object-oriented design with separate classes for each type of piece.
- Simple and clean code structure.

# **Installation**

To run this chess game on your local machine, follow these steps:

1. Clone the repository
    git clone https://github.com/Jatin-31-Goel/Chess.git

2. Navigate to the project directory:
    
    cd Chess
3. Compile the code using a C++ compiler, for example:
    
g++ main.cpp Bishop.cpp Knight.cpp Rook.cpp Queen.cpp Pawn.cpp King.cpp Chessboard.cpp -o chessgame

4. Run the compiled program:
   ./chessgame

# **Usage**

After compiling and running the game, you can play chess directly in your console. The game will prompt you to make moves by entering the coordinates of the pieces.

# **File Descriptions**

- `main.cpp`: Contains the main function and the game loop.
- `Bishop.cpp` and `Bishop.h`: Contains the implementation of the Bishop piece.
- `Knight.cpp` and `Knight.h`: Contains the implementation of the Knight piece.
- `Rook.cpp` and `Rook.h`: Contains the implementation of the Rook piece.
- `Queen.cpp` and `Queen.h`: Contains the implementation of the Queen piece, which inherits from Rook and Bishop.
- `Pawn.cpp` and `Pawn.h`: Contains the implementation of the Pawn piece.
- `King.cpp` and `King.h`: Contains the implementation of the King piece.
- `Chessboard.cpp` and `Chessboard.h`: Contains the implementation of the Chessboard class, which manages the game state and pieces.

# **Contributors**

- [Piyush Kumar](https://github.com/Piyushkumar2004)
- [Jatin Goel](https://github.com/member1)
- [Pranav Menon](https://github.com/member2)

# **License**

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.


