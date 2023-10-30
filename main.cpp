#include <iostream>
#include "pseudoMoves.h"
#include "board.h"
#include "Header.h"
#include "draw_board.h"
#include "input.h"
//#include "Header.h"
#include "windows.h"
#include "Square_pair.h"
#include "move.h"

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
    Square_pair square_pair;
    
    //calculatePseudoMoves(board);
    int attacks_to[144];
    
    while (!white_mated && !black_mated && !draw) {
        draw_board();
        square_pair = input(); // input is correct
        if (handleMove(square_pair, board)) (whiteTurn ? 0 : 1);
        auto moves = calculatePseudoMoves(board, 1);
        std::cout << "move size: " << moves.size();
        break;
        // Choose piece
        // Calculate legal moves
        // Play Move 
        // Change turn
        // AI play turn
        // Change turn
        Sleep(500);
        system("CLS");
        //break;
    }
  //  std::cout << "square 13: " << board[13];
	return 0;
}