#include "Headers.h"

int main() {
    Board testBoard;
    Square_pair square_pair;
    
    testBoard.updateBoardState(); // Add first board
    while (!testBoard.gameOver()) {
        
        testBoard.printTurn();
        testBoard.drawBoard();
        square_pair = input(testBoard.getTurn(), testBoard.board); // getBoard() change
        if (testBoard.handleMove(square_pair)) {
            testBoard.changeTurn();
            testBoard.updateBoardState(); // first change colour, then check
            testBoard.updateGameStatus();
        }
        Sleep(1500);
        system("CLS");
    }
    testBoard.printWinner();

	return 0;
}
