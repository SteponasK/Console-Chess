#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <algorithm>
#include "Square_pair.h"
#include <array>
Square_pair input(const int whiteTurn, const std::array<int, 120> currBoard);
std::string get_input();
void handle_input(const std::string &str, int& sq1, int& sq2);
bool input_error_check(const std::string& str);
bool check_turn(int whiteTurn, const int sq1, const std::array<int, 120> currBoard);

#endif // !INPUT_H