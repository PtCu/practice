#include <bits/stdc++.h>
using namespace std;
int n, target[1000];
int main()
{
    while (scanf("%d", &n) == 1)
    {
        stack<int> s;
        int A = 1, B = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &target[i]);
        }
        int ok = 1;
        while (B <= n)
        {
            if (A == target[B])
            {
                A++;
                B++;
            }
            else if (!s.empty() && s.top() == target[B])
            {
                s.pop();
                B++;
            }
            else if (A <= n)
                s.push(A++);
            else
            {
                ok = 0;
                break;
            }
        }
        printf("%s\n",ok?"Yes":"No");
    }
}