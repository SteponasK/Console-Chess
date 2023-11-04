#ifndef BOARD_H
#define BOARD_H

#include "boardStates.h"
#include <iostream>
#include "Square_pair.h"
#include "castling.h"
#include <array>

class Board {
public:
	Board();
	
	void drawBoard(const int currBoard[120]); // Overload -  For drawing previous moves
	void drawBoard(); // For drawing Current move

	bool handleMove(const Square_pair& move); // Move logic

	void changeTurn();
	int getTurn();
	std::string printTurn();

	void updateGameStatus();
	bool gameOver();
	bool whiteCheckmated = false; // Public for now, because used for displaying game status (game won by checkmate black, etc.)
	bool blackCheckmated = false;
	bool stalemate = false;
	std::array<int, 120> board; // input() wants this, so public for now (TODO: create .getBoard() fnc)

	void updateBoardState();
private: 
	int whiteTurn = 1; // White = 1 / Black = -1
	std::vector<boardState> boardStates{};
	Castling castling{};
	int wKing{ 95 };
	int bKing{ 25 };
	void updateKingPositions(); // Update KingPositions for current board -> probably add another one for specific board
	void updateCastling(); // Update "castling" struct variables
	bool canCastle(const Square_pair& move, const std::array<int, 120>& currentBoard, const int whiteTurn);
	void movePieces(const Square_pair& move); // Overload - Current Board
	void movePieces(const Square_pair& move, std::array<int, 120>& currentBoard); // Overload - specific Board
	bool isKingInCheck(const std::array<int, 120>& currentBoard,const int isWhite); // Overload - specific Board
	bool isKingInCheck(const int colour); // Overload - currentBoard (probably not needed,(maybe if tryng to do some logic in main.cpp)
	bool moveExists(const Square_pair& originalMove, const std::vector<Square_pair>& pseudoMoves); // Does the move exist
	
	std::vector<Square_pair> getPseudoMoves(const int colour); // Overload - current Board, all specific colour pieces
	std::vector<Square_pair> getPseudoMoves(const int piece, const int colour); // Overload - current Board, single piece
	std::vector<Square_pair> getPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour); // Overload - single piece, specific board.
	std::vector<Square_pair> getPseudoMoves(const std::array<int, 120>& currentBoard, const int colour); // Overload - specific Board, all specific colour pieces
	
	
	// Overload - single piece, specific Board.
	std::vector<Square_pair> getPawnPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getKingPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getQueenPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getRookPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getBishopPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);
	std::vector<Square_pair> getKnightPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour);

	//Overload - single piece, current Board.
	std::vector<Square_pair> getPawnPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getKingPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getQueenPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getRookPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getBishopPseudoMoves(const int piece, const int colour);
	std::vector<Square_pair> getKnightPseudoMoves(const int piece, const int colour);
};
#endif // !BOARD_H