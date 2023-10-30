#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Square_pair.h"
Square_pair input();
std::string get_input();
void handle_input(const std::string &str, int& sq1, int& sq2);
bool input_error_check(const std::string& str);