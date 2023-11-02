#pragma once
#include <vector>
#include "castling.h"
#include "Square_pair.h"
#include "move.h"
#include "pseudoMoves.h"
#include "boardStates.h"
#include <map>
#include <string>
#include "draw_board.h"
std::string getMoveString(const Square_pair& move);
unsigned long long Perft(int depth, int tempBoard[120], int colour, Castling& castling, std::vector<boardState>& boardStates, std::map<std::string, unsigned long long>& moveCounts, int currentDepth = 0, std::string currentMove = "");


