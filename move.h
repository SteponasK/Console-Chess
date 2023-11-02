#ifndef MOVE_H
#define MOVE_H

#include "Square_pair.h"
#include "castling.h"
#include <iostream>
#include "pseudoMoves.h"
#include "boardStates.h"
#include "Square_pair.h"
#include "draw_board.h"

void movePieces(Square_pair move, int currBoard[120], std::vector<boardState>& boardStates);
bool handleMove(Square_pair move, int currBoard[120], bool whiteTurn, std::vector<boardState>& boardStates, Castling& castling);
bool isEnPassant(Square_pair move, int currBoard[120]);
int getColour(Square_pair move, const int currBoard[120]);
bool isKingInCheck(int currBoard[120], int colour, Castling& castling, std::vector<boardState>& boardStates);
bool playMove_TEMPBOARD(Square_pair move, int colour, int originalBoard[120], Castling& castling, std::vector<boardState>& boardStates);
#endif // !MOVE_H