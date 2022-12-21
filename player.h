#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "board.h"
#include <iostream>
#include <string>

class Player {
	Board *b;
	std::string name;
	int highscore;

public:
	Player(Board *b, std::string name);
	~Player();
	int getHighscore();
	void update();
	std::string getName();
};

#endif
