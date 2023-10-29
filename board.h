#pragma once
#include "Header.h"
extern int board[10*12];
enum class Piece {
    EMPTY = 0,
    W_PAWN = 1,
    W_ROOK = 2,
    W_KNIGHT = 3,
    W_BISHOP = 4,
    W_QUEEN = 5,
    W_KING = 6,

    B_PAWN = -1,
    B_ROOK = -2,
    B_KNIGHT = -3,
    B_BISHOP = -4,
    B_QUEEN = -5,
    B_KING = -6
};