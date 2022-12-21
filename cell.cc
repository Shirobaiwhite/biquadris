#include "cell.h"
#include "block.h"
#include "graphicdisplay.h"
#include <iostream>
using namespace std;

Cell::Cell(int x, int y, graphicDisplay *g): x{x}, y{y}, 
parent{nullptr}, graph{g} {}

bool Cell::isFilled() {
	if (parent) {
		return true;
	}
	else {
		return false;
	}
}


void Cell::setUnfilled() {
	parent = nullptr;
}

void Cell::undraw() {
	if (graph != nullptr) {
		graph->undraw(this);
	}
}

void Cell::setFilled(Block *b) {
	if (!parent) {
		parent = b;
	}
}

void Cell::draw() {
	if (graph != nullptr) {
		graph->draw(this);
	}
}

char Cell::getChar() {
	if (parent) {
		return parent->getType();
	}
	else {
		return ' ';
	}
}

int Cell::getx() {
	return x;
}

int Cell::gety() {
	return y;
}

Block *Cell::getParent() {
	return parent;
}
