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
#include "previousMoves.h"

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
std::vector<Square_pair> generateMoves(int board[10 * 12], int colour);
unsigned long long Perft(int depth, int board[120], int colour);

void updateCastlingLegality(std::vector<boardState> boardStates, int& whiteARookMoved,
    int& whiteHRookMoved, int& blackARookMoved, int& blackHRookMoved, int& blackKingMoved,
    int& whiteKingMoved);
int main() {
    Square_pair square_pair;
    std::vector<boardState> boardStates;
    addBoardState(boardStates, board);

    
    // PERFT CODE
    //calculatePseudoMoves(board);
    int depth = 3;
    int colour = 1;
    //unsigned long long totalNodes = Perft(depth, board, colour);
    //std::cout << "Perft(" << depth << ") = " << totalNodes << " nodes.\n";
    // PERFT CODE

    while (!white_mated && !black_mated && !draw) {
        draw_board();
        square_pair = input(whiteTurn, board); // input is correct
        
        std::cout << "Square pair is: " << square_pair.sq1 << " " << square_pair.sq2 << std::endl;
        if (handleMove(square_pair, board, whiteTurn)) {
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
void updateCastlingLegality(std::vector<boardState> boardStates, int& whiteARookMoved,
    int& whiteHRookMoved, int& blackARookMoved, int& blackHRookMoved, int& blackKingMoved,
    int& whiteKingMoved) {

    if (boardStates.size() < 2)
        return;
    
    //White Rook moved check
    boardState currentBoard = boardStates.back();
    auto previousIterator = boardStates.end() - 1;
    boardState previousBoard = *previousIterator;
    int bRooka = 21;
    int bRookh = 28;
    int wRooka = 91;
    int wRookh = 98;
    // If currently rooks are not in their default squares
    if (currentBoard.array[bRooka] != -2) { 
        blackARookMoved = true;
    }
    if (currentBoard.array[bRookh] != -2) {
        blackHRookMoved = true;
    }
    if (currentBoard.array[wRooka] != 2) {
        whiteARookMoved = true;
    }
    if (currentBoard.array[wRookh] != 2) {
        whiteHRookMoved = true;
    }
    // If on the last move rooks were not in their squares
    if (previousBoard.array[bRooka] != -2) {
        blackARookMoved = true;
    }
    if (previousBoard.array[bRookh] != -2) {
        blackHRookMoved = true;
    }
    if (previousBoard.array[wRooka] != 2) {
        whiteARookMoved = true;
    }
    if (previousBoard.array[wRookh] != 2) {
        whiteHRookMoved = true;
    }

    // 4 rook pos
    // jeigu ne toj vietoj -> tada moved = true
    // jeigu last lentoj buvo toj pos, bet current lentoj ne -> tada moved = true

}
unsigned long long Perft(int depth, int board[120], int colour) {
    int newBoard[120];
    for (int i = 0; i < 120; ++i) {
        newBoard[i] = board[i];
    }
    if (depth == 0) {
        return 1;  
    }
    unsigned long long nodes = 0;
    std::vector<Square_pair> moves = generateMoves(board, colour);
    for (const auto& move : moves) {
        // make the move
        int originalPiece = board[move.sq2];
        board[move.sq2] = board[move.sq1];
        board[move.sq1] = 0; 

        // recursion for the next level
        nodes += Perft(depth - 1, board, -colour);

        // undo the move
        board[move.sq1] = board[move.sq2];
        board[move.sq2] = originalPiece;
    }
    return nodes;
}
std::vector<Square_pair> generateMoves(int board[10 * 12], int colour) {
    std::vector<Square_pair> legalMoves;
    
    auto pseudoMoves = calculatePseudoMoves(board, colour);
    for (auto pseudoMove : pseudoMoves) {
        int newBoard[120];
        for (int i = 0; i < 120; ++i) {
            newBoard[i] = board[i];
        }
        movePieces(pseudoMove, newBoard);
        if (!isKingInCheck(newBoard, colour)) {
            legalMoves.push_back(pseudoMove);
        }
    }

    return legalMoves;
}