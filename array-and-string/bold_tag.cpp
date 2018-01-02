// https://leetcode.com/problems/add-bold-tag-in-string/description/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string insert_bold(string s, vector<int> v) {
	string re = "";
	for (int i = 0; i < s.size(); ++i) {
		auto iter = find(v.begin(), v.end(), i);
		if (iter != v.end()) {
			if (distance(v.begin(), iter) % 2 == 0) {
				re += "<b>";
				re += s[i];
			}
			else {
				re += s[i];
				re += "</b>";
			}
		}
		else {
			re += s[i];
		}
	}
	return re;
}

vector<int> get_indexes(string s, const vector<string>& dict) {
	vector<pair<int,int>> temp;
	for (auto w : dict) {
		auto i = s.find(w);
		if (i != string::npos) {
			temp.push_back(make_pair(i, i + w.size() - 1));
		}
	}

	sort(temp.begin(), temp.end(), [](const pair<int, int> a, const pair<int, int> b) {return a.first < b.first; });

	vector<int> index{ temp[0].first };
	for (int i = 1; i < temp.size(); ++i) {
		if (temp[i].first - temp[i - 1].second > 1) {
			index.push_back(temp[i - 1].second);
			index.push_back(temp[i].first);
		}
	}
	index.push_back(temp[temp.size()-1].second);

	return index;
}

string add_bold_tag(string s, vector<string>& dict) {
	vector<int> index = get_indexes(s, dict);
	cout << endl;
	return insert_bold(s, index);
}

int main() {

	vector<int> v{ 1,5,2,6,8,9,10,13 };
	string s1 = "abcxyz123";
	vector<string> t1{ "abc","123" };
	cout << add_bold_tag(s1, t1) << endl;

	string s2 = "aaabbcc";
	vector<string> t2{ "aaa","aab","bc" };
	cout << add_bold_tag(s2, t2) << endl;
	system("pause");
	return 0;
}