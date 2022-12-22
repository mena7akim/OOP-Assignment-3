#include "Player.h"

int Player::id = 1;

Player::Player() : Player("Player # " + to_string(id)){

}

Player::Player(string s) : name(s) {
    id++;
}

string Player::getName() { return name; }

void Player::getMove(int &i){
    cout << getName() << "Enter the i-th robot you want to move\n";
    cin >> i;
}