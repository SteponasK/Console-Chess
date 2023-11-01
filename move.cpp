#include "move.h"
#include "previousMoves.h"
#include "Square_pair.h"
bool handleMove(Square_pair move, int currBoard[120], bool whiteTurn, std::vector<boardState>& boardStates, Castling &castling) { // https://peterellisjones.com/posts/generating-legal-chess-moves-efficiently/ -> Remove king, when generating attacked squares. Read more about capture and push mask.
	// isKingInCheck() -> if true, then 
	
	int colour = getColour(move, currBoard);
	checkCastlingPiecesMovement(boardStates, castling, colour); // Castling gets reset to default

	
	std::vector<Square_pair> pseudoMoves = calculatePseudoMovesSolo(currBoard, colour, move, castling, boardStates);
	
	// if colour = balta, and move yra from 95 i 93 tada:
	//padet karaliu i 94 93 vieta ir pazet ar butu checked
	std::cout << "SIZE OF PSEUDOMOVES: " << pseudoMoves.size() << std::endl;

	bool moveExists = false; // Handling incorrect move
	for (const auto& currMove : pseudoMoves) {
		if ((move.sq1 == currMove.sq1) && (move.sq2 == currMove.sq2)) {
			moveExists = true;
			break;
		}
	}
	if (!moveExists) {
		std::cout << "handleMove returned false: incorrect move selected\n";
		return false;
	}

	if (playMove_TEMPBOARD(move, colour, currBoard, castling, boardStates)) {
		std::cout << "MOVE is correct on the tempboard\n";
		movePieces(move, currBoard, boardStates);
		return true;
	}
	return false;
	// Calculate Pseudo Legal moves
	// If not in pseudo legal - return 0
	// Play every legal move (because i will have GUI in the future (legal moves will be displayed)
	// If that move is legal = play that move = return 1
}

bool playMove_TEMPBOARD(Square_pair move, int colour,int originalBoard[120], Castling& castling, std::vector<boardState>& boardStates) {
	int newBoard[120] = {};
	for (int i = 0; i < 120; ++i) {
		newBoard[i] = originalBoard[i];
	}
	bool newBoardChanged = false;
	if (newBoard[move.sq1] * colour == 6) {
		if (move.sq1 + 2 == move.sq2) { // Short castling
			if (isKingInCheck(originalBoard, colour, castling, boardStates)) {
				std::cout << "\nCAN'T CASTLE: KING IS IN CHECK\n";
				return 0;
			}
			// Check if move.sq1+1 isKing in check
			bool foo = movePieces({move.sq1, move.sq1+1}, newBoard, boardStates); // change fnc return type to void.
			newBoardChanged = true;
			if (isKingInCheck(newBoard, colour, castling, boardStates)) {
				std::cout << "SHORTCASTLE WOULD BE IN CHECK\n";
				return 0;
			}
		}
		if (move.sq1 - 2 == move.sq2) { // Long castling
			if (isKingInCheck(originalBoard, colour, castling, boardStates)) {
				std::cout << "\nCAN'T CASTLE: KING IS IN CHECK\n";
				return 0;
			}
			// Check if move.sq1-1  isKing in check
			bool foo = movePieces({ move.sq1, move.sq1 - 1 }, newBoard, boardStates); // change fnc return type to void.
			newBoardChanged = true;
			if (isKingInCheck(newBoard, colour, castling, boardStates)) {
				std::cout << "LONGCASTLE WOULD BE IN CHECK\n";
				return 0;
			}
		}
		// If newBoardWasChanged, we have to reset it, so we can castle
		for (int i = 0; i < 120; ++i) {
			newBoard[i] = originalBoard[i];
		}
	}
	bool foo = movePieces(move, newBoard, boardStates); // change fnc return type to void.
	if (isKingInCheck(newBoard, colour, castling, boardStates)) {
		std::cout << "TempBoard king in check\n";
		return 0;
	}
	return 1;
}
bool isKingInCheck(int currBoard[120],int colour, Castling& castling, std::vector<boardState>& boardStates) {
	int kingIndex{};
	for (int i = 0; i < 120; ++i) { // finding kingIndex
		if (currBoard[i] == 6 && colour == 1) { // White
			kingIndex = i;
			break;
		}
		if (currBoard[i] == -6 && colour == -1) { //Black
			kingIndex = i;
			break;
		}
	}
	Castling temp = castling;
	std::vector<Square_pair> pseudoMoves = calculatePseudoMoves(currBoard, -colour, temp, boardStates);
	for (const auto& move : pseudoMoves) {
		if (move.sq2 == kingIndex) {
			std::cout << "      King is in check: \n";
			std::cout << "      move.sq1: " << move.sq1 << "  move.sq2: "<< move.sq2 << std::endl;
			return true;
		}
	}



	// Calculate all enemy pieces pseudo moves
	// If includes king : king is in check
	//int newBoard[120] = currBoard[120];
	std::cout << "King is not in check\n";
	return false;
}
bool movePieces( Square_pair move, int currBoard[120], std::vector<boardState>& boardStates) {
	std::cout << "MOVE PIECES FNC";
	if (currBoard[move.sq1] == 6 || currBoard[move.sq1] == -6) {
		if (move.sq1 + 2 == move.sq2) {
			
			// Short castle
			// Rook going -2 tiles
			currBoard[move.sq2 - 1] = currBoard[move.sq2 + 1]; //Left of king = rook
			currBoard[move.sq2 + 1] = 0; // old rook pos = 0
		}
		else if (move.sq1 - 2 == move.sq2) {
			// Long castle
			// Rook going +3 tiles
			currBoard[move.sq2 + 1] = currBoard[move.sq2 - 2]; //Right of king = rook
			currBoard[move.sq2 - 2] = 0;
		}
	}
	else if (isEnPassant(move, currBoard)) {//En passant, return later
		if (currBoard[move.sq1] == 1) { // If the pawn is white == Capturing upwards
			currBoard[move.sq2 - 10] = 0;
		} // Redundant checks. WE can remove the function.
		else if (currBoard[move.sq1] == -1) {
			currBoard[move.sq2 + 10] = 0;
		}

		//return true;
	}
	currBoard[move.sq2] = currBoard[move.sq1];
	currBoard[move.sq1] = 0;

	return true; // Dont need return true. Just make this void
}
void foo() {
	// Blueprint for AI (black)
	// Get curr eval
	// Minimax fnc
	// Play highest eval move
	// Change turn 
}
int getColour(Square_pair move, const int currBoard[120]) {
	if (currBoard[move.sq1] > 0) return 1;
	// incorrect fnc. Returns board index not value
	return -1;
}
bool isEnPassant(Square_pair move, int currBoard[120]) {
	if (std::abs(move.sq1) != 1) return false; // if it's not a pawn move
	if (currBoard[move.sq2] == 0)
		return true; // pawn is capturing empty piece = must be en passant

	return false;
}
