#include "AI.h"

unsigned long long Perft(int depth, int tempBoard[120], int colour, Castling& castling, std::vector<boardState>& boardStates) {
  
    if (depth == 0) {
        return 1;
    }
    //create copy of tempBoard[120]
    int originalTempBoard[120]{};
    for (int i = 0; i < 120; ++i) {
        originalTempBoard[i] = tempBoard[i];
    }
    unsigned long long nodes = 0;
    //std::vector<Square_pair> moves = generateMoves(tempBoard, colour, castling, boardStates);
    std::vector<Square_pair> pseudoMoves = calculatePseudoMoves(tempBoard, colour, castling, boardStates);
    for (const auto& move : pseudoMoves) {
        // make the move
        movePieces(move, tempBoard, boardStates);
        // recursion for the next level
        if (!isKingInCheck(tempBoard, colour, castling, boardStates));
        nodes += Perft(depth - 1, tempBoard, -colour, castling, boardStates);

        // undo the move
        for (int i = 0; i < 120; ++i) {
            tempBoard[i] = originalTempBoard[i];
        }
    }
    return nodes;
}
//std::vector<Square_pair> generateMoves(int board[10 * 12], int colour, Castling& castling, std::vector<boardState>& boardStates) {
//    std::vector<Square_pair> Moves;
//
//    auto pseudoMoves = calculatePseudoMoves(board, colour, castling, boardStates);
//    for (const Square_pair pseudoMove : pseudoMoves) {
//        int newBoard[120] = {};
//        for (int i = 0; i < 120; ++i) {
//            newBoard[i] = board[i];
//        }
//        movePieces(pseudoMove, newBoard, boardStates); // We can remove this section, and add if (!IsKingIncheck()) in 
//        if (!isKingInCheck(newBoard, colour, castling, boardStates)) { 
//            Moves.push_back(pseudoMove);
//        } // Don't know if checkmate works here
//    }
//    // Castling and en passant logic needed:
//
//    return Moves;
//}