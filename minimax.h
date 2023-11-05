#ifndef  MINIMAX_H
#define MINIMAX_H
#include "board.h"
Square_pair findBestMove(Board perftBoard, int depth, std::array<int, 120> tempBoard, int colour, Castling castling);
int minimax(Board perftBoard, int depth, std::array<int, 120> tempBoard, int colour, Castling& castling, int alpha, int beta);

#endif // ! MINIMAX_H

