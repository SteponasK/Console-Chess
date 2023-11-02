#pragma once
#include <vector>
#include "castling.h"
#include "Square_pair.h"
#include "move.h"
#include "pseudoMoves.h"
#include "previousMoves.h"
#include <map>
//std::vector<Square_pair> generateMoves(int board[10 * 12], int colour, Castling& castling, std::vector<boardState>& boardStates);
//unsigned long long Perft(int depth, int board[120], int colour, Castling& castling, std::vector<boardState>& boardStates);
// Function declaration in header file
unsigned long long Perft(int depth, int tempBoard[120], int colour, Castling& castling, std::vector<boardState>& boardStates, std::map<std::string, unsigned long long>& moveCounts, int currentDepth = 0, std::string currentMove = "");


