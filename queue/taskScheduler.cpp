// https://leetcode.com/problems/task-scheduler/description/
#include <iostream>
#include <vector>
#include <queue>


// tasks = ["A","A","A","B","B","B"], n = 2
int leastInterval(vector<char>& tasks, int n){
	vector<int> map(26);
	for (auto l : tasks)
		map[l-"A"]++;
	
}