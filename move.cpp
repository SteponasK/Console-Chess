#include "move.h"

bool handleMove(Square_pair move, int currBoard[120], bool whiteTurn, std::vector<boardState>& boardStates, Castling &castling, GameEnd& game) { // https://peterellisjones.com/posts/generating-legal-chess-moves-efficiently/ -> Remove king, when generating attacked squares. Read more about capture and push mask.
	// isKingInCheck() -> if true, then 
	
	int colour = getColour(move, currBoard);
	checkCastlingPiecesMovement(boardStates, castling, colour); // Castling gets reset to default

	std::vector<Square_pair> pseudoMoves = calculatePseudoMovesSolo(currBoard, colour, move, castling, boardStates);
	bool moveExists = false; // Handling incorrect move
	for (const auto& currMove : pseudoMoves) {
		if ((move.sq1 == currMove.sq1) && (move.sq2 == currMove.sq2)) {
			moveExists = true;
			break;
		}
	}
	if (!moveExists) {
		return false;
	}

	if (playMove_TEMPBOARD(move, colour, currBoard, castling, boardStates)) {
		movePieces(move, currBoard, boardStates);
		return true;
	}
	return false;
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
				return 0;
			}
			// Check if move.sq1+1 isKing in check
			movePieces({move.sq1, move.sq1+1}, newBoard, boardStates); // change fnc return type to void.
			newBoardChanged = true;
			if (isKingInCheck(newBoard, colour, castling, boardStates)) {
				//std::cout << "SHORTCASTLE WOULD BE IN CHECK\n";
				return 0;
			}
		}
		if (move.sq1 - 2 == move.sq2) { // Long castling
			if (isKingInCheck(originalBoard, colour, castling, boardStates)) {
				return 0;
			}
			// Check if move.sq1-1  isKing in check
			movePieces({ move.sq1, move.sq1 - 1 }, newBoard, boardStates); // change fnc return type to void.
			newBoardChanged = true;
			if (isKingInCheck(newBoard, colour, castling, boardStates)) {
				return 0;
			}
		}
		// If newBoardWasChanged, we have to reset it, so we can castle
		for (int i = 0; i < 120; ++i) {
			newBoard[i] = originalBoard[i];
		}
	}
	movePieces(move, newBoard, boardStates);
	if (isKingInCheck(newBoard, colour, castling, boardStates)) {
		return 0;
	}
	return 1;
}
bool isKingInCheck(int currBoard[120],int colour, Castling& castling, std::vector<boardState>& boardStates) {
	int kingIndex{};
	for (int i = 0; i < 120; ++i) { // Finding kingIndex
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
			return true;
		}
	}

	return false;
}
void movePieces( Square_pair move, int currBoard[120], std::vector<boardState>& boardStates) {
	//std::cout << "MOVE PIECES FNC";
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
	else if (std::abs(currBoard[move.sq1]) == 1 && currBoard[move.sq2] == 0 && (move.sq2 % 10 != move.sq1 % 10)) { //En passant
		
		if (currBoard[move.sq1] == 1) { // If the pawn is white == Capturing upwards
			currBoard[move.sq2 + 10] = 0;
		} 
		else if (currBoard[move.sq1] == -1) {
			currBoard[move.sq2 - 10] = 0;
		}
	}
	currBoard[move.sq2] = currBoard[move.sq1];
	currBoard[move.sq1] = 0;
}
int getColour(Square_pair move, const int currBoard[120]) {
	if (currBoard[move.sq1] > 0) return 1;
	return -1;
}
void calculateGameEnd(int board[120], GameEnd& game,  int colour, Castling& castling, std::vector<boardState>& boardStates) {
	if (colour == 0) colour = -1; // Update the colour
	auto moves = calculatePseudoMoves(board, colour, castling, boardStates);
	
	for (const auto& move : moves) {
		if (playMove_TEMPBOARD(move, colour, board, castling, boardStates)) // If king has moves - return.
			return;
	}
	// If there are no legal moves for the king
	if (!isKingInCheck(board, colour, castling, boardStates)) {
		game.stalemate = true; // If the king is not in check
	}
	else if (colour == 1) { // Otherwise checkmate
		game.whiteCheckmated = true;
	}
	else if (colour == -1) {
		game.blackCheckmated = true;
	}
}
