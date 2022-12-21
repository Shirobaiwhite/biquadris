#include "player.h"
using namespace std;

Player::Player(Board *b, string name): b{b}, name{name}, highscore{0} {}

Player::~Player() {
	delete b;
}

int Player::getHighscore() {
	return highscore;
}

void Player::update() {
	if (b->getScore() > highscore) {
		highscore = b->getScore();
	}
}

string Player::getName() {
	return name;
}
