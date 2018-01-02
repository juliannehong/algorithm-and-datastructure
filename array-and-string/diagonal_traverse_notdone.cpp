//https://leetcode.com/problems/diagonal-traverse/description/
#include <iostream>
#include <vector>
using namespace std;

typedef enum { RIGHT, RIGHT_UP, DOWN, DOWN_LEFT } ACTION;

bool is_legal(const vector<vector<int>> & matrix, int r, int c) {
	return (r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size());
}

vector<int> diagonal_traverse(const vector<vector<int>> & matrix) {
	auto R = matrix.size();
	auto C = matrix[0].size();
	int i = 0, j = 0;
	ACTION pre = RIGHT_UP;

	while (i < R && j < C) {
		if (pre == RIGHT_UP) { // can be right, keep right up, or down
			if (i == 0 && j != C-1) { // right
				j++;
				pre = RIGHT;
			}
			else if (i > 0 && j != C-1) { // right up
				i--;
				j++;
				pre = RIGHT_UP;
			}
			else if (i == 0 && j == C - 1) { //down
				i++;
				pre = DOWN;
			}
		}
		else if (pre == DOWN_LEFT) {


		}
		else if (pre == RIGHT) {

		}
		else {

		}
	}
	

}