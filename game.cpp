#include "game.h"
void startGame(Board& testBoard) {
    Square_pair square_pair{};
    int choice{};
    while (!(choice == 1 || choice == 2 || choice == 3)) {

        std::cout << "What gamemode do you want:\n";
        std::cout << "{Player vs Player: '1'}\n";
        std::cout << "{Player vs CPU '2'}\n";
        std::cout << "{CPU vs CPU '3'}\n";
        std::cin >> choice;
        switch (choice) { // Make this a function
        case 1:
            gamePVP(testBoard, square_pair);
            break;
        case 2:
            gamePVE(testBoard, square_pair);
            break;
        case 3:
            gameEVE(testBoard, square_pair);
            break;
        default:
            std::cerr << "GameModes not found!\n";
            break;
        }
        system("CLS");
    }
}
int chooseTurn() {
    int turn;
    while (true) {
        std::cout << "What side do you want?\n";
        std::cout << "{White '1'}\n";
        std::cout << "{Black '-1'}\n";
        std::cin >> turn;
        if (turn == 1) {
            return 1;
        }
        else if (turn == -1) {
            return -1;
        }
        system("CLS");
    }
}
void gameEVE(Board& testBoard, Square_pair& square_pair) {
    testBoard.updateBoardState(); // Can call this in the constructor
    while (!testBoard.gameOver()) {
        testBoard.printTurn();
        testBoard.drawBoard();
        //Sleep(1500);
        Square_pair bestMove = findBestMove(testBoard, 4, testBoard.getBoard(), testBoard.getTurn(), testBoard.castling);
        testBoard.movePieces(bestMove);
        testBoard.changeTurn();
        testBoard.updateBoardState();
        testBoard.updateGameStatus();
        system("CLS");
    }
    testBoard.printWinner();
}
void gamePVE(Board& testBoard, Square_pair& square_pair) {
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
            /*std::cout << "CPU PLAYED THIS MOVE: " <<*/

            // CPU PLAYED THIS MOVE : bestMove
            // CPU CALCULATED THIS MANY BRANCHES IN THIS MUCH TIME:
        }

        // Sleep(1500);
        system("CLS");
    }
    testBoard.printWinner();
}
void gamePVP(Board& testBoard, Square_pair& square_pair) {
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