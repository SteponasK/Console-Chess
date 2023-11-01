//#include <iostream>
#include "pseudoMoves.h"
#include "board.h"
#include "Header.h"
#include "draw_board.h"
#include "input.h"
#include "windows.h"
#include "Square_pair.h"
#include "move.h"
#include "previousMoves.h"
//#include "castling.h"
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

extern int whiteARookMoved = 0;
extern int whiteHRookMoved = 0;
extern int blackARookMoved = 0;
extern int blackHRookMoved = 0;
extern int blackKingMoved = 0;
extern int whiteKingMoved = 0;



//int board[144];



int main() {
    Square_pair square_pair;
    std::vector<boardState> boardStates;
    addBoardState(boardStates, board);

    
    // PERFT CODE
    //calculatePseudoMoves(board);
    int depth = 3;
    int colour = 1;
    //Castling castling;
    //unsigned long long totalNodes = Perft(depth, board, colour, castling);
    //std::cout << "Perft(" << depth << ") = " << totalNodes << " nodes.\n";
    // PERFT CODE

    while (!white_mated && !black_mated && !draw) {
        draw_board();
        square_pair = input(whiteTurn, board); // input is correct
        
        std::cout << "Square pair is: " << square_pair.sq1 << " " << square_pair.sq2 << std::endl;
        if (handleMove(square_pair, board, whiteTurn, boardStates)) {
            whiteTurn = (whiteTurn ? 0 : 1); 
            addBoardState(boardStates, board);
            

           // updateCastlingLegality(addBoardState,);
        }
        else std::cout << "handleMove returned 1: incorrect move played\n";
        // Choose piece
        // Calculate legal moves
        // Play Move 
        // Change turn
        // AI play turn
        // Change turn
        

        //std::cout << "board[82]:" << board[92];
        //std::cout << "\nboard[62]: " << board[62];
        Sleep(1500);
        system("CLS");
    }
	return 0;
}

