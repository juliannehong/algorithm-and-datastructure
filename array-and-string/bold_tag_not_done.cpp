// https://leetcode.com/problems/add-bold-tag-in-string/description/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// todo : finish this algo
// todo : try to solve with two pointers

string add_bold_tag(string& s, vector<string>& dict) {
	vector<vector<int>> indexes;
	for (auto w : dict) {
		vector<int> index;
		index.push_back(s.find(w));
		index.push_back(s.find(w) + w.size() - 1);
		indexes.push_back(index);
	}

	sort(indexes.begin(), indexes.end(), [](const vector<int> a, const vector<int> b) {return a[0] < b[0]; });
	string result;
	vector<int> bolds;
	bolds.push_back(indexes[0][0]); 
	for (int i = 1; i < indexes.size(); ++i) {
		if (indexes[i][0] - indexes[i - 1][1] > 1) {
			bolds.push_back(indexes[i - 1][1]);
			bolds.push_back(indexes[i][0]);
		}
		else;
	}
	bolds.push_back(indexes[indexes.size() - 1][1]);
	for (auto b : bolds)
		cout << b << " ";
	int pos = 0;
	for (int i = 0; i < bolds.size(); ++i) {
		result += s.substr(pos, bolds[i] - pos + 1); 
		result += (i % 2 == 0) ? "<b>" : "</b>";
		pos = bolds[i];
	}
	return result;
}


int main() {
	string s1 = "abcxyz123";
	vector<string> dict1{ "abc","123" };
	//cout << s1.substr(1, 4) << endl;
	cout << add_bold_tag(s1, dict1) << endl;

	system("pause");
	return 0;
}

