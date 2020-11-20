#include <bits/stdc++.h>
//生成LR表所需的数据结构
namespace gen_LR
{
    //符号
    struct V_T
    {
        bool type;            //是否为终结符，1为终结符
        std::string raw_info; //原始的符号字面量
        V_T() = default;
        V_T(bool s_type, const std::string &s_s) : type(type), raw_info(s_s) {}
        bool operator==(const V_T &e) const
        {
            return type == e.type && raw_info == e.raw_info;
        }
        bool operator<(const V_T &e) const
        {
            return raw_info < e.raw_info;
        }
    };

    //胡乱写的一个哈希函数
    struct NodeHash
    {
        size_t operator()(const V_T &e) const
        {
            return e.raw_info.size() * 7 + e.type * 5;
        }
    };

    using P_left = V_T;                            //产生式左部
    using P_right = std::vector<std::vector<V_T>>; //产生式右部
    std::set<V_T> V_list;                          //非终结符表
    std::set<V_T> T_list;                          //终结符表

    std::unordered_map<P_left, P_right, NodeHash> tot_production; //总产生式集合。输入后先放在这里
    //带点的产生式
    struct dot_P
    {
        size_t dot_index;         //·的位置，规定·位于dot_index的符号的前面. dot_index为长度时是说明读完
        P_left P_left;            //产生式左部
        std::vector<V_T> P_right; //产生式右部
    };

    //一个项目
    struct Item
    {
        std::vector<dot_P> P_list; //一个项目的所有带点产生式
        int id;
    };

    struct Edge
    {
        int to;        //指向的结点
        V_T condition; //读入condition后跳转到to
    };

    std::vector<std::vector<Edge>> G; //项目集规范族.G[i]表示第i个结点的边

    //字符串分割函数
    inline void split(std::string str, std::string pattern, std::vector<std::string> &result)
    {
        std::string::size_type pos;

        str += pattern; //扩展字符串以方便操作
        size_t size = str.size();

        for (size_t i = 0; i < size; i++)
        {
            pos = str.find(pattern, i);
            if (pos < size)
            {
                std::string s = str.substr(i, pos - i);
                result.push_back(s);
                i = pos + pattern.size() - 1;
            }
        }
    }
}; // namespace gen_LR

using namespace std;
//读入终结符和非终结符列表
void getV()
{
    
}
void getV_T()
{
    string s;
    cout << "输入非终结符，以#结尾" << endl;
    while (cin >> s)
    {
        if (s == "#")
            break;
        //产生式左部符号入列表中
        gen_LR::T_list.insert({1, s});
    }
    cout << "输入终结符，以#结尾" << endl;
    while (cin >> s)
    {
        if (s == "#")
            break;
        //产生式左部符号入列表中
        gen_LR::V_list.insert({0, s});
        s.clear();
    }
}
void genProduction()
{
    string s, s_right;
    vector<string> tmp_result;
    gen_LR::P_right p_right;
    ifstream f("test1.txt");
    stringstream ss;

    while (getline(f, s))
    {
        //将字符串按照->分割，左边的为产生式左部符号
        gen_LR::split(s, "->", tmp_result);

        gen_LR::P_left p_left = {0, tmp_result[0]};

        //取产生式右边符号
        s_right = tmp_result[1];
        tmp_result.clear();

        //有多个产生式的话以|隔开，并将结果放入tmp_result中
        gen_LR::split(s_right, "|", tmp_result);
        s_right.clear();

        //右部产生式调整大小
        p_right.resize(tmp_result.size());

        //对每个产生式做操作：
        for (size_t i = 0; i < p_right.size(); ++i)
        {
            string p = tmp_result[i];
            tmp_result.clear();
            //按照空格分割为不同的符号
            gen_LR::split(p, " ", tmp_result);

            for (auto word : tmp_result)
            {
                //如果该符号是非终结符
                if (gen_LR::V_list.count({0, word}))
                {
                    p_right[i].push_back({0, word});
                }
                //否则就是终结符
                else if (gen_LR::T_list.count({1, word}))
                    p_right[i].push_back({1, word});
                else
                {
                    //报错
                }
            }
        }
        gen_LR::tot_production[p_left] = p_right;
        p_right.clear();
        tmp_result.clear();
    }

    for (auto i : gen_LR::tot_production)
    {
        cout << i.first.raw_info << "->";
        for (size_t j = 0; j < i.second.size(); ++j)
        {
            for (size_t k = 0; k < i.second[j].size(); ++k)
            {
                cout << i.second[j][k].raw_info << " ";
            }
            cout << " | ";
        }
        cout << endl;
    }
}
int main()
{
    getV_T();
    genProduction();
}
