#include "pseudoMoves.h"

std::vector<Square_pair> calculatePseudoMovesSolo(int array[], int colour, Square_pair move, Castling& castling, std::vector<boardState>& boardStates) {
    // colour needs to be 1 - White, -1 - Black
    std::vector<Square_pair> PseudoLegalMoves;
    int square = move.sq1; // Square index
            switch (array[square]) {
            case -99:
                break;
            case 0:
                break;
            case 1:
                PseudoLegalMoves = PAWNpseudoMoves(square, array, colour, boardStates);
                break;
            case 2:
                PseudoLegalMoves = ROOKpseudoMoves(square, array, colour);
                break;
            case 3:
                PseudoLegalMoves = KNIGHTpseudoMoves(square, array, colour);
                break;
            case 4:
                PseudoLegalMoves = BISHOPpseudoMoves(square, array, colour);
                break;
            case 5:
                PseudoLegalMoves = QUEENpseudoMoves(square, array, colour);
                break;
            case 6:
                PseudoLegalMoves = KINGpseudoMoves(square, array, colour, castling, boardStates);
                break;
            case -1:
                PseudoLegalMoves = PAWNpseudoMoves(square, array, colour, boardStates);
                break;
            case -2:
                PseudoLegalMoves = ROOKpseudoMoves(square, array, colour);
                break;
            case -3:
                PseudoLegalMoves = KNIGHTpseudoMoves(square, array, colour);
                break;
            case -4:
                PseudoLegalMoves = BISHOPpseudoMoves(square, array, colour);
                break;
            case -5:
                PseudoLegalMoves = QUEENpseudoMoves(square, array, colour);
                break;
            case -6:
                PseudoLegalMoves = KINGpseudoMoves(square, array, colour, castling, boardStates);
                break;
            default:
                break;
            }
    return PseudoLegalMoves;
}
std::vector<Square_pair> calculatePseudoMoves(int array[], int colour, Castling& castling, std::vector<boardState>& boardStates) {
    // Colour: 1 - White, -1 - Black
    std::vector<Square_pair> PseudoLegalMoves;
    int flag = colour ? 1 : 0;
    for (int i = 0; i < 120; ++i) {
        std::vector<Square_pair> newMoves;
        if (colour == 1) {
            switch (array[i]) {
                
            case -99:
                break;
            case 0:
                break;
            case 1:
                newMoves = PAWNpseudoMoves(i,  array, colour, boardStates);
                break;
            case 2:
                 newMoves= ROOKpseudoMoves(i,  array,  colour);
                break;
            case 3:
                 newMoves= KNIGHTpseudoMoves(i, array, colour);
                break;
            case 4:
                 newMoves= BISHOPpseudoMoves(i, array, colour);
                break;
            case 5:
                 newMoves= QUEENpseudoMoves(i, array, colour);
                break;
            case 6:
                 newMoves= KINGpseudoMoves(i, array, colour, castling, boardStates);
                break;
            }
        }
        else if(colour == -1){
            switch (array[i]) {
               
            case -99:
                break;
            case 0:
                break;
            case -1:
                 newMoves= PAWNpseudoMoves(i,  array,  colour, boardStates);
                break;
            case -2:
                 newMoves= ROOKpseudoMoves(i,  array,  colour);
                break;
            case -3:
                 newMoves = KNIGHTpseudoMoves(i,  array,  colour);
                break;
            case -4:
                 newMoves= BISHOPpseudoMoves(i,  array,  colour);
                break;
            case -5:
                 newMoves= QUEENpseudoMoves(i,  array,  colour);
                break;
            case -6:
                 newMoves= KINGpseudoMoves(i,  array,  colour, castling, boardStates);
                break;
            }
        }
        PseudoLegalMoves.insert(PseudoLegalMoves.end(), newMoves.begin(), newMoves.end());
    }
    return PseudoLegalMoves;
}
std::vector<Square_pair> ROOKpseudoMoves(int square, int array[], int colour) {
    // Colour 1 - White, Colour -1 = Black
    std::vector<Square_pair> pseudoMoves;
    int moveDirections[] = {
             { -10 },
    { -1 },          { +1 },
             { +10 }
    };
    for (int i = 0; i < 4; ++i) {
        int newSquare = square + moveDirections[i];
        while (array[newSquare] != -99) {
            pseudoMoves.push_back({square ,newSquare });
            if ((array[newSquare] * colour) > 0) { // Same colour pieces
                 pseudoMoves.pop_back();
                 break;
            }
            else if ((array[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += moveDirections[i];
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> BISHOPpseudoMoves(int square, int array[], int colour) {
    std::vector<Square_pair> pseudoMoves;
    int moveDirections[] = { 
    { -11 },    {  -9 },
    {  +9 },    { +11 }
    };
    for (int i = 0; i < 4; ++i) {
        int newSquare = square + moveDirections[i];
        while (array[newSquare] != -99) {
            pseudoMoves.push_back({ square ,newSquare });
            if ((array[newSquare] * colour) > 0) { // Same colour pieces
                 pseudoMoves.pop_back();
                 break;
            }
            else if ((array[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += moveDirections[i];
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> QUEENpseudoMoves(int square, int array[], int colour) {
    std::vector<Square_pair> pseudoMoves;
    int moveDirections[] = {
    { -11 }, { -10 },  { -9 },
    { -1 },            { +1 },
    { +9 },  { +10 },  { +11 }
};
    for (int i = 0; i < 8; ++i) {
        int newSquare = square + moveDirections[i];
        while (array[newSquare] != -99) {
            pseudoMoves.push_back({ square ,newSquare });
            if ((array[newSquare] * colour) > 0) { // Same colour pieces
                 pseudoMoves.pop_back();
                 break;
            }
            else if ((array[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += moveDirections[i];
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> KINGpseudoMoves(int square, int array[], int colour, Castling& castling, std::vector<boardState>& boardStates) {
    
    std::vector<Square_pair> pseudoMoves;
    int moveDirections[] = {
    { -11 }, { -10 },  { -9 },
    { -1 },            { +1 },
    { +9 },  { +10 },  { +11 }
    };
    for (int i = 0; i < 8; ++i) {
        int newSquare = square + moveDirections[i];
        if (array[newSquare] != -99) {
            pseudoMoves.push_back({ square ,newSquare });
            if ((array[newSquare] * colour) > 0) { // Same colour pieces
                 pseudoMoves.pop_back();
            }
            else if ((array[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
        }
    }
    if (colour == 1) { // Castling checks
        if (array[square - 1] == 0 && array[square - 2] == 0 && array[square - 3] == 0
            && !castling.whiteLongCastleOFF) {
            castling.whiteLongCastle = true;
        }
        if (array[square + 1] == 0 && array[square + 2] == 0
            && !castling.whiteShortCastleOFF) {
            castling.whiteShortCastle = true;
        }
    }
    if (colour == -1) {
        if (array[square - 1] == 0 && array[square - 2] == 0 && array[square - 3] == 0
            && !castling.blackLongCastleOFF) {
            castling.blackLongCastle = true;
        }
        if (array[square + 1] == 0 && array[square + 2] == 0
            && !castling.blackShortCastleOFF) {
            castling.blackShortCastle = true;
        }
    }
    if (colour == -1) {
        if (castling.blackLongCastle && !castling.blackLongCastleOFF) {
            pseudoMoves.push_back({ square, square-2 });
        }
        if (castling.blackShortCastle && !castling.blackShortCastleOFF) {
            pseudoMoves.push_back({ square, square + 2 });
        }
    }
    else {
        if (castling.whiteLongCastle && !castling.whiteLongCastleOFF) {
            pseudoMoves.push_back({ square, square - 2 });
        }
        if (castling.whiteShortCastle && !castling.whiteShortCastleOFF) {
            pseudoMoves.push_back({ square, square + 2 });
        }
    }
    return pseudoMoves;
}
void checkCastlingPiecesMovement(std::vector<boardState> boardStates, Castling& castling, const int colour) {

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
std::vector<Square_pair> KNIGHTpseudoMoves(int square, int array[], int colour) {
    std::vector<Square_pair> pseudoMoves;
    int moveDirections[] = {
       {-21},   {-19},
    {-12},           {-8},
    
    {+8},            {+12},
       {+19},    {+21}
    };
    for (int i = 0; i < 8; ++i) {
        int newSquare = square + moveDirections[i];
        if (array[newSquare] != -99) {
            pseudoMoves.push_back({ square ,newSquare });
            if ((array[newSquare] * colour) > 0) { // Same colour pieces
                 pseudoMoves.pop_back();
            }
        }
    }

    return pseudoMoves;
}
std::vector<Square_pair>PAWNpseudoMoves(int square, int array[], int colour, std::vector<boardState>& boardStates) {
    std::vector<Square_pair> pseudoMoves;
    int moveDirections[] = {
              { -20 },
    { -11 }, { -10 },  { -9 },
    };
    if (colour == -1) { // Move directions have to be changed for the black piece.
        for (int i = 0; i < 4; ++i)
            moveDirections[i] *= -1;
    }
    // [1] and [3] index are captures
    int newSquare = square + moveDirections[1]; 
    if (array[newSquare] * colour < 0 && array[newSquare] != -99){ // Different colour square.
        pseudoMoves.push_back({ square, newSquare });
    }
    newSquare = square + moveDirections[3];
    if (array[newSquare] * colour < 0 && array[newSquare] != -99) { // Different colour square.
        pseudoMoves.push_back({ square, newSquare });
    }

    newSquare = square + moveDirections[0]; // 2 Square Move
    if (array[newSquare] == 0 && array[newSquare] != -99) {
        if (colour == 1) {
            if ((square >= 81 && square <= 88) && array[square - 10] == 0) {
                pseudoMoves.push_back({ square, newSquare });
            }
        }
        else {
            if ((square >= 31 && square <= 38) && array[square + 10] == 0)
                pseudoMoves.push_back({ square, newSquare });
        }
    }
    newSquare = square + moveDirections[2]; // 1 Square move
    if (array[newSquare] == 0) {
        pseudoMoves.push_back({ square, newSquare });
    }
    if (boardStates.size() >= 2) {
        boardState currentBoard = boardStates.back();
        boardState previousBoard = boardStates[boardStates.size() - 2];
       if (colour == 1) {
            if (previousBoard.array[square - 21] == -1 && previousBoard.array[square - 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.array[square - 21 == 0] && currentBoard.array[square - 1] == -1) {
                    pseudoMoves.push_back({ square, square - 11 }); // En passant to the left
                }
            }
            if (previousBoard.array[square - 19] == -1 && previousBoard.array[square + 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.array[square - 19 == 0] && currentBoard.array[square + 1] == -1) {
                    pseudoMoves.push_back({ square, square - 9 }); // En passant to the right
                }
            }
        }
        else {
            if (previousBoard.array[square + 21] == 1 && previousBoard.array[square + 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.array[square + 21 == 0] && currentBoard.array[square + 1] == 1) {
                    pseudoMoves.push_back({ square, square + 11 }); // En passant to the left
                }
            }
            if (previousBoard.array[square + 19] == 1 && previousBoard.array[square - 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.array[square + 19 == 0] && currentBoard.array[square - 1] == 1) {
                    pseudoMoves.push_back({ square, square + 9 }); // En passant to the right
                }
            }
        }
    }
    return pseudoMoves;
}