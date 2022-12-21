#include "board.h"
#include "graphicdisplay.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

void Board::rotateI(bool cw, int times) {
	vector<Cell *> newBlock;
	int x, y;
	Cell *c;
	for (int i = 0; i < times; ++i) {
		if (cw) {
			if (cur->getDirect() == 1) {
					for (int i = 0; i < 4; ++i) {
						c = cur->getCell(i);
						x = c->getx() - i;
						y = c->gety() - 3 + i;
						newBlock.emplace_back(theBoard[y][x]);
					}
			}
			else if (cur->getDirect() == 2) {
				for (int i = 0; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 3 - i;
					y = c->gety() + 3 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 3) {
				for (int i = 0; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 3 + i;
					y = c->gety() - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else {
				for (int i = 0; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + i;
					y = c->gety() + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		else {
			if (cur->getDirect() == 1) {
					for (int i = 0; i < 4; ++i) {
						c = cur->getCell(i);
						x = c->getx() - i;
						y = c->gety() - i;
						newBlock.emplace_back(theBoard[y][x]);
					}
			}
			else if (cur->getDirect() == 2) {
				for (int i = 0; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + i;
					y = c->gety() + 3 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 3) {
				for (int i = 0; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 3 + i;
					y = c->gety() - 3 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else {
				for (int i = 0; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 3 - i;
					y = c->gety() + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			cur->setRelation();
			if (cw) {
				cur->changeDirect();
			} 
			else {
				cur->changeDirect();
				cur->changeDirect();
				cur->changeDirect();
			}
			newBlock.clear();
		} else {
			return;
		}
	}
}

void Board::rotateJ(bool cw, int times) {
	vector<Cell *> newBlock;
	int x, y;
	Cell *c;
	for (int i = 0; i < times; ++i) {
		if (cw) {
			if (cur->getDirect() == 1) {
				c = cur->getCell(0);
				x = c->getx() + 1;
				y = c->gety() - 1;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() - 3 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 2) {
				c = cur->getCell(0);
				x = c->getx() + 1;
				y = c->gety() + 2;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 3 - i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 3) {
				c = cur->getCell(0);
				x = c->getx() - 2;
				y = c->gety();
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 4) {
				c = cur->getCell(0);
				x = c->getx();
				y = c->gety() - 1;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		else {
			if (cur->getDirect() == 1) {
				c = cur->getCell(0);
				x = c->getx();
				y = c->gety() + 1;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 2) {
				c = cur->getCell(0);
				x = c->getx() - 1;
				y = c->gety() + 1;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() + 3 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 3) {
				c = cur->getCell(0);
				x = c->getx() - 1;
				y = c->gety() - 2;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 3 + i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 4) {
				c = cur->getCell(0);
				x = c->getx() + 2;
				y = c->gety();
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			cur->setRelation();
			if (cw) {
				cur->changeDirect();
			} 
			else {
				cur->changeDirect();
				cur->changeDirect();
				cur->changeDirect();
			}
			newBlock.clear();
		} else {
			return;
		}
	}
}

void Board::rotateL(bool cw, int times) {
	vector<Cell *> newBlock;
	int x, y;
	Cell *c;
	for (int i = 0; i < times; ++i) {
		if (cw) {
			if (cur->getDirect() == 1) {
				for (int i = 0; i < 3; ++i) {
					c = cur->getCell(i);
					x = c->getx() - i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				c = cur->getCell(3);
				x = c->getx() - 1;
				y = c->gety() + 1;
				newBlock.emplace_back(theBoard[y][x]);
			}
			else if (cur->getDirect() == 2) {
				for (int i = 0; i < 3; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				c = cur->getCell(3);
				x = c->getx() - 1;
				y = c->gety();
				newBlock.emplace_back(theBoard[y][x]);
			}
			else if (cur->getDirect() == 3) {
				for (int i = 0; i < 3; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				c = cur->getCell(3);
				x = c->getx();
				y = c->gety() - 2;
				newBlock.emplace_back(theBoard[y][x]);
			}
			else if (cur->getDirect() == 4) {
				for (int i = 0; i < 3; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				c = cur->getCell(3);
				x = c->getx() + 2;
				y = c->gety() + 1;
				newBlock.emplace_back(theBoard[y][x]);
			}
		}
		else {
			if (cur->getDirect() == 1) {
				for (int i = 0; i < 3; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				c = cur->getCell(3);
				x = c->getx() - 2;
				y = c->gety() - 1;
				newBlock.emplace_back(theBoard[y][x]);
			}
			else if (cur->getDirect() == 2) {
				for (int i = 0; i < 3; ++i) {
					c = cur->getCell(i);
					x = c->getx() + i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				c = cur->getCell(3);
				x = c->getx() + 1;
				y = c->gety() - 1;
				newBlock.emplace_back(theBoard[y][x]);
			}
			else if (cur->getDirect() == 3) {
				for (int i = 0; i < 3; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				c = cur->getCell(3);
				x = c->getx() + 1;
				y = c->gety();
				newBlock.emplace_back(theBoard[y][x]);
			}
			else if (cur->getDirect() == 4) {
				for (int i = 0; i < 3; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				c = cur->getCell(3);
				x = c->getx();
				y = c->gety() + 2;
				newBlock.emplace_back(theBoard[y][x]);
			}
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			cur->setRelation();
			if (cw) {
				cur->changeDirect();
			} 
			else {
				cur->changeDirect();
				cur->changeDirect();
				cur->changeDirect();
			}
			newBlock.clear();
		} else {
			return;
		}
	}
}

void Board::rotateT(bool cw, int times) {
	vector<Cell *> newBlock;
	int x, y;
	Cell *c;
	for (int i = 0; i < times; ++i) {
		if (cw) {
			if (cur->getDirect() == 1) {
				c = cur->getCell(0);
				x = c->getx() - 1;
				y = c->gety() - 1;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 2) {
				c = cur->getCell(0);
				x = c->getx() + 1;
				y = c->gety();
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() + 3 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}	
			else if (cur->getDirect() == 3) {
				c = cur->getCell(0);
				x = c->getx();
				y = c->gety();
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 3 + i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 4) {
				c = cur->getCell(0);
				x = c->getx();
				y = c->gety() + 1;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		else {
			if (cur->getDirect() == 1) {
				c = cur->getCell(0);
				x = c->getx();
				y = c->gety() - 1;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 2) {
				c = cur->getCell(0);
				x = c->getx() + 1;
				y = c->gety() + 1;
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}	
			else if (cur->getDirect() == 3) {
				c = cur->getCell(0);
				x = c->getx() - 1;
				y = c->gety();
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() - 3 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 4) {
				c = cur->getCell(0);
				x = c->getx();
				y = c->gety();
				newBlock.emplace_back(theBoard[y][x]);
				for (int i = 1; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 3 - i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			cur->setRelation();
			if (cw) {
				cur->changeDirect();
			} 
			else {
				cur->changeDirect();
				cur->changeDirect();
				cur->changeDirect();
			}
			newBlock.clear();
		} else {
			return;
		}
	}
}

void Board::rotateS(bool cw, int times) {
	vector<Cell *> newBlock;
	int x, y;
	Cell *c;
	for (int i = 0; i < times; ++i) {
		if (cw) {
			if (cur->getDirect() == 1) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() - i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 2) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() + 3 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 3) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 3 + i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 4) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		else {
			if (cur->getDirect() == 1) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 2) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() + i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 3) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() - 3 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 4) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 3 - i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			cur->setRelation();
			if (cw) {
				cur->changeDirect();
			} 
			else {
				cur->changeDirect();
				cur->changeDirect();
				cur->changeDirect();
			}
			newBlock.clear();
		} else {
			return;
		}
	}
}

void Board::rotateZ(bool cw, int times) {
	vector<Cell *> newBlock;
	int x, y;
	Cell *c;
	for (int i = 0; i < times; ++i) {
		if (cw) {
			if (cur->getDirect() == 1) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() - 3 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 2) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 1 - i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 3 - i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 3) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() + 2 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 4) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() + i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 2 + i;
					y = c->gety() - 1 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		else {
			if (cur->getDirect() == 1) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() - i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 2) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() + 1 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() + 3 - i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 3) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 1 + i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() - 3 + i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
			else if (cur->getDirect() == 4) {
				for (int i = 0; i < 2; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
				for (int i = 2; i < 4; ++i) {
					c = cur->getCell(i);
					x = c->getx() + 2 - i;
					y = c->gety() - 2 + i;
					newBlock.emplace_back(theBoard[y][x]);
				}
			}
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			cur->setRelation();
			if (cw) {
				cur->changeDirect();
			} 
			else {
				cur->changeDirect();
				cur->changeDirect();
				cur->changeDirect();
			}
			newBlock.clear();
		} else {
			return;
		}
	}
}

void Board::rotateO(bool cw, int times) {
	for (int i = 0; i < times; ++i) {
		if (cw) {
			cur->changeDirect();
		} 
		else {
			cur->changeDirect();
			cur->changeDirect();
			cur->changeDirect();
		}
	}
}

void Board::setNext(char type) {
	next = new Block{level, type};
	vector<Cell *> newBlock;
	Cell *c1;
	Cell *c2;
	Cell *c3;
	Cell *c4;
	if (type == 'I') {
    	c1 = theBoard[1][1];
   	 	c2 = theBoard[1][2];
    	c3 = theBoard[1][3];
    	c4 = theBoard[1][4];
	}
	else if (type == 'J') {
		c1 = theBoard[0][1];
   	 	c2 = theBoard[1][1];
    	c3 = theBoard[1][2];
    	c4 = theBoard[1][3];
	}
	else if (type == 'L') {
		c1 = theBoard[1][1];
   	 	c2 = theBoard[1][2];
    	c3 = theBoard[1][3];
    	c4 = theBoard[0][3];
	}
	else if (type == 'O') {
		c1 = theBoard[0][1];
   	 	c2 = theBoard[0][2];
    	c3 = theBoard[1][2];
    	c4 = theBoard[1][1];
	}
	else if (type == 'S') {
		c1 = theBoard[1][1];
   	 	c2 = theBoard[1][2];
    	c3 = theBoard[0][2];
    	c4 = theBoard[0][3];
	}
	else if (type == 'Z') {
		c1 = theBoard[0][1];
   	 	c2 = theBoard[0][2];
    	c3 = theBoard[1][2];
    	c4 = theBoard[1][3];
	}
	else if (type == 'T') {
		c1 = theBoard[1][2];
   	 	c2 = theBoard[0][1];
    	c3 = theBoard[0][2];
    	c4 = theBoard[0][3];
	}
    newBlock.emplace_back(c1);
    newBlock.emplace_back(c2);
   	newBlock.emplace_back(c3);
    newBlock.emplace_back(c4);
	next->setBlock(newBlock);
	next->draw();
}

bool Board::isOverlap(vector <Cell *> &newBlock, Block *b) {
	for (auto &c: newBlock) {
		if (c->getParent() != nullptr && c->getParent() != b) {
			return true;
		}
		if (c->getx() > 11 || c->getx() < 1) {
			return true;
		}
		if (c->gety() > 19) {
			return true;
		}
	}
	return false;
}

bool Board::lineClear(int row) {
	for (auto &c: theBoard[row]) {
		if (c->getx() > 0 && c->getx() < 12) {
			if (!c->isFilled()) {
				return false;
			}
		}
	}
	return true;
}

void Board::clearLine(int row) {
	for (auto &c: theBoard[row]) {
		if (c->getx() > 0 && c->getx() < 12) {
			c->getParent()->rmCell(c);
		}
	}
}

void Board::dropAbove(int row) {
	vector<Cell *> newBlock;
	Cell *c;
	int x, y;
	for (auto &b: blocks) {
		b->undraw();
		for (int i = 0; i < b->getSize(); ++i) {
			c = b->getCell(i);
			x = c->getx();
			y = c->gety();
			if (y < row) {
				y = y + 1;
			}
			newBlock.emplace_back(theBoard[y][x]);
		}
		if (!isOverlap(newBlock, b)) {
			b->setBlock(newBlock);
			b->draw();
		}
		newBlock.clear();
	} 
}


Board::Board(int level, string filename, int seed, graphicDisplay *g):theBoard{},
 score{0}, level{level}, state{0}, fileName0{filename}, readFilePos{0}, randomness{true},
 blocks{}, gameOver{false}, seed{seed}, graph{g} {}

Board::~Board() {
	delete cur;
	delete next;
	int bsize = blocks.size();
	for (int i = 0; i < bsize; i += 1) {
		delete blocks[i];
	}
	int colsize = theBoard.size();
	int rowsize;
	for (int i = 0; i < colsize; i += 1) {
		rowsize = theBoard[i].size();
		for (int j = 0; j < rowsize; j += 1) {
			delete theBoard[i][j];
		}
	}
}

void Board::initBoard() {
	for (int i = 0; i < 21; i += 1) {
		vector <Cell *> row;
		for (int j = 0; j < 15; j += 1) {
			Cell *c = new Cell{j, i, graph};
			row.emplace_back(c);
		}
		theBoard.emplace_back(row);
	}
	generateNext();
	cur = next;
	down(4);
	next = nullptr;
}

void Board::generateNext() {
    string file_name = fileName0;
    int templevel = level;
    if (level == 3 || level == 4) {
    	if (!randomness) {
    		file_name = fileNameRand;
    		templevel = 0;
    	}
    }
    switch(templevel) {
        case 0: {
            string type;
            string line;
            ifstream file(file_name.c_str()); //opens file (.c_str() not needed when using C++11)
            if (!file)
            {
                cout<<"Cannot open file\n";
                exit(1); // terminate with error
            }
            while (getline(file, line)) {
                type += line;
            }
            type += '\n';
            type.erase(remove(type.begin(), type.end(), ' '),type.end());
            int len = type.length();
            if (type[readFilePos] == 'I') {
                setNext('I');
            }
            else if (type[readFilePos] == 'J') {
                setNext('J');
            }
             else if (type[readFilePos] == 'L') {
                setNext('L');
            }
             else if (type[readFilePos] == 'O') {
                setNext('O');
            }
             else if (type[readFilePos] == 'S') {
                setNext('S');
            }
             else if (type[readFilePos] == 'Z') {
                setNext('Z');
            }
             else if (type[readFilePos] == 'T') {
                setNext('T');
            }
            readFilePos += 1;
            if (readFilePos == len - 1) {
             readFilePos = 0;
            }
        	break;
        }
        case 1: {
        	srand(seed);
            int rn1 = rand() % 12;
            switch(rn1) {
                case 0:
                    setNext('S');
                    break;
                case 1:
                    setNext('Z');
                    break;
                case 2: case 3:
                    setNext('I');
                    break;
                case 4: case 5:
                    setNext('J');
                    break;
                case 6: case 7:
                    setNext('L');
                    break;
                case 8: case 9:
                    setNext('O');
                    break;
                case 10: case 11:
                    setNext('T');
                    break;
            }
            break;
        }
        case 2: {
        	srand(seed);
            int rn2 = rand() % 7;
            switch(rn2) {
                case 0:
                    setNext('I');
                    break;
                case 1:
                    setNext('J');
                    break;
                case 2:
                    setNext('L');
                    break;
                case 3:
                    setNext('O');
                    break;
                case 4:
                    setNext('Z');
                    break;
                case 5:
                    setNext('S');
                    break;
                case 6:
                    setNext('T');
                    break;
            }
            break;
        }
        case 3: case 4: {
        	srand(seed);
            int rn3 = rand() % 9;
            switch(rn3) {
                case 0: case 1:
                    setNext('S');
                    break;
                case 2: case 3:
                    setNext('Z');
                    break;
                case 4:
                    setNext('I');
                    break;
                case 5:
                    setNext('J');
                    break;
                case 6:
                    setNext('L');
                    break;
                case 7:
                    setNext('O');
                    break;
                case 8:
                    setNext('T');
                    break;
            }
            break;
        }
    }
}

void Board::left(int times) {
	vector<Cell *> newBlock;
	Cell *c;
	int x, y;
	cur->undraw();
	for (int i = 0; i < times; ++i) {
		for (int j = 0; j < 4; ++j) {
			c = cur->getCell(j);
			x = c->getx() - 1;
			y = c->gety();
			newBlock.emplace_back(theBoard[y][x]);
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			newBlock.clear();
		} else {
			if (state == 1) {
				graph->blind();
			} else {
				cur->draw();
			}
			return;
		}
	}
	if (level == 3 || level == 4) {
		down();
	}
	if (state == 2) {
		if (!down(2)) {
			drop();
		} 
		else {
			cur->draw();
		}
	} 
	else {
		if (state == 1) {
			graph->blind();
		} else {
			cur->draw();
		}
	}
}

void Board::right(int times) {
	vector<Cell *> newBlock;
	Cell *c;
	int x, y;
	cur->undraw();
	for (int i = 0; i < times; ++i) {
		for (int j = 0; j < 4; ++j) {
			c = cur->getCell(j);
			x = c->getx() + 1;
			y = c->gety();
			newBlock.emplace_back(theBoard[y][x]);
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			newBlock.clear();
		} else {
			if (state == 1) {
				graph->blind();
			}
			 else {
				cur->draw();
			}
			return;
		}
	}
	if (level == 3 || level == 4) {
		down();
	}
	if (state == 2) {
		if (!down(2)) {
			drop();
		} 
		else {
			cur->draw();
		}
	} 
	else {
		if (state == 1) {
			graph->blind();
		} else {
			cur->draw();
		}
	}
}

bool Board::down(int times) {
	vector<Cell *> newBlock;
	Cell *c;
	int x, y;
	cur->undraw();
	for (int i = 0; i < times; ++i) {
		for (int j = 0; j < 4; ++j) {
			c = cur->getCell(j);
			x = c->getx();
			y = c->gety() + 1;
			newBlock.emplace_back(theBoard[y][x]);
		}
		if (!isOverlap(newBlock, cur)) {
			cur->setBlock(newBlock);
			newBlock.clear();
		} else {
			if (state == 1) {
				graph->blind();
			} else {
				cur->draw();
			}
			return false;
		}
	}
	if (state == 1) {
		graph->blind();
	} else {
		cur->draw();
	}
	return true;
}

void Board::cw(int times) {
	cur->undraw();
	if (cur->getType() == 'I') {
		rotateI(true, times);
	}
	else if (cur->getType() == 'J') {
		rotateJ(true, times);	
	}
	else if (cur->getType() == 'L') {
		rotateL(true, times);	
	}
	else if (cur->getType() == 'T') {
		rotateT(true, times);	
	}
	else if (cur->getType() == 'S') {
		rotateS(true, times);		
	}
	else if (cur->getType() == 'Z') {
		rotateZ(true, times);		
	}
	else {
		rotateO(true, times);
	}
	if (level == 3 || level == 4) {
		down();
	} else {
		if (state == 1) {
			graph->blind();
		} else {
			cur->draw();
		}
	}
}

void Board::ccw(int times) {
	cur->undraw();
	if (cur->getType() == 'I') {
		rotateI(false, times);
	}
	else if (cur->getType() == 'J') {
		rotateJ(false, times);	
	}
	else if (cur->getType() == 'L') {
		rotateL(false, times);	
	}
	else if (cur->getType() == 'T') {
		rotateT(false, times);	
	}
	else if (cur->getType() == 'S') {
		rotateS(false, times);		
	}
	else if (cur->getType() == 'Z') {
		rotateZ(false, times);		
	}
	else {
		rotateO(false, times);
	}
	if (level == 3 || level == 4) {
		down();
	} else {
		if (state == 1) {
			graph->blind();
		} else {
			cur->draw();
		}
	}
}

int Board::drop() {
	int count = 0;
	down(14);
	blocks.emplace_back(cur);
	if (state == 1) {
		graph->unblind();
		for(auto &b: blocks) {
			b->draw();
		}
	}
	state = 0;
	cur = next;
	next->undraw();
	next = nullptr;
	for (int i = 5; i < 20; ++i) {
		if (lineClear(i)) {
			clearLine(i);
			count += 1;
			Block *b;
			int bpos = 0;
			while (bpos != blocks.size()) {
				b = blocks[bpos];
				if (b->getSize() == 0) {
					delete b;
					blocks.erase(blocks.begin() + bpos);
					score = score + (b->getLevel() + 1) * (b->getLevel() + 1);
				} else {
					bpos += 1;
				}
			}
			dropAbove(i);
		}
	}
	if (count != 0) {
		score = score + (level + count) * (level + count); 
		graph->changeScore(score);
	}
	if (!down(4)) {
		gameOver = true;
	}
	return count;
}

void Board::replace(char) {

} 
void Board::levelUp() {
	if (level != 4) {
		level += 1;
		graph->changeLevel(level);
	}
}
void Board::levelDown() {
	if (level != 0) {
		level -= 1;
		graph->changeLevel(level);
	}
}

void Board::random() {
	if (level != 3 && level != 4) {
		cout << "You cannot set randomness in level " << level << endl; 
	}
	else {
		randomness = true;
		readFilePos = 0;
	}

}

void Board::norandom(std::string file){
	if (level != 3 && level != 4) {
		cout << "You cannot set randomness in level " << level << endl; 
	}
	else {
		fileNameRand = file;
		randomness = false;
		readFilePos = 0;
	}
}

void Board::restart() {
	score = 0;
	level = 0;
	state = 0;
	readFilePos = 0;
	randomness = true;
	gameOver = false;
	for (auto &b: blocks) {
		b->undraw();
		delete b;
	}
	blocks.clear();
	cur->undraw();
	delete cur;
	if (next != nullptr) {
		delete next;
	}
	initBoard();
}

void Board::blind() {
	state = 1;
	graph->blind();
}

void Board::heavy() {
	state = 2;
}

void Board::force(char type) {
	cur->undraw();
	vector<Cell *> newBlock;
	Cell *c1;
	Cell *c2;
	Cell *c3;
	Cell *c4;
	if (type == 'I') {
    	c1 = theBoard[5][1];
   	 	c2 = theBoard[5][2];
    	c3 = theBoard[5][3];
    	c4 = theBoard[5][4];
	}
	else if (type == 'J') {
		c1 = theBoard[4][1];
   	 	c2 = theBoard[5][1];
    	c3 = theBoard[5][2];
    	c4 = theBoard[5][3];
	}
	else if (type == 'L') {
		c1 = theBoard[5][1];
   	 	c2 = theBoard[5][2];
    	c3 = theBoard[5][3];
    	c4 = theBoard[4][3];
	}
	else if (type == 'O') {
		c1 = theBoard[4][1];
   	 	c2 = theBoard[4][2];
    	c3 = theBoard[5][2];
    	c4 = theBoard[5][1];
	}
	else if (type == 'S') {
		c1 = theBoard[5][1];
   	 	c2 = theBoard[5][2];
    	c3 = theBoard[4][2];
    	c4 = theBoard[4][3];
	}
	else if (type == 'Z') {
		c1 = theBoard[4][1];
   	 	c2 = theBoard[4][2];
    	c3 = theBoard[5][2];
    	c4 = theBoard[5][3];
	}
	else if (type == 'T') {
		c1 = theBoard[5][2];
   	 	c2 = theBoard[4][1];
    	c3 = theBoard[4][2];
    	c4 = theBoard[4][3];
	}
    newBlock.emplace_back(c1);
    newBlock.emplace_back(c2);
   	newBlock.emplace_back(c3);
    newBlock.emplace_back(c4);
	cur->setBlock(newBlock);
	cur->setType(type);
	cur->draw();
}

string Board::getRow(int i) {
	string row = "";
	if (state == 1 && i < 17 && i > 6) {
		for (int j = 1; j < 3; j += 1) {
			row += theBoard[i][j]->getChar();
		}
		for (int j = 3; j < 10; j += 1) {
			row += '?';
		}
		for (int j = 10; j < 12; j += 1) {
			row += theBoard[i][j]->getChar();
		}
	} 
	else {
		for (int j = 1; j < 12; j += 1) {
			row += theBoard[i][j]->getChar();
		}
	}
	return row;
}

int Board::getScore() {
	return score;
}

int Board::getLevel() {
	return level;
}

bool Board::isGameOver() {
	return gameOver;
}
