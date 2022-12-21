#ifndef __GRAPHYICDISPLAY_H__
#define __GRAPHYICDISPLAY_H__
#include "window.h"
#include "cell.h"
class Board;

class graphicDisplay {
	Xwindow w;
	Board *board;
	std::string playerName;
public:
	graphicDisplay();
	void blind();
	void unblind();
	void draw(Cell *c);
	void undraw(Cell *c);
	void init(std::string name, Board *b);
	void changeLevel(int level);
	void changeScore(int Score);
};




#endif
