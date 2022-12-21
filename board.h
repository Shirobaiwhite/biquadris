#ifndef __BOARD_H__
#define __BOARD_H__
#include "block.h"
#include "cell.h"
class graphicDisplay;

class Board {
	std::vector<std::vector<Cell *>> theBoard;
	int score;
	int level;
	int state; // 0: no special action, 1: blind, 2: heavy, 3: force
	//void clearBoard();
	std::string fileName0;
	std::string fileNameRand;
	int readFilePos;
	bool randomness; //only for level 3 & 4
	std::vector<Block *> blocks;
	bool gameOver;
	int seed;
	graphicDisplay *graph;
	Block *cur;
	Block *next;
	void rotateI(bool cw, int times);
	void rotateJ(bool cw, int times);
	void rotateL(bool cw, int times);
	void rotateT(bool cw, int times);
	void rotateS(bool cw, int times);
	void rotateZ(bool cw, int times);
	void rotateO(bool cw, int times);
	void setNext(char type);
	bool isOverlap(std::vector<Cell *> &newBlock, Block *b);
	bool lineClear(int row);
	void clearLine(int row);
	void dropAbove(int row);
public:
	Board(int level, std::string filename, int seed, graphicDisplay *g);
	~Board();

	void initBoard(); //sets up a board
	void generateNext();
	Block* getCurr(); // gets the current block (the block that is in the air) */
	void left(int times = 1);
	void right(int times = 1);
	bool down(int times = 1);
	void cw(int times = 1); // rotates clockwise
	void ccw(int times = 1); // rotates counter-clockwise
	int drop();
	void replace(char); // sets the next block to be char
	void levelUp();	// adds 1 to level
	void levelDown();
	void random();
	void norandom(std::string file);
	void restart();
	void blind();
	void heavy();
	void force(char type); 
	std::string getRow(int i);
	int getScore();
	int getLevel(); 
	int getState();
	bool isGameOver();
};

#endif
