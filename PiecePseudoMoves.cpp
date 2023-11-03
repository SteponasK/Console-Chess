#include "board.h"
#include <vector>
std::vector<Square_pair> Board::getPawnPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
              { -20 },
    { -11 }, { -10 },  { -9 },
    };
    if (colour == -1) { // Move directions have to be changed for the black piece.
        for (int& direction : moveDirections)
            direction *= -1;
    }
    // [1] and [3] index are captures 
    int newSquare = piece + moveDirections[1];
    if (currentBoard[newSquare] * colour < 0 && currentBoard[newSquare] != -99) { // Different colour square.
        pseudoMoves.push_back({ piece, newSquare });
    }
    newSquare = piece + moveDirections[3];
    if (currentBoard[newSquare] * colour < 0 && currentBoard[newSquare] != -99) { // Different colour square.
        pseudoMoves.push_back({ piece, newSquare });
    }

    newSquare = piece + moveDirections[0]; // 2 Square Move
    if (currentBoard[newSquare] == 0 && currentBoard[newSquare] != -99) {
        if (colour == 1) {
            if ((piece >= 81 && piece <= 88) && currentBoard[piece - 10] == 0) {
                pseudoMoves.push_back({ piece, newSquare });
            }
        }
        else {
            if ((piece >= 31 && piece <= 38) && currentBoard[piece + 10] == 0)
                pseudoMoves.push_back({ piece, newSquare });
        }
    }
    newSquare = piece + moveDirections[2]; // 1 Square move
    if (currentBoard[newSquare] == 0) {
        pseudoMoves.push_back({ piece, newSquare });
    }

    if (boardStates.size() >= 2) {
        boardState currentBoard = boardStates.back(); // Dont know if this is alright (using same boardstates as b4)
        boardState previousBoard = boardStates[boardStates.size() - 2];
        if (colour == 1) {
            if (previousBoard.currArray[piece - 21] == -1 && previousBoard.currArray[piece - 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.currArray[piece - 21 == 0] && currentBoard.currArray[piece - 1] == -1) {
                    pseudoMoves.push_back({ piece, piece - 11 }); // En passant to the left
                }
            }
            if (previousBoard.currArray[piece - 19] == -1 && previousBoard.currArray[piece + 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.currArray[piece - 19 == 0] && currentBoard.currArray[piece + 1] == -1) {
                    pseudoMoves.push_back({ piece, piece - 9 }); // En passant to the right
                }
            }
        }
        else {
            if (previousBoard.currArray[piece + 21] == 1 && previousBoard.currArray[piece + 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.currArray[piece + 21 == 0] && currentBoard.currArray[piece + 1] == 1) {
                    pseudoMoves.push_back({ piece, piece + 11 }); // En passant to the left
                }
            }
            if (previousBoard.currArray[piece + 19] == 1 && previousBoard.currArray[piece - 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.currArray[piece + 19 == 0] && currentBoard.currArray[piece - 1] == 1) {
                    pseudoMoves.push_back({ piece, piece + 9 }); // En passant to the right
                }
            }
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getKingPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int>  moveDirections = {
    { -11 }, { -10 },  { -9 },
    { -1 },            { +1 },
    { +9 },  { +10 },  { +11 }
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        if (currentBoard[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((currentBoard[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
            }
            else if ((currentBoard[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
        }
    }
    if (colour == 1) { // Castling checks
        if (currentBoard[piece - 1] == 0 && currentBoard[piece - 2] == 0 && currentBoard[piece - 3] == 0
            && !castling.blackLongCastleOFF) {
            castling.whiteLongCastle = true;
        }
        if (currentBoard[piece + 1] == 0 && currentBoard[piece + 2] == 0
            && !castling.whiteShortCastleOFF) {
            castling.whiteShortCastle = true;
        }
    }
    if (colour == -1) {
        if (currentBoard[piece - 1] == 0 && currentBoard[piece - 2] == 0 && currentBoard[piece - 3] == 0
            && !castling.blackLongCastleOFF) {
            castling.blackLongCastle = true;
        }
        if (currentBoard[piece + 1] == 0 && currentBoard[piece + 2] == 0
            && !castling.blackShortCastleOFF) {
            castling.blackShortCastle = true;
        }
    }
    if (colour == -1) {
        if (castling.blackLongCastle && !castling.blackLongCastleOFF) {
            pseudoMoves.push_back({ piece, piece - 2 });
        }
        if (castling.blackShortCastle && !castling.blackShortCastleOFF) {
            pseudoMoves.push_back({ piece, piece + 2 });
        }
    }
    else {
        if (castling.whiteLongCastle && !castling.whiteLongCastleOFF) {
            pseudoMoves.push_back({ piece, piece - 2 });
        }
        if (castling.whiteShortCastle && !castling.whiteShortCastleOFF) {
            pseudoMoves.push_back({ piece, piece + 2 });
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getQueenPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
    { -11 }, { -10 },  { -9 },
    { -1 },            { +1 },
    { +9 },  { +10 },  { +11 }
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        while (currentBoard[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((currentBoard[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
                break;
            }
            else if ((currentBoard[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += direction;
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getRookPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
             { -10 },
    { -1 },          { +1 },
             { +10 }
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        while (currentBoard[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((currentBoard[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
                break;
            }
            else if ((currentBoard[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += direction;
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getBishopPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
    { -11 },    {  -9 },
    {  +9 },    { +11 }
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        while (currentBoard[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((currentBoard[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
                break;
            }
            else if ((currentBoard[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += direction;
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getKnightPseudoMoves(const int piece, const std::array<int, 120>& currentBoard, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
       {-21},   {-19},
    {-12},           {-8},

    {+8},            {+12},
       {+19},    {+21}
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        if (currentBoard[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((currentBoard[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
            }
        }
    }
    return pseudoMoves;
}

// Overload: currnet board:
std::vector<Square_pair> Board::getPawnPseudoMoves(const int piece, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
              { -20 },
    { -11 }, { -10 },  { -9 },
    };
    if (colour == -1) { // Move directions have to be changed for the black piece.
        for (int& direction : moveDirections)
            direction *= -1;
    }
    // [1] and [3] index are captures 
    int newSquare = piece + moveDirections[1];
    if (board[newSquare] * colour < 0 && board[newSquare] != -99) { // Different colour square.
        pseudoMoves.push_back({ piece, newSquare });
    }
    newSquare = piece + moveDirections[3];
    if (board[newSquare] * colour < 0 && board[newSquare] != -99) { // Different colour square.
        pseudoMoves.push_back({ piece, newSquare });
    }

    newSquare = piece + moveDirections[0]; // 2 Square Move
    if (board[newSquare] == 0 && board[newSquare] != -99) {
        if (colour == 1) {
            if ((piece >= 81 && piece <= 88) && board[piece - 10] == 0) {
                pseudoMoves.push_back({ piece, newSquare });
            }
        }
        else {
            if ((piece >= 31 && piece <= 38) && board[piece + 10] == 0)
                pseudoMoves.push_back({ piece, newSquare });
        }
    }
    newSquare = piece + moveDirections[2]; // 1 Square move
    if (board[newSquare] == 0) {
        pseudoMoves.push_back({ piece, newSquare });
    }

    if (boardStates.size() >= 2) {
        boardState currentBoard = boardStates.back(); // Dont know if this is alright (using same boardstates as b4)
        boardState previousBoard = boardStates[boardStates.size() - 2];
        if (colour == 1) {
            if (previousBoard.currArray[piece - 21] == -1 && previousBoard.currArray[piece - 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.currArray[piece - 21 == 0] && currentBoard.currArray[piece - 1] == -1) {
                    pseudoMoves.push_back({ piece, piece - 11 }); // En passant to the left
                }
            }
            if (previousBoard.currArray[piece - 19] == -1 && previousBoard.currArray[piece + 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.currArray[piece - 19 == 0] && currentBoard.currArray[piece + 1] == -1) {
                    pseudoMoves.push_back({ piece, piece - 9 }); // En passant to the right
                }
            }
        }
        else {
            if (previousBoard.currArray[piece + 21] == 1 && previousBoard.currArray[piece + 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.currArray[piece + 21 == 0] && currentBoard.currArray[piece + 1] == 1) {
                    pseudoMoves.push_back({ piece, piece + 11 }); // En passant to the left
                }
            }
            if (previousBoard.currArray[piece + 19] == 1 && previousBoard.currArray[piece - 1] == 0) {
                // If enemy moved to possible en passant square
                if (currentBoard.currArray[piece + 19 == 0] && currentBoard.currArray[piece - 1] == 1) {
                    pseudoMoves.push_back({ piece, piece + 9 }); // En passant to the right
                }
            }
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getKingPseudoMoves(const int piece, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int>  moveDirections = {
    { -11 }, { -10 },  { -9 },
    { -1 },            { +1 },
    { +9 },  { +10 },  { +11 }
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        if (board[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((board[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
            }
            else if ((board[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
        }
    }
    if (colour == 1) { // Castling checks
        if (board[piece - 1] == 0 && board[piece - 2] == 0 && board[piece - 3] == 0
            && !castling.blackLongCastleOFF) {
            castling.whiteLongCastle = true;
        }
        if (board[piece + 1] == 0 && board[piece + 2] == 0
            && !castling.whiteShortCastleOFF) {
            castling.whiteShortCastle = true;
        }
    }
    if (colour == -1) {
        if (board[piece - 1] == 0 && board[piece - 2] == 0 && board[piece - 3] == 0
            && !castling.blackLongCastleOFF) {
            castling.blackLongCastle = true;
        }
        if (board[piece + 1] == 0 && board[piece + 2] == 0
            && !castling.blackShortCastleOFF) {
            castling.blackShortCastle = true;
        }
    }
    if (colour == -1) {
        if (castling.blackLongCastle && !castling.blackLongCastleOFF) {
            pseudoMoves.push_back({ piece, piece - 2 });
        }
        if (castling.blackShortCastle && !castling.blackShortCastleOFF) {
            pseudoMoves.push_back({ piece, piece + 2 });
        }
    }
    else {
        if (castling.whiteLongCastle && !castling.whiteLongCastleOFF) {
            pseudoMoves.push_back({ piece, piece - 2 });
        }
        if (castling.whiteShortCastle && !castling.whiteShortCastleOFF) {
            pseudoMoves.push_back({ piece, piece + 2 });
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getQueenPseudoMoves(const int piece, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
    { -11 }, { -10 },  { -9 },
    { -1 },            { +1 },
    { +9 },  { +10 },  { +11 }
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        while (board[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((board[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
                break;
            }
            else if ((board[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += direction;
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getRookPseudoMoves(const int piece, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
             { -10 },
    { -1 },          { +1 },
             { +10 }
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        while (board[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((board[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
                break;
            }
            else if ((board[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += direction;
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getBishopPseudoMoves(const int piece, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
    { -11 },    {  -9 },
    {  +9 },    { +11 }
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        while (board[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((board[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
                break;
            }
            else if ((board[newSquare] * colour) < 0) { // Not same colour (we can't move throught the piece)
                break;
            }
            newSquare += direction;
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair> Board::getKnightPseudoMoves(const int piece, const int colour) {
    std::vector<Square_pair> pseudoMoves;
    std::vector<int> moveDirections = {
       {-21},   {-19},
    {-12},           {-8},

    {+8},            {+12},
       {+19},    {+21}
    };
    for (int direction : moveDirections) {
        int newSquare = piece + direction;
        if (board[newSquare] != -99) {
            pseudoMoves.push_back({ piece ,newSquare });
            if ((board[newSquare] * colour) > 0) { // Same colour pieces
                pseudoMoves.pop_back();
            }
        }
    }
    return pseudoMoves;
}