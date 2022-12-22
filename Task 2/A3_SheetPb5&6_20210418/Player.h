//
// Created by over- on 16/12/2022.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include <bits/stdc++.h>
using namespace std;


class Player {
protected:
    string name;
    static int id;
public:
    Player();
    Player(string s);
    string getName();
    void getMove(int &i);
};


#endif
