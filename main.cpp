#include <iostream>

class Piece{
public:
    Piece();


};

Piece::Piece() = default;

struct moveCommand {
        int i;
        int j;
        Piece piece;
};


int main() {
    std::cout << "Start Chess" << std::endl;
    char pieces[32];
    bool checkmate = false;
    /* enumerate commands */


    while (!checkmate) {



    }
    return 0;
}



bool isValidMove() {

}
