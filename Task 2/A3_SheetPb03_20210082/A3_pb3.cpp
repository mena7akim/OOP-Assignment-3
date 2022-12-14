#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 9

vector<int>path;


void printMaze(int sol[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sol[i][j] << ' ';
		}
		cout << endl;


	}
}


void count_path(int sol[N][N]) {
	int sum=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sol[i][j] == 1) {
				sum++;
			}
		}
	}
	path.push_back(sum);
	//cout << sum << endl;
}

void shortest_path() {
	
	sort(path.begin(), path.end());
	cout << endl << "the shortest path is : " << path[0] << endl;
}


void solveMaze(int maze[N][N],int sol[N][N], int x, int y) {
	if (x == N - 1 && y == N - 1) {
		sol[x][y] = 1;
		count_path(sol);
		printMaze(sol);
		cout << endl << endl;
	}
	if (x >= N || y >= N || x < 0 || y < 0 || maze[x][y] == 0 || sol[x][y] == 1) {
		return;
	}
	sol[x][y] = 1;
	solveMaze(maze, sol, x - 1, y);
	solveMaze(maze, sol, x + 1, y);
	solveMaze(maze, sol, x, y + 1);
	sol[x][y] = 0;

}


void mazeGame(int maze[N][N]) {
	int sol[N][N] = { {0} };
	solveMaze(maze, sol, 0, 0);
}



int main() {
	int maze[N][N] = {
		{1, 0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 0},
		{0, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 1, 0, 1, 0, 1, 1, 1, 1},
		{0, 0, 0, 1, 0, 1, 0, 0, 1}
	};

	mazeGame(maze);
	shortest_path();
	
}





