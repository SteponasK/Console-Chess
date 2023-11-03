#ifndef  BOARDSTATES_H
#define BOARDSTATES_H
#include <vector>
#include <array>
struct boardState {
	int array[120];
	std::array<int, 120> currArray;
};
void addBoardState(std::vector<boardState>& boardStates, const int array[120]);
	
#endif // ! BOARDSTATES_H
