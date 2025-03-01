#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "dna.h"
using namespace std;
 
int N, T, len;
 
string makeStr(int size, char c = '0') {
	string s = "";
	for (int rep = 0; rep < size; ++rep) s.push_back(c);
	return s;
}
 
bool endswith(string s, string suffix) {
	// does s end with suffix;
	if (s.size() < suffix.size()) return false;
	while (!suffix.empty()) {
		if (s.back() != suffix.back()) return false;
		s.pop_back();
		suffix.pop_back();
	}
	return true;
}
 
int maxLen() {
	int l = 0, r = N + 1;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (make_test(makeStr(m))) l = m;
		else r = m;
	}
	return l;
}
 
string extendRight(string curr) {
	do {
		if (make_test(curr + '1')) {
			curr.push_back('1');
		}
		else {
			// assume its a 0, even though it might be the end of the string
			curr.push_back('0');
		}
	} while (!endswith(curr, makeStr(len + 1)));
	return curr;
}
 
string cullRight(string curr) {
	int l = curr.size() - len - 1, r = curr.size() + 1;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (make_test(curr.substr(0, m))) l = m;
		else r = m;
	}
	return curr.substr(0, l);
}
 
string extendLeft(string curr) {
	while (curr.size() < N) {
		if (make_test('1' + curr)) {
			curr = '1' + curr;
		}
		else {
			// assume its a 0, even though it might be the end of the string
			curr = '0' + curr;
		}
	}
	return curr;
}
 
string analyse(int n, int t) {
	N = n;
	T = t;
	len = maxLen();
 
	if (len == 0) return makeStr(N, '1');
	
	string curr = makeStr(len);
	//cout << curr << "\n";
	curr = extendRight(curr);
	//cout << curr << "\n";
	curr = cullRight(curr);
	//cout << curr << "\n";
	curr = extendLeft(curr);
	//cout << curr << "\n";
	return curr;
}
 
/*int main() {
	if (ans != analyse(ans.size(), -1)) throw 20;
	cout << numTests;
}*/