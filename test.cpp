#include <bits/stdc++.h>
using namespace std;
int P = 100000;
int Pow(long long base, int v)
{
    long long res = 1;
    for (; v; v >>= 1, (base *= base) %= P)
        if (v & 1)
            (res *= base) %= P;
    return res;
}
bool Enlarge(int &a, int &b)
{
    return a < b ? a = b, 1 : 0;
}
void split(const std::string &in,
           std::vector<std::string> &out,
           std::string token)
{
    out.clear();

    std::string temp;

    for (int i = 0; i < int(in.size()); i++)
    {
        std::string test = in.substr(i, token.size());
        //若pos的值超过了string的大小，则substr函数会抛出一个out_of_range异常；若pos+n的值超过了string的大小，则substr会调整n的值，只拷贝到string的末尾
        if (test == token)
        {
            if (!temp.empty())
            {
                out.push_back(temp);
                temp.clear();
                i += (int)token.size() - 1;
            }
            else
            {
                out.push_back("");
            }
        }
        else if (i + token.size() >= in.size())
        {
            temp += in.substr(i, token.size());
            out.push_back(temp);
            break;
        }
        else
        {
            temp += in[i];
        }
    }
}
std::string tail(const std::string &in)
{
    size_t token_start = in.find_first_not_of(" \t");
    size_t space_start = in.find_first_of(" \t", token_start);
    size_t tail_start = in.find_first_not_of(" \t", space_start);
    size_t tail_end = in.find_last_not_of(" \t");
    if (tail_start != std::string::npos && tail_end != std::string::npos)
    {
        return in.substr(tail_start, tail_end - tail_start + 1);
    }
    else if (tail_start != std::string::npos)
    {
        return in.substr(tail_start);
    }
    return "";
}
int main()
{
    string in = "0 12345 6";
    string token = "23";
    vector<string> out;
    string s=tail(in);
}