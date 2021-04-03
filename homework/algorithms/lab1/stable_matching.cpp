//hdu 1522 --marriage is stable
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> man_pre, wom_pre;  //男生和女生的喜好表
vector<int> proposed_num;              //第i个男生已追求的女生数
vector<int> m_matched, w_matched;      //男生和女生当前匹配的人的编号
vector<string> names;                  //记录名称
map<string, int> m_name2id, w_name2id; //名字转编号
void matching()
{
    bool hasSingle = true;
    while (hasSingle)
    {
        hasSingle = false;
        for (int i = 0; i < n; ++i)
        {
            //如果存在男生i未匹配且没有向所有女生表白
            if (m_matched[i] == -1 && proposed_num[i] != n)
            {
                hasSingle = true;
                //找到男生i喜爱列表的第一个女生w_
                int w_ = man_pre[i][proposed_num[i]++];
                //如果w_当前未匹配任何人
                if (w_matched[w_] == -1)
                {
                    //将i和w_匹配
                    m_matched[i] = w_;
                    w_matched[w_] = i;
                }
                //如果w_发现i比w_当前匹配的男生魅力大
                else
                {
                    auto it = find(wom_pre[w_].begin(), wom_pre[w_].end(), i);
                    auto mt = find(wom_pre[w_].begin(), wom_pre[w_].end(), w_matched[w_]);
                    //排名越小越喜欢
                    if (it < mt)
                    {
                        //m_被遗弃
                        m_matched[w_matched[w_]] = -1;
                        //将i和w_匹配
                        m_matched[i] = w_;
                        w_matched[w_] = i;
                    }
                }
            }
        }
    }
}
int main()
{
    cout << "输入情侣对数" << endl;
    //输入对数
    cin >> n;
    man_pre.resize(n, vector<int>(n));
    wom_pre.resize(n, vector<int>(n));
    m_matched.resize(n, -1);
    w_matched.resize(n, -1);
    names.resize(2 * n);
    proposed_num.resize(n, 0);

    cout << "输入男生喜好列表" << endl;
    //输入男生喜欢列表
    string tmp;
    cin >> names[0];
    m_name2id[names[0]] = 0;
    for (int j = 0; j < n; ++j)
    {
        cin >> names[n + j];
        w_name2id[names[n + j]] = j;
        man_pre[0][j] = j;
    }

    for (int i = 1; i < n; ++i)
    {
        cin >> names[i];
        m_name2id[names[i]] = i;
        for (int j = 0; j < n; ++j)
        {
            cin >> tmp;
            man_pre[i][j] = w_name2id[tmp];
        }
    }

    cout << "输入女生喜好列表" << endl;
    //输入女生喜欢列表
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        for (int j = 0; j < n; ++j)
        {
            cin >> tmp;
            wom_pre[i][j] = m_name2id[tmp];
        }
    }

    matching();
    cout << "结果为" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << names[i] << " " << names[m_matched[i] + n] << endl;
    }
}