#include "game_end.h"

bool gameOver(GameEnd game) {
	if (game.blackCheckmated || game.whiteCheckmated
		|| game.stalemate) {
		return true;
	}
	return false;
}
