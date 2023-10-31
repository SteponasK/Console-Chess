#ifndef PSEUDOMOVES_H
#define PSEUDOMOVES_H
#include <vector>
#include "Square_pair.h"
//struct Move {
//    int startIndex;
//    int endIndex; 
//};
std::vector<Square_pair> calculatePseudoMoves(int array[], int colour);
std::vector<Square_pair> calculatePseudoMovesSolo(int array[], int colour, Square_pair move);
std::vector<Square_pair> ROOKpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair> BISHOPpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair> QUEENpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair> KINGpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair> KNIGHTpseudoMoves(int square, int array[], int colour);
std::vector<Square_pair>PAWNpseudoMoves(int square, int array[], int colour);
#endif 

