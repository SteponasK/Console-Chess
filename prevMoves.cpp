#include "previousMoves.h"

void addBoardState(std::vector<boardState>& boardStates, const int array[120]) {
	boardState temp{};
	for (int i = 0; i < 120; ++i) {
		temp.array[i] = array[i];
	}
	boardStates.push_back(temp);
}