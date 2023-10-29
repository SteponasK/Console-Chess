#include <iostream>


enum class Piece
{
    EMPTY = 0,
    W_PAWN = 1,
    W_ROOK = 2,
    W_KNIGHT = 3,
    W_BISHOP = 4,
    W_QUEEN = 5,
    W_KING = 6,

    B_PAWN = -1,
    B_ROOK = -2,
    B_KNIGHT = -3,
    B_BISHOP = -4,
    B_QUEEN = -5,
    B_KING = -6
};

const int BOARD_WIDTH = 12;
const int BOARD_HEIGHT = 12;
const int BOARD_SIZE = BOARD_WIDTH * BOARD_HEIGHT;



bool whiteTurn = 1;
bool castlingRightsWhite = 1;
bool castlingRightsBlack = 1;
bool white_mated = 0;
bool black_mated = 0;
bool draw = 0;


void PawnPseudoMoves(int );
int main() {

    int board[BOARD_SIZE] = { // 12x12 Board
    -99, -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99, -99,
    -99, -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99, -99,
    -99, -99,    -2,  -3,  -4,  -5,  -6,  -4,  -3,  -2,   -99, -99,
    -99, -99,    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -99, -99,
    -99, -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99, -99,
    -99, -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99, -99,
    -99, -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99, -99,
    -99, -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99, -99,
    -99, -99,     1,   1,   1,   1,   1,   1,   1,   1,   -99, -99,
    -99, -99,     2,   3,   4,   5,   6,   4,   3,   2,   -99, -99,
    -99, -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99, -99,
    -99, -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99, -99
    };
    //  [26] = a8     // [32] = h8  
    // [110] = a1     // [118] = a8  

    while (!white_mated && !black_mated && !draw) {
        // Choose piece
        // Calculate legal moves
        // Play Move
        // Change turn
        // AI play turn
        // Change turn
        break;
    }




	return 0;
}
void PawnPseudoMoves() {

}