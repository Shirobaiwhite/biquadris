#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>
#include "cell.h"

// each block is consisted of 4 cells

class Block {
	std::vector <Cell *> theBlock;
	int level; // the level for this block (used for calculating the score)
	int direct;
	int size;
	char type;
public:
	Block(int level, char type);
	~Block();
	char getType();
	void setBlock(std::vector<Cell *> &theBlock);
	void draw();
	void undraw();
	void setType(char newType);
	bool isInBlock(Cell *c); // check if c is in the block
	int getLevel();
	Cell *getCell(int pos);
	int getDirect();
	void rmCell(Cell *c);
	void setRelation();
	void changeDirect();
	int getSize();


};


#endif
