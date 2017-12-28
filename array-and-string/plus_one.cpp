// https://leetcode.com/problems/plus-one/description/
#include <iostream>
#include <vector>
using namespace std;

vector<int> plus_one(vector<int>& digits) {
	for (int i = digits.size() - 1; i >= 0; --i) {
		if (digits[i] + 1 == 10)
			digits[i] = 0;
		else {
			digits[i]++;
			return digits;
		}
	}
	vector<int> ans(digits.size() + 1, 0);
	ans[0] = 1;
	return ans;
}

void print_answer(const vector<int>& answer) {
	for (auto d : answer)
		cout << d;
	cout << endl;
}

int main() {
	vector<int> test1{ 2,5,4,8 };
	vector<int> test2{ 1,8,3,8,9 };
	vector<int> test3{ 0 };
	vector<int> test4{ 9,9,9 };
	print_answer(plus_one(test1));
	print_answer(plus_one(test2));
	print_answer(plus_one(test3));
	print_answer(plus_one(test4));
	system("pause");
	return 0;
}