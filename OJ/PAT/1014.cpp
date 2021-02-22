#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
struct Window
{
    int current;
    int next;
    queue<int> Q;
} windows[maxn];

int finish[maxn];
int req[maxn];

int main()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; ++i)
    {
        cin >> req[i];
    }

    //第一波来的就办理业务的，finish[i]可以直接确定
    int cnt = 1;
    while (cnt <= k && cnt <= n)
    {
        windows[cnt].current = req[cnt];
        windows[cnt].next = req[cnt];
        finish[cnt] = req[cnt];
        cnt++;
    }

    //黄线以内的，排队
    while (cnt <= k && cnt <= n * m)
    {
        int id = (cnt % n == 0) ? n : cnt % n;
        windows[id].next += req[cnt];
        windows[id].Q.push(cnt);
        finish[cnt] = windows[id].next;
        cnt++;
    }

    //黄线以外的，挑选队列先变短的
    while (cnt <= k)
    {
        int id = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (windows[i].current < windows[id].current)
            {
                id = i;
            }
        }
        windows[id].current += req[windows[id].Q.front()];
        windows[id].Q.pop();
        windows[id].Q.push(cnt);
        windows[id].next += req[cnt];
        finish[cnt] = windows[id].next;
        cnt++;
    }
    for (int i = 1; i <= q; ++i)
    {
        int query;
        cin >> query;
        if(finish[query]-req[query]>=9*60){
            cout << "Sorry" << endl;
        }
        else{
            printf("%02d:%02d\n", finish[query] / 60 + 8, finish[query] % 60);
        }
    }
}