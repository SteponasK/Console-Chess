#include "AI.h"

unsigned long long Perft(int depth, int board[120], int colour, Castling& castling, std::vector<boardState>& boardStates) {
    int newBoard[120] = {};
    for (int i = 0; i < 120; ++i) {
        newBoard[i] = board[i];
    }
    if (depth == 0) {
        return 1;
    }
    unsigned long long nodes = 0;
    std::vector<Square_pair> moves = generateMoves(board, colour, castling, boardStates);
    for (const auto& move : moves) {
        // make the move
        int originalPiece = board[move.sq2];
        board[move.sq2] = board[move.sq1];
        board[move.sq1] = 0;

        // recursion for the next level
        nodes += Perft(depth - 1, board, -colour, castling, boardStates);

        // undo the move
        board[move.sq1] = board[move.sq2];
        board[move.sq2] = originalPiece;
    }
    return nodes;
}
std::vector<Square_pair> generateMoves(int board[10 * 12], int colour, Castling& castling, std::vector<boardState>& boardStates) {
    std::vector<Square_pair> legalMoves;

    auto pseudoMoves = calculatePseudoMoves(board, colour, castling, boardStates);
    for (const Square_pair pseudoMove : pseudoMoves) {
        int newBoard[120] = {};
        for (int i = 0; i < 120; ++i) {
            newBoard[i] = board[i];
        }
        movePieces(pseudoMove, newBoard);
        if (!isKingInCheck(newBoard, colour, castling, boardStates)) {
            legalMoves.push_back(pseudoMove);
        }
    }
    // Castling and en passant logic needed:

    return legalMoves;
}