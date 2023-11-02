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
#include "castling.h"
#include "AI.h"
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

int main() {
    Square_pair square_pair;
    std::vector<boardState> boardStates;
    addBoardState(boardStates, board);
    Castling castling;
    //while (!white_mated && !black_mated && !draw) {
    //    draw_board();
    //    square_pair = input(whiteTurn, board); // input is correct
    //    
    //    std::cout << "Square pair is: " << square_pair.sq1 << " " << square_pair.sq2 << std::endl;
    //    if (handleMove(square_pair, board, whiteTurn, boardStates, castling)) { // resettinas nes per nauja susikuria
    //        whiteTurn = (whiteTurn ? 0 : 1); 
    //        addBoardState(boardStates, board); // Bug = All board states are the same ( i think)
    //    }
    //    //else std::cout << "handleMove returned 1: incorrect move played\n";
    //    // 
    //    // Choose piece
    //    // Calculate legal moves
    //    // Play Move 
    //    // Change turn
    //    // AI play turn
    //    // Change turn
    //    Sleep(1500);
    //    system("CLS");
    //}

    int tempBoard[120]{};
    for (int i = 0; i < 120; ++i) {
        tempBoard[i] = board[i];
    }
    int depth = 1;
    int colour = 1; 
    unsigned long long totalNodes = Perft(depth, tempBoard, colour, castling, boardStates);
    std::cout << "Perft(" << depth << ") = " << totalNodes << " nodes.\n";

    depth = 2;
    totalNodes = Perft(depth, tempBoard, colour, castling, boardStates);
    std::cout << "Perft(" << depth << ") = " << totalNodes << " nodes.\n";

    depth = 3;// Depth 3 White - 8884, Black - 8900
    totalNodes = Perft(depth, tempBoard, colour, castling, boardStates);
    std::cout << "Perft(" << depth << ") = " << totalNodes << " nodes.\n";

    depth = 4;// Depth 3 White - 8884, Black - 8900
    totalNodes = Perft(depth, tempBoard, colour, castling, boardStates);
    std::cout << "Perft(" << depth << ") = " << totalNodes << " nodes.\n";

   /* Perft(1) = 20 nodes.
        Perft(2) = 400 nodes.
        Perft(3) = 8884 nodes.
        Perft(4) = 197164 nodes.*/
	return 0;
}

