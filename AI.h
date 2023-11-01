#pragma once
#include <vector>
#include "castling.h"
#include "Square_pair.h"
#include "move.h"
#include "pseudoMoves.h"
#include "previousMoves.h"
std::vector<Square_pair> generateMoves(int board[10 * 12], int colour, Castling& castling, std::vector<boardState>& boardStates);
unsigned long long Perft(int depth, int board[120], int colour, Castling& castling, std::vector<boardState>& boardStates);