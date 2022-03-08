// Vivian and Sarah's Studex Tasks
// https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-division-a/challenges/imc21-a2b2/problem
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, oddCount = 0, evenCount = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            evenCount += val;
        }
        else {
            oddCount += val;
        }
    }
    
    if (oddCount > evenCount) {
        cout << "Vivian\n";
    }
    else if (oddCount == evenCount) {
        cout << "Tie\n";
    }
    else {
        cout << "Sarah\n";
    }
}
