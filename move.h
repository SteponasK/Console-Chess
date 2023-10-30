#pragma once
#include "Square_pair.h"
bool move(Square_pair move);
bool handleMove(Square_pair move, int currBoard[120]);
bool getColour(Square_pair move);
bool isKingInCheck(int currBoard[120], bool isWhite);