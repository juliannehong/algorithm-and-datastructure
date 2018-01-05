// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/tutorial/
// https://leetcode.com/explore/interview/card/google/dynamic-programming-4/444/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int min_path_sum(vector<vector<int>>& grid) {
	int R = grid.size(), C = grid[0].size();
	vector<vector<int>> min_cost_grid (R, vector<int>(C));
	// base cases 1. [0][0], top most edge, left most edge
	min_cost_grid[0][0] = grid[0][0];
	
	for (int i = 1; i < C; ++i) {
		min_cost_grid[0][i] = min_cost_grid[0][i - 1] + grid[0][i];
	}

	for (int i = 1; i < R; ++i) {
		min_cost_grid[i][0] = min_cost_grid[i - 1][0] + grid[i][0];
	}

	for (int i = 1; i < R; ++i) {
		for (int j = 1; j < C; ++j) {
			min_cost_grid[i][j] = min(min_cost_grid[i - 1][j], min_cost_grid[i][j - 1]) + grid[i][j];
		}
	}

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cout << min_cost_grid[r][c] << " ";
		}
		cout << endl;
	}
	return min_cost_grid[R - 1][C - 1];
}

int main() {
	vector<vector<int>> v{ {1, 3, 1},
		{1, 5, 1},
		{4, 2, 1} };
	cout << min_path_sum(v) << endl;
	system("pause");
	return 0;
}