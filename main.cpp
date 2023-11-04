#include "Headers.h"
#include "perft.h"
void game(Board& testBoard, Square_pair& square_pair);
int main() {
    Board testBoard;
    Square_pair square_pair;
    //game(testBoard, square_pair);

        testBoard.updateBoardState();
        std::map<std::string, unsigned long long> moveCounts;
        int depth = 3;
        unsigned long long nodeCount = Perft(testBoard, depth, testBoard.getBoard(), testBoard.getTurn(),
        testBoard.castling, testBoard.boardStates,  moveCounts);
        
	return 0;
}
void game(Board &testBoard, Square_pair& square_pair) {
    testBoard.updateBoardState(); // Can call this in the constructor
    while (!testBoard.gameOver()) {

        testBoard.printTurn();
        testBoard.drawBoard();
        square_pair = input(testBoard.getTurn(), testBoard.getBoard());
        if (testBoard.handleMove(square_pair)) {
            testBoard.changeTurn();
            testBoard.updateBoardState(); // first change colour, then check
            testBoard.updateGameStatus();
        }
        Sleep(1500);
        system("CLS");
    }
    testBoard.printWinner();
}
