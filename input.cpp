#include "input.h"

Square_pair input(const bool whiteTurn, const int currBoard[120]) {
start:
    std::cout << "start\n\n\n";
    std::string str;
    do { str = get_input(); } while (!input_error_check(str));
    int sq1 = 0;
    int sq2 = 0;
    handle_input(str, sq1, sq2);
    if (!check_turn(whiteTurn, sq1, currBoard)) {
        goto start; // incorrect input
    }
    return { sq1, sq2 };

}
bool check_turn(bool whiteTurn, const int sq1, const int currBoard[120]) {
    if (whiteTurn && (currBoard[sq1] < 1 )) {
        std::cout << "currBoard[s1] == " << currBoard[sq1] << " sq1 == " << sq1 << std::endl;
        std::cout << "check_turn returned false: incorrect sq1 colour";
        return false;
    }
    if (!whiteTurn && (currBoard[sq1] > -1)) {
        std::cout << "check_turn returned false: incorrect sq1 colour";
        std::cout << "currBoard[s1] == " << currBoard[sq1] <<" sq1 == " << sq1<< std::endl;
        return false;
    }
    return true;
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

    const std::string xStr = " abcdefgh";
    
    char char1 = str[0];
    char char2 = str[3];
    char num1 = str[1];
    char num2 = str[4];

    int x1 = xStr.find(char1);
    int x2 = xStr.find(char2);
    // Convert to char
    int y1 = num1 - '0'; 
    int y2 = num2 - '0'; 
   // std::cout << "x1 = " << x1 << std::endl;
   // std::cout << "y1 = " << y1 << std::endl;
  //  y1 = 11 - y1; // gavom: a8 11-8
  //  y2 = 11 - y2;
    //calculate indexes
    sq1 =  100 - (10 * y1) + x1;
    sq2 =  100 - (10 * y2) + x2;
    //std::cout << "sq1: " << sq1 << " sq2: " << sq2 << std::endl;
    // changed row and colindex sides
}
