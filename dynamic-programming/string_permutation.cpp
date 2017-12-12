// cracking the coding interview pdf 8.4
#include <iostrea>
#include <vector>
#include <string>
using namespace std;

vector<string> permutation(const string& s, int current_index){
	vector<string> result;
	// basecase
	if (current_index == 0)
		result.push_back(s[0]);
}