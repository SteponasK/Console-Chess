//#include "board.h"
#include "pseudoMoves.h"
#include "Square_pair.h"

void calculatePseudoMoves(int array[], int colour) { 
    std::vector<Square_pair> PseudoLegalMoves;
    // Container PseudoLegalMoves;
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
                newMoves = PAWNpseudoMoves(i,  array, colour);
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
                 newMoves= KINGpseudoMoves(i, array, colour);
                break;
            }
        }
        else {
            switch (i) {
            case -99:
                break;
            case 0:
                break;
            case -1:
                 newMoves= PAWNpseudoMoves(i,  array,  colour);
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
            case 6:
                 newMoves= KINGpseudoMoves(i,  array,  colour);
                break;
            }
        }
        PseudoLegalMoves.insert(PseudoLegalMoves.end(), newMoves.begin(), newMoves.end());
    }
    // reuturn PseudoLegalMoves
}
std::vector<Square_pair> ROOKpseudoMoves(int square, int array[], int colour) {
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
            if ((array[newSquare] * colour) > 0) { // they are the same colour
                 pseudoMoves.pop_back();
            }
            else if ((array[newSquare] * colour) < 0) { // not same colour (we can't move throught the piece)
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
            if ((array[newSquare] * colour) > 0) { // they are the same colour
                 pseudoMoves.pop_back();
            }
            else if ((array[newSquare] * colour) < 0) { // not same colour (we can't move throught the piece)
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
            if ((array[newSquare] * colour) > 0) { // they are the same colour
                 pseudoMoves.pop_back();
            }
            else if ((array[newSquare] * colour) < 0) { // not same colour (we can't move throught the piece)
                break;
            }
            newSquare += moveDirections[i];
        }
    }
    return pseudoMoves;
}
// Knight and Pawn / King moves needed
std::vector<Square_pair> KINGpseudoMoves(int square, int array[], int colour) {
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
            if ((array[newSquare] * colour) > 0) { // they are the same colour
                 pseudoMoves.pop_back();
            }
            else if ((array[newSquare] * colour) < 0) { // not same colour (we can't move throught the piece)
                break;
            }
        }
    }
    return pseudoMoves;
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
            if ((array[newSquare] * colour) > 0) { // they are the same colour
                 pseudoMoves.pop_back();
            }
            else if ((array[newSquare] * colour) < 0) { // not same colour (we can't move throught the piece)
                break;
            }
        }
    }
    return pseudoMoves;
}
std::vector<Square_pair>PAWNpseudoMoves(int square, int array[], int colour) {
    std::vector<Square_pair> pseudoMoves;
    int moveDirections[] = {
              { -20 },
    { -11 }, { -10 },  { -9 },
    };
    if (!colour) {// black
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

    newSquare = square + moveDirections[0]; // 2 square move
    if (array[newSquare] == 0 && array[newSquare] != -99) {
        if (colour) {
            if(array[square] == 7 && array[square-10] == 0)
                pseudoMoves.push_back({ square, newSquare });
        }
        else {
            if (array[square] == 1 && array[square + 10] == 0)
                pseudoMoves.push_back({ square, newSquare });
        }
    }
    newSquare = square + moveDirections[2]; // 1 square move
    if (array[newSquare] == 0) {
        pseudoMoves.push_back({ square, newSquare });
    }
    return pseudoMoves;
}