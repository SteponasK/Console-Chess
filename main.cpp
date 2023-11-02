#include "Headers.h"

extern bool whiteTurn = 1;
extern bool white_mated = 0;
extern bool black_mated = 0;
extern bool draw = 0;
extern int perpetualCheckCount = 0;

int main() {
    clock_t start, end; // Clock timer
    
    Square_pair square_pair;
    std::vector<boardState> boardStates;
    addBoardState(boardStates, board);
    Castling castling;
    //while (!white_mated && !black_mated && !draw) {
    //    draw_board();
    //    square_pair = input(whiteTurn, board); // input is correct
    //    if (handleMove(square_pair, board, whiteTurn, boardStates, castling)) { // resettinas nes per nauja susikuria
    //        whiteTurn = (whiteTurn ? 0 : 1); 
    //        addBoardState(boardStates, board); // Bug = All board states are the same ( i think)
    //    }
    //    //else std::cout << "handleMove returned 1: incorrect move played\n";
    //    // 
    //    // Choose piece
    //    // Calculate legal moves
    //    // Play Move 
    //    // Change turn
    //    // AI play turn
    //    // Change turn
    //    Sleep(1500);
    //    system("CLS");
    //}

    int tempBoard[120]{};
    for (int i = 0; i < 120; ++i) {
        tempBoard[i] = board[i];
    }
  
    std::map<std::string, unsigned long long> moveCounts;
    int depth = 1;
    int colour = 1;
    for (depth = 1; depth <= 5; ++depth) {
        start = clock();
        unsigned long long totalNodes = Perft(depth, tempBoard, colour, castling, boardStates, moveCounts);
        end = clock();
        std::cout << "Perft(" << depth << ") = " << totalNodes << " nodes. ";
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        std::cout << "Time taken : " << std::fixed
            << time_taken << std::setprecision(5) <<'s' << std::endl;
    }
    /* Perft(1) = 20 nodes,      Time taken: 0.005s
       Perft(2) = 400 nodes,     Time taken: 0.085s
       Perft(3) = 8902 nodes,    Time taken: 1.851s
       Perft(4) = 197281 nodes,  Time taken: 40.828s
       Perft(5) = 4865351 nodes, Time taken : 1085.076s
       Note: Perft(5) is 258 moves short.
       258 Nodes should be en passant captures, maybe function doesn't count them.
    */
	return 0;
}
