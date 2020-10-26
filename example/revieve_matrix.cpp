#include<bits/stdc++.h>
using namespace std;

//从cin接受一个矩阵。按ctrl+z结束
void input_vector(vector<vector<int>> &vec)
{
    vector<int> v;
    while (!cin.eof())
    {
        int tmp(0);
        v.clear();
        string line;
        getline(cin, line);
        istringstream ss(line);
        while (ss >> tmp)
        {
            v.push_back(tmp);
        }
        vec.push_back(v);
    }
}