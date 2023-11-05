#pragma once
#include "board.h"
#include "perft.h"
#include "minimax.h"
#include "input.h"
#include <Windows.h>
void gamePVP(Board& testBoard, Square_pair& square_pair);
void gamePVE(Board& testBoard, Square_pair& square_pair, const int choice);
void gameEVE(Board& testBoard, Square_pair& square_pair);
int chooseTurn();
void startGame(Board& testBoard);