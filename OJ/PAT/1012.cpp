#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
char idx2type[4] = {'A', 'C', 'M', 'E'};
double S[maxn][4];
double G[4][maxn];
unordered_map<int, int> id2ord;
int main()
{
    int n, m_;
    cin >> n >> m_;
    int id;
    double c, m, e;
    double a;
    for (int i = 0; i < n; ++i)
    {
        cin >> id >> c >> m >> e;
        id2ord[id] = i;
        a = (c + m + e) / 3;
        S[i][0] = G[0][i] = a;
        S[i][1] = G[1][i] = c;
        S[i][2] = G[2][i] = m;
        S[i][3] = G[3][i] = e;
    }
    sort(G[0], G[0] + n, greater<double>());
    sort(G[1], G[1] + n, greater<double>());
    sort(G[2], G[2] + n, greater<double>());
    sort(G[3], G[3] + n, greater<double>());

    int ord, h_o;
    int h_t;
    for (int i = 0; i < m_; ++i)
    {
        h_o = INT_MAX;
        cin >> id;
        if (!id2ord.count(id))
        {
            cout << "N/A" << endl;
            continue;
        }
        int true_id = id2ord[id];
        for (int j = 0; j < 4; ++j)
        {
            ord = lower_bound(G[j], G[j] + n, S[true_id][j], greater<double>()) - G[j] + 1;
            if (ord < h_o)
            {
                h_o = ord;
                h_t = j;
            }
        }

        cout << h_o << " " << idx2type[h_t] << endl;
    }
    return 0;
}