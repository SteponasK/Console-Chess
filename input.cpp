#include "input.h"
#include "Square_pair.h"
Square_pair input() {
    std::string str;
    do { str = get_input(); } while (!input_error_check(str));
	int sq1 = 0;
	int sq2 = 0;
	handle_input(str, sq1, sq2);
	return { sq1, sq2 };
}
std::string get_input() {
	std::cout << "Type in your move (example: a2 a4)\n";
	std::string str;
	std::getline(std::cin, str);
	return str;
}
bool input_error_check(const std::string& str) {
    if (str.length() != 5)
        return false;
    return true;
}
void handle_input(const std::string& str, int& sq1, int& sq2) {

    const std::string col = " abcdefgh";

    char char1 = str[0];
    char char2 = str[3];
    char num1 = str[1];
    char num2 = str[4];

    int colIndex1 = col.find(char1);
    int colIndex2 = col.find(char2);
    // Convert to char
    int row1 = num1 - '0'; 
    int row2 = num2 - '0'; 
    //calculate indexes
    sq1 = 100 - (10 * row1) + colIndex1;
    sq2 = 100 -(10 * row2) + colIndex2;
}
