// cracking the coding interview pdf 8.4
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> get_valid_parens(int n) {
	unordered_set<string> re;
	// base case n == 0, n == 1
	if (n == 0) {
		;
	}
	else if (n == 1) {
		re.insert("()");
	}
	else {
		unordered_set<string> from_previous = get_valid_parens(n - 1);
		for (auto p : from_previous) {
			re.insert(p + "()");
			re.insert("()"+p);
			re.insert("("+p+")");
		}
	}
	return re;
}

int main() {
	unordered_set<string> result = get_valid_parens(4);
	for (auto s : result)
		cout << s << endl;

	return 0;
};