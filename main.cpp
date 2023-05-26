#include <iostream>
typedef std::pair<char, int> location;

struct Piece {
    location currentLocation;
    char type; // one of P, R, N, B, K, Q
};
struct moveCommand {
        location toLocation;
        Piece piece;
};

moveCommand parseMoveCommand(std::string command, char board[8][8]);
void modifyBoard(moveCommand move, bool side, char board[8][8]);
int pawnSquare (int file, char board[8][8]);
void printBoard(char board[8][8]);

int main() {
    std::cout << "Start Chess" << std::endl;
    char pieces[32];
    std::string command;
    bool checkmate = false, side = 1; // side 0 is white.

    char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
             {' ', 'p', ' ', ' ', ' ', ' ', ' ', ' ', }};
    /* enumerate commands */
    printBoard(board);

    while (!checkmate) {
    if (side) std::cout << "White to move: ";
    else std::cout << "Black to move: ";
    std::cin >> command;

    printBoard(board);
    modifyBoard(parseMoveCommand(command, board), side, board);



    side = !side; // Switch player whose turn it is
    }
    return 0;
}

moveCommand parseMoveCommand(std::string command, char board[8][8]) {
    moveCommand moveCommand;
    if (command.at(0) <= 'h' && command.at(0) >= 'a') {
        std::cout << "test flag 1";
        moveCommand.toLocation.first = command.at(0);
        moveCommand.piece.type = 'P';
        moveCommand.piece.currentLocation.first = moveCommand.toLocation.first;
        moveCommand.piece.currentLocation.second = pawnSquare(command.at(0) - 97, board);
    }
    else if ((command.at(0) >= 81 && command.at(0) <= 66 && command.at(0) % 3 == 0 && command.at(0) != 69) || command.at(0) == 82) {
        // move a different piece
    }
    else std::cout << "Invalid piece.\n";
    // else if

    if (command.at(1) == 'x') {
        // do stuff
    }
    else {
        moveCommand.toLocation.second = command.at(1);
    }
    return moveCommand;
}

int pawnSquare (int file, char board[8][8]) {
    std::cout << "\n" << file << std::endl;
    for (int i(0); i < 8; i++) {
        if (board[file][i] == 'p') return i;
    }
    return -1;
}

void modifyBoard(moveCommand move, bool side, char board[8][8]) {
    std::cout << "\ntolocation, first (letter, aka col): " << move.toLocation.first << std::endl;
    std::cout << "tolocation, second (number aka row): "<< move.toLocation.second << std::endl;
    std::cout << "currlocation, first (letter, aka col): "<< move.piece.currentLocation.first << std::endl;
    std::cout << "currlocation, second (number, aka row): "<< move.piece.currentLocation.second << std::endl;
    std::cout << "piece type: "<< move.piece.type << std::endl;

    board[move.piece.currentLocation.first-97][move.piece.currentLocation.second] = ' ';
    board[move.toLocation.first][move.toLocation.second] = move.piece.type;
}

void checkForMate(bool &checkmate) {

}

void printBoard(char board[8][8]) {
    std::cout << "\nBoard: \n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 'p') std::cout << "♙";
            else std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

bool isValidMove() {
    return 0;
}
