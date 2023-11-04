#include "board.h"

bool Board::handleMove(const Square_pair& move) {
	updateKingPositions();
	updateCastling();
	// Baltas nori paeiti
	std::vector<Square_pair> pseudoMoves = getPseudoMoves(move.sq1, whiteTurn); // Randam balto ejimus

	if (!moveExists(move, pseudoMoves))
		return 0;
	if ( (move.sq1 + 2 == move.sq2 || move.sq1 - 2 == move.sq2) && (std::abs(board[move.sq1]) == 6)) {
		if (!canCastle(move, board, whiteTurn)) {
			return 0; // Castling legality Check
		}
	}
	
	std::array<int, 120> tempBoard = board;
	movePieces(move, tempBoard); // Move the pieces on tempBoard
	
	if (isKingInCheck(tempBoard, whiteTurn)) {
		return 0;
	}
	movePieces(move);

	return 1;
}

bool Board::isKingInCheck(const std::array<int, 120>& currentBoard, const int colour) {// True - change colour
	std::vector<Square_pair> pseudoMoves = getPseudoMoves(currentBoard, -colour); // get enemies pseudo moves (squares they control)
	int currWking = 0;
	int currBking = 0;
	for (int i = 0; i < 120; ++i) {
		if (currentBoard[i] == 6)
			currWking = i;
		if (currentBoard[i] == -6)
			currBking = i;
	}
	for (const Square_pair& movePair : pseudoMoves) {
		if (colour == 1) {
			if (movePair.sq2 == currWking)
				return 1;
		}
		else {
			if (movePair.sq2 == currBking)
				return 1;
		}
		
	}
	return 0;
}
bool  Board::isKingInCheck(const int colour) { 
	std::vector<Square_pair> pseudoMoves = getPseudoMoves(-colour); // get enemies pseudo moves (squares they control)
	// NOT IMPLEMENTED PSEUDOMOVES FNC YET
	// this fnc will be used to check if king is currently in check in main.cpp
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

	if (boardStates.size() < 2) return;
	boardState currentBoard = boardStates.back(); // Dont know if this is alright (using same boardstates as b4)
	boardState previousBoard = boardStates[boardStates.size() - 2];

	// ROOKS AND KING MOVED CHECKING:
	int bRooka = 21;
	int bRookh = 28;
	int wRooka = 91;
	int wRookh = 98;

	// If currently rooks are not in their default squares
	if (currentBoard.currArray[bRooka] != -2) {
		castling.blackLongCastleOFF = true;
	}
	if (currentBoard.currArray[bRookh] != -2) {
		castling.blackShortCastleOFF = true;
	}
	if (currentBoard.currArray[wRooka] != 2) {
		castling.whiteLongCastleOFF = true;
	}
	if (currentBoard.currArray[wRookh] != 2) {
		castling.whiteShortCastleOFF = true;
	}
	int bKingdefault = 25;
	int wKingdefault = 95; // If the kings are not on their squares
	if (currentBoard.currArray[wKingdefault] != 6) {
		castling.whiteLongCastleOFF = true;
		castling.whiteShortCastleOFF = true;
	}
	if (currentBoard.currArray[bKingdefault] != -6) {
		castling.blackLongCastleOFF = true;
		castling.blackShortCastleOFF = true;
	}

	if (boardStates.size() < 2)
		return;
	// If on the last move rooks were not in their squares
	if (previousBoard.currArray[bRooka] != -2) {
		castling.blackLongCastleOFF = true;
	}
	if (previousBoard.currArray[bRookh] != -2) {
		castling.blackShortCastleOFF = true;
	}
	if (previousBoard.currArray[wRooka] != 2) {
		castling.whiteLongCastleOFF = true;
	}
	if (previousBoard.currArray[wRookh] != 2) {
		castling.whiteShortCastleOFF = true;
	}
	// If on the last move kings were not on there squares
	if (previousBoard.currArray[wKingdefault] != 6) {
		castling.whiteLongCastleOFF = true;
		castling.whiteShortCastleOFF = true;
	}
	if (previousBoard.currArray[bKingdefault] != -6) {
		castling.blackLongCastleOFF = true;
		castling.blackShortCastleOFF = true;
	}
}
std::vector<Square_pair> Board::getPseudoMoves(const int colour) {
	return {}; // pseudoMoves implementation with the same board ->new .cpp file needed
}
std::vector<Square_pair> Board::getPseudoMoves(const int piece, const int colour) {/*Done*/ // DO THIS RN
	std::vector<Square_pair> PseudoLegalMoves;
	switch (board[piece]) {
	case -99:
		break;
	case 0:
		break;
	case 1:
		//std::vector<Square_pair> Board::getPawnPseudoMoves(const int piece, const std::array<int, 120>&currentBoard, const int colour)
		PseudoLegalMoves = getPawnPseudoMoves(piece, colour);
		//PseudoLegalMoves = PAWNpseudoMoves(square, array, colour, boardStates);
		break;
	case 2:
		//PseudoLegalMoves = ROOKpseudoMoves(square, array, colour);
		PseudoLegalMoves = getRookPseudoMoves(piece, colour);
		break;
	case 3:
		//PseudoLegalMoves = KNIGHTpseudoMoves(square, array, colour);
		PseudoLegalMoves = getKnightPseudoMoves(piece, colour);
		break;
	case 4:
		//PseudoLegalMoves = BISHOPpseudoMoves(square, array, colour);
		PseudoLegalMoves = getBishopPseudoMoves(piece, colour);
		break;
	case 5:
		//PseudoLegalMoves = QUEENpseudoMoves(square, array, colour);
		PseudoLegalMoves = getQueenPseudoMoves(piece, colour);
		break;
	case 6:
		//PseudoLegalMoves = KINGpseudoMoves(square, array, colour, castling, boardStates);
		PseudoLegalMoves = getKingPseudoMoves(piece, colour);
		break;
	case -1:
		//PseudoLegalMoves = PAWNpseudoMoves(square, array, colour, boardStates);
		PseudoLegalMoves = getPawnPseudoMoves(piece, colour);
		break;
	case -2:
		//PseudoLegalMoves = ROOKpseudoMoves(square, array, colour);
		PseudoLegalMoves = getRookPseudoMoves(piece, colour);
		break;
	case -3:
		//PseudoLegalMoves = KNIGHTpseudoMoves(square, array, colour);
		PseudoLegalMoves = getKnightPseudoMoves(piece, colour);
		break;
	case -4:
		//PseudoLegalMoves = BISHOPpseudoMoves(square, array, colour);
		PseudoLegalMoves = getBishopPseudoMoves(piece, colour);
		break;
	case -5:
		//PseudoLegalMoves = QUEENpseudoMoves(square, array, colour);
		PseudoLegalMoves = getQueenPseudoMoves(piece, colour);
		break;
	case -6:
		//PseudoLegalMoves = KINGpseudoMoves(square, array, colour, castling, boardStates);
		PseudoLegalMoves = getKingPseudoMoves(piece, colour);
		break;
	default:
		break;
	}
	return PseudoLegalMoves;
	return {};
}
std::vector<Square_pair> Board::getPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour) {
	std::vector<Square_pair> PseudoLegalMoves;
	switch (board[piece]) {
	case -99:
		break;
	case 0:
		break;
	case 1:
		PseudoLegalMoves = getPawnPseudoMoves(piece, currentBoard, colour);
		break;
	case 2:
		PseudoLegalMoves = getRookPseudoMoves(piece, currentBoard, colour);
		break;
	case 3:
		PseudoLegalMoves = getKnightPseudoMoves(piece, currentBoard, colour);
		break;
	case 4:
		PseudoLegalMoves = getBishopPseudoMoves(piece, currentBoard, colour);
		break;
	case 5:
		PseudoLegalMoves = getQueenPseudoMoves(piece, currentBoard, colour);
		break;
	case 6:
		PseudoLegalMoves = getKingPseudoMoves(piece, currentBoard, colour);
		break;
	case -1:
		PseudoLegalMoves = getPawnPseudoMoves(piece, currentBoard, colour);
		break;
	case -2:
		PseudoLegalMoves = getRookPseudoMoves(piece, currentBoard, colour);
		break;
	case -3:
		PseudoLegalMoves = getKnightPseudoMoves(piece, currentBoard, colour);
		break;
	case -4:
		PseudoLegalMoves = getBishopPseudoMoves(piece, currentBoard, colour);
		break;
	case -5:
		PseudoLegalMoves = getQueenPseudoMoves(piece, currentBoard, colour);
		break;
	case -6:
		PseudoLegalMoves = getKingPseudoMoves(piece, currentBoard, colour);
		break;
	default:
		break;
	}
	return PseudoLegalMoves;
}
std::vector<Square_pair> Board::getPseudoMoves(const std::array<int, 120>& currentBoard, const int colour) { // All pieces - custom board
	// this needed
	std::vector<Square_pair> PseudoLegalMoves;
	for (int i = 0; i < 120; ++i) {
		const int squareValue = currentBoard[i]; // in the board
		if (squareValue == -99 || squareValue == 0) continue;

		
		std::vector<Square_pair> newMoves;
		if (colour == 1) {
			switch (squareValue) {
			case 1:
				newMoves = getPawnPseudoMoves(i, currentBoard, colour);
				break;
			case 2:
				newMoves = getRookPseudoMoves(i, currentBoard, colour);
				break;
			case 3:
				newMoves = getKnightPseudoMoves(i, currentBoard, colour);
				break;
			case 4:
				newMoves = getBishopPseudoMoves(i, currentBoard, colour);
				break;
			case 5:
				newMoves = getQueenPseudoMoves(i, currentBoard, colour);
				break;
			case 6:
				newMoves = getKingPseudoMoves(i, currentBoard, colour);
				break;
			default:
				break;
			}
		}
		else {
			switch (squareValue) {
			case -1:
				//PseudoLegalMoves = PAWNpseudoMoves(square, array, colour, boardStates);
				newMoves = getPawnPseudoMoves(i, currentBoard, colour);
				break;
			case -2:
				//PseudoLegalMoves = ROOKpseudoMoves(square, array, colour);
				newMoves = getRookPseudoMoves(i, currentBoard, colour);
				break;
			case -3:
				//PseudoLegalMoves = KNIGHTpseudoMoves(square, array, colour);
				newMoves = getKnightPseudoMoves(i, currentBoard, colour);
				break;
			case -4:
				//PseudoLegalMoves = BISHOPpseudoMoves(square, array, colour);
				newMoves = getBishopPseudoMoves(i, currentBoard, colour);
				break;
			case -5:
				//PseudoLegalMoves = QUEENpseudoMoves(square, array, colour);
				newMoves = getQueenPseudoMoves(i, currentBoard, colour);
				break;
			case -6:
				//PseudoLegalMoves = KINGpseudoMoves(square, array, colour, castling, boardStates);
				newMoves = getKingPseudoMoves(i, currentBoard, colour);
				break;
			default:
				break;
			}
		}
		
		PseudoLegalMoves.insert(PseudoLegalMoves.end(), newMoves.begin(), newMoves.end()); // could be bad insert
		
	}
	return PseudoLegalMoves;
}
void Board::movePieces(const Square_pair& move) { // pervadinti i MovePair
	//std::cout << "MOVE PIECES FNC";
	if (board[move.sq1] == 6 || board[move.sq1] == -6) {
		if (move.sq1 + 2 == move.sq2) {

			// Short castle
			// Rook going -2 tiles
			board[move.sq2 - 1] = board[move.sq2 + 1]; //Left of king = rook
			board[move.sq2 + 1] = 0; // old rook pos = 0
		}
		else if (move.sq1 - 2 == move.sq2) {
			// Long castle
			// Rook going +3 tiles
			board[move.sq2 + 1] = board[move.sq2 - 2]; //Right of king = rook
			board[move.sq2 - 2] = 0;
		}
	}
	else if (std::abs(board[move.sq1]) == 1 && board[move.sq2] == 0 && (move.sq2 % 10 != move.sq1 % 10)) { //En passant

		if (board[move.sq1] == 1) { // If the pawn is white == Capturing upwards
			board[move.sq2 + 10] = 0;
		}
		else if (board[move.sq1] == -1) {
			board[move.sq2 - 10] = 0;
		}
	}
	board[move.sq2] = board[move.sq1];
	board[move.sq1] = 0;
}
void Board::movePieces(const Square_pair& move, std::array<int, 120>& currentBoard) {
	//std::cout << "MOVE PIECES FNC";
	if (currentBoard[move.sq1] == 6 || currentBoard[move.sq1] == -6) {
		if (move.sq1 + 2 == move.sq2) {

			// Short castle
			// Rook going -2 tiles
			currentBoard[move.sq2 - 1] = currentBoard[move.sq2 + 1]; //Left of king = rook
			currentBoard[move.sq2 + 1] = 0; // old rook pos = 0
		}
		else if (move.sq1 - 2 == move.sq2) {
			// Long castle
			// Rook going +3 tiles
			currentBoard[move.sq2 + 1] = currentBoard[move.sq2 - 2]; //Right of king = rook
			currentBoard[move.sq2 - 2] = 0;
		}
	}
	else if (std::abs(currentBoard[move.sq1]) == 1 && currentBoard[move.sq2] == 0 && (move.sq2 % 10 != move.sq1 % 10)) { //En passant

		if (currentBoard[move.sq1] == 1) { // If the pawn is white == Capturing upwards
			currentBoard[move.sq2 + 10] = 0;
		}
		else if (currentBoard[move.sq1] == -1) {
			currentBoard[move.sq2 - 10] = 0;
		}
	}
	currentBoard[move.sq2] = currentBoard[move.sq1];
	currentBoard[move.sq1] = 0;
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
void Board::updateBoardState() {
	boardState tempBoard;
	tempBoard.currArray = board;
	boardStates.push_back(tempBoard);
}
void Board::updateGameStatus() {
	
	std::vector<Square_pair> pseudoMoves = getPseudoMoves(board, whiteTurn);
	for (const Square_pair& move : pseudoMoves) {
		if ((move.sq1 + 2 == move.sq2 || move.sq1 - 2 == move.sq2) && (std::abs(board[move.sq1]) == 6)){
			if (!canCastle(move, board, whiteTurn)) {
				continue;
			}
		}
		std::array<int, 120> tempBoard = board;
		movePieces(move, tempBoard); // Move the pieces on tempBoard

		if (!isKingInCheck(tempBoard, whiteTurn)) {
			return;
		}
	}
	if (!isKingInCheck(board, whiteTurn)) {
		// If king has no legal moves, but is not in check
		stalemate = true;
	}
	else if (whiteTurn == 1) { // If king in check, and colour is white
		whiteCheckmated = true;
	}
	else blackCheckmated = true;
}
bool Board::canCastle(const Square_pair& move, const std::array<int, 120>& currentBoard, const int whiteTurn) {
	if (move.sq1 + 2 == move.sq2) {
		std::array<int, 120> tempBoard = currentBoard;
		if (isKingInCheck(tempBoard, whiteTurn)) {
			return 0; // If currently king in check - Cant castle
		}
		movePieces({ move.sq1, move.sq1 + 1 }, tempBoard);

		if (isKingInCheck(tempBoard, whiteTurn)) {
			return 0; // If square between rook and king is not safe - Cant castle
		}
	}
	else if (move.sq1 - 2 == move.sq2) {
		std::array<int, 120> tempBoard = currentBoard;
		if (isKingInCheck(tempBoard, whiteTurn)) {
			return 0; // If currently king in check - Cant castle
		}
		movePieces({ move.sq1, move.sq1 - 1 }, tempBoard);

		if (isKingInCheck(tempBoard, whiteTurn)) {
			return 0; // If square between rook and king is not safe - Cant castle
		}
	}
	return 1;
}
bool Board::gameOver() {
	if (whiteCheckmated || blackCheckmated || stalemate)
		return true;
}
void Board::changeTurn() {
	if (whiteTurn == 1) {
		whiteTurn = -1;
	}
	else whiteTurn = 1;
}
int Board::getTurn() {
	return whiteTurn;
}
std::string Board::printTurn() {
	const int turn = getTurn();
	if (turn == 1) {
		return std::string{ "White" };
	}
	else return std::string{ "Black" };
}