#include "Square_pair.h"

bool Square_pair::operator==(const Square_pair& otherPair) const {
	return ((sq1 == otherPair.sq1) && (sq2 == otherPair.sq2));
}