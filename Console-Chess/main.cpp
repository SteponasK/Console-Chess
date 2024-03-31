#include "Headers.h"

#include "game.h"
int main() { // Promotion not added
    Board testBoard;

    // Import FEN string
    testBoard.setTurn(chooseTurn());
    startGame(testBoard);
    // Post-Game screen needed.
    // Restart the game option
    testBoard.drawBoard();
    Sleep(5000);
	return 0;
}