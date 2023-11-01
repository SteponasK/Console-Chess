#pragma once
struct Castling {
    int blackLongCastle = false; // Pseudo Legal Move = Empty Squares, both pieces had'nt moved
    int blackShortCastle = false; // Doesn't account for checks in between the squares.
    int whiteLongCastle = false;
    int whiteShortCastle = false;

    int blackLongCastleOFF = false; // Can't castle because Rook or King has moved
    int blackShortCastleOFF = false;
    int whiteLongCastleOFF = false;
    int whiteShortCastleOFF = false;
    
};