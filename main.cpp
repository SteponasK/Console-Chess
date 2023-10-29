#include <iostream>
#include "pseudoMoves.h"
#include "board.h"
#include "Header.h"
//#include "Header.h"

extern const int BOARD_WIDTH = 12;
extern const int BOARD_HEIGHT = 12;
extern const int BOARD_SIZE = BOARD_WIDTH * BOARD_HEIGHT;

extern bool whiteTurn = 1;
extern bool castlingRightsWhite = 1;
extern bool castlingRightsBlack = 1;
extern bool white_mated = 0;
extern bool black_mated = 0;
extern bool draw = 0;
extern int perpetualCheckCount = 0;
//int board[144];
int main() {

    
    //calculatePseudoMoves(board);
    int attacks_to[144];

    //while (!white_mated && !black_mated && !draw) {
    //    // Choose piece
    //    // Calculate legal moves
    //    // Play Move
    //    // Change turn
    //    // AI play turn
    //    // Change turn
    //    break;
    //}
	return 0;
}