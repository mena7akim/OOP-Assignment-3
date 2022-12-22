#include "AMGame.h"


int main(){
    AMGame game;
    int n;
    cin >> n;
    if(n){
        game.runVsComputer();
    }
    else{
        game.runVsPlayer();
    }
}
