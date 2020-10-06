#include <bits/stdc++.h>
using namespace std;
struct Element
{
    string name;
    int num;
    Element(string _name, int _num) : name(_name), num(_num) {}
};

//获取系数
int getNum(string s, int &index)
{
    int result = 0;
    while (isdigit(s[index]))
    {
        result += result * 10 + s[index] - '0';
        index++;
    }
    return result;
}

void Calculate(string &s, map<string, int> &mp)
{
    stringstream ss(s); //将字符串s作为输入流
    string item;
    while (getline(ss, item, '+')) //item为系数+化学式 getline(<字符数组chs>，<读取字符的个数n>，<终止符>)
    {
        vector<Element> arr;
        int factor = 1; //若系数为空串，则系数默认为1
        int i = 0;
        if (isdigit(item[i])) //若系数不是空串，则获取系数
        {                     //在调用完getNum函数之后，i指向字符串item系数后面的元素
            factor = getNum(item, i);
        }
        while (i < item.size()) //获取字母
        {
            if (isupper(item[i])) //若为大写字母
            {
                string name;
                name += item[i]; //获取元素的名称
                i++;
                if (islower(item[i])) //该元素由两个字母组成
                {
                    name += item[i];
                    i++;
                }
                arr.push_back(Element(name, 1));
            }
            else if (isdigit(item[i])) //项后面的系数
            {
                int behind = getNum(item, i);
                if (arr[arr.size() - 1].name == ")") //该系数位于右括号后边 (OH)2
                {
                    int j = arr.size() - 1;
                    arr[j].name = "*"; //将右括号标记为*
                    j--;
                    while (arr[j].name != "(")
                    {
                        arr[j].num *= behind; //更新括号内元素个数
                        j--;
                    }
                    arr[j].name = "*"; //将左括号标记为*
                }
                else //系数在单个元素的后边  O2
                {
                    arr[arr.size() - 1].num *= behind;
                }
            }
            else if (item[i] == '(') //处理左括号
            {
                arr.push_back(Element("(", 0));
                i++;
            }
            else if (item[i] == ')') //处理右括号
            {
                arr.push_back(Element(")", 0));
                //若右括号后边没有数字，则该系数默认为1
                //如Na(Au(CN)2)
                if (!isdigit(item[i + 1]) || item.size() == i + 1)
                {
                    item.insert(i + 1, "1"); //在右括号的后边插入1
                }
                i++;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].name == "*")
                continue;
            else //将所有元素乘上最前边的系数，更新mp
                mp[arr[i].name] += arr[i].num * factor;
        }
    }
}

void judge(map<string, int> &left, map<string, int> &right)
{
    if (left.size() != right.size())
    {
        cout << "N" << endl;
        return;
    }
    for (map<string, int>::iterator it = left.begin(); it != left.end(); it++)
    {
        if (it->second != right[it->first])
        {
            cout << "N" << endl;
            return;
        }
    }
    cout << "Y" << endl;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        map<string, int> left, right;
        string equation, str1, str2;
        getline(cin, equation); //读取一行方程式    string中的getline
        //istream& getline (istream&  is, string& str, char delim);
        // is ：表示一个输入流，例如 cin。
        // str ：string类型的引用，用来存储输入流中的流信息。
        // delim ：char类型的变量，所设置的截断字符；在不自定义设置的情况下，遇到’\n’，则终止输入。 
        stringstream ss(equation);
        getline(ss, str1, '='); //截取左半边，遇到=停止
        getline(ss, str2);      //截取右半边，遇到\n停止
        Calculate(str1, left);  //计算左半边的元素数
        Calculate(str2, right); //计算右半边的元素数
        judge(left, right);     //比较两端的个数
    }
    return 0;
}