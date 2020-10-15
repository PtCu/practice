#include <bits/stdc++.h>
/*
tie 函数
tie是将两个stream绑定的函数，空参数的话返回当前的输出流指针。
在ACM里，经常出现 数据集超大造成 cin TLE的情况。我们可以在IO之前将stdio解除绑定，这样做了之后要注意不要同时混用cout和printf 之类。
在默认的情况下cin绑定的是cout，每次执行 << 操作符的时候都要调用flush，这样会增加IO负担。可以通过tie(0)（0表示NULL）来解除cin与cout的绑定，进一步加快执行效率。
*/
int main() {
    std::ios::sync_with_stdio(0); //取消cin,cout的缓存
    std::cin.tie(0);std::cout.tie(0);    //解绑
    int T;std::cin>>T;
    while(T--) {
        std::string s;std::cin>>s;
        int r=0;
        for(char c : s)
            ((r*=10)+=c-'0')%=9;
        std::cout<<r<<'\n'; //endl=换行+缓冲。'\n'无缓冲
    }
    return 0;
}

