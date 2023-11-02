#include "AI.h"

std::string getMoveString(const Square_pair& move) { // Chat GPT help
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
unsigned long long Perft(int depth, int tempBoard[120], int colour, Castling& castling, std::vector<boardState>& boardStates, std::map<std::string, unsigned long long>& moveCounts, int currentDepth, std::string currentMove) {
    if (depth == 0) {
        // If you've reached the desired depth, increment the move count for this move.
        moveCounts[currentMove]++;
        return 1;  // Return 1 to signify that a leaf node was reached.
    }

    int originalTempBoard[120];
    for (int i = 0; i < 120; ++i) { // This array is needed to reset  tempBoard later.
        originalTempBoard[i] = tempBoard[i];
    }

    std::vector<Square_pair> pseudoMoves = calculatePseudoMoves(tempBoard, colour, castling, boardStates);
    unsigned long long nodes = 0;

    for (const auto& move : pseudoMoves) {

        movePieces(move, tempBoard, boardStates);
        if (!isKingInCheck(tempBoard, colour, castling, boardStates)) {
            std::string moveString = getMoveString(move);

            // If you're at the root node (depth-1 move), start a new count.
            if (currentDepth == 0) {
                nodes += Perft(depth - 1, tempBoard, -colour, castling, boardStates, moveCounts, 1, moveString);
            }
            else {
                // If you're not at the root, accumulate counts for the corresponding root move.
                nodes += Perft(depth - 1, tempBoard, -colour, castling, boardStates, moveCounts, currentDepth, currentMove);
            }
        }
        for (int i = 0; i < 120; ++i) { // Reset the board
            tempBoard[i] = originalTempBoard[i];
        }
    }

    return nodes;
}