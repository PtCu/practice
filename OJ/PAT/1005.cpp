#include <bits/stdc++.h>
using namespace std;
unordered_map<char, string> M{{'0', "zero"}, {'1', "one"}, {'2', "two"}, {'3', "three"}, {'4', "four"}, {'5', "five"}, {'6', "six"}, {'7', "seven"}, {'8', "eight"}, {'9', "nine"}};
int main()
{
    int sum = 0;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); ++i)
    {
        sum += input[i] - '0';
    }
    string ans = to_string(sum);
    cout << M[ans[0]];
    for (int i = 1; i < ans.size(); ++i)
    {
        cout << " " << M[ans[i]];
    }
}