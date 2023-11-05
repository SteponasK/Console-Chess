#include "Headers.h"

#include "game.h"
int main() { // Promotion not added
    Board testBoard;

    testBoard.setTurn(chooseTurn());
    startGame(testBoard);
    // Post-Game screen needed.
    testBoard.drawBoard();
    Sleep(5000);
	return 0;
}