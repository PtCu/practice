#include <bits/stdc++.h>
using namespace std;

struct node
{
    int num;//变换次数
    string s;//变换n次后的结果
    node(int num,string s):num(num),s(s){}//构造函数
};
string A,B;//初始字符串和目标字符串
vector< pair<string,string> >v;//存储规则
set<string>reapr;//判重

bool bfs()
{
    queue<node>q;
    q.push(node(0,A));
    while(!q.empty()){
        node u=q.front();
        q.pop();
        if(u.num>10) {printf("NO ANSWER!\n");return false;}//如果队头的字符串转换次数超过10次，不存在答案
        for (int i=0;i<v.size();i++)
            if (u.s.find(v[i].first)!=-1)//如果该字符串存在可以转换的情况
                for (int j=u.s.find(v[i].first);j<u.s.length();j=u.s.find(v[i].first,j+1)){//从该字符继续搜索串下一个可能转换位置
                    string t=u.s;
                    t.replace(j,v[i].first.length(),v[i].second);//构造出转换后的字符串
                    if(t==B) {printf("%d\n",u.num+1);return true;}//如果转换后的字符串为目标串B
                    if(!reapr.count(t)){//判重！非常重要，不然一定会超时
                        q.push(node(u.num+1,t));
                        reapr.insert(t);//如果之前没有出现过该字符串，则加入到已出现的集合，以防下次再次出现
                    }
                }
    }
    return false;//不存在答案
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>A>>B;
    string a,b;
    while(cin>>a>>b)
        v.push_back(make_pair(a,b));
    if(!bfs()) printf("NO ANSWER!\n");
    return 0;
}
