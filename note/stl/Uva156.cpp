//map的用法 5.2.4
#include<bits/stdc++.h>
using namespace std;
// vector 的reserve增加了vector的capacity，但是它的size没有改变！
//而resize改变了vector的capacity同时也增加了它的size！
// 原因如下：
//   reserve是容器预留空间，但在空间内不真正创建元素对象，所以在没有添加新的对象之前，
//不能引用容器内的元素。加入新的元素时，要调用push_back() /
//  insert() 函数。

// resize是改变容器的大小，且在创建对象，因此，调用这个函数之后，就可以引用容器内的对象了，因此当加入新的元素时，用operator[] 操作符，或者用迭代器来引用元素对象。此时再调用push_back() 函数，是加在这个新的空间后面的。
vector<string> words;
map<string,int> cnt;

//将字符串标准化
string repr(const string& s){
    string ans=s;
    for(int i=0;i<ans.length();i++){
        ans[i]=tolower(ans[i]);
    }
    sort(ans.begin(),ans.end());        //字符串也有迭代器
    return ans;
}
int main(){
    int n=0;
    string s;
    while(cin>>s){
        if(s[0]=='#') break;
        words.push_back(s); //保留原来的字符串
        string r=repr(s);
        if(!cnt.count(r)) cnt[r]=1; //先看看有没有。使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。
        else cnt[r]++;
    }
    vector<string> ans;
    sort(words.begin(),words.end());
    for(int i=0;i<words.size();i++){
        if(cnt[repr(words[i])]==1)
        cout<<words[i]<<endl;
    }

}