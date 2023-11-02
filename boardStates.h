#ifndef  BOARDSTATES_H
#define BOARDSTATES_H
#include <vector>
struct boardState {
	int array[120];
};
void addBoardState(std::vector<boardState>& boardStates, const int array[120]);
	
#endif // ! BOARDSTATES_H
