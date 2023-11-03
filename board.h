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
	Board();
	std::array<int, 120> board;// Galima i private // constructor to draw the board needed.
	void drawBoard(const int currBoard[120]);
	void drawBoard();
	bool handleMove(const Square_pair& move);
	int whiteTurn = 1; // White = 1 / Black = -1
	void updateGameStatus();
	bool canCastle(const Square_pair& move,const std::array<int, 120>& currentBoard, const int whiteTurn);
	bool gameOver();
	bool whiteCheckmated = false;
	bool blackCheckmated = false;
	bool stalemate = false;

	void updateBoardState(const std::array<int, 120>& currentBoard);
private: // suskirstyti i sekcijas pagal - be overload ir su
	
	void movePieces(const Square_pair& move);
	void movePieces(const Square_pair& move, std::array<int, 120>& currentBoard);
	bool isKingInCheck(const std::array<int, 120>& currentBoard,const int isWhite);
	bool isKingInCheck(const int colour);
	bool moveExists(const Square_pair& originalMove, const std::vector<Square_pair>& pseudoMoves);
	/*Done*/void updateCastling();
	std::vector<Square_pair> getPseudoMoves(const int colour);
	std::vector<Square_pair> getPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getPseudoMoves(const std::array<int, 120>& currentBoard, const int colour);
		// another function which getspseudoMoves based on the board given. (maybe outside the class)
	/*Done*/void updateKingPositions();
	
	std::vector<boardState> boardStates{};
	
	Castling castling{};
	int wKing{95};
	int bKing{25};
	

	
	std::vector<Square_pair> getPawnPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getKingPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getQueenPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getRookPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getBishopPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getKnightPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);

	//Overload normalp seudo moves:
	std::vector<Square_pair> getPawnPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getKingPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getQueenPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getRookPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getBishopPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getKnightPseudoMoves(const int piece, const int colour);

};
#endif // !BOARD_H