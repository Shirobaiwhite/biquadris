#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
class graphicDisplay;
class Block;

class Cell {
	int x; // the cell's horizontal id, starting 0 from the left side
	int y; // the cell's vertical id, starting 0 from the bottom
	Block *parent; // the block that the current cell belongs to
	graphicDisplay *graph;
public:
	Cell(int x, int y, graphicDisplay *g);
	char getChar();
	bool isFilled();
	void setFilled(Block *b);
	void draw();
	void setUnfilled();
	void undraw();
	int getx();
	int gety();
	Block *getParent();

};


#endif
