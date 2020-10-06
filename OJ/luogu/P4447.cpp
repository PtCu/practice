#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> sources(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sources[i];
    }
    vector<stack<int> *> Q;
    sort(sources.begin(), sources.end());
    stack<int> *s = new stack<int>;
    s->push(sources[0]);
    Q.push_back(s);
    int ans = INT_MAX;
   
    for (int i = 1; i < n; i++)
    {
        bool found = false;
        for (int j = Q.size()-1; j >=0; j--)
        {
            if (sources[i] == Q[j]->top() + 1)
            {
                found = true;
                Q[j]->push(sources[i]);
                break;
            }
            
        }
        if (!found)
        {
            stack<int> *s1 = new stack<int>;
            s1->push(sources[i]);
            Q.push_back(s1);
        }
    }

    for (int i = 0; i < Q.size(); i++)
    {
        ans = min(ans, (int)Q[i]->size());
        stack<int> s;
        swap(s, *Q[i]);
        delete Q[i];
    }
    cout << ans;
}