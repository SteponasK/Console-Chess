//#include "board.h"
#include "pseudoMoves.h"
void calculatePseudoMoves(int array[], int colour) { 
    // Container PseudoLegalMoves;
    int flag = colour ? 1 : 0;
    for (int i = 0; i < 120; ++i) {
        if (colour == 1) {
            switch (array[i]) {
            case -99:
                break;
            case 0:
                break;
            case 1:
                // PseudoLegalMoves += PAWNpseudoMoves(i, int array[], int colour);
                break;
            case 2:
                // PseudoLegalMoves += ROOKpseudoMoves(i, int array[], int colour);
                break;
            case 3:
                // PseudoLegalMoves += KNIGHTpseudoMoves(i, int array[], int colour);
                break;
            case 4:
                // PseudoLegalMoves += BISHOPpseudoMoves(i, int array[], int colour);
                break;
            case 5:
                // PseudoLegalMoves += QUEENpseudoMoves(i, int array[], int colour);
                break;
            case 6:
                // PseudoLegalMoves += KINGpseudoMoves(i, int array[], int colour);
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
                // PseudoLegalMoves += PAWNpseudoMoves(i, int array[], int colour);
                break;
            case -2:
                // PseudoLegalMoves += ROOKpseudoMoves(i, int array[], int colour);
                break;
            case -3:
                // PseudoLegalMoves += KNIGHTpseudoMoves(i, int array[], int colour);
                break;
            case -4:
                // PseudoLegalMoves += BISHOPpseudoMoves(i, int array[], int colour);
                break;
            case -5:
                // PseudoLegalMoves += QUEENpseudoMoves(i, int array[], int colour);
                break;
            case 6:
                // PseudoLegalMoves += KINGpseudoMoves(i, int array[], int colour);
                break;
            }
        }
    }
    // reuturn PseudoLegalMoves
}
void ROOKpseudoMoves(int square, int array[], int colour) {
    int moveDirections[] = {
             { -10 },
    { -1 },          { +1 },
             { +10 }
    };
    for (int i = 0; i < 4; ++i) {
        int newSquare = square + moveDirections[i];
        while (array[newSquare] != -99) {
            // pseudoMoves.push_back(newSquare);
            if ((array[newSquare] * colour) > 0) { // they are the same colour
                // pseudoMoves.pop_back();
            }
            else if ((array[newSquare] * colour) < 0) { // not same colour (we can't move throught the piece)
                break;
            }
            newSquare += moveDirections[i];
        }
    }
    // return pseudoMoves
}
