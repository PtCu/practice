#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string name, e_name, l_name;
    int start_t, end_t;
    int e_t = INT_MAX, l_t = -1;
    int h, m, s;

    for (int i = 0; i < n; ++i)
    {
        cin >> name;
        scanf("%d:%d:%d", &h, &m, &s);
        start_t = h * 3600 + m * 60 + s;
        scanf("%d:%d:%d", &h, &m, &s);
        end_t = h * 3600 + m * 60 + s;
        if (start_t < e_t)
        {
            e_t = start_t;
            e_name = name;
        }
        if (end_t > l_t)
        {
            l_t = end_t;
            l_name = name;
        }
    }
    cout << e_name << " " << l_name;
}