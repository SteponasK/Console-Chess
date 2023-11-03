#ifndef BOARD_H
#define BOARD_H

#include "boardStates.h"
#include <iostream>
#include "Square_pair.h"
#include "castling.h"
#include <array>

extern int board[12*10];
class Board {
public:
	std::array<int, 120> board;// Galima i private // constructor to draw the board needed.
	void drawBoard(const int currBoard[120]);
	void drawBoard();
	bool handleMove(const Square_pair& move);
private: // suskirstyti i sekcijas pagal - be overload ir su
	void updateBoardState(boardState& currentBoard); 
	void movePieces(const Square_pair& move);
	void movePieces(const Square_pair& move, std::array<int, 120>& currentBoard);
	bool isKingInCheck(const std::array<int, 120>& currentBoard,const bool isWhite);
	bool isKingInCheck(const int colour);
	bool moveExists(const Square_pair& originalMove, const std::vector<Square_pair>& pseudoMoves);
	/*Done*/void updateCastling();
	void updateGameEndState();
	std::vector<Square_pair> getPseudoMoves(const int colour);
	std::vector<Square_pair> getPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getPseudoMoves(const std::array<int, 120>& currentBoard, const int colour);
		// another function which getspseudoMoves based on the board given. (maybe outside the class)
	/*Done*/void updateKingPositions();
	bool whiteCheckmated = false;
	bool blackCheckmated = false;
	bool stalemate = false;
	std::vector<boardState> boardStates{};
	int whiteTurn = 1; // White = 1 / Black = -1
	Castling castling{};
	int wKing{};
	int bKing{};
	
};
#endif // !BOARD_H