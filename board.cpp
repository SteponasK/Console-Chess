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

bool Board::handleMove(const Square_pair& move) {
	updateKingPositions();
	updateCastling();
	
	std::vector<Square_pair> pseudoMoves = getPseudoMoves(move.sq1, whiteTurn);

	if (!moveExists(move, pseudoMoves))
		return 0;

	std::array<int, 120> tempBoard = board;
	movePieces(move, tempBoard); // Move the pieces on tempBoard
	
	if (isKingInCheck(tempBoard, -whiteTurn)) {
		return 0;
	}
	movePieces(move);

	return 1;
}

bool Board::isKingInCheck(const std::array<int, 120>& currentBoard, const bool colour) {// True - change colour
	std::vector<Square_pair> pseudoMoves = getPseudoMoves(currentBoard, colour); // get enemies pseudo moves (squares they control)
	
	for (const Square_pair& movePair : pseudoMoves) {
		if (colour == 1) {
			if (movePair.sq2 == wKing)
				return 1;
		}
		else {
			if (movePair.sq2 == bKing)
				return 1;
		}
		
	}
	return 0;
}
bool  Board::isKingInCheck(const int colour) { 
	std::vector<Square_pair> pseudoMoves = getPseudoMoves(colour);
	return 0;
}
bool Board::moveExists(const Square_pair& originalMove, const std::vector<Square_pair>& pseudoMoves) {
	for (const Square_pair& movePair : pseudoMoves) {
		if (originalMove == movePair)
			return 1;
	}
	return 0;
}
void Board::updateCastling() {/*Done*/
	// CastleOFF - Can't even castle that side
	// Castle = false, castling is legal, but not allowed under these circumstances.

	boardState currentBoard = boardStates.back();
	auto previousIterator = boardStates.end() - 1;
	boardState previousBoard = *previousIterator;

	// ROOKS AND KING MOVED CHECKING:
	int bRooka = 21;
	int bRookh = 28;
	int wRooka = 91;
	int wRookh = 98;

	// If currently rooks are not in their default squares
	if (currentBoard.array[bRooka] != -2) {
		castling.blackLongCastleOFF = true;
	}
	if (currentBoard.array[bRookh] != -2) {
		castling.blackShortCastleOFF = true;
	}
	if (currentBoard.array[wRooka] != 2) {
		castling.whiteLongCastleOFF = true;
	}
	if (currentBoard.array[wRookh] != 2) {
		castling.whiteShortCastleOFF = true;
	}
	int bKing = 25;
	int wKing = 95; // If the kings are not on their squares
	if (currentBoard.array[wKing] != 6) {
		castling.whiteLongCastleOFF = true;
		castling.whiteShortCastleOFF = true;
	}
	if (currentBoard.array[bKing] != -6) {
		castling.blackLongCastleOFF = true;
		castling.blackShortCastleOFF = true;
	}

	if (boardStates.size() < 2)
		return;
	// If on the last move rooks were not in their squares
	if (previousBoard.array[bRooka] != -2) {
		castling.blackLongCastleOFF = true;
	}
	if (previousBoard.array[bRookh] != -2) {
		castling.blackShortCastleOFF = true;
	}
	if (previousBoard.array[wRooka] != 2) {
		castling.whiteLongCastleOFF = true;
	}
	if (previousBoard.array[wRookh] != 2) {
		castling.whiteShortCastleOFF = true;
	}
	// If on the last move kings were not on there squares
	if (previousBoard.array[wKing] != 6) {
		castling.whiteLongCastleOFF = true;
		castling.whiteShortCastleOFF = true;
	}
	if (previousBoard.array[bKing] != -6) {
		castling.blackLongCastleOFF = true;
		castling.blackShortCastleOFF = true;
	}
}
std::vector<Square_pair> Board::getPseudoMoves(const int colour) {
	return {};
}
std::vector<Square_pair> Board::getPseudoMoves(const int piece, const int colour) {/*Done*/ // DO THIS RN
	std::vector<Square_pair> PseudoLegalMoves;
	switch (board[piece]){
	case -99:
		break;
	case 0:
		break;
	case 1:
		//PseudoLegalMoves = PAWNpseudoMoves(square, array, colour, boardStates);
		break;
	case 2:
		//PseudoLegalMoves = ROOKpseudoMoves(square, array, colour);
		break;
	case 3:
		//PseudoLegalMoves = KNIGHTpseudoMoves(square, array, colour);
		break;
	case 4:
		//PseudoLegalMoves = BISHOPpseudoMoves(square, array, colour);
		break;
	case 5:
		//PseudoLegalMoves = QUEENpseudoMoves(square, array, colour);
		break;
	case 6:
		//PseudoLegalMoves = KINGpseudoMoves(square, array, colour, castling, boardStates);
		break;
	case -1:
		//PseudoLegalMoves = PAWNpseudoMoves(square, array, colour, boardStates);
		break;
	case -2:
		//PseudoLegalMoves = ROOKpseudoMoves(square, array, colour);
		break;
	case -3:
		//PseudoLegalMoves = KNIGHTpseudoMoves(square, array, colour);
		break;
	case -4:
		//PseudoLegalMoves = BISHOPpseudoMoves(square, array, colour);
		break;
	case -5:
		//PseudoLegalMoves = QUEENpseudoMoves(square, array, colour);
		break;
	case -6:
		//PseudoLegalMoves = KINGpseudoMoves(square, array, colour, castling, boardStates);
		break;
	default:
		break;
}
	return PseudoLegalMoves;
}
std::vector<Square_pair> Board::getPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour) {
	return {};
}
std::vector<Square_pair> Board::getPseudoMoves(const std::array<int, 120>& currentBoard, const int colour) {
	return {};
}
void Board::movePieces(const Square_pair& move) { // pervadinti i MovePair

}
void Board::movePieces(const Square_pair& move, std::array<int, 120>& currentBoard) {

}
void Board::updateKingPositions() {// Done 
	std::vector<int> moveDirections = { {0},
		{ -11 }, { -10 },  { -9 },
 { -2 }, { -1 },            { +1 }, { +2 },
		{ +9 },  { +10 },  { +11 }
	};
	for (const int& direction : moveDirections) {
		int newPosition = wKing + direction;
		if (board[newPosition] == 6) {
			wKing = newPosition;
			break;
		}
			
	}
	for (const int& direction : moveDirections) {
		int newPosition = bKing + direction;
		if (board[newPosition] == -6) {
			bKing = newPosition;
			break;
		}
			
	}
	
} 
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