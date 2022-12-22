//
// Created by over- on 16/12/2022.
//

#include "AMGame.h"

AMGame::AMGame() : AMGame(5){
}

AMGame::AMGame(int n) : N(n){
    grid.resize(N, vector<char>(N));
    firstPlayerRobot.resize(N);
    secondPlayerRobot.resize(N);
}

void AMGame::creatBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            grid[i][j] = ' ';
            if((!i && !j) || (!i && j == N - 1) || (i == N - 1 && j == N - 1) || (!j && i == N - 1)){
                grid[i][j] = ' ';
            }
        }
    }
    for(int i = 1; i < N - 1; i++)
        grid[0][i] = 'v', grid[i][0] = '>';
}
void AMGame::printBoard(){
    cout << "  ";
    for(int j = 0; j < N; j++)
        cout << '_' << "   ";
    cout << '\n';
    for(int i = 0; i < N; i++){
        cout << "| ";
        for(int j = 0; j < N; j++)
            cout << grid[i][j] << " | ";
        cout << '\n';
        cout << "  ";
        for(int j = 0; j < N; j++){
            cout << '_' << "   ";
        }
        cout << '\n';
    }
}

bool AMGame::isWinner(){
    bool win = 1;
    for(int i = 1; i < N - 1; i++){
        if(grid[i][N - 1] == ' '){
            win = 0;
            break;
        }
    }
    if(win){
        cout << "First player wins\n";
        return true;
    }
    win = 1;
    for(int i = 1; i < N - 1; i++){
        if(grid[N - 1][i] == ' '){
            win = 0;
            break;
        }
    }
    if(win) {
        cout << "Second Player wins\n";
        return true;
    }
    return false;
}

bool AMGame::makeMove(int i, int turn){
    if(i > N - 2 || i < 1){
        cout << "NOT A VAlID MOVE, TRY AGAIN\n";
        return false;
    }
    if((!turn && grid[N - 1][i] == 'v') || (turn && grid[i][N - 1] == '>')){
        cout << "This robot already reached the last his last cell, try another one\n";
        return false;
    }
    int j = (turn ? firstPlayerRobot[i] : secondPlayerRobot[i]);
    if(turn){
        if(grid[i][j + 1] == ' '){
            grid[i][j + 1] = '>';
            grid[i][j] = ' ';
            firstPlayerRobot[i] = j + 1;
        }
        else if(grid[i][j + 2] == ' '){
            grid[i][j + 2] = '>';
            grid[i][j] = ' ';
            firstPlayerRobot[i] = j + 2;
        }
        else{
            cout << "You can not move, try to move another one\n";
            return false;
        }
    }
    else{
        if(grid[j + 1][i] == ' '){
            grid[j + 1][i] = 'v';
            grid[j][i] = ' ';
            secondPlayerRobot[i] = j + 1;
        }
        else if(grid[j + 2][i] == ' '){
            grid[j + 2][i] = 'v';
            grid[j][i] = ' ';
            secondPlayerRobot[i] = j + 2;
        }
        else{
            cout << "You can not move, try to move another one\n";
            return false;
        }
    }
    return true;
}

void AMGame::runVsComputer(){
    creatBoard();
    bool turn = 0;
    printBoard();
    while(!isWinner()){
        cout << '\n';
        if(noMoves(turn)){
            turn = !turn;
        }
        if(turn){
            computer.getBoard(grid);
            makeMove(computer.getBestMove(), 0);
            cout << "Computer Player\n";
        }
        else{
            int playerMove;
            firstPlayer.getMove(playerMove);
            while(!makeMove(playerMove, 1)){
                firstPlayer.getMove(playerMove);
            }
        }
        turn = !turn;
        printBoard();
    }
    cout << '\n';
}

void AMGame::runVsPlayer(){
    creatBoard();
    bool turn = 0;
    printBoard();
    while(!isWinner()){
        cout << '\n';
        if(noMoves(turn)){
            turn = !turn;
        }
        if(turn){
            int playerMove;
            secondPlayer.getMove(playerMove);
            while(!makeMove(playerMove, 0)){
                secondPlayer.getMove(playerMove);
            }
        }
        else{
            int playerMove;
            firstPlayer.getMove(playerMove);
            while(!makeMove(playerMove, 1)){
                firstPlayer.getMove(playerMove);
            }
        }
        turn = !turn;
        printBoard();
    }
}

bool AMGame::noMoves(bool turn) {
    bool move = 0;
    if (turn) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'v' && i != N - 1) {
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
                if (grid[i][j] == '>' && j != N - 1) {
                    if(grid[i][j + 1] == ' ' || (j + 2 < N && grid[i][j + 2] == ' ')){
                        move = 1;
                    }
                }
            }
        }
        return !move;
    }
}