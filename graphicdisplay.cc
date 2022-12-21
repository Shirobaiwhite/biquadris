#include "graphicdisplay.h"
#include "board.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

graphicDisplay::graphicDisplay(): w{375, 675} {
}

void graphicDisplay::blind() {
	w.fillRectangle(100, 225, 175, 250);
}

void graphicDisplay::unblind() {
	w.fillRectangle(100, 225, 175, 250, 0);
}

void graphicDisplay::draw(Cell *c) {
	int x, y, color;
	char type = c->getParent()->getType();
	if (type == 'I') {
		color = 2;
	}
	else if (type == 'J') {
		color = 3;
	}
	else if (type == 'L') {
		color = 4;
	}
	else if (type == 'O') {
		color = 5;
	}
	else if (type == 'S') {
		color = 6;
	}
	else if (type == 'Z') {
		color = 7;
	}
	else if (type == 'T') {
		color = 8;
	}
	x = c->getx();
	y = c->gety();
	if (x > 0 && x < 12 && y > 1 && y < 20) {
		x = 50 + 25 * (x - 1);
		y = 100 + 25 * (y - 2);
		w.fillRectangle(x, y, 25, 25, color);
	}
	if (x > 0 && x < 12 && y < 2) {
		x = 50 + 25 * (x - 1);
		y = 590 + 25 * y;
		w.fillRectangle(x, y, 25, 25, color);
	}
}

void graphicDisplay::undraw(Cell *c) {
	int x, y;
	x = c->getx();
	y = c->gety();
	if (x > 0 && x < 12 && y > 1 && y < 20) {
		x = 50 + 25 * (x - 1);
		y = 100 + 25 * (y - 2);
		w.fillRectangle(x, y, 25, 25, 0);
	}
	if (x > 0 && x < 12 && y < 2) {
		x = 50 + 25 * (x - 1);
		y = 590 + 25 * y;
		w.fillRectangle(x, y, 25, 25, 0);
	}
}

void graphicDisplay::init(string name, Board *b) {
	playerName = name;
	board = b;
	int nlevel = b->getLevel();
	string level = to_string(nlevel);
	int nscore = b->getScore();
	string score = to_string(nscore);
	w.drawBigString(50, 50, name, 1);
	w.drawString(50, 70, "Level: ", 1);
	w.drawString(100, 70, level, 1);
	w.drawString(50, 90, "Score: ", 1);
	w.drawString(100, 90, score, 1);
	w.fillRectangle(45, 95, 5, 460);
	w.fillRectangle(50, 95, 280, 5);
	w.fillRectangle(325, 100, 5, 455);
	w.fillRectangle(50, 550, 275, 5);
	w.drawString(50, 575, "NEXT:", 1);
}

void graphicDisplay::changeLevel(int level) {
	string slevel = to_string(level);
	w.fillRectangle(100, 50, 25, 25, 0);
	w.drawString(100, 70, slevel, 1);
}

void graphicDisplay::changeScore(int score) {
	string sscore = to_string(score);
	w.fillRectangle(100, 70, 25, 25, 0);
	w.drawString(100, 90, sscore, 1);
}
