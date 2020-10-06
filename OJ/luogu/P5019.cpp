#include <bits/stdc++.h>
using namespace std;
vector<int> sources;
int main() {
    int n,d;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> d;
        sources.push_back(d);
    }
    int days = 0;
    for (int i = 1; i < n;i++)
    {
        if(sources[i]>sources[i-1])
            days += sources[i] - sources[i - 1];
    }
    cout << days+sources[0];
}