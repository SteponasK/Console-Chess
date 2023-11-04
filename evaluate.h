#ifndef  EVALUATE_H
#define EVALUATE_H
#include "board.h"
struct PieceValues
{
	static constexpr int pawnValue = 100;
	static constexpr int kingValue = 100;
};



int countMaterial(const std::array<int, 120>& board, const int colour);
int evaluate(const std::array<int, 120>& board);
#endif // ! EVALUATE_H

