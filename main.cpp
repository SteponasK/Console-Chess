#include "Headers.h"
#include "perft.h"
#include "minimax.h"
void game(Board& testBoard, Square_pair& square_pair);
void game(Board& testBoard, Square_pair& square_pair, bool minimax);
int main() { // Promotion not added
    Board testBoard;
    Square_pair square_pair{};
    // GAME OPTIONS:
    // PLAYER VS CPU
    // CPU VS CPU
    // PLAYER VS PLAYER (yourself)
    game(testBoard, square_pair, true);
    // post Game screen
	return 0;
}


void game(Board& testBoard, Square_pair& square_pair, bool minimax) {
    testBoard.updateBoardState(); // Can call this in the constructor
    while (!testBoard.gameOver()) {

        testBoard.printTurn();
        testBoard.drawBoard();
        if (testBoard.getTurn() == 1) {
            // Player's turn
            square_pair = input(testBoard.getTurn(), testBoard.getBoard());
            if (testBoard.handleMove(square_pair)) {
                testBoard.changeTurn();
                testBoard.updateBoardState(); // This outside loop (repeats iself)
                testBoard.updateGameStatus();
            }
        }
        else {
            // Minimax turn
            Square_pair bestMove = findBestMove(testBoard, 5, testBoard.getBoard(), -1, testBoard.castling); // TODO: BEFORE AFTER FUNCTION CALL DO A TIMER
            //Square_pair enemyMove = findBestMove(testBoard, 3, testBoard.getBoard(), 1, testBoard.castling);
            testBoard.movePieces(bestMove);
            testBoard.changeTurn();
            testBoard.updateBoardState();
            testBoard.updateGameStatus();
            // CPU PLAYED THIS MOVE : bestMove
            // CPU CALCULATED THIS MANY BRANCHES IN THIS MUCH TIME:
        }

       // Sleep(1500);
        system("CLS");
    }
    testBoard.printWinner();
}
void game(Board& testBoard, Square_pair& square_pair) {
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

/*
 testBoard.updateBoardState(); 
std::map<std::string, unsigned long long> moveCounts;
for (int i = 0; i <= 5; ++i) {
    printPerftResults(testBoard, i);
    //Perft(0) = 1 nodes.Time taken : 0.000000s
    //Perft(1) = 20 nodes.Time taken : 0.00200s
    //Perft(2) = 400 nodes.Time taken : 0.05000s
    //Perft(3) = 8902 nodes.Time taken : 1.13600s
    //Perft(4) = 197281 nodes.Time taken : 23.63400s
    //Perft(5) = 4865351 nodes. Time taken: 583.56800s // Doesnt find 258 e.p. moves
}*/