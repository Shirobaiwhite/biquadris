#include "textdisplay.h"
#include <iomanip>
#include <iostream>
using namespace std;

textDisplay::textDisplay(Board *b1, Board *b2, Player *p1, Player *p2):
b1{b1}, b2{b2}, p1{p1}, p2{p2} {}

void textDisplay::display() {
	string divider{"-----------"};
	cout << p1->getName();
	cout << setw(16 - p1->getName().length());
	cout << "";
	cout << p2->getName();
	cout << endl;
	cout << "Level:    " << b1->getLevel();
	cout << "     ";
	cout << "Level:    " << b2->getLevel();
	cout << endl;
	cout << "Score:";
	cout << setw(5);
	cout << b1->getScore();
	cout << "     ";
	cout << "Score:";
	cout << setw(5);
	cout << b2->getScore();
	cout << endl;
	cout << divider << "     " << divider;
	cout << endl;
	for(int i = 2; i < 20; i += 1) {
		cout << b1->getRow(i);
		cout << "     ";
		cout << b2->getRow(i);
		cout << endl;
	}
	cout << divider << "     " << divider;
	cout << endl;
	cout << "Next:";
	cout << "           ";
	cout << "Next:";
	cout << endl;
	cout << b1->getRow(0);
	cout << "     ";
	cout << b2->getRow(0);
	cout << endl;
	cout << b1->getRow(1);
	cout << "     ";
	cout << b2->getRow(1);
	cout << '\n' << endl;

}
