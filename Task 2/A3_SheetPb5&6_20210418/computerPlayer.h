#ifndef MAIN_CPP_COMPUTERPLAYER_H
#define MAIN_CPP_COMPUTERPLAYER_H

#include "Player.h"

class computerPlayer : protected Player{
    vector<vector<char>> grid;
    int N;
public:
    computerPlayer();
    void getBoard(vector<vector<char>> &board);
    int tryMoves(int turn);
    bool isWinner();
    int getBestMove();
    bool noMoves(bool turn);
};


#endif
