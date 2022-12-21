#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include "board.h"
#include "player.h"

class textDisplay {
	Board *b1;
	Board *b2;
	Player *p1;
	Player *p2;
public:
	textDisplay(Board *b1, Board *b2, Player *p1, Player *p2);
	void display();
};




#endif
