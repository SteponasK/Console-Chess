#include "evaluate.h"
#include "activityBoards.h"
int evaluate(const std::array<int, 120>& board, const int colour) {
	int whiteMaterial = countMaterial(board, 1); // count material
	int blackMaterial = countMaterial(board,-1);
	int whitePosition = countPosition(board, 1);
	int blackPosition = countPosition(board,-1);

	int whiteEval = whiteMaterial + whitePosition;
	int blackEval = blackMaterial + blackPosition;
	int evaluation = whiteEval - blackEval;
	int perspective = (colour == 1) ? 1 : -1;
	return evaluation * perspective;
}
int countPosition(const std::array<int, 120>& board, const int colour) {
	int points{};
	if (colour == 1) {
		for (int i = 21; i < 100; ++i) {
			if (board[i] == 1) points += wPawn[i];
			if (board[i] == 2) points += wRook[i];
			if (board[i] == 3) points += Knight[i];
			if (board[i] == 4) points += wBishop[i];
			if (board[i] == 5) points += Queen[i];
		}
	}
	else {
		for (int i = 21; i < 100; ++i) {
			if (board[i] == -1) points += bPawn[i];
			if (board[i] == -2) points += bRook[i];
			if (board[i] == -3) points += Knight[i];
			if (board[i] == -4) points += bBishop[i];
			if (board[i] == -5) points += Queen[i];
		}
	}
	
	return points;
}
int countMaterial(const std::array<int, 120>& board, const int colour) {
	int points{};
	const int pieceValues[] = { 0, 100, 500, 300, 300, 900, 0 };// King score is not counted 
	for (int i = 21; i < 100; ++i) {
		int value = board[i] * colour;
		if (value > 0) { // same Colour
			if (value < 8)
				points += pieceValues[value];
		}
	}
	return points;
}
