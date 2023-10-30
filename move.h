#pragma once
#include "Square_pair.h"
bool movePieces(Square_pair move, int currBoard[120]);
bool handleMove(Square_pair move, int currBoard[120]);
int getColour(Square_pair move);
bool isKingInCheck(int currBoard[120], int colour);
bool playMove_TEMPBOARD(Square_pair move, int colour, int originalBoard[120]);