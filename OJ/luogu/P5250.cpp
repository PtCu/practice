#include <bits/stdc++.h>
using namespace std;
set<int> S;
int main()
{
    int n, length, x;
    cin >> n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (n--)
    {
        cin >> x >> length;
        if (x == 1)
        {
            if (S.count(length))
            {
                cout << "Already Exist" << endl;
                continue;
            }
            S.insert(length);
        }
        else if (x == 2)
        {

            if (S.empty())
            {
                cout << "Empty" << endl;
                continue;
            }
            set<int>::iterator it1 = S.find(length);
            //存在length长度
            if (it1 != S.end())
            {
                cout << *it1 << endl;
                S.erase(it1);
            }
            else
            {
                //assert：此时至少有一个元素，且这个元素长度不为length
                //第一个大于length的木材
                it1 = S.upper_bound(length);

                //如果不存在大于length的木材
                if (it1 == S.end())
                {
                    //直接输出小于length的木材
                    cout << *(--it1) << endl;
                    S.erase(it1);
                }
                //有大于length的木材
                else
                {
                    //没有小于length的木材
                    if (it1 == S.begin())
                    {
                        //直接输出大于length的木材
                        cout << *it1 << endl;
                        S.erase(it1);
                    }
                    //存在大于length和小于length的木材
                    else
                    {
                        set<int>::iterator it2 = it1; //较短的
                        --it2;
                        int size2 = abs(length - *it2), size1 = abs(*it1 - length);
                        //较长的更合适
                        if (size1 < size2)
                        {
                            cout << *it1 << endl;
                            S.erase(it1);
                        }
                        else
                        {
                            cout << *it2 << endl;
                            S.erase(it2);
                        }
                    }
                }
            }
        }
    }
}