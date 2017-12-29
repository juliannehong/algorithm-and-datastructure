// https://leetcode.com/problems/merge-intervals/description/
// https://leetcode.com/problems/merge-intervals/solution/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> result;
	if (intervals.empty())
		return result;
	sort(intervals.begin(), intervals.end(), [](const Interval a, const Interval b) {return a.start < b.start; });
	result.push_back(Interval(intervals[0].start, 0));
	for (int i = 1; i < intervals.size(); ++i) {
		if (intervals[i].start - intervals[i - 1].end > 1) {
			// update last struct
			result[result.size() - 1].end = intervals[i - 1].end;
			// create new struct
			result.push_back(Interval(intervals[i].start, 0));
		}
		else if (intervals[i].start - intervals[i - 1].end < 0 && intervals[i].end <= intervals[i - 1].end){
			intervals.erase(intervals.begin() + i);
		}
		else;
	}
	result[result.size() - 1].end = intervals[intervals.size() - 1].end;
	return result;
}

int main() {


	system("pause");
	return 0;

}