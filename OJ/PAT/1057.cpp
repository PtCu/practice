#include <bits/stdc++.h>
using namespace std;
multiset<int> se;
stack<int> st;
auto mid = se.begin();
int main()
{
    int n;
    cin >> n;
    char s[12];
    int x;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        if (s[1] == 'e')
        {
            int n = se.size();
            int mid;
            if (se.size() % 2 == 0)
            {
                mid = n / 2;
            }
            else
            {
                mid = (n + 1) / 2;
            }
            auto ans = next(se.begin(), mid);
        }
        else if (s[1] == 'o')
        {
            if (st.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                st.pop();
                auto er = se.lower_bound(x);
                if (*er < *mid)
                    ++mid;
                se.erase(se.lower_bound(x));
            }
        }
        else if (s[2] == 'u')
        {
            scanf("%d", &x);
            st.push(x);
            auto in = se.insert(x);
            if (x < *mid)
                --mid;
        }
    }
}