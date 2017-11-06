// https://leetcode.com/problems/remove-invalid-parentheses/description/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void removeInvalidprantheses(string str){
	if (str.empty())
		return ;

	vector<string> visited;

	queue<string> q;
	string temp;
	bool level;

	q.push(str);
	visited.push_back(str);

	while (!q.empty()){
		str = q.front();
		q.pop();
		
	}
}