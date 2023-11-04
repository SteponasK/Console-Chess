#include "Headers.h"

int main() {
    Square_pair square_pair;
    Castling castling;
    
    Board testBoard;
    testBoard.updateBoardState();
    while (!testBoard.gameOver()) {
        std::cout << "Turn = " << testBoard.printTurn() << std::endl;
        

        testBoard.drawBoard();
        square_pair = input(testBoard.getTurn(), testBoard.board); // getBoard() change
        if (testBoard.handleMove(square_pair)) {
            testBoard.changeTurn();
            testBoard.updateBoardState(); // first change colour, then check
            testBoard.updateGameStatus();

        }
        Sleep(1500);
        system("cls");
    }
    
    std::cout << "Game over!\n"; // Pass it to the function maybe
    if (testBoard.blackCheckmated) std::cout << "White won by checkmate!\n";
        if (testBoard.whiteCheckmated) std::cout << "Black won by checkmate!\n";
        if (testBoard.stalemate) std::cout << "Draw by stalemate!\n";

	return 0;
}
