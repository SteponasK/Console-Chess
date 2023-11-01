#pragma once
#include "Square_pair.h"
#include "castling.h"

#include <iostream>
#include "pseudoMoves.h"



bool movePieces(Square_pair move, int currBoard[120], std::vector<boardState>& boardStates);
bool handleMove(Square_pair move, int currBoard[120], bool whiteTurn, std::vector<boardState>& boardStates, Castling& castling);
bool isEnPassant(Square_pair move, int currBoard[120]);
int getColour(Square_pair move, const int currBoard[120]);
bool isKingInCheck(int currBoard[120], int colour, Castling& castling, std::vector<boardState>& boardStates);
bool playMove_TEMPBOARD(Square_pair move, int colour, int originalBoard[120], Castling& castling, std::vector<boardState>& boardStates);
//bool checkTurn(const int colour, const bool whiteTurn);