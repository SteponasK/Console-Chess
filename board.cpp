#include "board.h"
int board[120] = { // 10x12 Board
    -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99,
    -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99,
    -99,    -2,  -3,  -4,  -5,  -6,  -4,  -3,  -2,   -99,
    -99,    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   -99,
    -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99,
    -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99,
    -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99,
    -99,     0,   0,   0,   0,   0,   0,   0,   0,   -99,
    -99,     1,   1,   1,   1,   1,   1,   1,   1,   -99,
    -99,     2,   3,   4,   5,   6,   4,   3,   2,   -99,
    -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99,
    -99,   -99, -99, -99, -99, -99, -99, -99, -99,   -99
};
void Board::drawBoard(const int currBoard[120]) {
	
	std::cout << "     a   b   c   d   e   f   g   h\n";
	std::cout << "   +---+---+---+---+---+---+---+---+\n";
	int count = 8;
	for (int i = 21; i < 100; ++i) {
		if (i % 10 == 1) std::cout << ' ' << count << " |";
		std::cout << " ";
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
			std::cout << "error";
			break;
		}
		std::cout << " |";

		if (i % 10 == 8) {
			i += 2;
			std::cout << " " << count;
			std::cout << "\n   +---+---+---+---+---+---+---+---+\n";
			--count;
		}
	}
	std::cout << "     a   b   c   d   e   f   g   h\n\n";
}
void Board::drawBoard() {

	std::cout << "     a   b   c   d   e   f   g   h\n";
	std::cout << "   +---+---+---+---+---+---+---+---+\n";
	int count = 8;
	for (int i = 21; i < 100; ++i) {
		if (i % 10 == 1) std::cout << ' ' << count << " |";
		std::cout << " ";
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
			std::cout << "error";
			break;
		}
		std::cout << " |";

		if (i % 10 == 8) {
			i += 2;
			std::cout << " " << count;
			std::cout << "\n   +---+---+---+---+---+---+---+---+\n";
			--count;
		}
	}
	std::cout << "     a   b   c   d   e   f   g   h\n\n";
}
void Board::updateBoardState(boardState& currentBoard) {
	boardStates.push_back(currentBoard);
}
bool Board::handleMove(const Square_pair& move) {
	//updateKingPosition
	updateCastling();
	
	std::vector<Square_pair> pseudoMoves = getPseudoMoves(move.sq1);

	if (!moveExists(move, pseudoMoves))
		return 0;

	std::array<int, 120> tempBoard = board;
	/*if (isKinginCheck(tempBoard)) {
		return 0;
	}*/

	//movePieces(move);
	
	//std::vector<Square_pair> pseudoMoves = calculatePseudoMovesSolo(currBoard, colour, move, castling, boardStates);
	return 1;
}
bool Board::isKingInCheck(const std::array<int, 120>& currentBoard) {

}
bool Board::moveExists(const Square_pair& originalMove, const std::vector<Square_pair>& PseudoMoves) {
	for (const Square_pair& currentMove : PseudoMoves) {
		if (originalMove == currentMove)
			return 1;
	}
	return 0;
}
void Board::updateCastling() {

}
std::vector<Square_pair> Board::getPseudoMoves() {
	return {};
}
std::vector<Square_pair> Board::getPseudoMoves(const int piece) {
	return {};
}
void Board::movePieces(const Square_pair& move) { // pervadinti i SquarePiece

}
void Board::updateKingPositions() {
	
}