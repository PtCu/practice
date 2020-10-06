// #include <bits/stdc++.h>
// using namespace std;
// const int XN=1e3+10;
// vector<string> source(XN);
// map<char, int> first, last;
// int n;
// bool visited[XN];
// string dfs(int cur, int remain)
// {
//     string current = source[cur];
//     int len = current.length();
//     string next1 ="";   //更深的dfs遍历结果的最大值
//     if (remain == 1)
//         return current;
//     for (int i = 0; i < n; i++)
//     {
//         if (visited[i])
//             continue;
//         if (source[i][0] == source[cur][len - 1])
//         {
//             visited[i] = true;
//             string next2=dfs(i,remain-1);
//             if(next1.length()<next2.length()){
//                 next1=next2;
//             }
//             visited[i] = false;
//         }
//     }
//     if(remain==n&&next1=="") return "***";
//     return current+"."+next1;
// }
// int main()
// {

//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> source[i];
//         int len = source[i].length();
//         first[source[i][0]]++; //map第二个为int类型的话自动初始为0
//         last[source[i][len - 1]]++;
//     }
//     int start = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (first[source[i][0]] - last[source[i][0]] == 1)
//         {
//             start = i;
//             break;
//         }
//     }
//     visited[start] = true;
//     cout<<dfs(start,n);
// }
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
     sort(source.begin(),source.begin()+n);
    int start = 0;
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