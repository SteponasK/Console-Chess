#include "Headers.h"
#include "perft.h"
void game(Board& testBoard, Square_pair& square_pair);
int main() {
    Board testBoard;
    Square_pair square_pair{};
    //game(testBoard, square_pair);

        testBoard.updateBoardState(); 
        std::map<std::string, unsigned long long> moveCounts;

        for (int i = 0; i <= 4; ++i) {
            printPerftResults(testBoard, i);
            //Perft(0) = 1 nodes.Time taken : 0.000000s
            //Perft(1) = 20 nodes.Time taken : 0.00200s
            //Perft(2) = 400 nodes.Time taken : 0.05000s
            //Perft(3) = 8902 nodes.Time taken : 1.13600s
            //Perft(4) = 197281 nodes.Time taken : 23.63400s
        }
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
