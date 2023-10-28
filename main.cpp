#include <iostream>

const int BOARD_WIDTH = 12;
const int BOARD_HEIGHT = 12;
const int BOARD_SIZE = BOARD_WIDTH * BOARD_HEIGHT;

const int EMPTY = 0;

const int WPAWN = 1;
const int WROOK = 2;
const int WKNIGHT = 3;
const int WBISHOP = 4;
const int WQUEEN = 5;
const int WKING = 6;


const int BPAWN = -1;
const int BROOK = -2;
const int BKNIGHT = -3;
const int BBISHOP = -4;
const int BQUEEN = -5;
const int BKING = -6;

int main() {
    

            int board[BOARD_SIZE] = { // 12x12 Board
         -99, -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99, -99,
         -99, -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99, -99,
         -99, -99,     2,   3,   4,  -5,  -6,   4,   3,   2,   -99, -99,
         -99, -99,     1,   1,   1,   1,   1,   1,   1,   1,   -99, -99,
         -99, -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99, -99,
         -99, -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99, -99,
         -99, -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99, -99,
         -99, -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99, -99,
         -99, -99,    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -99, -99,
         -99, -99,    -2,  -3,  -4,   5,   6,  -4,  -3,  -2,   -99, -99,
         -99, -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99, -99,
         -99, -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99, -99
        };


	return 0;
}