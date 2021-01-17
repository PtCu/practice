#include <bits/stdc++.h>
using namespace std;
const int XN = 1e3 + 10;
vector<string> source(XN);
map<char, int> first, last;
int n;
bool visited[XN];
bool isFound = false;
vector<string> ans;
vector<string> now;
void dfs(int cur, int remain)
{
    if (isFound)
        return;
    string current = source[cur];
    int len = current.length();
    if (remain == 1)
    {
        isFound = true;
        ans.assign(now.begin(), now.end());
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        if (source[i][0] == source[cur][len - 1])
        {
            visited[i] = true;
            now.push_back(source[i]);
            dfs(i, remain - 1);
            // if (now.size() > 0)
            now.pop_back();
            visited[i] = false;
        }
    }
}
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> source[i];
        int len = source[i].length();
        first[source[i][0]]++; //map第二个为int类型的话自动初始为0
        last[source[i][len - 1]]++;
    }
    sort(source.begin(), source.begin() + n);
    int start = 0;
    /*
    （１）一定有一个字母，其出现在字符串首位的个数等于出现在字符串末尾的个数＋１，这个字母一定作起点（设为c）。
    （２）一定还有一个字母，其出现在字符串首位的个数等于出现在字符串末尾的个数－１，这个字母一定作终点（设为d）。
    我们在以ｃ为首的字符串中找到字典序小的，让它作为起点即可。
    但是同时我们得保证该字符串的终点不为d，或者以d为结尾的个数不为１，要加上这个判断
    */
    //开头比结尾多一的单词作为起点
    for (int i = 0; i < n; i++)
    {
        if (first[source[i][0]] - last[source[i][0]] == 1)
        {
            start = i;
            break;
        }
    }

    visited[start] = true;
    now.push_back(source[start]);
    dfs(start, n);
    if (isFound)
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << ans[i];
            else
                cout << ans[i] << ".";
        }
    else
        cout << "***";
}