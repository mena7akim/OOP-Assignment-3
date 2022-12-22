#ifndef MAIN_CPP_AMGAME_H
#define MAIN_CPP_AMGAME_H

#include "computerPlayer.h"

class AMGame {
    int N;
    Player firstPlayer;
    Player secondPlayer;
    computerPlayer computer;
    vector<vector<char>> grid;
    vector<int> firstPlayerRobot, secondPlayerRobot;
public:
    AMGame();
    AMGame(int n);
    void runVsComputer();
    void runVsPlayer();
    void creatBoard();
    void printBoard();
    bool makeMove(int i, int turn);
    bool isWinner();
    bool noMoves(bool turn);
};


#endif
