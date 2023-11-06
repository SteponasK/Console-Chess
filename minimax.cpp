#include "minimax.h"
#include "evaluate.h"                                                               // colour param may be emitted (we see everything when board object is passed)
Square_pair findBestMove(Board perftBoard, int depth, std::array<int, 120> tempBoard, int colour, Castling castling
, unsigned long long& nodesCount) {
    std::vector<Square_pair> pseudoMoves = perftBoard.getPseudoMoves(tempBoard, colour);

    Square_pair bestMove = { -1, -1 }; // Invalid move
    int maxPlayer = perftBoard.getTurn();
    int bestScore = (maxPlayer == 1) ? INT_MIN : INT_MAX;
    int alpha = INT_MIN; // Alpha - negative infinity
    int beta = INT_MAX;  // Beta - positive infinity

    for (const auto& move : pseudoMoves) {
        std::array<int, 120> tempBoardCopy = tempBoard;
        perftBoard.movePieces(move, tempBoardCopy);

        int score = minimax(perftBoard, depth - 1, tempBoardCopy, -maxPlayer, castling, alpha, beta, nodesCount);

        if (colour == maxPlayer && score > bestScore) {
            bestScore = score;
            bestMove = move;
            alpha = score;
        }
        else if (colour == -maxPlayer && score < bestScore) {
            bestScore = score;
            bestMove = move;
            beta = score;
        }
    }
    return bestMove;
}

int minimax(Board perftBoard, int depth, std::array<int, 120> tempBoard, int colour, Castling& castling, int alpha, int beta,
    unsigned long long& nodesCount) {
    ++nodesCount;
    if (depth == 0) {
        return evaluate(tempBoard, colour);
    }

    std::vector<Square_pair> pseudoMoves = perftBoard.getPseudoMoves(tempBoard, colour);

    if (colour == 1) { // Maximizing player
        int maxScore = INT_MIN;
        for (const auto& move : pseudoMoves) {
            std::array<int, 120> tempBoardCopy = tempBoard;
            perftBoard.movePieces(move, tempBoardCopy);
            if (perftBoard.isKingInCheck(tempBoardCopy, colour)) continue;
            int score = minimax(perftBoard, depth - 1, tempBoardCopy, -colour, castling, alpha, beta, nodesCount);
            maxScore = std::max(maxScore, score);
            alpha = std::max(alpha, maxScore);
            if (beta <= alpha) {
                break; // Beta cut-off
            }
        }
        return maxScore;
    }
    else { // Minimizing player
        int minScore = INT_MAX;
        for (const auto& move : pseudoMoves) {
            std::array<int, 120> tempBoardCopy = tempBoard;
            perftBoard.movePieces(move, tempBoardCopy);
            int score = minimax(perftBoard, depth - 1, tempBoardCopy, -colour, castling, alpha, beta, nodesCount);
            minScore = std::min(minScore, score);
            beta = std::min(beta, minScore);
            if (beta <= alpha) {
                break; // Alpha cut-off
            }
        }
        return minScore;
    }
}

