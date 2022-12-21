#include "textdisplay.h"
#include "graphicdisplay.h"
#include "board.h"
#include "block.h"
#include "cell.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	Board *b1 = new Board{0, "sequence1.txt", nullptr};
	Board *b2 = new Board{0, "sequence2.txt", nullptr};
	b1->initBoard();
	b2->initBoard();
    Player *p1 = new Player{b1, "Player1"};
    Player *p2 = new Player{b2, "Player2"};
	textDisplay *t = new textDisplay{b1, b2, p1, p2};
	b1->generateNext();
	t->display();
	b1->norandom("sequence1.txt");
	t->display();
	b1->drop();
	t->display();
	//b2 manipulate
	b1->generateNext();
	t->display();
	b1->drop();
	t->display();
	b1->generateNext();
	t->display();
	delete p1;
	delete p2;
	delete t;

}
