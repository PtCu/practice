#include <bits/stdc++.h>
using namespace std;
int used[20];
int n;
string source[20];
int ans = 0;
//求最小重叠部分
int leastOverlap(string s1, string s2)
{
    int len1=s1.length();
    int len2=s2.length();
    for(int i=1;i<min(len1,len2);i++){
        string sub1=s1.substr(len1-i,i);
        string sub2=s2.substr(0,i);
        if(!sub1.compare(sub2)) //x相等返回0
        return i;
    }
    return 0;

}
void dfs(string now, int length)
{
    ans = max(length, ans);
    for (int i = 0; i < n; i++)
    {
        if (used[i] >= 2)   //最多出现两次
            continue;
        int overlap_nums = leastOverlap(now, source[i]);
        if (!overlap_nums)
            continue;
        used[i]++;
        dfs(source[i], length + source[i].length() - overlap_nums);
        used[i]--; //这条分支已经探索过，回溯时要还原为原来的样子
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i <n; i++)
    {
       cin>>source[i];
    }
    char head;
    cin>>head;
    for(int i=0;i<n;i++){
        if(source[i][0]==head){
            used[i]++;
            dfs(source[i],source[i].length());
        }
        
    }
   
    cout<<ans;
    // cout<<leastOverlap("e","envelope");
}