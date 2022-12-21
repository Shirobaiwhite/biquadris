#include "block.h"
using namespace std;

Block::Block(int level, char type): theBlock{}, level{level}, direct{1}, size{0},
type{type} {}

Block::~Block() {
	for (auto &c: theBlock) {
		c->setUnfilled();
	}
}

char Block::getType() {
	return type;
}

void Block::setBlock(vector<Cell *> &newBlock) {
	for (auto &c: theBlock) {
		c->setUnfilled();
		theBlock.clear();
	}
	for (auto &c: newBlock) {
		theBlock.emplace_back(c);
	}
	setRelation();
	size = newBlock.size();
}

void Block::draw() {
	for (auto &c: theBlock) {
		c->draw();
	}
}

void Block::undraw() {
	for (auto &c: theBlock) {
		c->undraw();
	}
}

void Block::setType(char newType) {
	type = newType;
}

bool Block::isInBlock(Cell *c) {
	for (auto &cell: theBlock) {
		if (cell != c) {
			return false;
		}
	}
	return true;
}


int Block::getLevel() {
	return level;
}


Cell *Block::getCell(int pos) {
	return theBlock[pos];
}

int Block::getDirect() {
	return direct;
}

void Block::rmCell(Cell *c) {
	int pos = 0;
	for (auto &cell: theBlock) {
		if (c == cell) {
			theBlock.erase(theBlock.begin() + pos);
			c->setUnfilled();
			c->undraw();
			size -= 1;
			return;
		} else {
			pos += 1;
		}
	}
}

void Block::setRelation() {
	for (auto &c: theBlock) {
		c->setFilled(this);
	}
}

void Block::changeDirect() {
	if (direct == 4) {
		direct = 1;
	}
	else {
		direct += 1;
	}
}

int Block::getSize() {
	return size;
}


