#include "perft.h"

std::string getMoveString(const Square_pair& move) { // Convert from a move to a string
    if (move.sq1 < 21 || move.sq2 < 21 || move.sq1 > 100 || move.sq2 > 100) {
        return "Invalid Move";  // Handle invalid moves
    }
    int fromFile = 'a' + (move.sq1 % 10 - 1);
    int fromRank = 10 - move.sq1 / 10;
    int toFile = 'a' + (move.sq2 % 10 - 1);
    int toRank = 10 - move.sq2 / 10;

    std::string moveString = "";
    moveString += static_cast<char>(fromFile);
    moveString += std::to_string(fromRank);
    moveString += static_cast<char>(toFile);
    moveString += std::to_string(toRank);

    return moveString;
}
//unsigned long long getPerft(Board& perftBoard, std::map<std::string, unsigned long long>& moveCounts) {
//    Board perftBoard;
//    perftBoard.updateBoardState();
//    //std::map<std::string, unsigned long long> moveCounts;
//    int depth = 1;
//    // 
//    unsigned long long nodeCount = Perft(perftBoard, depth, perftBoard.getBoard(), perftBoard.getTurn(),
//   perftBoard.castling, perftBoard.boardStates,  moveCounts);
//    return 1;
//}
void printPerftResults(Board& perftBoard, const int depth) {
    clock_t start{}; // Clock timer
    clock_t end{};

    std::map<std::string, unsigned long long> moveCounts;
    start = clock();
    unsigned long long nodeCount = Perft(perftBoard, depth, perftBoard.getBoard(), perftBoard.getTurn(),
        perftBoard.castling, perftBoard.boardStates, moveCounts);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Perft(" << depth << ") = " << nodeCount << " nodes. ";
    std::cout << "Time taken : " << std::fixed
        << time_taken << std::setprecision(5) <<'s' << std::endl;
}
unsigned long long Perft(Board perftBoard,int depth, std::array<int, 120> tempBoard, int colour, Castling& castling,
    std::vector<boardState>& boardStates, std::map<std::string, // prie array pass by reference gal
    unsigned long long>& moveCounts, int currentDepth, std::string currentMove) {
    
    if (depth == 0) {
        // If you've reached the desired depth, increment the move count for this move.
        moveCounts[currentMove]++;
        return 1;  // Return 1 to signify that a leaf node was reached.
    }
    std::array<int, 120> originalTempBoard = tempBoard; //used to reset later

    std::vector<Square_pair> pseudoMoves = perftBoard.getPseudoMoves(tempBoard, colour);
    unsigned long long nodes = 0;

    for (const auto& move : pseudoMoves) {

        perftBoard.movePieces(move, tempBoard);
        if (!perftBoard.isKingInCheck(tempBoard, colour)) {
            std::string moveString = getMoveString(move);

            // If you're at the root node (depth-1 move), start a new count.
            if (currentDepth == 0) {
                nodes += Perft(perftBoard, depth - 1, tempBoard, -colour, perftBoard.castling, perftBoard.boardStates,
                    moveCounts, 1, moveString);
            }
            else {
                // If you're not at the root, accumulate counts for the corresponding root move.
                nodes += Perft(perftBoard, depth - 1, tempBoard, -colour, perftBoard.castling, perftBoard.boardStates,
                    moveCounts, currentDepth, currentMove);
            }
        }
        tempBoard = originalTempBoard;
    }

    return nodes;
}