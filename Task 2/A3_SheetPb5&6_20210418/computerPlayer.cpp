//
// Created by over- on 16/12/2022.
//

#include "computerPlayer.h"


computerPlayer::computerPlayer() : Player("Computer Player"){

}

void computerPlayer::getBoard(vector<vector<char>> &board){
    grid = board;
    N = grid.size();
}

bool computerPlayer::isWinner(){
    bool win = 1;
    for(int i = 1; i < N - 1; i++){
        if(grid[i][N - 1] == ' '){
            win = 0;
            break;
        }
    }
    if(win) return 1;
    win = 1;
    for(int i = 1; i < N - 1; i++){
        if(grid[N - 1][i] == ' '){
            win = 0;
            break;
        }
    }
    if(win) return 1;
    return 0;
}


int computerPlayer::tryMoves(int turn){
    if(noMoves(turn)) return tryMoves(!turn);
    int win = isWinner();
    if(win) return 1;
    int ret = 0;
    if(turn){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == '>' && j != N - 1){
                    if(grid[i][j + 1] == ' '){
                        grid[i][j + 1] = '>';
                        grid[i][j] = ' ';
                        ret = max(ret, tryMoves(!turn));
                        grid[i][j + 1] = ' ';
                        grid[i][j] = '>';
                    }
                    else if(grid[i][j + 2] == ' '){
                        grid[i][j + 2] = '>';
                        grid[i][j] = ' ';
                        ret = max(ret, tryMoves(!turn));
                        grid[i][j + 2] = ' ';
                        grid[i][j] = '>';
                    }
                }
            }
        }
    }
    else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 'v' && i != N - 1){
                    if(grid[i + 1][j] == ' '){
                        grid[i + 1][j] = 'v';
                        grid[i][j] = ' ';
                        ret = max(ret, tryMoves(!turn));
                        grid[i + 1][j] = ' ';
                        grid[i][j] = 'v';
                    }
                    else if(grid[i + 2][j] == ' '){
                        grid[i + 2][j] = 'v';
                        grid[i][j] = ' ';
                        ret = max(ret, tryMoves(!turn));
                        grid[i + 2][j] = ' ';
                        grid[i][j] = 'v';
                    }
                }
            }
        }
    }
    return !ret;
}

int computerPlayer::getBestMove() {
    int temp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 'v' && i != N - 1){
                if(grid[i + 1][j] == ' '){
                    grid[i + 1][j] = 'v';
                    grid[i][j] = ' ';
                    if(tryMoves(1)) {
                        return j;
                    }
                    grid[i + 1][j] = ' ';
                    grid[i][j] = 'v';
                    temp = j;
                }
                else if(grid[i + 2][j] == ' '){
                    grid[i + 2][j] = 'v';
                    grid[i][j] = '.';
                    if(tryMoves(1)) {
                        return j;
                    }
                    grid[i + 2][j] = ' ';
                    grid[i][j] = 'v';
                    temp = j;
                }
            }
        }
    }
    return temp;
}

bool computerPlayer::noMoves(bool turn) {
    bool move = 0;
    if (turn) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '>' && i != N - 1) {
                    if(grid[i + 1][j] == ' ' || (i + 2 < N && grid[i + 2][j] == ' ')){
                        move = 1;
                    }
                }
            }
        }
        return !move;
    }
    else{
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'v' && j != N - 1) {
                    if(grid[i][j + 1] == ' ' || (j + 2 < N && grid[i][j + 2] == ' ')){
                        move = 1;
                    }
                }
            }
        }
        return !move;
    }
}