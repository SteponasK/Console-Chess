#include "evaluate.h"
#include "activityBoards.h"
int evaluate(const std::array<int, 120>& board, const int colour) {
	int whiteMaterial = countMaterial(board, 1); // count material
	int blackMaterial = countMaterial(board,-1);

	int whiteEval = whiteMaterial;
	int blackEval = blackMaterial;
	int evaluation = whiteEval - blackEval;
	int perspective = (colour == 1) ? 1 : -1;
	return evaluation * perspective;
}
int countPosition(const std::array<int, 120>& board, const int colour) {

	return 1;
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
