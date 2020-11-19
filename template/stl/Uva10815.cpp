//set的用法。5.2.3
#include<bits/stdc++.h>
using namespace std;
set<string> dict;

int main(){
    string s,buf;
    while(cin>>s){  //输入空格或者回车时接受下一个
        if(s[0]=='#') break;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        stringstream ss(s);
        while(ss>>buf)  //stringstream以空格分割字符串
            dict.insert(buf);   //利用set中的字符串已经排好顺序这一性质。
    }
    for(set<string>::iterator i=dict.begin();i!=dict.end();i++){
        cout<<*i<<'\n';
    }
    return 0;
}