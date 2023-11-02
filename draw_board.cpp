#include "draw_board.h"

void draw_board() {
	std::cout << "-----------------\n|";
	int count = 8;
	for (int i = 21; i < 100; ++i) {

		switch (board[i])
		{
		case 0: std::cout << ' '; break;
		case 1: std::cout << 'P'; break;
		case 2: std::cout << 'R'; break;
		case 3: std::cout << 'N'; break;
		case 4: std::cout << 'B'; break;
		case 5: std::cout << 'Q'; break;
		case 6: std::cout << 'K'; break;
		case -1: std::cout << 'p'; break;
		case -2: std::cout << 'r'; break;
		case -3: std::cout << 'n'; break;
		case -4: std::cout << 'b'; break;
		case -5: std::cout << 'q'; break;
		case -6: std::cout << 'k'; break;
		
		default:
			std::cout << "4";
			break;
		}
		std::cout << '|';
		
		if (i % 10 == 8) {
			i += 2;
			std::cout << count<<"\n-----------------\n|";
			--count;
		}
	}
	std::cout << "a b c d e f g h\n\n";
}
void draw_board(int currBoard[120]) {
	
		std::cout << "-----------------\n|";
		int count = 8;
		for (int i = 21; i < 100; ++i) {

			switch (currBoard[i])
			{
			case 0: std::cout << ' '; break;
			case 1: std::cout << 'P'; break;
			case 2: std::cout << 'R'; break;
			case 3: std::cout << 'N'; break;
			case 4: std::cout << 'B'; break;
			case 5: std::cout << 'Q'; break;
			case 6: std::cout << 'K'; break;
			case -1: std::cout << 'p'; break;
			case -2: std::cout << 'r'; break;
			case -3: std::cout << 'n'; break;
			case -4: std::cout << 'b'; break;
			case -5: std::cout << 'q'; break;
			case -6: std::cout << 'k'; break;

			default:
				std::cout << "4";
				break;
			}
			std::cout << '|';

			if (i % 10 == 8) {
				i += 2;
				std::cout << count << "\n-----------------\n|";
				--count;
			}
		}
		std::cout << "a b c d e f g h\n\n";
}