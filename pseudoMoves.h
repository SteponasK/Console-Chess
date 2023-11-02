#ifndef PSEUDOMOVES_H
#define PSEUDOMOVES_H
#include <vector>
#include "Square_pair.h"
#include "castling.h"
#include "boardStates.h"
#include "Square_pair.h"
#include <iostream>

void checkCastlingPiecesMovement(std::vector<boardState> boardStates, Castling& castling, const int colour);
std::vector<Square_pair> calculatePseudoMoves(int array[], int colour, Castling& castling, std::vector<boardState>& boardStates);
std::vector<Square_pair> calculatePseudoMovesSolo(int array[], int colour, Square_pair move, Castling& castling, std::vector<boardState>& boardStates);
std::vector<Square_pair> ROOKpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair> BISHOPpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair> QUEENpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair> KINGpseudoMoves(int square, int array[], int colour, Castling& castling, std::vector<boardState>& boardStates);
std::vector<Square_pair> KNIGHTpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair>PAWNpseudoMoves(int square, int array[], int colour, std::vector<boardState>& boardStates);
#endif // !PSEUDOMOVES_H

