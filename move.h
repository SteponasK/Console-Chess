#pragma once
#include "Square_pair.h"
bool movePieces(Square_pair move, int currBoard[120]);
bool handleMove(Square_pair move, int currBoard[120], bool whiteTurn);
int getColour(Square_pair move, const int currBoard[120]);
bool isKingInCheck(int currBoard[120], int colour);
bool playMove_TEMPBOARD(Square_pair move, int colour, int originalBoard[120]);
//bool checkTurn(const int colour, const bool whiteTurn);