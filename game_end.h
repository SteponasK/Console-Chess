#ifndef GAME_END_H
#define GAME_END_H

//#include "move.h"
struct GameEnd
{
	bool whiteCheckmated = false;
	bool blackCheckmated = false;
	bool stalemate = false;
};
bool gameOver(GameEnd game);

#endif // !GAME_END_H
