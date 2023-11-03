#ifndef SQUARE_PAIR_H
#define SQUARE_PAIR_H

struct Square_pair {
	int sq1;
	int sq2;

	
	bool operator==(const Square_pair& otherPair) const;
};

#endif // !SQUARE_PAIR_H