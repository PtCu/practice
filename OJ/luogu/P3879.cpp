#include <bits/stdc++.h>
using namespace std;
vector<unordered_set<string>> passages;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, L;
    string s;
    cin >> N;
    passages.resize(N);
    for (size_t i = 0; i < N; ++i)
    {
        cin >> L;
       while (L--)
        {
            cin >> s;
            passages[i].insert(s);
        }
    }
    int M;
    cin >> M;
    for (size_t i = 1; i <= M; ++i)
    {
        cin >> s;
        for (size_t j = 0; j < passages.size(); ++j)
        {
            if (passages[j].count(s))
                cout << j + 1 << " ";
        }
        cout << endl;
    }
}