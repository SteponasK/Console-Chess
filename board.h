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
private:
	void updateBoardState(boardState& currentBoard);
	void movePieces(const Square_pair& move);
	bool isKingInCheck(const std::array<int, 120>& currentBoard);
	bool moveExists(const Square_pair& originalMove, const std::vector<Square_pair>& PseudoMoves);
	void updateCastling();
	void updateGameEndState();
	std::vector<Square_pair> getPseudoMoves();
	std::vector<Square_pair> getPseudoMoves(const int piece);
	void updateKingPositions();
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