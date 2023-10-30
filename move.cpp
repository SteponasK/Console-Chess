#include "move.h"
bool handleMove(Square_pair move, int currBoard[120]) { // https://peterellisjones.com/posts/generating-legal-chess-moves-efficiently/ -> Remove king, when generating attacked squares. Read more about capture and push mask.
	// isKingInCheck() -> if true, then 
	bool isWhite = getColour(move);
	bool check = isKingInCheck(currBoard, isWhite);
	// Calculate Pseudo Legal moves
	// If not in pseudo legal - return 0
	// Play every legal move (because i will have GUI in the future (legal moves will be displayed)
	// If that move is legal = play that move = return 1
	return true;
}
bool isKingInCheck(int currBoard[120],bool isWhite) {
	int kingIndex;
	for (int i = 0; i < 120; ++i) { // finding kingIndex
		if (currBoard[i] == 6 && isWhite) {
			kingIndex = i;
			break;
		}
		if (currBoard[i] == -6 && !isWhite) {
			kingIndex = i;
			break;
		}
	}


	// Calculate all enemy pieces pseudo moves
	// If includes king : king is in check
	//int newBoard[120] = currBoard[120];
	return true;
}
bool move(Square_pair move) {
	// if move was not made return 0;

	return true;
}
void foo() {
	// Blueprint for AI (black)
	// Get curr eval
	// Minimax fnc
	// Play highest eval move
	// Change turn 
}
bool getColour(Square_pair move) {
	return move.sq1 > 0;
}