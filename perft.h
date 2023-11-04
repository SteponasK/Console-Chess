#ifndef  PERFT_H
#define PERFT_H
#include "Square_pair.h"
#include <string>
#include <iostream>
#include <map>
#include "board.h"
std::string getMoveString(const Square_pair& move);

unsigned long long Perft(Board perftBoard, int depth, std::array<int, 120> tempBoard, int colour, Castling& castling,
    std::vector<boardState>& boardStates, std::map<std::string, // prie array pass by reference gal
    unsigned long long>& moveCounts, int currentDepth = 0, std::string currentMove = "");
#endif // ! PERFT_H


