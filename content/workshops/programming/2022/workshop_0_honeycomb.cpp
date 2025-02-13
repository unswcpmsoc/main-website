// Cece's Honeycomb
// https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-division-a/challenges/imc21-a7b5
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int triangleArea(int sideLength) {
    return sideLength * (sideLength + 1) / 2;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int A = stoi(first_multiple_input[0]);

    int B = stoi(first_multiple_input[1]);

    int C = stoi(first_multiple_input[2]);

    int D = stoi(first_multiple_input[3]);

    int E = stoi(first_multiple_input[4]);

    int F = stoi(first_multiple_input[5]);

    // Write your code here
    cout << triangleArea(F + A + B - 2) - triangleArea(F - 1) - triangleArea(B - 1) - triangleArea(D - 1);
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
