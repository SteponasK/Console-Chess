//#include "board.h"
#include "pseudoMoves.h"
#include "Square_pair.h"
#include <iostream>
std::vector<Square_pair> calculatePseudoMoves(int array[], int colour) {
    // colour needs to be 1 - White, -1 - Black
    std::vector<Square_pair> PseudoLegalMoves;
    // Container PseudoLegalMoves;
    int flag = colour ? 1 : 0;
    for (int i = 0; i < 120; ++i) {
        std::vector<Square_pair> newMoves;
        if (colour == 1) {
            //std::cout << "\n White colour switch\n";
            switch (array[i]) {
                
            case -99:
                break;
            case 0:
                break;
            case 1:
                
                newMoves = PAWNpseudoMoves(i,  array, colour);
                std::cout << "Pawn pseudo move L: " << newMoves.size() << std::endl;
                break;
            case 2:
                
                 newMoves= ROOKpseudoMoves(i,  array,  colour);
                 std::cout << "Rook pseudo move L: " << newMoves.size() << std::endl;
                break;
            case 3:
                 newMoves= KNIGHTpseudoMoves(i, array, colour);
                 std::cout << "Knight pseudo move L: " << newMoves.size() << std::endl;
                break;
            case 4:
                 newMoves= BISHOPpseudoMoves(i, array, colour);
                 std::cout << "Bishop pseudo move L: " << newMoves.size() << std::endl;
                break;
            case 5:
                 newMoves= QUEENpseudoMoves(i, array, colour);
                 std::cout << "Queen pseudo move L: " << newMoves.size() << std::endl;
                break;
            case 6:
                 newMoves= KINGpseudoMoves(i, array, colour);
                 std::cout << "KING pseudo move L: " << newMoves.size() << std::endl;
                break;
            }
        }
        else if(colour == -1){
            /*std::cout << "\n Black colour switch\n";*/
            switch (array[i]) {
               
            case -99:
                break;
            case 0:
                break;
            case -1:
                 newMoves= PAWNpseudoMoves(i,  array,  colour);
                 std::cout << "Pawn pseudo move L: " << newMoves.size() << std::endl;
                break;
            case -2:
                 newMoves= ROOKpseudoMoves(i,  array,  colour);
                 std::cout << "Rook pseudo move L: " << newMoves.size() << std::endl;
                break;
            case -3:
                 newMoves = KNIGHTpseudoMoves(i,  array,  colour);
                 std::cout << "Knight pseudo move L: " << newMoves.size() << std::endl;
                break;
            case -4:
                 newMoves= BISHOPpseudoMoves(i,  array,  colour);
                 std::cout << "Bishop pseudo move L: " << newMoves.size() << std::endl;
                break;
            case -5:
                 newMoves= QUEENpseudoMoves(i,  array,  colour);
                 std::cout << "Queen pseudo move L: " << newMoves.size() << std::endl;
                break;
            case -6:
                 newMoves= KINGpseudoMoves(i,  array,  colour);
                 std::cout << "KING pseudo move L: " << newMoves.size() << std::endl;
                break;
            }
        }
        PseudoLegalMoves.insert(PseudoLegalMoves.end(), newMoves.begin(), newMoves.end());
    }
    return PseudoLegalMoves;
}
std::vector<Square_pair> ROOKpseudoMoves(int square, int array[], int colour) {
    // colour 1 - white, colour -1 = black
  /*  std::cout << "rook pseudo move fncx called";*/
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
                 break;
                 //std::cout << "rooked poped out\n";
            }
            else if ((array[newSquare] * colour) < 0) { // not same colour (we can't move throught the piece)
                break;
            }
            newSquare += moveDirections[i];
        }
    }
    /*for (const auto& move : pseudoMoves) {
        std::cout << move.sq2 << std::endl;
    }*/
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
                 break;
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
                 break;
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
    //for (const auto& move : pseudoMoves) {
    //    std::cout << "King move: " << move.sq2 << std::endl;
    //}
    //std::cout << "      King square: " << square << std::endl;
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
    /*for (const auto& move : pseudoMoves) {
        std::cout << "Knight move: " << move.sq2 << std::endl;
    }*/
    return pseudoMoves;
}
std::vector<Square_pair>PAWNpseudoMoves(int square, int array[], int colour) {
    std::vector<Square_pair> pseudoMoves;
    int moveDirections[] = {
              { -20 },
    { -11 }, { -10 },  { -9 },
    };
    if (colour == -1) {// black
        for (int i = 0; i < 4; ++i)
            moveDirections[i] *= -1;
    }
    //for (int i = 0; i < 4; ++i) // CHANGED CORRECTLy
    //    std::cout << moveDirections[i] << std::endl;

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
        if (colour == 1) {
            //std::cout << "      Colour is white\n";
            //std::cout << "      Curr square: " << square << std::endl;
            //std::cout << "      Square-10: " << array[square - 10] << std::endl;
            if ((square >= 81 && square <= 88) && array[square - 10] == 0) {
                pseudoMoves.push_back({ square, newSquare });
            }
        }
        else {
            if ((square >= 31 && square <= 38) && array[square + 10] == 0)
                pseudoMoves.push_back({ square, newSquare });
        }
    }
    newSquare = square + moveDirections[2]; // 1 square move
    if (array[newSquare] == 0) {
        pseudoMoves.push_back({ square, newSquare });
    }
    /*for (auto const& move : pseudoMoves) {
        std::cout << "Pawn move: " << move.sq2 << std::endl;
    }*/
    return pseudoMoves;
}