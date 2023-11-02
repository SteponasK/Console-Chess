#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Square_pair.h"

#include <iostream>
Square_pair input(const bool whiteTurn, const int currBoard[120]);
std::string get_input();
void handle_input(const std::string &str, int& sq1, int& sq2);
bool input_error_check(const std::string& str);
bool check_turn(bool whiteTurn, const int sq1, const int currBoard[120]);