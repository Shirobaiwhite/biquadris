#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "board.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "player.h"
using namespace std;

string recogComm(string command) {
    string left = "left";
    string right = "right";
    string down = "down";
    string clockwise = "clockwise";
    string counterclockwise = "counterclockwise";
    string drop = "drop";
    string levelup = "levelup";
    string leveldown = "leveldown";
    string norandom = "norandom";
    string random = "random";
    string sequence = "sequence";
    string restart = "restart";
    string help = "help";
    if (command.length() != 1) {
        if ((command[0] == 'l') && (command[1] == 'e') && (left.find(command) != string::npos) &&
            (levelup.find(command) == string::npos) && (leveldown.find(command) == string::npos)) {
            return left;
        }
        if ((command[0] == 'l') && (command[1] == 'e') && (levelup.find(command) != string::npos) && (left.find(command) == string::npos) && (leveldown.find(command) == string::npos)) {
            return levelup;
        }
        if ((command[0] == 'l') && (command[1] == 'e') && (leveldown.find(command) != string::npos) && (left.find(command) == string::npos) && (levelup.find(command) == string::npos)) {
            return leveldown;
        }
        if ((command[0] == 'r') && (right.find(command) != string::npos) &&
            (restart.find(command) == string::npos) && (random.find(command) == string::npos)) {
            return right;
        }
        if ((command[0] == 'r') && (random.find(command) != string::npos) &&
            (restart.find(command) == string::npos) && (right.find(command) == string::npos)) {
            return random;
        }
        if ((command[0] == 'r') && (restart.find(command) != string::npos) &&
            (random.find(command) == string::npos) && (right.find(command) == string::npos)) {
            return restart;
        }
        
        if ((command[0] == 'd') && (down.find(command) != string::npos) &&
            (drop.find(command) == string::npos)) {
            return down;
        }
        if ((command[0] == 'd') && (drop.find(command) != string::npos) &&
            (down.find(command) == string::npos)) {
            return drop;
        }
        if ((command[0] == 'c') && (clockwise.find(command) != string::npos)) {
            return clockwise;
        }
        if ((command[0] == 'c') && (counterclockwise.find(command) != string::npos)) {
            return counterclockwise;
        }
        if ((command[0] == 'n') && (norandom.find(command) != string::npos)) {
            return norandom;
        }
        if (command [0] == 'h') {
            return help;
        }
    }
    else {
        if (command[0] == 'I') {
            return "I";
        }
        if (command[0] == 'J') {
            return "J";
        }
        if (command[0] == 'L') {
            return "L";
        }
        if (command[0] == 'O') {
            return "O";
        }
        if (command[0] == 'S') {
            return "S";
        }
        if (command[0] == 'Z') {
            return "Z";
        }
        if (command[0] == 'T') {
            return "T";
        }
    }
}

int recogTimes(string &comm) {
    string n = "";
    int times;
    while (comm[0] == '0' || comm[0] == '1' || comm[0] == '2' ||
           comm[0] == '3' || comm[0] == '4' || comm[0] == '5' ||
           comm[0] == '6' || comm[0] == '7' || comm[0] == '8' ||
           comm[0] == '9') {
        n += comm[0];
        comm = comm.substr(1);
    }
    
    if (n != "") {
        istringstream iss{n};
        iss >> times;
        return times;
    } else {
        return 1;
    }
}

void manipBoard(Board *b, textDisplay *t, Player *p){
    string comm;
    while(true) {
        cout << p->getName() <<", please enter your command: ";
        if (!(cin >> comm)) {
            break;
        }
        int times = recogTimes(comm);
        comm = recogComm(comm);
        if (comm == "left") {
            b->left(times);
            t->display();
        }
        else if (comm == "right") {
            b->right(times);
            t->display();

        }
        else if (comm == "down") {
            b->down(times);
            if (b->getLevel() == 3 && b->getLevel() == 4) {
                b->down();
            }
            t->display();
        }
        else if (comm == "clockwise") {
            b->cw(times);
            t->display();
        }
        else if (comm == "counterclockwise") {
            b->ccw(times);
            t->display();
        }
        else if (comm == "drop") {
            break;
        }
        else if (comm == "levelup") {
            b->levelUp();
            t->display();
        }
        else if (comm == "leveldown") {
            b->levelDown();
            t->display();
        }
        else if (comm == "norandom") {
            string file;
            cin >> file;
            b->norandom(file);
            t->display();
        }
        else if (comm == "random") {
            b->random();
            t->display();
        }
        else if (comm == "sequence") {
            cout << "sequence" << endl;
        }
        else if (comm == "I" || comm == "J" || comm == "L" ||
                 comm == "O" || comm == "S" || comm == "Z" || comm == "T") {
            cout << "replace" << endl;
        }
        else if (comm == "restart") {
            p->update();
            b->restart();
            b->generateNext();
            t->display();
        }
        else if (comm == "help") {
            cout << endl;
            cout << "**********************************************************" << endl;
            cout << "left - move your current block one unit to the left" << endl;
            cout << "right - move your current block one unit to the right" << endl;
            cout << "Down - move your current block one unit downward" << endl;
            cout << "clockwise - rotate your current block ~ by 90 degrees" << endl;
            cout << "counterclockwise - rotate your current block ~ by 90 degrees" << endl;
            cout << "drop - drops your current block and end your turn" << endl;
            cout << "levelup - increase your current level!" << endl;
            cout << "leveldown - too hard?" << endl;
            cout << "restart - reset" << endl;
            cout << "**********************************************************" << endl;
            cout << endl;
        }
        else {
            cout << "Invalid Command! Please re-enter: ";
        }
    }
}


int main(int argc, char *argv[]) {
    string args;
    graphicDisplay *g1;
    graphicDisplay *g2;
    int seed = 1;
    string filename1 = "sequence1.txt";
    string filename2 = "sequence2.txt";
    int level = 0;
    for (int i = 1; i < argc; i++) {
        args = argv[i];
        if (args == "-text") {
            g1 = nullptr;
            g2 = nullptr;
        } 
        else if (args == "-seed") {
            stringstream str(argv[i+1]);
            str >> seed;
            i += 1;
        }
        else if (args == "-scriptfile1") {
            filename1 = argv[i+1];
            i += 1;
        }
        else if (args == "-scriptfile2") {
            filename2 = argv[i+1];
            i += 1;
        }
        else if (args == "-startlevel") {
            stringstream str(argv[i+1]);
            str >> level;
            i += 1;
        }
    }
    if (argc == 0 || (g1 != nullptr && g2 != nullptr)) {
        g1 = new graphicDisplay{};
        g2 = new graphicDisplay{};
    }

    cout << "-----------------------" << endl;
    cout << " Welcome to Biquadris!" << endl;
    cout << "-----------------------" << endl;
    cout << endl;
    Board *b1 = new Board{level, filename1, seed, g1};
    Board *b2 = new Board{level, filename2, seed, g2};
    string name;
    cout << "Please Enter the Name of Player 1: ";
    cin >> name;
    Player *p1 = new Player{b1, name};
    cout << "Please Enter the Name of Player 2: ";
    cin >> name;
    cout << endl;
    Player *p2 = new Player{b2, name};
    b1->initBoard();
    b2->initBoard();
    textDisplay *t = new textDisplay{b1, b2, p1, p2};
    if (g1 != nullptr && g2 != nullptr) {
        g1->init(p1->getName(), b1);
        g2->init(p2->getName(), b2);
    }
    bool p1Turn{true};
    int count;
    while(true){
        if (p1Turn){
            b1->generateNext();
            t->display();
            manipBoard(b1, t, p1);
            count = b1->drop();
            if (b1->isGameOver()) {
                    p1->update();
                    p2->update();
                    cout << endl;
                    cout << "Game Over! " << p2->getName() << " WIN!" << endl;
                    cout << p1->getName() << "'s highest score: " << p1->getHighscore() << endl;
                    cout << p2->getName() << "'s highest score: " << p2->getHighscore() << endl;
                    break;
            }
            if (count > 1) {
                t->display();
                char action;
                cout << p1->getName() <<", please choose one of following special action:" << endl;
                cout << "A: Blind your opponent" << endl;
                cout << "B: Make your opponent's next block heavy" << endl;
                cout << "C: Choose your opponent's next block" << endl;
                while (true) {
                    cin >> action;
                    if (action == 'A') {
                        b2->blind();
                        break;
                    }
                    else if (action == 'B') {
                        b2->heavy();
                        break;
                    }
                    else if (action == 'C') {
                        cout << "Choose one of following blocks for your opponent:" << endl;
                        cout << "I, J, L, O, S, Z, T" << endl;
                        char blockid;
                        while(true) {
                            cin >> blockid;
                            if (blockid != 'I' && blockid != 'J' && blockid != 'L'
                                && blockid != 'O' && blockid != 'S' && blockid != 'Z'
                                && blockid != 'T') {
                                cout << "Invalid Choice! Please re-enter: ";
                            } else {
                                b2->force(blockid);
                                break;
                            }
                        }
                        break;
                    }
                    else {
                         cout << "Invalid Choice! Please re-enter: ";
                    }
                }
            }
            p1Turn = false;
        } else {
            b2->generateNext();
            t->display();
            manipBoard(b2, t, p2);
            count = b2->drop();
            if (b2->isGameOver()) {
                    cout << "Game Over! " << p1->getName() << " WIN!" << endl;
                    cout << p1->getName() << "'s highest score: " << p1->getHighscore() << endl;
                    cout << p2->getName() << "'s highest score: " << p2->getHighscore() << endl;
                break;
            }
            if (count > 1) {
                t->display();
                char action;
                cout << p2->getName() <<", please choose one of following special action:" << endl;
                cout << "A: Blind your opponent" << endl;
                cout << "B: Make your opponent's next block heavy" << endl;
                cout << "C: Choose your opponent's next block" << endl;
                while (true) {
                    cin >> action;
                    if (action == 'A') {
                        b1->blind();
                        break;
                    }
                    else if (action == 'B') {
                        b1->heavy();
                        break;
                    }
                    else if (action == 'C') {
                        cout << "Choose one of following blocks for your opponent:" << endl;
                        cout << "I, J, L, O, S, Z, T" << endl;
                        char blockid;
                        while(true) {
                            cin >> blockid;
                            if (blockid != 'I' && blockid != 'J' && blockid != 'L'
                                && blockid != 'O' && blockid != 'S' && blockid != 'Z'
                                && blockid != 'T') {
                                cout << "Invalid Choice! Please re-enter: ";
                            } 
                            else {
                                b1->force(blockid);
                                break;
                            }
                        }
                        break;
                    }   
                    else {
                         cout << "Invalid Choice! Please re-enter: ";
                    }
                }
            }
            p1Turn = true;
        }
    }
    delete p1;
    delete p2;
    delete t;
    delete g1;
    delete g2;
}
