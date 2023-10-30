#include "move.h"
#include <iostream>
#include "pseudoMoves.h"

bool handleMove(Square_pair move, int currBoard[120], bool whiteTurn) { // https://peterellisjones.com/posts/generating-legal-chess-moves-efficiently/ -> Remove king, when generating attacked squares. Read more about capture and push mask.
	// isKingInCheck() -> if true, then 
	
	int colour = getColour(move, currBoard);
	/*if (!checkTurn(colour, whiteTurn)) {
		return false;
	}*/
	bool check = isKingInCheck(currBoard, colour);
	std::vector<Square_pair> pseudoMoves = calculatePseudoMovesSolo(currBoard, colour, move);
	for (const auto& currMove : pseudoMoves) {
		std::cout << "   Pseudo Legal moves : " << currMove.sq1 << ' ' << currMove.sq2 << std::endl;
	}
	std::cout << "SIZE OF PSEUDOMOVES: " << pseudoMoves.size() << std::endl;

	bool moveExists = false; // Handling incorrect move
	for (const auto& currMove : pseudoMoves) {
		if ((move.sq1 == currMove.sq1) && (move.sq2 == currMove.sq2)) {
			moveExists = true;
			break;
		}
	}
	if (!moveExists) {
		std::cout << "handleMove returned false: incorrect move selected\n";
		return false;
	}
	// Get Pseudo legal moves
	// If in pseudo legal moves
	// else return false
	if (playMove_TEMPBOARD(move, colour, currBoard)) {
		std::cout << "MOVE is correct on the tempboard\n";
		movePieces(move, currBoard);
		return true;
	}
	return false;
	// Calculate Pseudo Legal moves
	// If not in pseudo legal - return 0
	// Play every legal move (because i will have GUI in the future (legal moves will be displayed)
	// If that move is legal = play that move = return 1
}
//bool checkTurn(const int colour,const bool whiteTurn) {
//	if (whiteTurn && (colour != 1)) return false;
//	if (!whiteTurn && (colour != -1)) return false;
//	// if whiteTurn == 1 , o colour != 1 return false
//	// if whiteTurn == 0 , o colour != -1 return false
//	return true;
//}
bool playMove_TEMPBOARD(Square_pair move, int colour,int originalBoard[120]) {
	int newBoard[120];
	for (int i = 0; i < 120; ++i) {
		newBoard[i] = originalBoard[i];
	}
	bool foo = movePieces(move, newBoard); // change fnc return type to void.
	if (isKingInCheck(newBoard, colour)) {
		std::cout << "TempBoard king in check\n";
		return 0;
	}
	

	return 1;
}
bool isKingInCheck(int currBoard[120],int colour) {
	int kingIndex{};
	for (int i = 0; i < 120; ++i) { // finding kingIndex
		if (currBoard[i] == 6 && colour == 1) { // White
			kingIndex = i;
			break;
		}
		if (currBoard[i] == -6 && colour == -1) { //Black
			kingIndex = i;
			break;
		}
	}
	std::vector<Square_pair> pseudoMoves = calculatePseudoMoves(currBoard, colour);
	for (const auto& move : pseudoMoves) {
		if (move.sq2 == kingIndex) {
			std::cout << "      King is in check: \n";
			std::cout << "      move.sq1: " << move.sq1 << "  move.sq2: "<< move.sq2 << std::endl;
			return true;
		}
	}



	// Calculate all enemy pieces pseudo moves
	// If includes king : king is in check
	//int newBoard[120] = currBoard[120];
	std::cout << "King is not in check\n";
	return false;
}
bool movePieces( Square_pair move, int currBoard[120]) {
	currBoard[move.sq2] = currBoard[move.sq1];
	currBoard[move.sq1] = 0;

	// if move was not made return 0;

	// this fnc only moves. Legal move checking should be other fnc.
	return true;
}
void foo() {
	// Blueprint for AI (black)
	// Get curr eval
	// Minimax fnc
	// Play highest eval move
	// Change turn 
}
int getColour(Square_pair move, const int currBoard[120]) {
	if (currBoard[move.sq1] > 0) return 1;
	// incorrect fnc. Returns board index not value
	return -1;
}