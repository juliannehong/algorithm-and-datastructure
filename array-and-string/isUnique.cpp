// cracking coding interview

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void test(string str){
	vector<char> l;
	for (auto c : str){
		auto it = find(begin(l), end(l), c);
		if (it != nullptr)
			return false;
	}
	return true;
}
int main(){
	const char* str1 = "hello";
	const char* str2 = "apehwlbi";
	test("hello");
	//cout << isUnique(str1) << endl;
	//cout << isUnique(str2) << endl;

	return 0;
}