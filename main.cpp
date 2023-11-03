#include "Headers.h"

extern bool whiteTurn = 1;

int main() {
    //Board board;
    Square_pair square_pair;
    std::vector<boardState> boardStates;
    addBoardState(boardStates, board);
    Castling castling;

    GameEnd game;
    
    Board testBoard;
    testBoard.updateBoardState(testBoard.board);
    while (true) {
        std::cout << "Turn = ";
        if (testBoard.whiteTurn == 1) std::cout << "White\n";
        else std::cout << "Black\n";

        testBoard.drawBoard();
        square_pair = input(testBoard.whiteTurn, testBoard.board);
        //std::cout << "\nPair: " << square_pair.sq1 << " " << square_pair.sq2 << std::endl;
        //std::cout << "\nPiece: " << testBoard.board[square_pair.sq1] << " " << testBoard.board[square_pair.sq2] << std::endl;
        //Sleep(2500);
        if (testBoard.handleMove(square_pair)) {
            if (testBoard.whiteTurn == 1) {
                testBoard.whiteTurn = -1;
            }
            else testBoard.whiteTurn = 1;
            testBoard.updateBoardState(testBoard.board); // first change colour, then check
        }
       // testBoard.updateGameEndState();
        Sleep(1500);
        system("cls");
    }

    //while (!gameOver(game)){
    //    std::cout << "Turn = " << (whiteTurn ? "White\n" : "Black\n");
    //    draw_board();
    //    //board.draw_board();
    //    square_pair = input(whiteTurn, board);
    //    if (handleMove(square_pair, board, whiteTurn, boardStates, castling, game)) {
    //        whiteTurn = (whiteTurn ? 0 : 1); 
    //        addBoardState(boardStates, board);
    //        calculateGameEnd(board, game, whiteTurn, castling, boardStates);// Checking if the enemy is checkmated
    //    }
    //    Sleep(1500);
    //    system("CLS");
    //    //game.blackCheckmated = true;
    //}
    auto currentBoard = boardStates.back();
    int maxIndex = boardStates.size() - 1;
    int index = boardStates.size() - 1;
    char key;
    do {
        std::cout << "Game over!\n"; // Pass it to the function maybe
        if (game.blackCheckmated) std::cout << "White won by checkmate!\n";
        if (game.whiteCheckmated) std::cout << "Black won by checkmate!\n";
        if (game.stalemate) std::cout << "Draw by stalemate!\n";
        std::cout << std::endl;
        if (index > maxIndex) index = maxIndex; // Out of bounds checking
        else if (index < 0) index = 0;
        
        draw_board(boardStates.at(index).array);
        std::cout << "Navigate using 'A' and 'D' keys to view past moves.\n";
        std::cout << "Press 'E' to exit the application\n\n";
        std::cout << "Move: " << index + 1;
        key = _getch();
        key = toupper(key);
        if (key == 'A') { // Index through all board moves.
            --index;
        }
        if (key == 'D') {
            ++index;
        }
        system("CLS");
    } while (key != 'E');
	return 0;
}
