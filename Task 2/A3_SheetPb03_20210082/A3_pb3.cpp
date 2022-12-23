#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define N 9

vector<int>path;

vector<vector<int>> printMaze(int sol[N][N]) {
	vector<vector<int>>shortest = {
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sol[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			shortest[i][j] = sol[i][j];
		}
	}
	return shortest;
}


int count_path(int sol[N][N]) {
	int sum=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sol[i][j] == 1) { 
				sum++;
			}
		}
	}
	path.push_back(sum);
	cout << sum << endl;
	return sum;
	
}

void printVector(vector<vector<int>>vec) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

void shortest_path(multimap <int, vector<vector<int>>>&mp) {
	
	sort(path.begin(), path.end());
	cout << endl << "the shortest path is : " << path[0] << endl;

	cout << "and it is: " << endl;
	for (auto itr = mp.find(path[0]); itr != mp.end(); itr++) {
		 printVector(itr->second);
		 cout << endl << endl;
	}
}


void solveMaze(int maze[N][N],int sol[N][N], multimap <int, vector<vector<int>>>&mp, int x, int y) {
	if (x == N - 1 && y == N - 1) {
		sol[x][y] = 1;
		mp.insert(pair<int, vector<vector<int>>>(count_path(sol), printMaze(sol)));
		cout << endl << endl;
		
	}
	if (x >= N || y >= N || x < 0 || y < 0 || maze[x][y] == 0 || sol[x][y] == 1) {
		return;
	}
	sol[x][y] = 1;
	solveMaze(maze, sol,mp, x - 1, y);
	solveMaze(maze, sol, mp, x + 1, y);
	solveMaze(maze, sol, mp, x, y + 1);
	sol[x][y] = 0;

}


void mazeGame(int maze[N][N]) {
	multimap <int, vector<vector<int>>>map;
	int sol[N][N] = { {0} };
	solveMaze(maze, sol,map, 0, 0);
	cout << "\n\n";
	cout << "THE SHORTEST PATH" << endl;
	shortest_path(map);

}



int main() {
	int maze[N][N] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 0, 1, 0, 0, 1},
		{0, 0, 1, 1, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 1, 0, 0, 0, 1},
		{0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 1, 0, 0, 1},
		{0, 1, 0, 1, 0, 1, 1, 1, 1},
		{0, 0, 0, 1, 0, 1, 0, 0, 1}
	};

	mazeGame(maze);
	
}















